/*
C++

Consider the unsorted, unbalanced binary trees 11 and 12. We wish to define an "add" operation for binary trees.

The diagram provided shows the result of the "add" operation on 11 and 12.


Task: Define the "add" function as described below:
The "add" function takes a pointer to the root node of TI and a pointer to the root node of 12 and returns a pointer to the root of a newly generated tree with each positionally matching Node.value pair from 11 and 12 added together to make the Node values of the result tree.

Notes:

Ensure that you return the result tree without modifying the contents or structure of the input trees. It may be helpful to implement a cpNode function to make a deep copy of a node and all of its children.

If there is an "add" on an existent node and a null node, the result node will be a deep copy of the existent node.

If both nodes are null, return null.*/
#include <stdexcept>
#include <string>
#include <iostream>

// The Node class is provided to you.
// NOTE: you **MAY** alter this class if you wish
class Node
{
public:
    Node(int value, Node *left, Node *right)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    int getValue() const
    {
        return value;
    }

    Node *getLC() const
    {
        return left;
    }

    Node *getRC() const
    {
        return right;
    }
    void setValue(int value)
    {
        this->value = value;
    }
    void setLC(Node *left)
    {
        this->left = left;
    }
    void setRC(Node *right)
    {
        this->right = right;
    }

private:
    int value;
    Node *left;
    Node *right;
};

class BinaryTreeAdd
{
public:
    // OPTIONAL -- see the description for cpNode in the Notes section
    static Node *cpNode(Node *t)
    {
        if(t == NULL){
            return NULL;
        }
        Node * copy_node = new Node(t->getValue(), cpNode(t->getLC()), cpNode(t->getRC()));
        return copy_node;
    }

    static Node *add(Node *t1, Node *t2)
    {
        if((t1 == NULL) && (t2 == NULL)){
            return NULL;
        }
        else if(!t2){
            return cpNode(t1);
        }
        else if(!t1){
            return cpNode(t2);
        }
        Node *new_node = (t1->getValue() + t2->getValue(), add(t1->getLC(), t2->getLC()), add(t1->getRC(), t2->getRC()));
        return new_node;
    }
};

#ifndef RunTests
int main()
{
    // Add print debugging or tests here if you wish
}
#endif