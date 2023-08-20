// gfg  Inorder Successor in BST

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        Node* succ = NULL;
        Node* temp = root;
        while(temp->data!=x->data){
            if(temp->data>x->data){
                succ = temp;
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }
        }
        Node* tree = temp->right;
        while(tree){
            succ = tree;
            tree = tree->left;
        }
        return succ;
    }
};
