#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

     Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* input_tree() {
    int val;
    cin >> val;
    Node* root = nullptr;
    if (val != -1) {
        root = new Node(val);
        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* p = q.front();
            q.pop();

            int l, r;
            cin >> l >> r;

            if (l != -1) {
                p->left = new Node(l);
                q.push(p->left);
            }
            if (r != -1) {
                p->right = new Node(r);
                q.push(p->right);
            }
        }
    }
    return root;
}

void minMax(Node* root, int& minv, int& maxv) {
    if (!root) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* cur = q.front();
        q.pop();

        if (!cur->left && !cur->right) {
            minv = min(minv, cur->val);
            maxv = max(maxv, cur->val);
        }

        if (cur->left) {
            q.push(cur->left);
        }
        if (cur->right) {
            q.push(cur->right);
        }
    }
}

int main() {
    Node* root = input_tree();

    int minv = INT_MAX;
    int maxv = INT_MIN;

    minMax(root, minv, maxv);

    cout <<  maxv <<" ";
    cout <<  minv<< endl;
    

    return 0;
}
