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
        if (t == NULL)
        {
            return NULL;
        }
        // OPTIONAL -- Implement your deep copy here
        return new Node(t->getValue(), cpNode(t->getLC()), cpNode(t->getRC()));
    }

    static Node *add(Node *t1, Node *t2)
    {
        if (!t1 && !t2)
        {
            return nullptr;
        }
        if (!t1)
        {
            return cpNode(t2);
        }
        if (!t2)
        {
            return cpNode(t1);
        }
        Node *newNode = new Node(t1->getValue() + t2->getValue(), nullptr, nullptr);

        newNode->setLC(add(t1->getLC(), t2->getLC()));
        newNode->setRC(add(t1->getRC(), t2->getRC()));
        // returns a new node
        return newNode;
    }
};

#ifndef RunTests
int main()
{
    // Add print debugging or tests here if you wish
}
#endif