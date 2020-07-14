#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int _count; //global variable to count insertions

class BinaryTreeNode        
{
                                            //PUBLIC CLASS MEMBERS 

 
    ///////////////////////////////////////////CONSTRUCTORS FOR TREE//////////////////////////////////////////////////
    
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



    ////////////////////////////////////////////////METHODS//////////////////////////////////////////////////////////

    
    
    static void Preorder_Output(BinaryTreeNode *tr)
    {   //PREORDER OUTPUT OF ELEMENTS  
        if(tr)
        {
            cout << tr -> data << " ";
            Preorder_Output(tr -> LeftChild);
            Preorder_Output(tr -> RightChild);
        }
    } 


    static void Inorder_Output(BinaryTreeNode *tr)
    {   //INORDER OUTPUT OF ELEMENTS
        if(tr)
        {
            Inorder_Output(tr -> LeftChild);
            cout << tr -> data << " ";
            Inorder_Output(tr -> RightChild);
        }
    }

    static void Postorder_Output(BinaryTreeNode *tr)
    {   //POSTORDER OUTPUT OF ELEMENTS
        if(tr)
        {
            Postorder_Output(tr -> LeftChild);
            Postorder_Output(tr -> RightChild);
            cout << tr -> data << " ";
        }
    }

    //FIND MAX KEY
    
    static void Findmaxkey(BinaryTreeNode *tr) 
    {  
        //Find max key element of tree
        if (tr)
        {
            //we create a dummy node-pointer same as the starting one (root), and we set the maximum value as the root value
            BinaryTreeNode *p = tr;
            int maxkey = p -> data;
            tr -> Maxkey = p;

            //then we lie onto the root's right subtree (since the left subtrees only have values less than the root)
            p = p -> RightChild;
        
            //and while p is not null
            while(p)
            {
                //we check to see if there's any value bigger than the previous one
                if (p -> data > maxkey)
                {
                    //and if there is, we update the maximum element
                    maxkey = p -> data;
                    tr -> Maxkey = p;
                }
                
                //then we continue to check for all the right subtrees
                p = p -> RightChild;
            }
        }
    }

    
    

    //TREE HEIGHT
    static int Subtreeheight(BinaryTreeNode *str)  //Get the height of a subtree
    {  

        if (!str)       //if subtree is null
            return 0;

        int hltr = Subtreeheight(str->LeftChild);  // height of left subtree
        int hrtr = Subtreeheight(str->RightChild); // height of right subtree

        if (hltr > hrtr) //we return the max height of left and right subtree plus 1 (because we have to add the root's hight also)
        {
            return ++hltr;   
        } 
        else
        {
            return ++hrtr;
        }
    }
    
    //CHECK FOR DUPLICATE VALUES
    
    static bool Preorder_Search(BinaryTreeNode *tr, int k)
    {  
        //recursive function to search for values in preorder
        if(tr)
        {
            if (tr->data == k)
                return true; 
            
            if (Preorder_Search(tr -> LeftChild, k)) //If left subtree has the element k return true
            	return true;
            	
            if(Preorder_Search(tr -> RightChild, k)) //If right subtree has the element k return true
            	return true;
        }
        
		return false;  //If element k is not in the tree return false	 
    }
    
    static bool Searchsamekey(BinaryTreeNode *tr, int k)
    { 
        //Search if given key element already exists in tree
        if(tr)
        {   
            //if the value of the node is the same, then we have a duplicate 
            if (tr->data == k)
            {
                return true; 
            }

            //if the key is greater than the current node, then we lie on the right subtree
            else if (k > tr->data)
            {
                return Searchsamekey(tr->RightChild, k);
            }

            //else, it means that the key could be anywhere else, so we search for it in the whole subtree using preorder search
            else if(Preorder_Search(tr,k))
            {
            	return true; 
            }
        }
        
        //otherwise, there are no duplicates
        return false; 
    }

    // GET BALANCE FACTOR OF NODE nd 
    
    static int Ndbalance(BinaryTreeNode *nd)  
    {  
        //if there is no node, then there is no balance
        if (nd == 0)
        {
            return 0;
        }

        //otherwise we return the balance, which is the left children height subtracted with the right children height.
        else
        {
            return (Subtreeheight(nd->LeftChild) - Subtreeheight(nd->RightChild)); 
        } 
        
    }
    
    
    
    
    
    
    //ROTATION METHODS FOR INSERT FUNCTION
    
