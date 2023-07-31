#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int value) : val(value), left(NULL), right(NULL){}
};

int sum(Node* root) {
    if (!root) {
        return 0;
    }

    queue<Node*> q;
    q.push(root);
    int sum = 0;

    while (!q.empty()) {
        Node* root = q.front();
        q.pop();
        sum += root->val;

        if (root->left) {
            q.push(root->left);
        }
        if (root->right) {
            q.push(root->right);
        }
    }

    return sum;
}

Node* input() {
    int val;
    
    cin >> val;

    if (val == -1) {
        return NULL;
    }

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* root = q.front();
        q.pop();

        int leftVal, rightVal;
        
        cin >> leftVal;
        if (leftVal != -1) {
            root->left = new Node(leftVal);
            q.push(root->left);
        }

        
        cin >> rightVal;
        if (rightVal != -1) {
            root->right = new Node(rightVal);
            q.push(root->right);
        }
    }

    return root;
}

int main() {
    
    Node* root = input();

    int result = sum(root);
    cout << result << endl;

    

    return 0;
}
