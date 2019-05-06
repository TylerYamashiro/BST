//Tyler Yamashiro
//BST.cpp
//Purpose: Implementation file for the BST class
//Input: Takes in values to create, find, and delete nodes in a BST

#include "BST.h"

BST::BST()//constructor
{
  myRoot = nullptr;
}


BST::BST(const BST& rhs)//copy constructor
{
  if(rhs.myRoot){
	myRoot = Clone(rhs.myRoot);//uses clone to create new tree
  }
}


BST::~BST()
{
  makeEmpty(myRoot);//calls make empty to deallocate all memory
}

const BST BST::operator= (const BST& rhs)
{
  makeEmpty(myRoot); //deallocates memory
  if(rhs.myRoot){
	myRoot = Clone(rhs.myRoot);//uses clone to create copy of specified BST
  }
  return *this;
}


ostream& operator << (ostream& out, BST &rhs)//overloades streaming operator
{
  rhs.recursiveInorder(out); //prints Inorder 
  return out;
}
  

void BST::recursivePostorder()//recursively prints in postorder
{
  postHelper(myRoot);
}

void BST::recursivePreorder()//recursively prints in preorder
{
  preHelper(myRoot);
}

void BST::recursiveInorder(ostream& out)//recursivly prints in inorder
{
  inHelper(myRoot,out);
}


void BST::nonrecursiveInorder(ostream& out)
{
  if(!myRoot)  //uses a stack to iterate throught the BST and print
	return;
  BinNode* temp = myRoot;
  stack<BST::BinNodePtr> s;
  for(; ;){
	while(temp){
	  s.push(temp);
	  temp = temp->left;
	}
	if(s.empty())
	  break;
	temp = s.top();
	s.pop();
	out << temp->data << ' ';
	temp = temp->right;
  }
}


void BST::makeEmpty(BinNode* &node)//deletes all child nodes from specified
{                                 //node
  if(node){
	makeEmpty(node->left);
	delete node;
	makeEmpty(node->right);
  }
}

void BST::recursiveInsert(const int& item)//insert function calls insertHelp()
{
  insertHelp(myRoot, item);
}


void BST::insertHelp(BinNodePtr& root, const int& item)//helper function 
{                                                //to insert nodes
  if(root == nullptr){
	root = new BinNode(item, nullptr, nullptr);
	return;
  }

  if(root->data < item){
	insertHelp(root->right, item); //inserts data recursivley
  }
  else if(root->data > item){
	insertHelp(root->left, item);
	}
}



void BST::insert(const int& item)//non recursive insert funciton
{
  if(myRoot == nullptr){
	myRoot = new BinNode(item, nullptr, nullptr);
  }
  else{
	BinNode* parent = nullptr;
	BinNode* current = myRoot;
	while(current != nullptr){
	  parent = current;
	  if(current->data <= item){
		current = current->right;
	  }
	  else{
		current = current->left;
	  }
	}
	if(parent->data <= item){
	  parent->right = new BinNode(item, nullptr, nullptr);
	}
	else{
	  parent->left = new BinNode(item, nullptr, nullptr);
	}
  }
}
  

bool BST::empty()//checks if BST is empty
{
  if(myRoot == nullptr){
	return true;
  }
  else{
	return false;
  }
}

bool BST::search(const int& item)//searches for value using searchHelper()
{
  return searchHelper(myRoot, item);
}

bool BST::searchHelper(BinNode* root, const int& item)
{
  if(root == nullptr){
	return false;
  }
  else if(item < root->data ){
	return searchHelper(root->left, item); //recursivley searches the tree
  }
  else if(item > root->data){
	return searchHelper(root->right, item);
  }
  else{
	return true;
  }
}

void BST::remove(const int& item)//removes a node using deleteHelper()
{
  deleteHelper(myRoot, item);
}