    //Since Insert() uses 4 different pointers, we must create rotation functions that include those 4 pointers as parameters (or just 3 in 3rd case).
    
    //These functions are taking as parameters: //1// pointer a, the root of the tree to be rotated. //2// pointer pal, pointer to parent of a, if a is leftchild
    //3//pointer par, pointer to parent of a, if a is rightchild
    
    //The rotation methods that are probably going to change the tree's root, are taking the root pointer as a parameter by reference in order for given "r" to point
    //to the correct root after the rotation
    
    //In case where a has parents, we have to change pal's LeftChild or par's RightChild after the rotation, in order for them to have the new root as child
      
    static void Rightrotation(BinaryTreeNode *a, BinaryTreeNode * & r , BinaryTreeNode *pal, BinaryTreeNode *par)  //For LL,LRI,LRII, and RLI,RLII cases
    {  
        BinaryTreeNode *b = a->LeftChild;  
        BinaryTreeNode *bR = b->RightChild;  
  
        // Perform rotation  
        b->RightChild = a;  
        a->LeftChild = bR;
        
        if(par)
        {
            par->RightChild = b;
        }
        else if(pal)
        {
            pal->LeftChild = b;
        }
        else if (r)
        {
        	r = b;
		}
    }
    
    static void LeftrotationI(BinaryTreeNode *a, BinaryTreeNode *&r, BinaryTreeNode *pal, BinaryTreeNode *par) //FOR RRI,RLI,LRI 
    {   
        BinaryTreeNode *b  = a->RightChild;  
        BinaryTreeNode *bL = b->LeftChild;      

        // Perform rotation  
        b->LeftChild  = a;
        a->RightChild = bL;
		              
        if(par)
        {
            par->RightChild = b;
        }
        else if(pal)
        {
            pal->LeftChild = b;
        }
        else if(r)
        {
        	r = b;	
		}  
    }

    static void LeftrotationII(BinaryTreeNode *a, BinaryTreeNode *pal, BinaryTreeNode *par) //FOR RRII,RLII,LRII  
    {     
        BinaryTreeNode *b  = a->RightChild;  
        BinaryTreeNode *aL = a->LeftChild;
		BinaryTreeNode *c  = a->RightChild->RightChild;  
  
        // Perform rotation  
        b->RightChild = aL;  
        a->LeftChild  = b;
		a->RightChild = c; 
         
        if(par)
        {
            par->RightChild = a;
        }
        else if(pal)
        {
            pal->LeftChild = a;
        }                 
    }
    
    
    
    
    
    
    //ROTATION METHODS FOR DELETE FUNCTION
    //These functions are working different from insert functions. They take only as a parameter the root of the tree that has to be rebalanced. They return the new root
    
    static BinaryTreeNode* Rightrotation(BinaryTreeNode *tr) //For LL,LRI,LRII, and RLI,RLII cases
    {
        BinaryTreeNode *b  = tr->LeftChild;  
        BinaryTreeNode *bR = b->RightChild;  
  
        // Perform rotation  
        b->RightChild = tr;  
        tr->LeftChild = bR;

        return b;
    }

    static BinaryTreeNode* LeftRotationI(BinaryTreeNode *tr) //FOR RRI,RLI,LRI
    {
        BinaryTreeNode *b  = tr -> RightChild;
        BinaryTreeNode *bL = b  -> LeftChild;

        b  -> LeftChild  = tr;
        tr -> RightChild = bL;

        return b;
    }
    
    static BinaryTreeNode* LeftRotationII(BinaryTreeNode *tr) //FOR RRII,RLII,LRII 
    {
        BinaryTreeNode *b   = tr -> RightChild;
        BinaryTreeNode *trL = tr -> LeftChild;
        BinaryTreeNode *c   = tr -> RightChild -> RightChild;  
  
        // Perform rotation  
        b  -> RightChild = trL;  
        tr -> LeftChild  = b;
		tr -> RightChild = c; 

        return tr;
    }








                //RETURN MAX KEY OF TREE  



    //This function just returns the max element (O(1)).
    //It returns the data of Maxkey pointer-object of root.
    //The Findmaxkey method above, is responsible for setting 
    //the pointer Maxkey to point to the node that has the max element.
    
    static int Returnmaxkey(BinaryTreeNode *tr)
    {
        //Showing the max key element in O(1)
            return tr -> Maxkey -> data;          
    }
    




                //DELETE FUNCTION
                        
                        
                        


