//--------------------------------------------------------------------
//				CS315-001  Assignment 2 
//--------------------------------------------------------------------
// Author: Justin Hamilton
// Date: 3/9/21
// Description: Add values to a ternary tree and then print them
// Assistance: Tau Beta Pi tutoring 
//--------------------------------------------------------------------


#include <iostream>
#include <climits>
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
    node(int value);
};

//--------------------------------------------------------------------------------------
//                                      node()
//--------------------------------------------------------------------------------------
node::node(){
    small = INT_MAX; 
    large = INT_MIN; 
    left = NULL;
    right = NULL;
    middle = NULL;
}

//--------------------------------------------------------------------------------------
//                                      node()
//--------------------------------------------------------------------------------------
// Given: some int 
// Create node with said int in data 
//--------------------------------------------------------------------------------------
node::node(int value)
{
    small = value;
    large = INT_MIN;
    left = NULL;
    right = NULL;
    middle = NULL; 
}
 
//Tree Class
class tree
{
private:
    node * root; 
public:
    tree();
    node * insert(node * current, int value); 
    void swap(node * current,int value);
    void print(node * current);
    node * getRoot();  
};

//--------------------------------------------------------------------------------------
//                                      tree()
//--------------------------------------------------------------------------------------
// Default Constructor
//--------------------------------------------------------------------------------------
tree::tree()
{
    root = NULL; 
}

//--------------------------------------------------------------------------------------
//                                      getRoot()
//--------------------------------------------------------------------------------------
// Given: some int 
// Create node with said int in data 
//--------------------------------------------------------------------------------------
node * tree::getRoot(){
    return root; 
}

//--------------------------------------------------------------------------------------
//                                      swap()
//--------------------------------------------------------------------------------------
// Given: node, some int  
// Swaps the values in the node if new value is smaller than previous value
//--------------------------------------------------------------------------------------
void tree::swap(node * current, int value){
    if (current->large == INT_MIN){
        if(value < current->small){
            current->large = current->small; 
            current->small = value;  
        }
        else{ 
            current->large = value;
        }
    } 
}

//--------------------------------------------------------------------------------------
//                                      insert()
//--------------------------------------------------------------------------------------
// Given: node, some int  
// Returns: updated node
// Insert node with given value into tree according to parameters
//--------------------------------------------------------------------------------------
node * tree::insert(node * current, int value){
    //Base Case 
    if(current == NULL){ 
        current = new node(value);
        if(root == NULL){
            root = new node(value);
            return root;
        }
        return current;  
    }
    else{
        // If value is smaller than current-> small it swaps, else it just inserts at current->large
        if(current->large == INT_MIN){
            swap(current,value);
        }
        
        //Insert new node if current node is filled according to parameters
        else if(value <= current->small){
            current->left = insert(current->left,value);
        }
        else if(value > current->small && value <= current->large){ 
            current->middle = insert(current->middle,value);
                
        }
        else if(value > current->large){
            current->right = insert(current->right,value);    
        }
        return current; 
    }
}

//--------------------------------------------------------------------------------------
//                                      print()
//--------------------------------------------------------------------------------------
// Given: a node  
// Prints the tree with parenthesis around children  
//--------------------------------------------------------------------------------------
void tree::print(node * current) 
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
        cout << ") "; 
    }
    
    //Output Child->smaller
    if(current->small != INT_MAX){
        cout << current->small;
    }

    //Go down Middle Child
    if(current->middle != NULL){
        cout << " ("; 
        print(current->middle);
        cout << ")";
    } 

    //Output Child->bigger
    if(current->large != INT_MIN){
        cout << " " << current->large; 
    }

    //Go down Right Child 
    if (current->right != NULL)
    {
        cout << " ("; 
        print(current->right);
        cout << ")"; 
    } 
} 



//--------------------------------------------------------------------------------------
//                                      main()
//--------------------------------------------------------------------------------------
int main(int argc, char const *argv[])
{
    // New Tree
    tree * ternary = new tree();
    //Input numberOfInts from Parameters
    int numberOfInts = stoi(argv[1]), temp; 
    //Insert Values into tree
    for(int i = 0; i < numberOfInts; i ++){
        cin >> temp;        
        ternary->insert(ternary->getRoot(),temp);
    }
    //Print
    ternary->print(ternary->getRoot());  
    cout << endl;
    return 0;
}
