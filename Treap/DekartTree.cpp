#include <bits/stdc++.h>

/*
░░░░░░▄▀▒▒▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒█
░░░░░█▒▒▒▒░░░░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█
░░░░█▒▒▄▀▀▀▀▀▄▄▒▒▒▒▒▒▒▒▒▄▄▀▀▀▀▀▀▄
░░▄▀▒▒▒▄█████▄▒█▒▒▒▒▒▒▒█▒▄█████▄▒█
░█▒▒▒▒▐██▄████▌▒█▒▒▒▒▒█▒▐██▄████▌▒█
▀▒▒▒▒▒▒▀█████▀▒▒█▒░▄▒▄█▒▒▀█████▀▒▒▒█
▒▒▐▒▒▒░░░░▒▒▒▒▒█▒░▒▒▀▒▒█▒▒▒▒▒▒▒▒▒▒▒▒█
▒▌▒▒▒░░░▒▒▒▒▒▄▀▒░▒▄█▄█▄▒▀▄▒▒▒▒▒▒▒▒▒▒▒▌
▒▌▒▒▒▒░▒▒▒▒▒▒▀▄▒▒█▌▌▌▌▌█▄▀▒▒▒▒▒▒▒▒▒▒▒▐
▒▐▒▒▒▒▒▒▒▒▒▒▒▒▒▌▒▒▀███▀▒▌▒▒▒▒▒▒▒▒▒▒▒▒▌
▀▀▄▒▒▒▒▒▒▒▒▒▒▒▌▒▒▒▒▒▒▒▒▒▐▒▒▒▒▒▒▒▒▒▒▒█
▀▄▒▀▄▒▒▒▒▒▒▒▒▐▒▒▒▒▒▒▒▒▒▄▄▄▄▒▒▒▒▒▒▄▄▀
▒▒▀▄▒▀▄▀▀▀▄▀▀▀▀▄▄▄▄▄▄▄▀░░░░▀▀▀▀▀▀
▒▒▒▒▀▄▐▒▒▒▒▒▒▒▒▒▒▒▒▒▐
*/

using namespace std;

const int INF = 1e9;
mt19937 rng((uint64_t) new char);

template<typename T>
class ImplicitTreap {
    struct Node {
        T min;
        T value;
        T priority;
        int cnt = 1;

        Node* left = nullptr;
        Node* right = nullptr;
        Node* parent = nullptr;

        Node(T x, T y): min(x), value(x), priority(y) {}
    }* root;

    int count(Node* node) {
        return node ? node->cnt : 0;
    }

    int min_(Node* node) {
        return node ? node->min : INF;
    }

    void update(Node* &node) {
        if (!node) return;
        node->cnt = 1 + count(node->left) + count(node->right);
        node->min = min({node->value, min_(node->left), min_(node->right)});
        if (node->left) { node->left->parent = node; }
        if (node->right) { node->right->parent = node; }
    }

    void split(T x, Node* node, Node* &first, Node* &second) {
        if (!node) {
            first = nullptr;
            second = nullptr;
            return;
        }
        int key = count(node->left);
        if (key < x) {
            split(x - key - 1, node->right, node->right, second);
            first = node;
        } else {
            split(x, node->left, first, node->left);
            second = node;
        }
        update(first);
        update(second);
    }

    void merge(Node* &node, Node* first, Node* second) {
        if (!first) {
            node = second;
        } else if (!second) {
            node = first;
        } else if (first->priority > second->priority) {
            merge(first->right, first->right, second);
            node = first;
        } else {
            merge(second->left, first, second->left);
            node = second;
        }
        update(node);
    }

    void insert(int pos, T x, T y, Node* &node) {
        if (!node) {
            node = new Node(x, y);
        } else if (node->priority < y) {
            auto tmp = new Node(x, y);
            split(pos, node, tmp->left, tmp->right);
            node = tmp;
        } else {
            int key = count(node->left);
            if (key < pos) {
                insert(pos - key - 1, x, y, node->right);
            } else {
                insert(pos, x, y, node->left);
            }
        }
        update(node);
    }

    void traverse(ostream &out, Node* node) {
        if (node) {
            traverse(out, node->left);
            out << node->value << " ";
            traverse(out, node->right);
        }
    }

public:
    ImplicitTreap() {
        root = nullptr;
    }

    void insert(int pos, T x) {
        insert(pos, x, rng(), root);
    }

    T rmq(int l, int r) {
        Node* left = nullptr;
        Node* mid = nullptr;
        Node* right = nullptr;
        split(l, root, left, mid);
        split(r - l + 1, mid, mid, right);
        T res = mid->min;
        merge(root, left, mid);
        merge(root, root, right);
        return res;
    }

    ~ImplicitTreap() {
        delete root;
    }
};

void solve() {
    int n;
    cin >> n;

    ImplicitTreap<int> treap;
    for(char cmd; n-- && cin >> cmd;) {
    	int u, v;
    	cin >> u >> v;
    	if (cmd == '+') {
    		treap.insert(u, v);
    	} else {
    		cout << treap.rmq(u - 1, v - 1) << endl;
    	}
//    	treap.traverse();
    }
}

int main() {
#ifdef LOCAL
    const string FILENAME = "bst";
    freopen((FILENAME + ".in").c_str(), "r", stdin);
    freopen((FILENAME + ".out").c_str(), "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}