    static BinaryTreeNode* deleteNode(BinaryTreeNode* tr, int key)  
    
    //We are searching the key 'k' with the help of 'tr' pointer. 'k' is the maxkey of tree
    {   
        //We check to see if the current node's data is less than the key to be deleted
        //if it is, then the current node is not the one to be deleted.
        //Then we lie on the right subtrees of the root, by calling the function itself but this time with the right subtree.
        
        if(key > tr->data)  
            tr->RightChild = deleteNode(tr->RightChild, key);  
        
        //else, we know that this is the node to be deleted  
        else
        {  
            //one child or zero children case  
            if( (tr->LeftChild == NULL) || (tr->RightChild == NULL) )  
            {
                //we create a dummy node same as the left or right child node (whichever exsists)
                BinaryTreeNode *temp = tr->LeftChild ? tr->LeftChild : tr->RightChild;  
    
                //if temp is NULL then we know there are zero children, so this is the leaf to be deleted  
                if (temp == NULL)  
                {  
                    temp = tr;
                    tr = NULL;  
                }
                //else we alternate the two nodes, so the maximum key becomes a leaf, and then we delete the leaf.
                else  
                    *tr = *temp; 

                temp = NULL;
            }
            //else, we find the maximum key of the left subtree, so we can trade it's value with the current node (maximum key).
            //This proccess is being repeated until the maximum key becomes a leaf.
            else
            {   
                //we find the max key of the left subtree
                Findmaxkey(tr->LeftChild);
                int max_left = Returnmaxkey(tr->LeftChild);
 
                //we change the current node's data with the maximum left-child node's data
                int temp = tr->data;
                tr->data = max_left;
                tr->LeftChild->Maxkey->data = temp;

                //and we continue to do that, (now for the max key of left subtree that has the maximum tree value), until the maximum tree value becomes a leaf.
                tr->LeftChild = deleteNode(tr->LeftChild, temp);
            }  
        }  

        if (tr == NULL)
            return tr; //Recursive function returns null.That means tr->RightChild = null.
        
        
        
        
        //REBALANCING TREE
        
        
        
        
        //we get current node's balance, to rebalance it if necessary
        int balance = Ndbalance(tr);  
    
        //If this node becomes unbalanced, then there are 7 cases
        
        //In every case, we are doing the required rotation and then we are searching once again for the tree's max value.
        //Then, we return the subtree
        
        //functions of rotations are also being described above (see ROTATION METHODS FOR DELETE FUNCTION)
        
        
        
    
        // Left Left Case
        
        //This is the classic AVL LL case. Balance > 1 means that the problem has been made from the left. LeftChild's balance >=0
        //means that we have to make LL rotation
        
        if (balance > 1 && Ndbalance(tr->LeftChild) >= 0) 
        { 
        	cout<<"LL"<<endl;
            tr = Rightrotation(tr);
            Findmaxkey(tr);
            return tr;  
        }

        // Left Right Case I
        
        //This is the classic AVL LR case. Balance > 1 means that the problem has been made from the left. LeftChild's balance < 0 means that
        //he have to make a LR rotation.In this case: tr->LeftChild->data < tr->LeftChild->RightChild->data. So we can perform the classic left
        //rotation of tr->LeftChild tree. Then the right rotation of tr tree
        
        
        if (balance > 1 && Ndbalance(tr->LeftChild) < 0 && tr->LeftChild->data < tr->LeftChild->RightChild->data)  
        {  
        	cout<<"LR I "<<endl;
            tr->LeftChild = LeftRotationI(tr->LeftChild);  
            tr = Rightrotation(tr);
            Findmaxkey(tr);
            return tr;  
        }
        
        // Left Right Case II 
        
        //This is not the classic AVL LR case. Balance > 1 means that the problem has been made from the left. LeftChild's balance < 0 means that
        //he have to make a LR rotation.In this case: tr->LeftChild->data > tr->LeftChild->RightChild->data. So we cant perform the classic left
        //rotation of tr->LeftChild tree because we will have an illegal tree. So, the main concept of LRII is to bring tr->LeftChild->RightChild
        //node as left child of tr->LeftChild.
        
        if (balance > 1 && Ndbalance(tr->LeftChild) < 0 && tr->LeftChild->data > tr->LeftChild->RightChild->data)  
        {  
        	cout<<"LR II "<<endl;
            tr->LeftChild = LeftRotationII(tr->LeftChild);  
            tr = Rightrotation(tr);
            Findmaxkey(tr);
            return tr;  
        }
    
        // Right Right Case I
        
        //This is the classic AVL RR case. Balance < -1 means that the problem has been made from the right. RightChild's balance <= 0 means that
        //he have to make a RR rotation.In this case: tr->RightChild->data > tr->data. So we can perform the classic left
        //rotation of tr.
        
        if (balance < -1 && Ndbalance(tr->RightChild) <= 0 && tr->RightChild->data > tr->data)  
        {
        	cout<<"RR I "<<endl;
            tr = LeftRotationI(tr);
            Findmaxkey(tr);
            return tr;
        }
            
        // Right Right Case II
        
        //This is not the classic AVL RR case. Balance < -1 means that the problem has been made from the right. RightChild's balance <= 0 means that
        //he have to make a RR rotation.In this case: tr->RightChild->data < tr->data. So we cant perform the classic left
        //rotation because the tree is going to be illegal. So the main concept of RRII is to bring tr->RightChild node as tr->LeftChild.
        
        if (balance < -1 && Ndbalance(tr->RightChild) <= 0 && tr->RightChild->data < tr->data)  
        {
        	cout<<"RR II "<<endl;
            tr = LeftRotationII(tr);
            Findmaxkey(tr);
            return tr;
        }
    
        // Right Left Case I
        
        //This is the classic AVL RL case. Balance < -1 means that the problem has been made from the right. RightChild's balance > 0 means that
        //he have to make a RL rotation.In this case: tr->data < tr->RightChild->LeftChild->data . So we can perform the classic right
        //rotation of tr->RightChild and then the classic left rotation of tr.
        
        if (balance < -1 && Ndbalance(tr->RightChild) > 0 && tr->data < tr->RightChild->LeftChild->data)
        {  
        	cout<<"RL I "<<endl;
            tr->RightChild = Rightrotation(tr->RightChild);  
            tr = LeftRotationI(tr);
            Findmaxkey(tr);
            return tr;  
        }
        
        // Right Left Case II
        
        //This is not the classic AVL RL case. Balance < -1 means that the problem has been made from the right. RightChild's balance > 0 means that
        //he have to make a RL rotation.In this case: tr->data > tr->RightChild->LeftChild->data . So we can perform the classic right
        //rotation of tr->RightChild but not the classic left rotation of tr. Instead, the main concept for this left rotation is similiar to RRII case.
        
        if (balance < -1 && Ndbalance(tr->RightChild) > 0 && tr->data > tr->RightChild->LeftChild->data)
        {  
        	cout<<"RL II "<<endl;
            tr->RightChild = Rightrotation(tr->RightChild);  
            tr = LeftRotationII(tr);
            Findmaxkey(tr);
            return tr;  
        }

        //If rebalancing is not necessary, we update the maximum key element and we return the modified whole Right subtree of root.
        Findmaxkey(tr);
        return tr;  
    }
 
 
 
 
 
 
                    
                    
                //INSERT FUNCTION
                     
                     
                     
    
       
