#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<climits>
#include<iomanip>
#include<unordered_map>
#define mp make_pair
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
#define ll long long
const int MAX_N = 2e5 + 1;
const ll m = 998244353;
const ll INF = 1e9;
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
void solve() {
ll a,b;
cin>>a>>b;
if(b==1){
    cout<<"YES"<<"\n";
}
else{bool ans  = false;
     ll no = b,in = INT_MAX; 
    for(int i=1;i<=30;i++){
        //cout<<a<<" "<<no<<" "<<__gcd(a,b)<<"\n";
        
        if(no%a == 0){
            ans = true;
            break;
        }
        no*=b;
      

        no =  no%a;
    }
    if(ans){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }
}
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
     cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}
