//--------------------------------------------------------------------
//				CS315-001  Assignment 2 
//--------------------------------------------------------------------
// Author: Justin Hamilton
// Date: 3/5/21
// Description: Ternary Trees 
// Assistance: We'll see 
//--------------------------------------------------------------------


//Current Problems
    //Insert Method 
        //For some reason doesnt want to add to another cell or go down tree
    //Print 
        //I hope to Jesus, Mary and Joseph it works
    //Main 
        //Fuck it looks right 



//Import limits, iostream 
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

node::node(){
    cout << "I have made it to the node" << endl; 
    small = INT_MAX; 
    large = INT_MIN; 
    left = NULL;
    right = NULL;
    middle = NULL;
}

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
node * tree::insert(node * current, int value){
    //Base Case 
    if(current == NULL){
        cout << "I have returned" << endl;  
        current = new node(value);
        if(root == NULL){
            cout << "Root here" <<endl;
            root = new node(value);
            return root;
        }
        return current;  
    }
    else{
        // Check to see if node is filled
        if (current->large == INT_MIN)
        {
            if(value < current->small){
                cout << "Swapping" << endl; 
                current->large = current->small; 
                current->small = value;  
            }
            else{
                cout << "Doesn't need to be swapped" <<endl; 
                current->large = value;
            }
        }
        else if(value <= current->small){
            if(current->left == NULL){
                cout << "Small boi" << endl; 
                current->left = current;
            }
            else{
                cout << "Small Boi insert" <<endl; 
                insert(current->left,value);
            }
        }
        else if(value > current->small && value < current->large){
            if(current-> middle == NULL){
                cout <<"Middle Boy" <<endl;
                current->middle = current;
            }
            else{
                cout << "Middle Boy INsert" << endl; 
                insert(current->middle,value);
            }
        }
        else if(value > current->large){
            if(current->right == NULL){
                cout << "Large Boy" << endl; 
                current->right = current;
            }
            else{
                cout << "Large  Boy Insert" <<endl; 
                insert(current->right,value);
                cout << "Hello Darkness my old friend" <<endl; 
            }
        }
        return current; 
    }
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
    int numberOfInts = stoi(argv[1]), temp; 
    for(int i = 0; i < numberOfInts; i ++){
        cin >> temp;        
        ternary->insert(ternary->getRoot(),temp);
    }
    //Print
    ternary->print(ternary->getRoot());  
    return 0;
}