    static BinaryTreeNode* Insert(BinaryTreeNode *tr,int k)
    {
        //INSERTING A NEW KEY ON THE TREE WITH DATA k.FOR KEYS THAT ARE SMALLER THAN THEIR ROOT, THERE IS 
		//A 50% CHANCE FOR POINTER p TO DECIDE TO PROCEED FROM THE LEFT AND A 50% CHANCE TO DECIDE TO PROCEED FROM THE RIGHT.
		//THE DECISION IS BEING MADE FOR EACH THAT NODE WHILE DESCENTING


		int random;
        int randoms[_count]; //This data is being used in order to create a random number and store it in array randoms every 
                            //time p->data is bigger than k. We explain these in depth bellow 
        
        bool b = Searchsamekey(tr,k); //Checking for duplicate value
        if(b) //if k already in tree return root (tr is root)
        {
        	cout<<"Given element already exists"<<endl;
            return tr;
		}
        
        BinaryTreeNode *a = 0; //pointer to unbalanced node that has to be the root of the tree we are going to rebalance.
        //(a is the last unbalanced node we visit as we descenting)
        BinaryTreeNode *par = 0; //pointer to parent of a (par will be != 0 if a is right child of par)
        BinaryTreeNode *pal = 0; //pointer to parent of a (pal will be != 0 if a is left child of pal)
        
        //a will have par or pal for parent (not both) 
        
        for(int i=1; i<=2; i++) //We are executing this part two times. One for inserting node (1st descenting) and one to check if there is any unbalanced node
        //after insertion (2nd descenting). The 2nd descenting will follow the same path as 1st.
        {
            BinaryTreeNode *p = tr; //pointer p will begin from root at both descentings
            BinaryTreeNode *pp = 0; //pp is parent of p, at first it is 0
            
            if(Ndbalance(p)>1 || Ndbalance(p)<-1) //This will probably occur after insertion. If balance of p (at this point p is root) is >1 or <-1 that means
                a = tr;                           //root is unbalanced. So we set a = tr
                
        
            int position = 0; //this variable is being used to have access at "randoms" array elements
            
            while(p) //while p is not null
            {

                pp = p; //set pp equal to p
                
                if (Ndbalance(p->RightChild) > 1 || Ndbalance(p->RightChild) < -1) //Check if right child of p is unbalanced. If it is, par will be
                //this node, and pal will be null.
                {
                    par = p;
                    pal = 0;
                    
                }
                else if (Ndbalance(p->LeftChild) > 1 || Ndbalance(p->LeftChild) < -1)//Check if left child of p is unbalanced. If it is, pal will be
                //this node, and par will be null.
                {
                    
                    pal = p;
                    par = 0;
                }

                if (i==1) //For first descenting only (i=1), generate a random number (0 or 1) and store it to randoms array. This number corresponds to the
                //current node.
                {
                    random = (rand() % 2);
                    randoms[position] = random;
                }         
                

                if (k>p->data || (k<p->data && randoms[position] == 1)) //At first case, if k is greater than the current node data, 
                //we have to procced from the right. At second case, if k is less than current node and node's corresponding random number is 1,
                //we procced from the right again. At 2nd descenting, the corresponding random numbers for each node are already at "randoms" array so
                //for each node-step p is following the same path 
                
                {  								
                    p = p->RightChild;						               
                }
                else //Else, if k<p->data and the corresponding random value is 0 procced from the left
                {
                    p = p->LeftChild;  
                } 
                
                if(Ndbalance(p)>1 || Ndbalance(p)<-1) //if current node is unbalanced set a to that node
                    a = p;
                
                position++; //add one to position, in order to access the next "randoms" element
            }
            
            if(i==1) //For first descenting only, the insertion has to be made. While loop has been ended so p is null and pp is in the parent
            //of the future new node.
            {
                BinaryTreeNode *newnode = new BinaryTreeNode (k); //make new node with element k
                    
                if (!tr) //If there is no root, we have to make the new node our root 
                {
                    _count++; //Global variable count is being used to declare the "randoms" size in each insertion start. So we have to add one after inserting a new node
                    tr = newnode;  
                    
                    Findmaxkey(tr); //find maxkey at new tree
                    return tr; //return the root
                }
                
                position-=1; //We have to substract one from position before using it because after while loop, position is out of bounds
            
                if(k>pp->data || (k<pp->data && randoms[position] == 1)) //pp's node corresponding number (last number in "randoms") is telling us
                //from which side to insert the new node, if it is smaller than pp's node data
                {
                    pp->RightChild = newnode;
                    _count++;
                    cout<<"element "<<k<<" has been inserted as right child of "<<pp->data<<endl;
                
                }
                else
                {
                    pp->LeftChild = newnode;
                    _count++;
                    cout<<"element "<<k<<" has been inserted as left child of "<<pp->data<<endl; 
                }
            }
        }
    
    
    
    
        //REBALANCING TREE
        
        
      
        int a_balance = Ndbalance(a); //get balance of a
        
        //functions of rotations are being described above (see ROTATION METHODS FOR INSERT FUNCTION) Results of these rotation functions are the same as delete 
        //rotation functions, they just work differently.
        
        //a_balance < -1 means that we will have a case from the right
        
        //a_balance > 1 means that we will have a case from the left
        
        //in RL and LR cases we have to check with a Preorder_Search function if
        //the new node is at a->RightChild->LeftChild tree or a->LeftChild->RightChild tree
        //in order to not match these cases with other cases
        
        //After every rebalance we are searching the new max key of tree and we return the rebalanced tree (tr)
        
        
        
       
        // Right Left Case I
        
        if (a_balance < -1  && Preorder_Search(a->RightChild->LeftChild, k) && a->data < a->RightChild->LeftChild->data)   
        {  
        	cout<<"RL I "<<endl;
            Rightrotation(a->RightChild,a->RightChild,0,0);
            LeftrotationI(a,tr,pal,par);
            
            Findmaxkey(tr);
			return tr;
        } 
        
         // Right Left Case II  
        
        else if (a_balance < -1 && Preorder_Search(a->RightChild->LeftChild, k) && a->data > a->RightChild->LeftChild->data)      
        {
        	cout<<"RL II"<<endl;
		    Rightrotation(a->RightChild,a->RightChild,0,0);
            LeftrotationII(a,pal,par);
            
			Findmaxkey(tr);
			return tr;
        } 
  
        // Right Right Case I
        
         else if (a_balance < -1 && a->data < a->RightChild->data)
         {
		 	cout<<"RR I"<<endl;
            LeftrotationI(a,tr,pal,par);

            Findmaxkey(tr);
            return tr; 
        }

        // Right Right Case II
        
        else if (a_balance < -1 && a->data > a->RightChild->data)
        {	
        	cout<<"RR II"<<endl;
        	LeftrotationII(a,pal,par); 
        	
        	Findmaxkey(tr);
        	return tr;
		}               

        // Left Right Case I
        
        else if (a_balance > 1 && Preorder_Search(a->LeftChild->RightChild, k) && a->LeftChild->data < a->LeftChild->RightChild->data)  
        {  
        	cout<<"LR I"<<endl;
            LeftrotationI(a->LeftChild,a->LeftChild,0,0);  
            Rightrotation(a,tr,pal,par); 
            
            Findmaxkey(tr);
			return tr; 
        }  
  
        // Left Right Case II 
        
        else if (a_balance > 1 && Preorder_Search(a->LeftChild->RightChild, k) && a->LeftChild->data > a->LeftChild->RightChild->data)  
        {  
        	cout<<"LR II"<<endl;
            LeftrotationII(a->LeftChild,0,0);
            Rightrotation(a,tr,pal,par);  
            
            Findmaxkey(tr);
            return tr;
        } 
  
        // Left Left Case 

        else if (a_balance > 1 && k < a->LeftChild->data)   
        {
        	cout<<"LL"<<endl;
            Rightrotation(a,tr,pal,par);
            
            Findmaxkey(tr);
            return tr;  
        }
        
        else //If it is not neccessery to make a rotation we just search the new max key and return the new tree (tr)
        { 
        	Findmaxkey(tr);
        	return tr; 	
        }
	} 
     
     
     //PRIVATE CLASS DATA
     
