#include <bits/stdc++.h>

using namespace std;

const int INF = -1;
const int MOD = 1e9;

mt19937 rng((uint64_t) new char);

template<typename T>
class Treap {
    struct Node {
        T key;
        T priority;

        Node* left = nullptr;
        Node* right = nullptr;

        Node(T x, T y): key(x), priority(y) {}
    }* root;

    auto min(Node* node) {
        while (node && node->left) {
            node = node->left;
        }
        return node;
    }

    void next(T x, Node* node, Node* &nxt) {
        if (!node)  return;

        if (node->key >= x) {
            nxt = node;
            next(x, node->left, nxt);
        } else if (node->key < x) {
            next(x, node->right, nxt);
        } else if (node->right) {
            nxt = min(node->right);
        }
    }
    void split(T x, Node* node, Node* &first, Node* &second) {
        if (!node) {
            first = nullptr;
            second = nullptr;
        } else if (x > node->key) {
            split(x, node->right, node->right, second);
            first = node;
        } else {
            split(x, node->left, first, node->left);
            second = node;
        }
    }

    void insert(T x, T y, Node* &node) {
        if (!node) {
            node = new Node(x, y);
        } else if (node->priority < y) {
            auto tmp = new Node(x, y);
            split(x, node, tmp->left, tmp->right);
            node = tmp;
        } else {
            insert(x, y, node->key < x ? node->right : node->left);
        }
   }

public:
    Treap() {
        root = nullptr;
    }

    void insert(T x) {
        insert(x,  rng() % INF, root);
    }

    T next(T x) {
        Node* nxt = nullptr;
        next(x, root, nxt);
        return nxt ? nxt->key : -1;
    }

    ~Treap() {
        delete root;
    }
};

void solve() {
    int n;
    cin >> n;

    Treap<long long> treap;
    long long prev = 0;
    for (char cmd; n && cin >> cmd; --n) {
        if (cmd == '+') {
            int x;
            cin >> x;
            treap.insert((prev + x) % MOD);
            prev = 0;
        } else {
            int y; cin >> y;
            prev = treap.next(y);
            if (prev == -1) {
                cout << -1 << endl;
                continue;
            }
            cout << prev << endl;
        }
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
