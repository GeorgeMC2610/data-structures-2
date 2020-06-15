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
            BinaryTreeNode *pp = p;
            p = p -> RightChild;
        
            while(p)
            {
                pp = p;
                if (p -> data > maxkey)
                {
                    maxkey = p -> data;
                }
                p = p -> RightChild;
            }

        tr -> Maxkey = pp;
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
    BinaryTreeNode nd39 (39), nd12 (12), nd22 (22);
    
    //Rest nodes
    BinaryTreeNode nd10 (10,0,&nd12);
    BinaryTreeNode nd13 (13,&nd10,&nd22); 
    BinaryTreeNode nd26 (26,&nd13,0);  
    BinaryTreeNode nd41 (41,&nd39,&nd26);
     
     
     
     
     
                        //  Right subtree of root
                        
    //Leafs
    BinaryTreeNode nd35 (35), nd9 (9), nd52 (52), nd85 (85), nd87 (87);
    
    //Rest nodes
    BinaryTreeNode nd2 (2,0,&nd9);
    BinaryTreeNode nd40 (40,&nd35,&nd2); 
    BinaryTreeNode nd44 (44,&nd40,0);  
    BinaryTreeNode nd61 (61,&nd44,0);
    
    BinaryTreeNode nd90 (90,&nd85,&nd87); 
    BinaryTreeNode nd101 (101,&nd90,0);  
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