    private:
        int data; //Node data
        BinaryTreeNode *Maxkey, *LeftChild, *RightChild; //pointer to max element, left subtree and right subtree
};



int main()
{ 
	srand(time(NULL));
    BinaryTreeNode *tree = 0;
    //showing the menu of actions
    cout << "\n--- ACTIONS MENU ---"            << endl << endl;
    cout << "1. Insert a value"                         << endl;
    cout << "2. Return the maximum value of the tree"   << endl;
    cout << "3. Delete the Maximum value of the tree"   << endl;
    cout << "4. Exit the menu"                  << endl << endl; 

    int action;
    do 
    {
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
        //if the tree is empty, we assist the user to start adding nodes
        else
        {
            cout << "The tree is currently empty. Type '1' to start adding nodes." << endl;
        }

        cout << endl;

        //after that, the user chooses his action
        do
        {
            cout << "\nENTER A NUMBER FOR AN ACTION: ";
            cin >> action;
            
        } while (action > 4 || action < 1);

        //switch case for each action
        //after each action we use system(pause), so the user can see the changes that have been made

        int number, maximum;
        switch (action)
        {
            case 1:
                cout << "Enter the number (only integer numbers) you want to insert: ";
                cin >> number;

                tree = BinaryTreeNode::Insert(tree, number);
                system("pause");
                cout << endl;
                break;

            case 2:
            	if(tree)
                	cout << "The maximum value of the tree is: " << BinaryTreeNode::Returnmaxkey(tree) << endl;
                else
                	cout<< "The tree is null.Unable to find maximum value" << endl;
                system("pause");
                cout << endl;
                break;

            case 3:
            	if (tree)
            	{
                	maximum = BinaryTreeNode::Returnmaxkey(tree);
                	cout << "Deleting node with value: " << maximum << endl;
                	tree    = BinaryTreeNode::deleteNode(tree, maximum);
                }
                else 
                	cout << "The tree is null.Unable to delete the maximum value" << endl;
                system("pause");
                cout << endl;
                break;
        }
    } while (action != 4);
    
    return 0;
}
