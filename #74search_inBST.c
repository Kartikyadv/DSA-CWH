#include<stdio.h>
#include<malloc.h>
struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node* createNode(int data){
    struct node *n;// creating the node pointer
    n = (struct node *) malloc(sizeof(struct node)); // allocating memory in the heap
    n->data = data;// setting the data
    n->left = NULL;// setting the left and right and left children to NULL
    n->right = NULL;// setting the left and right and left children to NULL
    return n;// returning the created node
    }
    void preOrder(struct node* root){
        if(root!=NULL){
            printf("%4d", root->data);
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    void inOrder(struct node* root){
        if(root!=NULL){
            inOrder(root->left);
            printf("%4d", root->data);
            inOrder(root->right);
        }
    }
    int isBST(struct node* root){
        static struct node *prev = NULL;
        if(root!=NULL){
           if(!isBST(root->left)){//checking left subtree is bst
               return 0;    // 0 indicates failure of left subtree
           }
        if (prev!=NULL && root->data <= prev->data){// for 1st time prev = null so it will not return 0 then prev == root
           return 0;// 0 will indicate not a bst
        }
        prev = root;
        return isBST(root->right);
        }
        else{
            return 1;// 1 will indicate bst
        }
    }
   void postOrder(struct node* root){
        if(root!=NULL){
            postOrder(root->left);
            postOrder(root->right);
            printf("%4d", root->data);
        }
    }

    struct node * search(struct node*root, int key){
        if(root==NULL){
            return NULL;
        }
        if(key==root->data){
            return root;
        }
        else if(key<root->data){
            return search(root->left, key);
        }
        else{
            return search(root->right, key);
        }
    }
int main(){
    // constructing the root node using function (recommended)
    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);
    //Finally the tree looks like this:
    /*      5
           / \
          3   6
         / \
        1   4
    */
    //linking the root node with left and right children
    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    struct node* n = search(p, 1);
    if(n!=NULL){
    printf("found : %d\n", n->data);
    }
    else{
        printf("element not found\n");
    }
    
    return 0;
}