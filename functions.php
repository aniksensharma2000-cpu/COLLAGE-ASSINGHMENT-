<?php

// ─────────────────────────────────────────────────────────────
//  PRODUCT FUNCTIONS  (DB-backed, with safe fallbacks)
// ─────────────────────────────────────────────────────────────

/**
 * Fetch all active products from the database.
 */
function getCatalog(): array
{
    if (!DB_CONNECTED) {
        return [];
    }
    $result = mysqli_query(db(), "SELECT * FROM products WHERE status = 'active' ORDER BY created_at DESC");
    if (!$result) {
        return [];
    }
    $items = [];
    while ($row = mysqli_fetch_assoc($result)) {
        $items[] = _normaliseProduct($row);
    }
    return $items;
}

/**
 * Fetch only featured active products.
 */
function getFeaturedProducts(): array
{
    if (!DB_CONNECTED) {
        return [];
    }
    $result = mysqli_query(db(), "SELECT * FROM products WHERE status = 'active' AND featured = 1 ORDER BY created_at DESC");
    if (!$result) {
        return [];
    }
    $items = [];
    while ($row = mysqli_fetch_assoc($result)) {
        $items[] = _normaliseProduct($row);
    }
    return $items;
}

/**
 * Find a single product by its slug.
 */
function getProductBySlug(string $slug): ?array
{
    if (!DB_CONNECTED || $slug === '') {
        return null;
    }
    $stmt = mysqli_prepare(db(), "SELECT * FROM products WHERE slug = ? AND status = 'active' LIMIT 1");
    if (!$stmt) {
        return null;
    }
    mysqli_stmt_bind_param($stmt, 's', $slug);
    mysqli_stmt_execute($stmt);
    $result = mysqli_stmt_get_result($stmt);
    $row    = mysqli_fetch_assoc($result);
    mysqli_stmt_close($stmt);
    return $row ? _normaliseProduct($row) : null;
}

/**
 * Find a single product by its ID — single query, no N+1.
 */
function getProductById(int $id): ?array
{
    if (!DB_CONNECTED || $id <= 0) {
        return null;
    }
    $stmt = mysqli_prepare(db(), "SELECT * FROM products WHERE id = ? AND status = 'active' LIMIT 1");
    if (!$stmt) {
        return null;
    }
    mysqli_stmt_bind_param($stmt, 'i', $id);
    mysqli_stmt_execute($stmt);
    $result = mysqli_stmt_get_result($stmt);
    $row    = mysqli_fetch_assoc($result);
    mysqli_stmt_close($stmt);
    return $row ? _normaliseProduct($row) : null;
}

/**
 * Normalise a DB row into the shape the front-end templates expect.
 */
function _normaliseProduct(array $row): array
{
    return [
        'id'          => (int)   ($row['id']          ?? 0),
        'slug'        =>          $row['slug']         ?? '',
        'name'        =>          $row['name']         ?? '',
        'category'    =>          $row['category']     ?? '',
        'price'       => (float) ($row['price']        ?? 0),
        'rating'      => (float) ($row['rating']       ?? 4.5),
        'reviews'     => (int)   ($row['reviews']      ?? 0),
        'featured'    => (bool)  ($row['featured']     ?? false),
        'badge'       =>          $row['badge']        ?? 'New',
        'image'       =>          $row['image_url']    ?? '',
        'description' =>          $row['description']  ?? '',
        'demo'        =>          $row['demo_url']     ?? '',
        // files stored as comma-separated string → array
        'files'       => array_values(array_filter(array_map('trim', explode(',', $row['files'] ?? '')))),
        'status'      =>          $row['status']       ?? 'active',
    ];
}

// ─────────────────────────────────────────────────────────────
//  STATIC CONTENT FUNCTIONS
// ─────────────────────────────────────────────────────────────

function getTestimonials(): array
{
    return [
        [
            'name'  => 'Nadia S.',
            'role'  => 'Course Creator',
            'quote' => 'VISTARA helped me package my knowledge into a polished digital product launch in under a week.'
        ],
        [
            'name'  => 'Arun P.',
            'role'  => 'SaaS Founder',
            'quote' => 'The onboarding templates and dashboards are incredibly practical. It feels premium and useful from day one.'
        ],
        [
            'name'  => 'Leah M.',
            'role'  => 'Marketing Lead',
            'quote' => 'Everything is organized, easy to purchase, and the support experience was smooth and fast.'
        ]
    ];
}

function getFaqs(): array
{
    return [
        ['question' => 'How do I download purchased products?',  'answer' => 'After checkout, visit your Orders page and use the secure download link to access your purchased files.'],
        ['question' => 'Are updates included?',                  'answer' => 'Yes. All products include updates for the current version and future minor enhancements included in your plan.'],
        ['question' => 'Do you offer refunds?',                  'answer' => 'Digital products are usually covered by our satisfaction policy, and the admin can review refund requests manually.'],
        ['question' => 'Can I use these assets commercially?',   'answer' => 'Most product packs include commercial-use rights, and the listing details specify the exact licensing terms.']
    ];
}

// ─────────────────────────────────────────────────────────────
//  PRICE HELPER
// ─────────────────────────────────────────────────────────────

function formatPrice(float $price): string
{
    return '₹' . number_format($price, 2);
}

// ─────────────────────────────────────────────────────────────
//  FLASH MESSAGE HELPERS
// ─────────────────────────────────────────────────────────────

/**
 * Store a one-time flash message in the session.
 * type: 'success' | 'error'
 */
function setFlash(string $type, string $message): void
{
    $_SESSION['flash'] = ['type' => $type, 'message' => $message];
}

/**
 * Read and clear the flash message. Returns null if none.
 */
function getFlash(): ?array
{
    if (!isset($_SESSION['flash'])) {
        return null;
    }
    $flash = $_SESSION['flash'];
    unset($_SESSION['flash']);
    return $flash;
}

// ─────────────────────────────────────────────────────────────
//  CART FUNCTIONS  (session-based)
// ─────────────────────────────────────────────────────────────

function getCartCount(): int
{
    return count($_SESSION['cart'] ?? []);
}

function addToCart(int $productId): void
{
    $cart = $_SESSION['cart'] ?? [];
    // Prevent duplicates
    if (!in_array($productId, $cart, true)) {
        $cart[] = $productId;
    }
    $_SESSION['cart'] = $cart;
}

function removeFromCart(int $productId): void
{
    $cart             = $_SESSION['cart'] ?? [];
    $_SESSION['cart'] = array_values(array_filter($cart, fn($id) => (int)$id !== $productId));
}

/**
 * Fetch cart items — single query per item (no N+1 double-query).
 */
function getCartItems(): array
{
    $cart  = $_SESSION['cart'] ?? [];
    $items = [];
    foreach ($cart as $productId) {
        $product = getProductById((int) $productId);
        if ($product) {
            $items[] = $product;
        }
    }
    return $items;
}

function getCartTotal(): float
{
    $total = 0.0;
    foreach (getCartItems() as $item) {
        $total += (float) $item['price'];
    }
    return $total;
}
