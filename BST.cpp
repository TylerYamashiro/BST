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

