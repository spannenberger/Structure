#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1337228;

template<typename T>
class Stack {
	T st[SIZE];
	int sz = 0;
public:

	void push(T x) {
		st[sz++] = x;
		cout << "ok" << endl;
	}

	T pop() {
		return st[--sz];
	}
    void back(){
        cout << st[sz - 1] << endl;
    }
    T clear(){
        sz = 0;
        return sz;
    }
	int size() {
		return sz;
	}
};

int main() {

    string req;
    int numb;
    Stack<int> mn;

    do{
        cin >> req;
        if(req == "push"){
            cin >> numb;
            mn.push(numb);
        }
        else if(req == "pop"){
            cout << mn.pop() << endl;
        }
        else if(req == "size"){
            cout << mn.size() << endl;
        }
        else if(req == "clear"){
            mn.clear();
            cout << "ok" << endl;
        }
        else if(req == "back"){
            mn.back();
        }
    }while(req != "exit");
    cout << "bye";
    return 0;
}
