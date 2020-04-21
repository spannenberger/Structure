#include <bits/stdc++.h>

using namespace std;

class LinkedDeque {
    struct Node{
        int value;
        Node *next;
        Node *prev;
        Node(int value, Node* next, Node* prev)
		: value(value), next(next), prev(prev) {}
    } *Head, *Tail;
    int sz;

public:
    LinkedDeque()
    : Head(nullptr), Tail(nullptr), sz(0) {};

    void push_front(int x) {
        auto tmp = Head;
        Head = new Node(x, tmp, nullptr);
        if (sz) {
            tmp->prev = Head;
        } else Tail = Head;
        ++sz;
    }

    void push_back(int x) {
        auto tmp = Tail;
        Tail = new Node(x, nullptr, tmp);
        if (sz) {
            tmp->next = Tail;
        } else Head = Tail;
        ++sz;
    }

    int pop_front() {
    	int val = front();
    	Head = Head->next;
    	if(Head){
            Head->prev = nullptr;
    	}
    	--sz;
    	return val;
    }

    int pop_back(){
        int val = back();
        Tail = Tail->prev;
        if(Tail){
            Tail->next = nullptr;
        }
        --sz;
        return val;
    }

    int front() {
    	assert(Head);
    	return Head->value;
    }

    int back() {
    	assert(Tail);
    	return Tail->value;
    }

    void clear() {
    	Head = Tail = nullptr;
    	sz = 0;
    }

    void show(){
        auto tmp = Head;
        while(tmp){
            cout << tmp->value << " ";
            tmp = tmp->next;
        }
        cout << endl;
    }

    int size() {
    	return sz;
    }
};

int main () {
    LinkedDeque q;

    for (string req; cin >> req && req != "exit";) {
    	if (req == "push_front") {
    		int num;
            cin >> num;
            q.push_front(num);
            cout << "ok" << endl;
        } else if (req == "push_back") {
            int num;
            cin >> num;
            q.push_back(num);
            cout << "ok" << endl;
        } else if (req == "show") {
            q.show();
        } else if (req == "clear") {
            q.clear();
            cout << "ok" << endl;
        } else if (req == "size") {
        	cout << q.size() << endl;
        } else if (!q.size()) {
        	cout << "error" << endl;
        } else if (req == "pop_front") {
        	cout << q.pop_front() << endl;
        } else if (req == "pop_back") {
            cout << q.pop_back() << endl;
        } else if (req == "front") {
        	cout << q.front() << endl;
        } else if (req == "back") {
            cout << q.back() << endl;
        }
    }
    cout << "bye";

    return 0;
}
