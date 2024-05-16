#include <bits/stdc++.h>
using namespace std;


// puts sum of subarrays of size sqrt(n) in block array
void preprocess(vector<int> &arr, vector<int> &block){
    int len = block.size();
    int sz = arr.size();
    for(int i = 0; i < sz; i++) block[(i/len)] += arr[i];
}

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i <n; i++) cin >> arr[i];
    
    int len = sqrt(n); // log (n) 😟
    vector<int> block(len);
    
    // preprocess the blocks with sum
    preprocess(arr, block);
    
    int q;
    cin >> q;
    
    int l, r;
    
    while(q--){
        // 1 indexed queries
        cin >> l >> r;
        l -= 1;
        r -= 1;
        
        int sum = 0;
        
        // traverse l -> r by taking already calculated sum of block array
        
        for(int i = l; i <= r;){
            if( (i%len == 0) && (i + len -1 <= r)){
                sum += block[i/len];
                i += len; 
            }else{
                sum += arr[i];
                i++;
            }
        }
        
        // the sum
        cout<<sum<<"\n";
    }
}

int main(){
    solve();
}