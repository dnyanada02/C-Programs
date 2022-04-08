#include<iostream>                 //header 
using namespace std;
class node                         //class node 
{
	public:
		node *left;
		node *right;
		int val;
};
node *root=NULL;

int insertnode(node * , node *);
int preorder(node *);
int inorder(node *);
int postorder(node *);
node* search(node* , int k);
node* deletenode(node* , int k);
void display(node *);
void nonrec_inorder(node *);
void nonrec_preorder(node *);
void nonrec_postorder(node *);

class stack                        //class stack for non recursive traversal
{
 int top;
 node *stack_nodes[20];
  public:
   stack()
   {
    top=-1;
   }
  void push(node *);
  node* pop();
  node* peek( stack stk);
  int empty()
  {
   if(top==-1)
      return(1);
   return(0);
  }
};

void stack::push(node *node)
{
 stack_nodes[++top]=node;
}

node *stack::pop()
{
 return(stack_nodes[top--]);
}

//main function
int main()
{
	int choice,v;
	int a,b;
	do
	{
		cout<<"\n\n***** OPERATIONS ON BINARY TREE *****";
		cout<<"\n 1. Insert node";
		cout<<"\n 2. Preorder traversal";
		cout<<"\n 3. Inorder traversal";
		cout<<"\n 4. Postorder traversal";
		cout<<"\n 5. Search";
		cout<<"\n 6. Delete";
		cout<<"\n 7. Display";
		cout<<"\n 8. Non-recursive Traversal";
		cout<<"\nEnter your choice";
		cin>>choice;
		
		switch(choice)
		{
			case 1:
				node *temp;
				temp=new node;
				cout<<"\nEnter value to be inserted: ";
				cin>>temp->val;
				if(root==NULL)
				{
					root=new node;
					root->val=temp->val;
					root->left=NULL;
					root->right=NULL;
					cout<<"Root node added";
				}
				else
				 v=insertnode(root,temp);
				if(v==1)
					cout<<"Node added to left";
				else if(v==2)
					cout<<"Node added to right";
				else if(v==3)
					cout<<"Node already exixts";
				break;	
				
		case 2:
			cout<<"\nPreorder traversal is: ";
			preorder(root);
			break;
			
		case 3:
			cout<<"\nInorder traversal is: ";
			inorder(root);
			break;
			
		case 4: 
			cout<<"\nPostorder traversal is: ";
			postorder(root);
			break;
			
		case 5:
			if(root!=NULL)
            {
            cout<<"\nEnter node to be Searched:";
            int a;
            cin>>a;
           if(search(root,a)!=NULL)
             cout<<a<<" is present in tree";
           else
             cout<<a<<" is not present in tree";
            }
                else
                    cout<<"\nTree is empty";
			break;
		
		case 6:
			int delete_data;
                cout<<"\nEnter the node to be deleted: ";
                cin>>delete_data;
                deletenode(root,delete_data);
			 break;	
		
		case 7:
			cout<<"\nElements of binary tree are: ";
            display(root);
			break;
			
		case 8:
			cout<<"\nIn order Traversal: ";
			nonrec_inorder(root);
			cout<<"\nPre order Traversal: ";
			nonrec_preorder(root);
			cout<<"\nPost order Traversal: ";
			nonrec_postorder(root);
			break;
			
		default:
		 cout<<"\nPlease enter a valid choice";	
		}
	}while (choice!=0);
	return 0;
}

//insert node in tree
	int insertnode(node *curr_root, node *new_node)
			{
			if(curr_root->val == new_node->val)
				return 3;
			else
			{
			if(new_node->val < curr_root->val)
			{
				if(curr_root->left!=NULL)
					insertnode(curr_root->left,new_node);
				else
				{
					curr_root->left=new_node;
					(curr_root->left)->left=NULL;
					(curr_root->left)->right=NULL;
					return 1;
				}
			}
			else
			{
				if(curr_root->right!=NULL)
					insertnode(curr_root->right,new_node);
				else
					{
						curr_root->right=new_node;
						(curr_root->right)->left=NULL;
						(curr_root->right)->right=NULL;
						return 2;
					}
			}	
			}	
			}	

