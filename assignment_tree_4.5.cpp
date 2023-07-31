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

bool isPerfect(Node* root) {
    if (!root) {
        return true;
    }

    queue<Node*> q;
    q.push(root);
    int depth = 0;
    int leaf = -1;
    int total = 0;

    while (!q.empty()) {
        int curnodes = q.size();

        while (curnodes--) {
            Node* cur = q.front();
            q.pop();

            if (!cur->left && !cur->right) {
                if (leaf == -1) {
                    leaf = depth;
                } else if (depth != leaf) {
                    return false;
                }
            }

            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }

            total++;
        }

        depth++;
    }

    int last = pow(2, leaf + 1) - 1;
    return total == last;
}

int main() {
    Node* root = input_tree();

    if (isPerfect(root)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
