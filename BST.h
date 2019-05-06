//Tyler Yamashiro
//BST.h
//Purpose: The .h file for the BST class declares the BinNode class as well
// as the member functions of the BST class and helper and friend fucnitons

#include <iostream>
#include<stack>
#include<queue>

using namespace std;


#ifndef BST_H
#define BST_H

class BST
{
 private:
  class BinNode{//Binary node class to create nodes for the BST
  public:
	int data;
	BinNode* left;
	BinNode* right;
  BinNode(int item,BinNode* l, BinNode* r)
	: data(item), left(0), right(0)
	  {
		left = l;
		right = r;
	}
  BinNode():left(0), right(0){}
  };

  typedef BinNode* BinNodePtr;
  BinNodePtr myRoot;

  BinNode* Clone(BinNode* node){//copy constructor helper clones a tree from 
	if(node == nullptr){           //node and make a new one 
	  return NULL;
	}
	else{
	  return new BinNode(node->data, Clone(node->left), Clone(node->right));
	}
  }
  
  void postHelper(BinNode* root)//recursivepostorder helper recusively
  {                            //iterates through tree in postorder 
	if(root){
	postHelper(root->left);
	postHelper(root->right);
	cout << root->data << endl;
	}
  }

  void preHelper(BinNode* root)//recursive preorder helper 
  {
	if(root){
	  cout << root->data << endl;
	  preHelper(root->left);
	  preHelper(root->right);
	}
  }

  void inHelper(BinNode* root, ostream& out)//recursive in order helper
  {
	if(root){
	  inHelper(root->left, out);
	  out << root->data << ' ';
	  inHelper(root->right, out);
	}
  }

  BinNode* findMin(BinNode* node) const //helps the deleteHelper fucntion
  {
	if(node == nullptr)
	  return nullptr;
	if(node->left == nullptr)
	  return node;
	return findMin(node->left);
  }

  
 public:
  BST();
  //Constructor for the BST class
  //PreCondition:A BST object is to be created
  //PostCondition: initializes myRoot to NULL and creates object
  BST(const BST& rhs);
  //Copy constructor for the BST class
  //PreCondition: A BST object already exists
  //PostCondition: Uses exisiting object as a parameter and creates a copy
  //off the object
  ~BST();
  //Deconstructor
  //Precondition:BST object exists
  //PostCondition:De allocates all the memory taken by the BST object
  const BST operator= (const BST &rhs);
  //Overloaded assingment operator
  //Precondition: 2 BST objects exist
  //Copies the rhs object to the left object
  friend ostream& operator<<(ostream& out, BST& rhs);
  //Overloaded Stream opterator
  //PreCondition: A BST object exists
  //PostCondition:overloads the << operator to print a BST object inOrder
  void recursivePostorder();
  //Precondition: A tree needs to be printed and traversed in postorder
  //PostConditin: Recursively traverses and prints postorder
  void recursivePreorder();
  //PreCondition: A tree needs to be printed and traversed in preorder
  //PostCondition: Recursively traverses and prints preorder
  void recursiveInorder(ostream& out);
  //PreCondition: A tree needs to be printed and traversed in inorder style
  //PostCondition:recursively traverses and prints inorder style
  void nonrecursiveInorder(ostream& out);
  //PreConditon: A tree needs to be printed and traversed in order
  //PostCondiditon: Uses a stack to iterate through the tree and print inorder
  void makeEmpty(BinNode*& node);
  //Precondition:All nodes froma specified node is to be deleted
  //PostCondition:deletes all leaf nodes from specifed node
  void recursiveInsert(const int& item);
  //PreConditon:A node needs to be inserted into the BST passed as a parameter
  //PostCondition:Uses insertHelp to create and recursivley insert the node
  void insertHelp(BinNodePtr& root,const int& item);
  //helper for recursiveInsert
  void deleteTree();
  //PreConditon :All nodes in the tree are to be deleted
  //PostConditionn: Deletes all nodes in tree using makeEmpty()
  bool empty();
  //PreConditon: Needs to check if the BST is empty
  //PostCondition: Returns true if empty and false if not empty
  bool search(const int& item);
  //PreConditon: Parameter passed as an int to be found in BST
  //PostConditon: Recursivley uses searchHelper() to find the value in the
  //tree returns true if it is found and false if it is not
  bool searchHelper(BinNode* root, const int& item);
  //helper function for search
  void insert(const int& item);
  //Preconditon: A value is to be added to the BST
  //PostCondition: Iterates throught the tree and inserts the value as a new
  //node
  void remove(const int& item);
  //PreConditon: A value is to be removed from the BST specified as a
  //parameter
  //PostCondition: Uses deleteHelper() to recursively remove the specified
  //value from the BST
  void deleteHelper(BinNode*& root, const int& item);
  //Helper function for remove()
  int recursiveLevel(const int& item);
  //Precondition: User wants to find out what level a node is on in the BST
  //specified by the parameter
  //PostConditon: Uses levelHelper() to recursivley determine what level
  //the node is on the BST
  int levelHelper(BinNode* root, const int& item, int level);
  //Helper fucnciton for recursiveLevel
  int nonrecursiveLevel(const int& item);
  //PreConditon: Parameter specifies what node is to be found in BST
  //PostConditon: Iterates throught the BST and returns the level that
  //the node is on
  int height();
  //Precondtion: The height of the BST is watned
  //PostConditon: Using heightHelper()  recursively determines the height of
  //the tree and returns it
  int heightHelper(BinNode* root);
  //Helper funciton for height();
  void levelTraversal(ostream& out);
  //Preconditon: A tree is to be iterated through and printed level by level
  //PostCondition: Uses a queue to traverse though the BST level by level
 
};

#endif
