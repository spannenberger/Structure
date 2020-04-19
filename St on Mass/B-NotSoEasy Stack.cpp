#include <iostream>
using namespace std;

class LinkedStack {
	struct Node {
		int value;
		Node* prev;

		Node(int value, Node* prev)
		: value(value), prev(prev) {}
	}* top;
	int sz;

public:
	LinkedStack() : sz(0) {}

	void push(int x) {
		auto tmp = new Node(x, top);
		++sz;
		top = tmp;
	}

	int pop() {
		int x = back();
		top = top->prev;
		--sz;
		return x;
	}

	int back() {
		return top->value;
	}

	void clear() {
		top = nullptr;
		sz = 0;
	}

	int size() {
		return sz;
	}
};

int main() {
	LinkedStack st;
    string req;
    int numb;
    do{
        cin >> req;
        if(req == "push"){
            cin >> numb;
            st.push(numb);
            cout << "ok" << endl;
        }
        else if(req == "pop"){
            if(!st.size()){
                cout << "error" << endl;
            }else cout << st.pop() << endl;
        }
        else if(req == "size"){
            cout << st.size() << endl;
        }
        else if(req == "clear"){
            st.clear();
            cout << "ok" << endl;
        }
        else if(req == "back"){
            if(!st.size()){
                cout << "error" << endl;
            }else cout << st.back() << endl;
        }
    }while(req != "exit");
    cout << "bye";
	return 0;
}
