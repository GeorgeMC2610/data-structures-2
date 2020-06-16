#include <iostream>
using namespace std;

class BinaryTreeNode        
{ 
    ///////////////////////FOR TREE
    public:
        BinaryTreeNode()
        {
            LeftChild = RightChild = 0;
        }

        BinaryTreeNode(const int& e)
        {
            data = e;
            LeftChild = RightChild = 0;
        }

        BinaryTreeNode(const int& e, BinaryTreeNode *l, BinaryTreeNode *r)
        {
            data = e;
            LeftChild = l;
            RightChild = r;
        }


    ////////////////////////////////////////////////METHODS

    static void Preorder_Output(BinaryTreeNode *r){
        if(r)
        {
            cout << r -> data << " ";
            Preorder_Output(r -> LeftChild);
            Preorder_Output(r -> RightChild);
        }
    }

    static void Findmaxkey(BinaryTreeNode *tr)
    {  
        //Find max key element of tree
        if (tr)
        {
            BinaryTreeNode *p = tr;
            int maxkey = p -> data;
            tr -> Maxkey = p;
            p = p -> RightChild;
        
            while(p)
            {
                if (p -> data > maxkey)
                {
                    maxkey = p -> data;
                    tr -> Maxkey = p;
                }
                
                p = p -> RightChild;
            }
        }
    }

    static int Returnmaxkey(BinaryTreeNode *tr)
    {
        if (tr)
        {
            return tr -> Maxkey -> data;
        }

        else
        {
            cout << "The tree is NULL" << endl;
        }
    }

    private:

        int data;
        BinaryTreeNode *Maxkey, *LeftChild, *RightChild; //pointer to max element, left subtree and right subtree

};


int main()
{
                        //  Left subtree of root
    
    //Leafs 
    BinaryTreeNode nd27 (27), nd12 (12), nd22 (22), nd20 (20);
    
    //Rest nodes
    BinaryTreeNode nd10 (10,&nd12,0); 
    BinaryTreeNode nd13 (13,0,&nd22); 
    BinaryTreeNode nd26 (26,&nd13,&nd27);
    BinaryTreeNode nd39 (39,&nd10,&nd20);
    BinaryTreeNode nd41 (41,&nd39,&nd26); 
                                            
     
     
     
     
     
                        //  Right subtree of root
                        
    //Leafs
    BinaryTreeNode nd35 (35), nd9 (9), nd52 (52), nd40 (40), nd90 (90), nd87 (87);
    
    //Rest nodes
    BinaryTreeNode nd2 (2,&nd35,&nd9);
    BinaryTreeNode nd44 (44,&nd40,0);  
    BinaryTreeNode nd61 (61,&nd2,&nd44);
    
    BinaryTreeNode nd101 (101,&nd90,&nd87);  
    BinaryTreeNode nd59 (59,&nd52,&nd101);
    BinaryTreeNode nd67 (67,&nd61,&nd59); 
    
                        
                        
                        
                        
                        // Root
     
    BinaryTreeNode rt50 (50,&nd41,&nd67); 
    BinaryTreeNode *root = &rt50; //Pointer to root. 
    BinaryTreeNode *tree = root;  //Now root is our tree because its the node that contains the rest nodes.
//###################################################################################    
    
    
    BinaryTreeNode::Preorder_Output(tree);
    BinaryTreeNode::Findmaxkey(tree);
    cout<<endl<<BinaryTreeNode::Returnmaxkey(tree);                        
}