//recurisve preorder traversal			
int preorder(node *curr_root)
{
	if(curr_root == NULL)
		return 0;
	else
	{
		cout<<curr_root->val<<" ";
		if(curr_root->left!=NULL)
			preorder(curr_root->left);
		if(curr_root->right!=NULL)
			preorder(curr_root->right);
	}
}			

//recurisve inorder traversal
int inorder(node *curr_root)
{
	if(curr_root == NULL)
		return 0;
	else
	{
		if(curr_root->left!=NULL)
			inorder(curr_root->left);
		cout<<curr_root->val<<" ";
		if(curr_root->right!=NULL)
			inorder(curr_root->right);
	}
}

//recurisve postorder traversal
int postorder(node *curr_root)
{
	if(curr_root == NULL)
        return 0;
    else
     {
        if(curr_root->left != NULL)
        	postorder(curr_root->left);
        if(curr_root->right != NULL)
            postorder(curr_root->right);
            cout<<curr_root->val<<" ";
     }
}

//search node in tree
node* search(node* root, int k)
{
  if(root == NULL || root->val == k)
   return root;
  if(  k > root->val)
   return search(root->right,k);
  return search(root->left,k);
 }

// Delete a node from tree
node* deletenode(node* root, int k)
{
  if (root == NULL)
    return root;
  if(k < root->val)
  {
    root->left = deletenode(root->left, k);
    return root;
  }
  else if(k  > root->val)
  {
    root->right = deletenode(root->right, k);
    return root;
  }
  
  //delete node with on child
  if (root->left == NULL)
  {
     node* temp = root->right;
     delete root;
     cout<<"Node deleted";
     return temp;
  }
  else if (root->right == NULL)
  {
            node* temp = root->left;
            delete root;
             cout<<"Node deleted";
            return temp;
  }
  
  //delete node with two children
  else
  {
          node* Parent = root;

         //finding inorder successor
          node *succ = root->right;
          while (succ->left != NULL)
          {
              Parent = succ;
              succ = succ->left;
          }

          if (Parent != root)
                Parent->left = succ->right;
          else
                Parent->right = succ->right;
                
            root->val= succ->val;
            
            delete succ;
             cout<<"Node deleted";
            return root;
        }
    }
    
//nonrecurisve inorder traversal
void nonrec_inorder(node *curr_root)
{
 stack stk;
 node *temp;
 if(curr_root!=NULL)
 {
  temp=curr_root;
  do
  {
   while(temp!=NULL)
   {
      stk.push(temp);
      temp=temp->left;
   }
   if(!stk.empty())
   {
      temp=stk.pop();
      cout<<temp->val<<"  ";
      temp=temp->right;
   }
   else
    break;
  }while(1);
 }
 else
  cout<<"The tree is empty ";
}

//nonrecurisve preorder traversal
void nonrec_preorder(node *curr_root)
{
 stack stk;
 node *temp=curr_root;
 stk.push(temp);
 while(!stk.empty())
 {
  temp=stk.pop();
  if(temp!=NULL)
  {
   cout<<temp->val<<"  ";
   stk.push(temp->right);
   stk.push(temp->left);
  }
 }
}

//nonrecurisve postorder traversal
void nonrec_postorder(node *ptr)
{     int flag[50];                 //to keep track weather we are visting right or left child 
      int top_prev;
      node * stk_array[50];
      int top =1;
      stk_array[++top]=NULL;
      do
      {
          while (ptr!=NULL)
          {
              stk_array[++top]=ptr;
              flag[top]=1;
              if (ptr->right !=NULL)
              {
                  stk_array[++top]=ptr->right;
                  flag[top]=-1;
              }
              ptr=ptr->left;
          }
          top_prev=top;
          ptr=stk_array[top--];

          while (flag[top_prev]==1)
          {
              cout<<ptr->val<<"  ";
              top_prev=top;
              ptr=stk_array[top--];
          }
      }while (ptr!=NULL);
      }

void display(node *ptr)
{
  node *que[20];
  int   front= 0,rear=0 ;
  que[rear]=ptr;

  while (front<=rear)
  {
      ptr=que[front++];
      if (ptr!=NULL)
      {    cout<<"  "<<ptr->val<<"  ";
           que[++rear]=ptr->left;
           que[++rear]=ptr->right;
      }
   }
}
