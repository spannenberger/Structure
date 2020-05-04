//Solve for this task:https://informatics.msk.ru/mod/statements/view3.php?id=599&chapterid=762#1
#include <bits/stdc++.h>

using namespace std;

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

    void print_parent(Node* &node){
        if(node->left) print_parent(node->left);
        if(node->left && node->right){
            cout << node->val << endl;
        }
        if(node->right) print_parent(node->right);
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

    auto min(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }
public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(T x) {
        insert(x, root);
    }
    void pr_parent(){
        print_parent(root);
    }
    int height() {
        return max_depth;
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

    bst.pr_parent();
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
