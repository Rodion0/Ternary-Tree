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
    node * insert(node * root, int value); 
    void print(node * current);
    node * getRoot();  
};

tree::tree()
{
    root = NULL; 
}

node * tree::getRoot(){
    return root; 
}

//Insert Method
node * tree::insert(node * root, int value){
    //If Null return node with 
}

void tree::print(node * current) // In-order traversal
{
    //If Tree is Empty
    if(current == NULL){
        cout << "There is no tree" <<endl; 
        return; 
    }
    //Go Down Left Child
    if(current->left != NULL){
        cout << "("; 
        print(current->left);
        cout << ")"; 
    }
    
    //Output Child->smaller
    
    if(current->small != INT_MAX){
        cout << current->small << " ";
    }
    else{
        cout << current->small; 
    }

    //Go down Middle Child
    if(current->middle != NULL){
        cout << "("; 
        print(current->middle);
        cout << ")";
    } 

    //Output Child->bigger
    if(current->large != INT_MIN){
        cout << current->large << " "; 
    }
    else{
        cout << current->large; 
    }

    //Go down Right Child 
    if (current->right != NULL)
    {
        cout << "("; 
        print(current->right);
        cout << ")"; 
    }
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
    ternary->print(ternary->getRoot());  
    return 0;
}



//Old insert
/* void tree::insert(int value)  
{
    //Create new node
    node * temp = new node();
    node * traveler = root;
    //Set node data to value 
    //Check to see if empty
    /* if (root == NULL)
    {
        value = temp->small;
        root = temp;
    } */
    //Loop until reaches bottom level  
        //Determine which child it(p) should go to  
            // p <= a
            // a < p <= b
            // b > p
        //If no a/b in node then add, else add a child 
    /* while(traveler!= NULL){
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
    } */