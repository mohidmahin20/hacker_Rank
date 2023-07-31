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

void printlevelx(Node* root, int levelx) {
    if (!root || levelx < 0) {
    
        return;
    }

    queue<Node*> q;
    q.push(root);
    int curl = 0;

    while (!q.empty()) {
        int nodecur = q.size();

        if (curl == levelx) {
            
            while (nodecur--) {
                Node* cur = q.front();
                q.pop();
                cout << cur->val << " ";
            }
            cout << endl;
            return;
        }

        while (nodecur--) {
            Node* cur = q.front();
            q.pop();

            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }

        curl++;
    }

    
}

int main() {
    Node* root = input_tree();

    int levelx;
    
    cin >> levelx;

    printlevelx(root, levelx);

    return 0;
}
