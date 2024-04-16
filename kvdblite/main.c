//https://github.com/garyexplains/kvdblite
struct avl_key {
    int key;
} avl_key_t


struct node {
    struct node *left, *right;
    int diff;
    avl_key_t *key;
    avl_value_t *value;
}

struct avltree {
    struct node *root;
}

struct avl_lookup_result {
    avl_key_t *key;
    avl_value_t *value;
}

struct avltree *avl_make(uint8_t *);
void avl_free(struct avltree *);

void avl_insert(struct avltree *, avl_key_t *, avl_value_t *);
void avl_remove(struct avltree *, avl_key_t *);
struct avl_lookup_result *avl_lookup(struct avltree *, avl_key_t *);
void avl_free_lookup_result(struct avl_lookup_result *r);

void rotate_right(struct node **rp);
void rotate_left(struct node **rp);
int balance(struct node **rp);

void rotate_right(struct node **rp)
{
    struct node *a = *rp, *b = a->left;
    a->left = b->right;
    b->right = a;
    fix_diffs_right(&a->diff, &b->diff);
    *rp = b;
}

void rotate_left(struct node **rp)
{
    struct node *a = *rp, *b = a->right;
    a->right = b->left;
    b->left = a;
    fix_diffs_left(&a->diff, &b->diff);
    *rp = b;
}