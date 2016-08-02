// IMPORTANT: DO NOT CHANGE THESE VALUES
const int PRE_ORDER = 0;
const int IN_ORDER = 1;
const int POST_ORDER = 2;

// IMPORTANT: DO NOT CHANGE THESE DEFINITIONS
struct bstnode {
    int item;
    struct bstnode *left;
    struct bstnode *right;
    int size;
};

struct bst {
    struct bstnode *root;
};

Bst bst_create(void) {
    struct bst *new = malloc(sizeof(struct bst));
    new->root = NULL;
    return new;
}

static void free_bstnode(struct bstnode *node) {
  if (node) {
    free_bstnode(node->left);
    free_bstnode(node->right);
    free(node);
  } 
}

void bst_destroy(Bst t) {
    assert(t);
    free_bstnode(t->root);
    free(t);
}

int bst_size(Bst t) {
    assert(t);
    return t->root->size;
}

static struct bstnode *insert_bstnode(int i, struct bstnode *node) {
  if (node == NULL) {
    node = malloc(sizeof(struct bstnode));
    node->item = i;
    node->size = 1;
    node->left = NULL;
    node->right = NULL;
    } 
    else if (i < node->item) {
        node->size++;
        node->left = insert_bstnode(i, node->left);
    } 
    else {
        node->size++;
        node->right = insert_bstnode(i, node->right);
    } 
  return node;
}

void bst_insert(int i, Bst t) {
    assert(t);
    if (bst_find(i, t)) return;
    t->root = insert_bstnode(i, t->root);
}

static bool bstnode_find(int i, struct bstnode *node){
    if (node == NULL) return 0;
    if (i == node->item) return 1;
    else if (i < node->item)
            return bstnode_find(i, node->left);
    else return bstnode_find(i, node->right);
}

bool bst_find(int i, Bst t) {
    assert(t);
    return bstnode_find(i, t->root);
}

static int select_node(int k, struct bstnode *node) {
    int left_size = 0;
    if (node->left) 
        left_size = node->left->size;
    if (k < left_size) 
        return select_node(k, node->left);
    if (k == left_size) 
        return node->item;
    return select_node(k - left_size - 1, node->right);
}


int bst_select(int k, Bst t) {
    assert(t);
    assert(0 <= k && k < t->root->size);
    return select_node(k, t->root);
}

static struct bstnode *remove_bstnode(int key, struct bstnode *node) { // key did not exist:
    if (node == NULL) return NULL;
// search for the node that contains the key
    if (key < node->item) {
        node->size--;
        node->left = remove_bstnode(key, node->left);
    }
    else if (key > node->item) {
        node->size--;
        node->right = remove_bstnode(key, node->right);
    } 
    else if (node->left == NULL) {
      struct bstnode *backup = node->right;
      free(node);
      return backup;
    } 
    else if (node->right == NULL) {
      struct bstnode *backup = node->left;
      free(node);
      return backup;
    } 
    else {
      struct bstnode *next = node->right;
      while (next->left) {
        next = next->left;
    }
// replace the key/value of this node
    node->item = next->item;
    node->size--;
// remove the next largest key
    node->right = remove_bstnode(next->item, node->right);
    }
    return node;
  }

void bst_remove (int i, Bst t) {
    assert(t);
    assert(bst_find(i, t));
    t->root = remove_bstnode(i, t->root);
}

static int bstnode_range(int start,int end, struct bstnode *node){
    if (node == NULL) return 0;
    if (node->item<start){
        return bstnode_range(start, end, node->right);
    }
    if (node->item>end){
        return bstnode_range(start, end, node->left);
    }
    return 1 + bstnode_range(start, end, node->left) + bstnode_range(start, end, node->right);

}

int bst_range(int start, int end, Bst t) {
    assert(t);
    return bstnode_range(start, end, t->root);
}

static void bstnode_preorder_list(struct bstnode *node, int *index, int *arr){
    if (node == NULL) return;
    arr[*index] = node->item;
    *index += 1;
    bstnode_preorder_list(node->left, index, arr);
    bstnode_preorder_list(node->right, index, arr);
}

static void bstnode_inorder_list(struct bstnode *node, int *index, int *arr){
    if (node == NULL) return;
    bstnode_inorder_list(node->left, index, arr);
    arr[*index] = node->item;
    *index += 1;
    bstnode_inorder_list(node->right, index, arr);
}

static void bstnode_postorder_list(struct bstnode *node, int *index, int *arr){
    if (node == NULL) return;
    bstnode_postorder_list(node->left, index, arr);
    bstnode_postorder_list(node->right, index, arr);
    arr[*index] = node->item;
    *index += 1;
}

void bst_print (int o, Bst t) {
    assert(t);
    if(t->root == NULL){
      printf("[]\n");
      return;
    }
    int *arr = malloc(t->root->size * sizeof(int));
    int len = t->root->size;
    int index = 0;
    int *p = &index;
    assert(o == PRE_ORDER||o == IN_ORDER||o == POST_ORDER);
    if (o == PRE_ORDER)
        bstnode_preorder_list(t->root, p, arr);
    else if (o == IN_ORDER)
        bstnode_inorder_list(t->root, p, arr);
    else
        bstnode_postorder_list(t->root, p, arr);
    printf("[");
    for (int i = 0; i < len; ++i)
    {
      if (i)
        printf(",");
      printf("%d", arr[i]);
    }
    printf("]\n");
    free(arr);
}

int *bst_to_sorted_array(Bst t) {
    assert(t);
    int *arr = malloc(t->root->size * sizeof(int));
    int index = 0;
    int *p = &index;
    bstnode_inorder_list(t->root, p, arr);
    return arr;
}

static struct bstnode *create_node(int i, int size){
    struct bstnode *new = malloc(sizeof(struct bstnode));
    new->item = i;
    new->size = size;
    new->left = NULL;
    new->right = NULL;
    return new;
}

static struct bstnode *sorted_array_to_bstnode(int *arr, int start, int end){
    if (start > end) return NULL;
    int middle =  (start + end)/2;
    int size;
    if ((start + end) % 2 == 0)
        size = end - start + 1;
    else
        size = end - start;
    struct bstnode *new = create_node(arr[middle], size);
    new->left = sorted_array_to_bstnode(arr, start, middle-1);
    new->right = sorted_array_to_bstnode(arr, middle+1, end);
    return new;
}

Bst sorted_array_to_bst(int *arr, int len) {
    struct bst *root = bst_create();
    root->root = sorted_array_to_bstnode(arr, 0, len-1);
    return root;
}

