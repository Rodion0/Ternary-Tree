//--------------------------------------------------------------------
//				CS315-001  Assignment 2 
//--------------------------------------------------------------------
// Author: Justin Hamilton
// Date: 3/5/21
// Description: Ternary Trees 
// Assistance: We'll see 
//--------------------------------------------------------------------
//Import Strings, limits, iostream 
#include <iostream>
#include <limits>
#include <string>
using namespace std; 

//Node Class
class node
{
private:
    int small; 
    int large; 
    node * left; 
    node * middle; 
    node * right; 
public:
    friend class tree; 
    node();
};

node::node()
{
    small = INT_MAX; 
    large = INT_MIN; 
    left = right = middle = NULL; 
}
 
//Tree Class
class tree
{
private:
    node * root; 
public:
    tree();
    void insert(int value); 
    void print(); 
};

tree::tree()
{
    root = NULL; 
}

void tree::insert(int value) // Assumes each node visted is full 
{
    //Create new node
    node * temp = new node();
    //Set node data to value 
    //Check to see if empty
    if(root == NULL){

    }
    //Loop until reaches bottom level  
        //Determine which child it(p) should go to  
            // p <= a
            // a < p <= b
            // b > p
        //If no a/b in node then add, else add a child 
}

void tree::print() // In-order traversal
{

} 

//Main
int main(int argc, char const *argv[])
{
    // New Tree
    tree * ternary = new tree(); 
    //Input numberOfInts from Parameters
    int numberOfInts = stoi(argv[1]), int first = 0, int temp;
    cin >> first; 
    ternary->insert(first); 
    for(int i = 0; i < numberOfInts; i ++){
        cin >> temp;        
        ternary->insert(temp);
    }
    //Print
    ternary->print();  
    return 0;
}
