#include <iostream>
#include <cstdlib>
using namespace std;

struct Node {
int data;
Node *left, *right;
};

// Create a new node
Node* createNode(int value) {
Node* newNode = new Node;

```
newNode->data = value;
newNode->left = newNode->right = NULL;

return newNode;
```

}

// Insert a node into BST
Node* insert(Node* root, int value) {
if (root == NULL)
return createNode(value);

```
if (value < root->data)
    root->left = insert(root->left, value);
else if (value > root->data)
    root->right = insert(root->right, value);

return root;
```

}

// Search an element in BST
Node* search(Node* root, int key) {
if (root == NULL || root->data == key)
return root;

```
if (key < root->data)
    return search(root->left, key);

return search(root->right, key);
```

}

// Inorder Traversal
void inorder(Node* root) {
if (root != NULL) {
inorder(root->left);
cout << root->data << " ";
inorder(root->right);
}
}

int main() {
Node* root = NULL;
Node* result;

```
int n, value, key;

cout << "Enter number of nodes: ";
cin >> n;

cout << "Enter node values:\n";

for (int i = 0; i < n; i++) {
    cin >> value;
    root = insert(root, value);
}

cout << "Inorder traversal: ";
inorder(root);

cout << "\nEnter value to search: ";
cin >> key;

result = search(root, key);

if (result != NULL)
    cout << "Element found";
else
    cout << "Element not found";

return 0;
```

}
