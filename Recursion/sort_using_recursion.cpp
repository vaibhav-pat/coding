#include<iostream>
#include<vector>
using namespace std;
void insert(vector<int> &v, int val){
    if(v.size() == 0) return;//BC
    else if(v[v.size()-1]<val){//BC
        v.push_back(val);return;
    }
    int rem = v.back();//H
    v.pop_back();//H
    insert(v,val);//H
    v.push_back(rem);// Induction
    //return;optional
}
void sort(vector<int> &v){
    if(v.size() == 1) return; // BC
    int back = v[v.size()-1]; // Hyothesis
    v.pop_back();//Hypothesis
    sort(v);//Hypothesis
    insert(v,back);//Induction
    //return;optional
}
void print(vector<int> v ){
    if(v.size() == 0)return;//BC
    int temp = v.back();//H
    v.pop_back();//H
    print(v);//H
    cout<<temp<<" ";//Induction
    //return;optional
}
int main(){
    int n ;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n ; i++){
        cin>>v[i];
    }
    sort(v);//Recursive Function
    print(v);//Recursive Function
}