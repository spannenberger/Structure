#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9 + 1337;

template<typename T>
class BinarySearchTree {
    struct Node {
        T val;
        int depth;

        Node* left = nullptr;
        Node* right = nullptr;
        Node* parent = nullptr;

        explicit Node(T val): val(val) {}
    }* root;
    int max_depth = 0;
    int elem_counter = 0;

    void update_depth(Node* &node) {
        node->depth = 1 + (node->parent ? node->parent->depth : 0);
        max_depth = max(max_depth, node->depth);
    }

    void insert(T x, Node* &node) {
        if (!node) {
            elem_counter++;
            node = new Node(x);
            update_depth(node);
            return;
        }
        if (x < node->val) {
            insert(x, node->left);
            node->left->parent = node;
            update_depth(node->left);
        } else if (x > node->val) {
            insert(x, node->right);
            node->right->parent = node;
            update_depth(node->right);
        }
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(T x) {
        insert(x, root);
    }

    int height() {
        return max_depth;
    }
    int counter(){
        return elem_counter;
    }
    ~BinarySearchTree() {
        delete root;
    }
 };

void solve() {
    BinarySearchTree<int> bst;
    for (int num; cin >> num && num;) {
        bst.insert(num);
    }
    cout << bst.counter();
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

