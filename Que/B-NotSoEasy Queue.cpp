#include <bits/stdc++.h>

using namespace std;

class LinkedQueue {
    struct Node{
        int value;
        Node *next;
        Node(int value, Node* next)
		: value(value), next(next) {}
    } *Head, *Tail;
    int sz;

public:
    LinkedQueue()
    : Head(nullptr), Tail(nullptr), sz(0) {};

    void push(int x) {
        auto tmp = Tail;
        Tail = new Node(x, nullptr);
        if (Head) {
            tmp->next = Tail;
        } else Head = Tail;
        sz++;
    }

    int pop() {
    	int val = front();
    	Head = Head->next;
    	sz--;
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
int main (){
    LinkedQueue q;
    string req;
    do{
        cin >> req;
    	if (req == "push") {
    		int num;
            cin >> num;
            q.push(num);
            cout << "ok" << endl;
        } else if (req == "pop") {
            if(!q.size()){
                cout << "error" << endl;
            }else cout << q.pop() << endl;
        } else if (req == "show") {
            q.show();
        } else if (req == "clear") {
            q.clear();
            cout << "ok" << endl;
        } else if (req == "front") {
            if(!q.size()){
                cout << "error" << endl;
            }else cout << q.front() << endl;
        } /*else if (req == "back") {
            cout << q.back() << endl;
        } */else if (req == "size"){
        	cout << q.size() << endl;
        }
    }while(req != "exit");

    cout << "bye";

    return 0;
}
