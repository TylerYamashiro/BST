//Tyler Yamashiro
//Project3.cpp
//Purpose: Driver function that test methods of the BST class
//Input:A file containing ints 
//Proccessing:Reads in the file and turns it into an array of ints
//Output:Prints the results of each test as well as what each test is testing 
#include "BST.h"
#include <fstream>
#include <string>
#include<sstream>
#include <vector>
using namespace std;

int main()
{
  BST t1;//first tree
  int i = 0;
  ifstream infile; 
  string temp;
  infile.open("tree.txt");
  if(infile.fail()){  //stops program if file fails to read
	cout << "File read error, press enter to exit program";
	cin.get();
	return 0;
  }

  while (infile){ //gets the information of the file and stores it in temp
	getline(infile, temp);
  }
  infile.close();
  vector<int> v; 
  stringstream ss(temp);
  
  while( ss >> i) //Turns the string into ints parsing based on commas 
	{             //and inserts them into  a vector
	  v.push_back(i);
	  if(ss.peek() == ',')
		ss.ignore();
	}
  cout << endl;
  cout << "Now creating BST t1 from file." << endl;
  for(unsigned i= 0; i < v.size(); i++){ //creates a BST from the vector
	t1.insert(v.at(i));
  }
  
  //Copy constructor test
  cout <<"Now testing the copy constructor to crete t2." << endl;
  BST t2(t1);
  
  //Prints contents of t1 and t2 using levelTraversal 
  cout << "Now printing contents of t1." << endl;
  t1.levelTraversal(cout);
  cout << endl;
  cout << "Now printing contents of t2." << endl;
  t2.levelTraversal(cout);   
  cout << endl << endl;

  //OAO test on t3 copies values from t2 and print t3
  cout << "Now testing the Overloaded assignment operator to create t3."
	   << endl;
  BST t3;
  t3 = t2;
  cout << "Now printing contents of t3." << endl;
  t3.levelTraversal(cout);
  cout << endl << endl;

  //Test for empty() fucntion
  cout << "Now calling empty() on t1." << endl;
  if(t1.empty())
	cout << "empty() returns true, so the tree is empty." << endl;
  else
	cout << "empty() returns false, so the tree is not empty." << endl;
  cout << endl;

  //Tests the search function 
  cout << "Now searching for 22 in t1." << endl;
  if( t1.search(22))
	cout << "22 is in t1" << endl;
  else
	cout << "22 is not in t1" << endl;
  cout << endl;
  
  cout << "Now searching for 50 in t1." << endl;
  if( t1.search(50))
	cout << "50 is in t1" << endl;
  else
	cout << "50 is not in t1" << endl;
  cout << endl;

  //Testing the insert function
  cout <<"Now testing insert() on t1." << endl;
  cout << "Now inserting 100 into t1." <<endl;
  t1.insert(100);
  cout <<"Now searching to see if 100 is in t1." << endl;
  if(t1.search(100))
	cout << "100 is in t1" << endl;
  else
	cout << "100 is not in t1" << endl;
  cout << endl;

  //Testing the remove fucntion
  cout <<"Now testing remove() on t1" << endl;
  cout << "Now removing 100 from t1." <<endl;
  t1.remove(100);
  cout <<"Now searching to see if 100 is in t1." << endl;
  if(t1.search(100))
	cout << "100 is in t1" << endl;
  else
	cout << "100 is not in t1" << endl;
  cout << endl;

  //Testing the overlaoded streaming operator
  cout <<"Now testing the << operator." << endl;
  cout <<"Now printing t1." << endl;
  cout << t1;
  cout << endl << endl;

  //Tests the recursiveInorder() function
  cout << "Now testing recursiveInorder() on t1." << endl;
  cout << "Printing contents of t1." << endl;
  t1.recursiveInorder(cout);
  cout << endl << endl;

  //Tests the nonrecursiveInorder() fucntion
  cout << "Now testing nonrecursiveInorder() on t1." << endl;
  cout << "Printing contents of t1." << endl;
  t1.nonrecursiveInorder(cout);
  cout << endl << endl;

  //Tests recursiveLevel() fucntion 
  cout <<"Now testing recursiveLevel() on t1." << endl;
  cout <<"Printing level of node 15." << endl;
  cout <<"15 is on level " << t1.recursiveLevel(15) << endl;
  cout << endl;

  //Tests the nonrecursiveLevel() function
  cout << "Now testing nonrecursiveLevel() on t1." << endl;
  cout <<"Printing level of node 12." << endl;
  cout << "12 is on level " << t1.nonrecursiveLevel(12) << endl;
  cout << endl;
  
  //Test levelTraversal() function
  cout<< "Now testing levelTraversal() on t1." << endl;
  cout <<"Printing contents of t1." << endl;
  t1.levelTraversal(cout);
  cout << endl << endl;
  
  //Tests the height() function
  cout <<"Now testing height() on t1." << endl;
  cout <<"The height of t1 is " << t1.height() << endl;
  cout << endl;
  
}

 