void BST::deleteHelper(BinNode* &root, const int& item)
{
  if(root == nullptr)
	return;

  if(item < root->data){
	deleteHelper(root->left, item); //recursively find the node
  }
  else if(item > root->data){
	deleteHelper(root->right, item);
  }
  else if(root->left != nullptr && root->right != nullptr){
	root->data = findMin(root->right)->data;//calls findmin
	deleteHelper(root->right, root->data);
  }
  else{
	BinNode* oldNode = root; //then deletes it from the tree
	if(root->left != nullptr)
	  root = root->left;
	else{
	  root = root->right;
	}
	delete oldNode;
  }
}


int BST::levelHelper(BinNode* root,const int& item, int level)
{
  if(root == nullptr)
	return -1;
  if(root->data == item)  //recursively returns the level a node is at
	return level;
  int l = levelHelper(root->left, item, level + 1);
  if(l != -1)
	return l;
  else{
	return levelHelper(root->right, item, level+1);
  }
}


int BST::recursiveLevel(const int& item)//finds level of a node based on 
{                                      //parameter
  return levelHelper(myRoot, item, 0);
}

int BST::nonrecursiveLevel(const int& item)
{
  int level = 0;    //finds level nonrecursively using a while loop
  BinNode* temp = myRoot; 
  if(myRoot == nullptr)
	return -1;

  else{
	while(temp != nullptr){
	  if(item < temp->data)
		temp = temp->left;
	  else if(item > temp->data)
		temp = temp->right;
	  else{
		return level;
	  }
	  level++;
	}
	return -1;
  }
}


int BST::height()
{
  return heightHelper(myRoot); //recusivly returns height of the tree
}


int BST::heightHelper(BinNode* root)
{
  if(root == nullptr)
	return -1;
  int leftHeight = heightHelper(root->left);  //recursivley iterates to 
  int rightHeight = heightHelper(root->right);//find talles point
  if( leftHeight > rightHeight)
	return (leftHeight + 1);
  else{
	return (rightHeight + 1);
  }
}

void BST::levelTraversal(ostream& out)//Uses a queue to iterate level by 
{                                   //level through a BST printing each node
  if(myRoot == nullptr)
	return;
  queue<BinNode*> q;
  q.push(myRoot);
  while(!q.empty()){
	BinNode* current = q.front();
	out << current->data << ' ';
	if(current->left != nullptr)
	  q.push(current->left);
	if(current->right != nullptr)
	  q.push(current->right);
	q.pop();
  }
}

int BST::returnSecondLargest()//calls secondLargestElement() to return
{                            //the value of the second largest element
  int counter = 0;
  int value;
  secondLargestElement(myRoot,counter,value);
  return value;
}

void BST::secondLargestElement(BinNode* root, int& counter, int& value)
{            //recursively finds the second larges element and stores
  if(root == nullptr || counter >=2)//the value is passed by referenced
	return;
  
  secondLargestElement(root->right, counter, value);
  
  counter++;
  
  if(counter == 2){
	value =  root->data;
  }
  
  secondLargestElement(root->left, counter, value);
}

int BST::getCount(int low, int high)//calls getCountInRange to return elements
{                                 //in range
 return  getCountInRange(myRoot,low,high);
}

int BST::getCountInRange(BinNode* root, int low, int high)
{             //recursively returns the number of items in the range
  if(root == nullptr)
	return 0;
  if(root->data <= high && root->data >= low)
	return 1 + getCountInRange(root->right,low,high) +
	  getCountInRange(root->left,low,high);
  else if(root->data < low)
	return getCountInRange(root->right,low,high);
  else
	return getCountInRange(root->left,low,high);
}

int BST:: findMinValue()//calls FindMinHelper to find the minimum in a BST
{
  return findMinHelper(myRoot);
}

int BST::findMinHelper(BinNode* root)//recusivley finds the minimum in a BST 
{                                   //returns the value
  if(root == nullptr){
	cout << "Tree is empty" << endl;
	return -1;
  }
  else if(root->left == nullptr)
	return root->data;
  return findMinHelper(root->left);
}

BST::BinNode* BST::find(BinNode* root,int item)//finds a specified node
{
  if(item == root->data)
	return root;
  else if( item < root->data)
	return find(root->left, item);
  else{
	return find(root->right, item);
  }
}

