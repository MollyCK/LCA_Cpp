/*
* Binary Search Tree implementation in C++
* Originally by Harish R (https://gist.github.com/harish-r/a7df7ce576dda35c9660)
* Adapted for purpose by MollyCK
* 2020/12/10
*/
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

class BinarySearchTree {
    struct Node {
        int key;      //sorted by key
        char val;     //associated data
        Node* left;   //left subtree
        Node* right;  //right subtree
        int N;        //number of nodes in (sub)tree
    };

    Node* root; //root of BST

    int size(Node* tree)
    {
        if (tree == NULL)
            return 0;
        else return tree->N;
    }

    Node* makeEmpty(Node* tree) {
        if (tree == NULL)
            return NULL;
        {
            makeEmpty(tree->left);
            makeEmpty(tree->right);
            delete tree;
        }
        return NULL;
    }

    Node* put(int key, char val, Node* tree)
    {
        if (tree == NULL)
        {
            tree = new Node;
            tree->key = key;
            tree->val = val;
            tree->N = 1;
            tree->left = tree->right = NULL;
        }
        else if (key < tree->key)
            tree->left = put(key, val, tree->left);
        else if (key > tree->key)
            tree->right = put(key, val, tree->right);
        else
            tree->val = val;
        tree->N = 1 + size(tree->left) + size(tree->right);
        return tree;
    }

    char get(Node* tree, int key) {
        if (tree == NULL)
            return NULL;
        if (key < tree->key)
            return get(tree->left, key);
        else if (key > tree->key)
            return get(tree->right, key);
        else
            return tree->val;
    }

    void printKeysInOrder(Node* tree)
    {
        if (tree == NULL)
            return;
        printKeysInOrder(tree->left);
        cout << tree->key << " ";
        printKeysInOrder(tree->right);
    }

    string prettyPrintKeys(Node* tree, string prefix)
    {
        string prettyPrint(prefix);
        if (isEmpty())
        {
            prettyPrint += "-null\n";
        }
        else
        {
            stringstream addition;
            addition << "-" << tree->key << "\n";
            prettyPrint += addition.str();
            prefix += " |";
            if (tree->left == NULL)
            {
                prettyPrint += prefix;
                prettyPrint += "-null\n";
            }
            else if (tree->left != NULL)
            {
                prettyPrint += prettyPrintKeys(tree->left, prefix);
            }
            prefix = prefix.substr(0, prefix.length() - 1);
            prefix += " ";
            if (tree->right == NULL)
            {
                prettyPrint += prefix;
                prettyPrint += "-null\n";
            }
            else if (tree->right != NULL)
            {
                prettyPrint += prettyPrintKeys(tree->right, prefix);
            }
        }
        return prettyPrint;
    }

    vector<Node*>* getPath(Node* tree, int child, vector<Node*>* path)
    {
        path->push_back(tree);
        if (tree->key == child)
        {
            return path;
        }
        if (tree->left != NULL && getPath(tree->left, child, path) != NULL)
        {
            return path;
        }
        if (tree->right != NULL && getPath(tree->right, child, path) != NULL)
        {
            return path;
        }
        path->pop_back();
        return NULL;
    }

public:
    BinarySearchTree() {
        root = NULL;
    }

    ~BinarySearchTree() {
        root = makeEmpty(root);
    }

    void put(int key, char val) {
        root = put(key, val, root);
    }

    void printKeysInOrder() {
        printKeysInOrder(root);
        cout << endl;
    }

    string prettyPrintKeys() {
        string prettyPrint = prettyPrintKeys(root, "");
        cout << prettyPrint << endl;
        return prettyPrint;
    }

    bool isEmpty() {
        return size() == 0;
    }

    int size() {
        return size(root);
    }

    bool contains(int key)
    {
        return get(key) != NULL;
    }

    char get(int key)
    {
        return get(root, key);
    }

    vector<int> getPath(int child) {
        vector<Node*> pathNodes;
        vector<Node*>* pathNodesPointer = &pathNodes;
        pathNodesPointer = getPath(root, child, pathNodesPointer);
        vector<int> pathKeys;
        for (int i = 0; i < pathNodes.size() - 1; i++)
        {
            int keyTBA = pathNodes[i]->key;
            pathKeys.push_back(keyTBA);
        }
        return pathKeys;
    }

    int LCA(int key1, int key2)
    {
        int LCA = NULL;
        if (!contains(key1) | !contains(key2))
        {
            return LCA;
        }
        vector<int> path1 = getPath(key1);
        vector<int> path2 = getPath(key2);
        bool found = false;
        for (int i = path1.size() - 1; i > -1 && !found; i--)
        {
            for (int j = path2.size() - 1; j > -1 && !found; j--)
            {
                if (path1[i] == path2[j])
                {
                    found = true;
                    LCA = path1[i];
                }
            }
        }
        return LCA;
    }
};

int main() {
    BinarySearchTree testBST;
    testBST.put(7, '7');
    testBST.put(8, '8');
    testBST.put(3, '3');
    testBST.put(1, '1');
    testBST.put(2, '2');
    testBST.put(6, '6');
    testBST.put(4, '4');
    testBST.put(5, '5');
    cout << "Printing keys in order: ";
    testBST.printKeysInOrder();
    cout << "Pretty printing keys:\n";
    testBST.prettyPrintKeys();
    cout << "This tree's size is: " << testBST.size() << endl;
    cout << "This tree is empty: " << testBST.isEmpty() << endl;
    cout << "The LCA of 2 & 4 is: " << testBST.LCA(2, 4) << endl;

    return 0;
}