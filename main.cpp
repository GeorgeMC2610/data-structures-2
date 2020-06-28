#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

int _count; //global variable to count insertions

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

    static void Preorder_Output(BinaryTreeNode *tr)
    {   //OUTPUT
        if(tr)
        {
            cout << tr -> data << " ";
            Preorder_Output(tr -> LeftChild);
            Preorder_Output(tr -> RightChild);
        }
    } 


    static void Inorder_Output(BinaryTreeNode *tr)
    {   //OUTPUT
        if(tr)
        {
            Inorder_Output(tr -> LeftChild);
            cout << tr -> data << " ";
            Inorder_Output(tr -> RightChild);
        }
    }

    static void Postorder_Output(BinaryTreeNode *tr)
    {   //OUTPUT
        if(tr)
        {
            Postorder_Output(tr -> LeftChild);
            Postorder_Output(tr -> RightChild);
            cout << tr -> data << " ";
        }
    }

    //FIND AND RETURN MAX KEY 
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
            return 0;
        }
    }
    
  
  
  
    //TREE HEIGHT
      
    static int Subtreeheight(BinaryTreeNode *str) { //Get the height of a subtree 

        if (!str) //if subtree is null
        {
            return 0;
        }           
        int hltr = Subtreeheight(str->LeftChild); // height of left subtree
        int hrtr = Subtreeheight(str->RightChild); // height of right subtree
        if (hltr > hrtr)
        {
            return ++hltr;   
        } 
        else {
            return ++hrtr;
        }
    }
    
    //CHECK FOR DUPLICATE VALUES
    
    static bool Preorder_Search(BinaryTreeNode *tr,int k)
    {  
        if(tr)
        {
            if (tr->data == k)
            {
                return true; 
            }
            return Preorder_Search(tr -> LeftChild, k);
            return Preorder_Search(tr -> RightChild, k);
        }
        
		return false;	
        	 
    }
    
    static bool Searchsamekey(BinaryTreeNode *tr, int k){ 
        //Search if given key element already exists in tree
        if(tr)
        {   
            if (tr->data == k){
                return true; 
            }
            else if (k > tr->data)
            {
                
                return Searchsamekey(tr->RightChild, k);
                
            }
            else if(Preorder_Search(tr,k)){
                      
            	return true; 
                
            }
        }
        
        return false; 
    }

    // GET BALANCE FACTOR OF NODE nd 
    
    static int Ndbalance(BinaryTreeNode *nd)  
    {  
        
        if (nd == 0){
            return 0;
        }else{
            return (Subtreeheight(nd->LeftChild) - Subtreeheight(nd->RightChild)); 
        } 
        
    }
    
    //ROTATION METHODS
      
    static void Rightrotation(BinaryTreeNode *a, BinaryTreeNode * & r , BinaryTreeNode *pal, BinaryTreeNode *par)  
    {  
        BinaryTreeNode *b = a->LeftChild;  
        BinaryTreeNode *bR = b->RightChild;  
  
        // Perform rotation  
        b->RightChild = a;  
        a->LeftChild = bR;
        
        if(par){
            par->RightChild = b;
        }else if(pal){
            pal->LeftChild = b;
        }else if (r){
        	r = b;
		}
    }
    
    static void LeftrotationI(BinaryTreeNode *a, BinaryTreeNode * & r, BinaryTreeNode *pal, BinaryTreeNode *par)  
    {   
        BinaryTreeNode *b = a->RightChild;  
        BinaryTreeNode *bL = b->LeftChild;      

        // Perform rotation  
        b->LeftChild = a;
        a->RightChild = bL;
		              
        if(par){
            par->RightChild = b;
        }else if(pal){
            pal->LeftChild = b;
        }else if(r){
        	r = b;	
		}  
    }

    static void LeftrotationII(BinaryTreeNode *a, BinaryTreeNode *pal, BinaryTreeNode *par)  
    {     
        BinaryTreeNode *b = a->RightChild;  
        BinaryTreeNode *aL = a->LeftChild;
		BinaryTreeNode *c = a->RightChild->RightChild;  
  
        // Perform rotation  
        b->RightChild = aL;  
        a->LeftChild = b;
		a->RightChild = c; 
         
        if(par){
            par->RightChild = a;
        }else if(pal){
            pal->LeftChild = a;
        }                 
    }

    static BinaryTreeNode* DeleteMaximum(BinaryTreeNode *tr, int k)
    {
        if (tr == NULL)
            return tr;
        //since we want to delete the maximum key we always lie in the right subtree
        if (k > tr -> data)
    }
    
    static BinaryTreeNode* Insert(BinaryTreeNode *tr,int k) //INSERT FUNCTION
    {
        //INSERTING A NEW KEY ON THE TREE.FOR EVERY INSERTION OF KEYS THAT ARE SMALLER THAN THEIR ROOT, THERE IS 
		//A 50% CHANCE TO DECIDE TO PROCEED FROM THE LEFT AND A 50% CHANCE TO DECIDE TO PROCEED FROM THE RIGHT.

        const int theseis = _count + 1;

		int random;
        int randoms[_count];
        
        bool b = Searchsamekey(tr,k);
        if(b)
        {
        	cout<<"Given element already exists";
            return tr;
		}
        
        
        BinaryTreeNode *a = 0;
        BinaryTreeNode *par = 0;
        BinaryTreeNode *pal = 0;
        
        for(int i=1; i<=2; i++)
        {
          
            BinaryTreeNode *p = tr;
            BinaryTreeNode *pp = 0;
            
            if(Ndbalance(p)>1 || Ndbalance(p)<-1){
                a = tr;
        }
        
        int position = 0;
        while(p)
        {

            pp = p;
            
            if (Ndbalance(p->RightChild) > 1 || Ndbalance(p->RightChild) < -1) 
            {
                par = p;
                
            }else if (Ndbalance(p->LeftChild) > 1 || Ndbalance(p->LeftChild) < -1)
            {
                
                pal = p;
               
            }

            if (i==1)
            {
                random = (rand() % 2);
                randoms[position] = random;
            }         
            

            if (k>p->data || (k<p->data && randoms[position] == 1))
			{  								
				p = p->RightChild;						               
            }else
            {
                p = p->LeftChild;  
            } 
            
            if(Ndbalance(p)>1 || Ndbalance(p)<-1){
                a = p;
            }

            position++;
        }
        
        if(i==1)
        {
            BinaryTreeNode *newnode = new BinaryTreeNode (k);
        	
            if (!tr)
            {
            	_count++;
                tr = newnode;
                
                Findmaxkey(tr);
                return tr;
            }
        
            if(k>pp->data || (k<pp->data && randoms[position] == 1))
            {
                pp->RightChild = newnode;
                cout<<"The new element has been inserted as right child of "<<pp->data<<endl;
            
            }
            else
            {
                pp->LeftChild = newnode;
                cout<<"The new element has been inserted as left child of "<<pp->data<<endl; 
            }
        }
        }
    
    
        
        //REBALANCING TREE
      
       
        int a_balance = Ndbalance(a); 
        
        // Left Left Case

        if (a_balance > 1 && k < a->LeftChild->data)   
        {
        	
            Rightrotation(a,tr,pal,par);
            
            Findmaxkey(tr);
            return tr;
            
        }
        
        // Right Left Case I (We need to check if the new node is in the left subtree of the right subtree of a,
        //in order to not match this case with RRII case)
        
        else if (a_balance < -1 && k < a->RightChild->data && a->data < k && Preorder_Search(a->RightChild->LeftChild, k))   
        {  
             
            Rightrotation(a->RightChild,a->RightChild,0,0);
            LeftrotationI(a,tr,pal,par);
            
            Findmaxkey(tr);
			return tr;  
        } 
        
         // Right Left Case II  
        
       else if (a_balance < -1 && k < a->RightChild->data && a->data > k && Preorder_Search(a->RightChild->LeftChild, k) )      
        {  
            Rightrotation(a->RightChild,a->RightChild,0,0);
            
            BinaryTreeNode *temp = a->RightChild->RightChild;
            a->RightChild->RightChild = a->LeftChild;
            a->LeftChild = a->RightChild;
            a->RightChild = temp;
            
            if(par){
                par->RightChild = a;
            }else if(pal){
                pal->LeftChild = a;
			}
			
			Findmaxkey(tr);
			return tr;
			
        } 
  
        // Right Right Case I
        
        else if (a_balance < -1 && a->data < a->RightChild->data)
        {		
             LeftrotationI(a,tr,pal,par);

             Findmaxkey(tr);
			 return tr; 
        }

        // Right Right Case II
        
        else if (a_balance < -1 && a->data > a->RightChild->data){
        	LeftrotationII(a,pal,par); 
        	
        	Findmaxkey(tr);
        	return tr;
        	
		}               

        // Left Right Case I
        
       else if (a_balance > 1 && k > a->LeftChild->data)  
        {  
            
            LeftrotationI(a->LeftChild,a->LeftChild,0,0);  
            Rightrotation(a,tr,pal,par); 
            
            Findmaxkey(tr);
			return tr; 
			
        }  
  
        // Left Right Case II 
        
        else if (a_balance > 1 && k < a->LeftChild->data)  
        {  
            
            BinaryTreeNode *temp = a->LeftChild->LeftChild;
            a->LeftChild->LeftChild = a->LeftChild->RightChild;
            a->LeftChild->RightChild = temp;
            
            Rightrotation(a,tr,pal,par);  
            
            Findmaxkey(tr);
            return tr;
        } 
  
  
        else {
        	
        	Findmaxkey(tr);
        	return tr; 
        	
        }	
	}
     



    private:
        int data; //Node data
        BinaryTreeNode *Maxkey, *LeftChild, *RightChild; //pointer to max element, left subtree and right subtree

};

