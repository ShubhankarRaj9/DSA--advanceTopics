#include<bits/stdc++.h>
using namespace std;
void solve(int n, int start, int destination, int mediatator, int& count){
    count++;
    if(n == 1) {
        cout<<"moving plate: "<<n<<" from: "<<start<<" to: "<<destination<<endl;
        return;
    }
    solve(n-1,start,mediatator,destination,count);
    cout<<"moving plate: "<<n<<" from: "<<start<<" to: "<<destination<<endl;
    solve(n-1,mediatator,destination,start,count);
    return ;
}
int main(){
    int count = 0;
    int n,a,b,c;cin>>n>>a>>b>>c;
    solve(n,a,b,c,count);
    cout<<count<<endl;
    return 0;
}