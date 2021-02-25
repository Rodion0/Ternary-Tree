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

void tree::insert(int value)  
{
    //Create new node
    node * temp = new node();
    node * traveler = root;
    //Set node data to value 
    //Check to see if empty
    if(root == NULL){
        value = temp->small;
        root = temp;
    }
    //Loop until reaches bottom level  
        //Determine which child it(p) should go to  
            // p <= a
            // a < p <= b
            // b > p
        //If no a/b in node then add, else add a child 
    while(traveler!= NULL){
        if(value < traveler->small){
            traveler= traveler->right;
        }
        else if(value > traveler->small && value < traveler->large){
            traveler= traveler->middle;
        }
        else if(value > root->large){
            traveler= traveler->left;
        }
    }
    if(value < traveler->small){
            traveler->right = temp;
    }
    else if(value > traveler->small && value < traveler->large){
            traveler->middle= temp;
    }
    else if(value > root->large){
            traveler->left = temp;
    }
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
    int numberOfInts = stoi(argv[1]), first = 0, temp;
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