int main()
{ 
	srand(time(NULL));
    //AVL TREE CREATION
                    
                    
                    
    /* //  Left subtree of root
    
    //Leafs 
    BinaryTreeNode nd27 (27), nd8 (8), nd22 (22), nd20 (20);
    
    //Rest nodes
    BinaryTreeNode nd10 (10,&nd8,0); 
    BinaryTreeNode nd13 (13,0,&nd22); 
    BinaryTreeNode nd26 (26,&nd13,&nd27);
    BinaryTreeNode nd39 (39,&nd10,&nd20);
    BinaryTreeNode nd41 (41,&nd39,&nd26); 
                                            
    //  Right subtree of root
                        
    //Leafs
    BinaryTreeNode nd43 (43), nd9 (9), nd52 (52), nd40 (40), nd90 (90), nd87 (87);
    
    //Rest nodes
    BinaryTreeNode nd56 (56,&nd43,&nd9);
    BinaryTreeNode nd44 (44,&nd40,0);  
    BinaryTreeNode nd61 (61,&nd56,&nd44);
    BinaryTreeNode nd101 (101,&nd90,&nd87);  
    BinaryTreeNode nd59 (59,&nd52,&nd101);
    BinaryTreeNode nd67 (67,&nd61,&nd59); 

    // Root
     
    BinaryTreeNode rt50 (50,&nd41,&nd67); 
    BinaryTreeNode *root = &rt50; //Pointer to root. 
    //Now root is our tree because its the node that contains the rest nodes.
    BinaryTreeNode *tree = root;
    //############################### */

    BinaryTreeNode *tree = 0;
   
    tree = BinaryTreeNode::Insert(tree, 80);
    tree = BinaryTreeNode::Insert(tree, 70);
	tree = BinaryTreeNode::Insert(tree, 86);
	tree = BinaryTreeNode::Insert(tree, 345);
	tree = BinaryTreeNode::Insert(tree, 72);
	tree = BinaryTreeNode::Insert(tree, 40);
	  	
    int action;
    do 
    {
        //showing the menu of actions
        cout << "\n--- ACTIONS MENU ---"            << endl << endl;
        cout << "1. Insert a value"                         << endl;
        cout << "2. Return the maximum value in the tree"   << endl;
        cout << "3. Delete the Maximum value in the tree"   << endl;
        cout << "4. Exit the menu"                  << endl << endl;

        //after we show the user the menu of actions, we show the tree in preorder, inorder and postorder output
        if (tree)
        {
            cout << "Preorder: ";
            BinaryTreeNode::Preorder_Output(tree);

            cout << endl << "Inorder: ";
            BinaryTreeNode::Inorder_Output(tree);

            cout << endl << "Postorder: ";
            BinaryTreeNode::Postorder_Output(tree);
        }
        else
        {
            cout << "The tree is currently empty. Select 'insert' to add values" << endl;
        }

        cout << endl << endl;

        //after that, the user chooses his action
        do
        {
            cout << "ENTER A NUMBER FOR AN ACTION: ";
            cin >> action;
        } while (action > 4 || action < 1);


        switch (action)
        {
            case 1:
                int number;
                cout << "Enter the number you want to insert: ";
                cin >> number;

                tree = BinaryTreeNode::Insert(tree, number);
                system("pause");
                break;
            
            case 2:
                cout << "The maximum value of the tree is: " << BinaryTreeNode::Returnmaxkey(tree) << endl;
                system("pause");
                break;

            case 3:
                
                break;
        }
    } while (action != 4);
    
    return 0;
}