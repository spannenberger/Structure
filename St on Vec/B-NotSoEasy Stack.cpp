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
    int size(){
        return st.size();
    }
    void clear(){
        st.clear();
        cout << "ok" << endl;
    }
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
            if(!mn.size()){
                cout << "error" << endl;
            }else mn.pop();
        }
        else if(req == "size"){
            cout << mn.size()<< endl;
        }
        else if(req == "clear"){
            mn.clear();
        }
        else if(req == "back"){
            if(!mn.size()){
                cout << "error" << endl;
            }else mn.back();
        }
    }while(req != "exit");
    cout << "bye";
    return 0;
}
