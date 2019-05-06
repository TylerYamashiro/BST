//Tyler Yamashiro
//Project5.cpp

#include "BST.h"
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
  
  BST BST1;//create tree 1
  BST BST2;//create tree 2
  int i = 0;
  ifstream infile;
  string temp;
  infile.open("tree1.txt");//open the file
  if(infile.fail()){
	cout << "File read error, please press enter to exit program";
	cin.get();
	return 0;
  }

  while(infile){//read in the contents
	getline(infile,temp);
  }

  infile.close();
  vector<int> v;
  stringstream ss(temp);

  while (ss >> i)//convert into int and store in a vector
	{
	  v.push_back(i);
	  if(ss.peek() == ',')
		ss.ignore();
	}

  for(unsigned i = 0; i < v.size(); i++){//insert into the BST
	BST1.insert(v.at(i));
  }


  //read in file tree2.txt same process as above
  int j = 0;
  ifstream myfile;
  string temp2;
  myfile.open("tree2.txt");
  if(myfile.fail()){
	cout << "File read error, please press enter to exit program";
	cin.get();
	return 0;
  }

  while(myfile){
	getline(myfile,temp2);
	
  }

  myfile.close();
  vector<int> w;
  stringstream tt(temp2);
  while (tt >> j)
	{
	  w.push_back(j);
	  if(tt.peek() == ',')
		tt.ignore();
	}

  for(unsigned j = 0; j < w.size(); j++){
   BST2.insert(w.at(j));
  }

  //Prints both BST in order 
  cout << endl << endl;
  cout << "Now creating BST t1, t2 from files tree1, tree2 respectively."
	   << endl;
  cout << "Now printing t1 inOrder" << endl;
  BST1.recursiveInorder(cout);
  cout << endl;
  cout << "Now printing t2 inOrder" << endl;
  BST2.recursiveInorder(cout);
  cout << endl << endl;

  //Testing the secondLargesElement() fucntion
  cout << "Now testing secondLargestElement" << endl;
  cout << "Calling on BST1" << endl;
  cout << "The second largest element of BST1 is "<< BST1.returnSecondLargest()
	   <<endl;
  cout << "Calling on BST2" << endl;
  cout << "The second largest element of BST2 is " <<
	BST2.returnSecondLargest() << endl;
  cout << endl << endl;

  //Testing the getCoutInRange() fucntion
  cout <<"Now testing getCountInRange() 5 to 12" << endl;
  cout <<"Calling on BST1" <<endl;
  cout << "There are " <<  BST1.getCount(5,12) << " items in range." << endl;
  cout <<"Calling on BST2" <<endl;
  cout << "There are " <<  BST2.getCount(5,12) << " items in range." << endl;
  cout << endl << endl;

  //Testing the findMinValue() function
  cout <<"Now testing findMinValue()" << endl;
  cout <<"Calling on BST1" << endl;
  cout <<"The minimum value of BST1 is " << BST1.findMinValue() << endl;
  cout <<"Calling on BST2" << endl;
  cout <<"The minimum value of BST2 is " << BST2.findMinValue() << endl;
  cout << endl << endl;

  //Testing the findingPrededessor() fucniton
  cout <<"Now testing findingPredecessor()" << endl;
  cout << "Now calling on BST1" << endl;
  cout << "The predecessor for 20 is " << BST1.returnPredecessor(20) << endl;
  cout << "Now calling on BST2" << endl;
  cout << "The predecessor for 20 is " << BST2.returnPredecessor(20) << endl;
  cout << endl << endl;

  //Testing the lca() funciton
  cout <<"Now testing lca()" <<  endl;
  cout <<"Now calling on BST1" << endl;
  cout << "The lca for 10 and 14 is " << BST1.getLCA(10,14) << endl;
  cout <<"Now calling on BST2" << endl;
  cout << "The lca for 10 and 14 is " << BST2.getLCA(10,14) << endl;
  cout << endl << endl;

  //Testing the findPairWithSum() function
  cout << "Now testing findPairWithSum()" << endl;
  cout <<"Now calling on BST1" << endl;
  if(BST1.pairWithSum(22))
	cout <<"There are numbers that sum to 22." << endl;
  else
	cout << "There are not numbers that sum to 22." <<endl;
  cout <<"Now calling on BST2" << endl;
  if(BST2.pairWithSum(22))
	cout <<"There are numbers that sum to 22." << endl;
  else
	cout << "There are not numbers that sum to 22." <<endl;
  cout << endl << endl;

  //Testing the printCommon() function
  cout <<"Now testing printCommon()" << endl;
  cout <<"Now calling on BST1 and BST2" << endl;
  cout <<"The common nodes are ";
  BST1.printCommonNodes(BST2.returnRoot());
  cout << endl << endl;
 
}