int BST::returnPredecessor(int key)//calls FfindPredecessor() to recursively
{                           //find the predecessor of the specified item
 return  findPredecessor(myRoot, key);
}

int BST::findPredecessor(BinNode* root, int key)
{     //recursively finds the predecessor of the key and returns it
  BinNode* current = find(root, key);
  if(current == nullptr)
	return -1;
  //Case 1:Node has left subtree
  if(current->left != nullptr){
	BinNode* temp = current->left;
	while(temp->right != nullptr)
	  temp = temp->right;
	return temp->data;
  }
  //Case 2: Node doesnt have left subtree
  else{
	BinNode* predecessor = nullptr;
	BinNode* ancestor = root;
	while(ancestor != current){
	  if(current->data > ancestor->data){
		predecessor = ancestor;
		ancestor = ancestor->right;
	  }
	  else{
		ancestor = ancestor->left;
	  }
	}
	return predecessor->data;
  }
}

int BST::lca(BinNode* root, int n1 , int n2){//finds the lca recursively
  if(root->data < n1 && root->data < n2){//right if both values are bigger
	return lca(root->right, n1, n2);
  }
  else if(root->data > n1 && root->data > n2){//moves left if both are bigger
	return lca(root->left,n1 , n2);
  }
  else{
	return root->data; //if one is bigger and the other is smaller returns data
  }
}

int BST::getLCA(int n1, int n2)//calls lca() to recursively find the lca 
{                             //of specified items
  return lca(myRoot, n1, n2);
}


void BST::returnBSTSize(BinNode* root, int& size)//pass the size of a 
{                                         //binary search tree by reference
  if(root){
	returnBSTSize(root->left, size);
	size++;
	returnBSTSize(root->right, size);
  }
}
  
void BST::arrayInOrder(BinNode* root,int*& arr, int& index)
{         //creates an array in order from a binary search tree
  if(root){
	arrayInOrder(root->left, arr, index);
	arr[index++] = root->data;
	arrayInOrder(root->right, arr, index);
  }
}


int BST::pairWithSum(int targetSum)
{                //calls findPairWithSum() to recusivley return true or false
  //if the sum can be made from numbers in the bst
 return findPairWithSum(myRoot, targetSum);
}

int BST::findPairWithSum(BinNode* root, int targetSum)
{ 
  int size = 0;
  int p1;
  int p2;
  returnBSTSize(root, size);
  int* arr= new int[size];
  int index = 0;
  arrayInOrder(myRoot,arr, index);//creates an inorder array to compare
  p1 = 0;
  p2 = size - 1;
  while( p1 < p2)
	{
  
	  if(arr[p1]+arr[p2] == targetSum) //returns 1 if there is a sum
		return 1;
  
	  else if(arr[p1] + arr[p2] < targetSum)//increments along arrays
		p1++;
	  else
		p2--;
	}
  return 0;//returns 0 if none are found
}


void BST::printCommonNodes(BinNode* root2)//calls printCommon() to recursively
{                                     //print all nodes in common between
  printCommon(myRoot, root2);           //two trees
}

void BST::printCommon(BinNode* root1, BinNode* root2)
{                        //recursively prints all nodes that are in common
  int size1 = 0;           //between two BSTs
  returnBSTSize(root1, size1);
  int* arr1= new int [size1];//creates an array of one


  int size2 = 0;
  returnBSTSize(root2, size2);
  int* arr2 = new int [size2];//creates array of second
  int index1 = 0;
  int index2 = 0;
  
  arrayInOrder(root1,arr1 , index1);
  arrayInOrder(root2,arr2, index2);
  index1 = 0;
  index2 = 0;
 
  while( index1 < size1 && index2 < size2){//walks through arrays and prints
	if(arr1[index1] < arr2[index2]){      //the nodes in common
	  index1++;
	}
	else if(arr1[index1] > arr2[index2]){
	  index2++;
	}
	else if(arr1[index1] == arr2[index2]){
	  cout <<  arr1[index1] << ' ';
	  index1++;
	  index2++;
	}
  }
}
  
BST::BinNode* BST::returnRoot()//returns root of a BST
{
  return myRoot;
}
