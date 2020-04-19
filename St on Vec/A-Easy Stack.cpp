#include <bits/stdc++.h>

using namespace std;
class intStack{
private:
    vector<int> st;
public:
    void push(int el){
        st.push_back(el);
        cout << "ok" << endl;
    }
    void pop(){
        cout << *(st.end() - 1) << endl;
        st.pop_back();
    }
    void back(){
         cout << *(st.end() - 1) << endl;
    }
    void size(){
        cout << st.size()<< endl;
    }
    void clear(){
        st.clear();
        cout << "ok" << endl;
    }
    /*void exit(){
        cout << "bye";
    }*/
};
signed main(){
    string req;
    int numb;
    intStack mn;

    do{
        cin >> req;
        if(req == "push"){
            cin >> numb;
            mn.push(numb);
        }
        else if(req == "pop"){
            mn.pop();
        }
        else if(req == "size"){
            mn.size();
        }
        else if(req == "clear"){
            mn.clear();
        }
        else if(req == "back"){
            mn.back();
        }
    }while(req != "exit");
    cout << "bye";
    return 0;
}
