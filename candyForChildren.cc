#include <iostream>
#include <vector>
using namespace std;
vector <int> child;
struct node {
    int val;
    int cnt;
    int candy;
};
vector <struct node> d;
int N;


void handingCandytoRight(vector<struct node>::iterator it){
    auto itt = it + 1;
            
    for (; itt != d.end(); itt++) {
        if(itt->candy == 0)itt->candy = (itt - 1)->candy + 1;
        else {
            itt->candy = (itt - 1)->candy + 1 > itt->candy ? (itt - 1)->candy + 1 : itt->candy;
        }
        if( itt+1 == d.end() || itt->val > (itt+1)->val ) {
            break;
        }
                
    }
}

void handingCandytoLeft(vector<struct node>::iterator it){
    auto itt = it - 1;
            
    for (; ; itt--) {
        if(itt->candy == 0)itt->candy = (itt + 1)->candy + 1;
        else {
            itt->candy = (itt + 1)->candy + 1 > itt->candy ? (itt + 1)->candy + 1 : itt->candy;
        }
        if( itt == d.begin() || itt->val > (itt-1)->val ) {
            break;
        }
                
    }
}

int main() {
    int t;
    char c;
    while(cin>>t) {
        child.push_back(t);
        if(!cin.get(c)||c==EOF||c=='\n')
            break;
    }
    if(child.size() == 0){
        cout << "0" << endl;
        return 0;
    }
    else if(child.size() == 1)
    {
        cout << "1" << endl;
        return 0;
    }
    

    for(auto it = child.begin(); it != child.end(); it++)
    {
        struct node tmp;
        if(d.size() == 0) {
            tmp.val = *it;
            tmp.cnt = 1;
            tmp.candy = 0;
            d.push_back(tmp);
        }
        else{
            if( d.back().val == *it) {
                d.back().cnt++;
            }
            else {
                tmp.val = *it;
                tmp.cnt = 1;
                tmp.candy = 0;
                d.push_back(tmp);
            }
        }
    }
    if(d.size()==1){
        cout << d.begin()->cnt << endl;
        return 0;
    }

    for (auto it = d.begin(); it != d.end(); it++) {
        if(it->candy!=0)
            continue;
        if( it == d.begin() &&  (it->val) < ((it+1)->val) )
        {
            it->candy = 1;
            handingCandytoRight(it);
        }

        else if( it+1 == d.end() &&  (it->val) < ((it-1)->val) )
        {
            it->candy = 1;
            handingCandytoLeft(it);
        }

        else {
            if((it->val) < ((it+1)->val) &&  (it->val) < ((it-1)->val))
            {
                it->candy = 1;
                handingCandytoRight(it);
                handingCandytoLeft(it);
            }
        }
    }
    int ans = 0;
    for (auto it = d.begin(); it != d.end(); it++) {
        ans += it->candy * it->cnt;
    }
    cout << ans << endl;

    return 0;
}

