#ifndef HYPERTREE_H
#define HYPERTREE_H

template <typename Comparable>
class HyperTree { 
    private:
        struct HB_Node
        {
            Comparable element;
            HB_Node *left;
            HB_Node *right;
            int height;
            int lsize;
            int rsize;
            
            HB_Node( const Comparable & theElement, HB_Node *lt, HB_Node *rt,
                int h = 0, int ls = 0, int rs = 0 ) : element( theElement ), left( lt ), right( rt ),
                    height ( h ), lsize( ls ), rsize( rs ) { }
        };
        HB_Node *root;
        
    public:
        
        // Helper function to insert a node into the hypertree
        void insert(const Comparable & x) {
                
            HB_Node *inode = new HB_Node(x, NULL, NULL);
            insert(inode, root);
        }
        
        void insert( HB_Node * & x, HB_Node * & t ) {
        
            if( t == NULL )
                t = x; 
            else if( x->element < t->element ) {
                t->lsize++;//not following yeah 
                insert( x, t->left );
            }
            else if( t->element <= x->element ) {
                t->rsize++;
                insert( x, t->right );
            }
            
            if(t->lsize == t->rsize + 2 || t->lsize == t->rsize - 2) {
                rebalance(t); 
            }
            return;
        }
        
        void rebalance( HB_Node* &t) {
            
            if(t->lsize == (t->rsize + 2) ) {
                
                HB_Node* z = removeMax(t->left); 
                HB_Node* temp = t;
                t->element = z->element;
                z->element = temp->element; //Swap the elements of the root and the node to be rearranged
                
                insert(z, t);
                
                t->lsize--;
                return;
            }
            
            if(t->lsize == (t->rsize - 2) ) {
                
                HB_Node* z = removeMin(t->right);
                HB_Node* temp = t;
                t->element = z->element;
                z->element = temp->element; //Swap the elements of the root and the node to be rearranged
                
                insert(z, t);
                
                t->rsize--;
                return;
            }
        }
        
        HB_Node * removeMax( HB_Node * & t ) {
            
            if( t == NULL )
                return NULL;   // Item not found; do nothing
            
            if(t->right == nullptr) {
                HB_Node* temp = t;
                root -> left = t-> left;
                t->rsize--;
                return temp;
            }
            else if( t->right->right == nullptr) {
                HB_Node temp = t -> right;
                t ->right = nullptr;
                t->rsize--;
                return temp;
            }
            else {
                t->rsize--;
                removeMax(t->right);
            }
            
            if(t->lsize == t->rsize + 2 || t->lsize == t->rsize - 2) {
                rebalance(t); 
            }
            
            return; 
        }
            
        HB_Node * removeMin( HB_Node * & t ) {
            
            if( t == NULL )
                return;   // Item not found; do nothing
            
            if( t->left == nullptr) {
                HB_Node* temp = t;
                root -> right = t-> right;
                t->lsize--;
                return temp;
            }    
            else if( t->left->left == nullptr) {
                HB_Node* temp = t -> left;
                t ->left = nullptr;
                t->lsize--;
                return temp;
            }
            else {
                t->lsize--;
                removeMax(t->left);   
            }
            
            if(t->lsize == t->rsize + 2 || t->lsize == t->rsize - 2) {
                rebalance(t); 
            }
        }
        
         /**
         * My implemented function. Used to print out the tree 
         */
         
        void prettyPrint() {
            
            string p2 = "  ";
            string p3 = " <";
            prettyPrint(root, p2, p3);
        }
        
        void prettyPrint(HB_Node *t, string linePrefix, string nodeTag) {
            
            if(t == NULL)//was nullptr
                return;
            
            if(t == root) {
                nodeTag = " <";
                prettyPrint(t->right, linePrefix + "  ", " /");
                outfile << linePrefix << nodeTag << t->element << endl;
                prettyPrint(t->left, linePrefix + "  ", " \\");
            }
            else if(nodeTag == " /") {
                prettyPrint(t->right, linePrefix + "  ", " /");
                outfile << linePrefix << nodeTag << t->element << endl;
                prettyPrint(t->left, linePrefix + "| ", " \\");
            }
            else if(nodeTag == " \\") {
                prettyPrint(t->right, linePrefix + "| ", " /");
                outfile << linePrefix << nodeTag << t->element << endl;
                prettyPrint(t->left, linePrefix + "  ", " \\");
            }
            
            return;
        }
};

#endif