// cpp ->10^8 operations(elementary addn,subtra...)/sec not I/O operations -> T(endl) >> T(\n)[endl flushes o/p every time you use it whereas \n is simply an escape sequence .'. flushing is handled by cout autom.. and it appr.. flush the o/p once per 1000 lines  and Time taken is dependent on no of flushing operations]
#include <algorithm>
#include <array>
#include <bitset>
#include <chrono>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <unordered_map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#define mp make_pair
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
#define ll long long
#define lld  long double
const int MAX_N = 2e5 + 1;
const ll m = 998244353;
const ll INF = 1e9;
typedef unsigned long long ull;
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd(ll a, ll b, ll*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); ll x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
ll mminv(ll a, ll b) {ll arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
//Stress Tester
struct testcase{
    int a,n,d;
};
int randomNumber(int a,int b){
    return a + (rand() % b);
}
testcase generateTestCase(){
    testcase randomTest;
    randomTest.a = randomNumber(1,100000);
    randomTest.n = randomNumber(1,100000);
    randomTest.d = randomNumber(-100000,100000);

}
int bruteForce(testcase T){
    int ret;
    return ret;
}
int optimizedSolution(testcase T){
    int ret;
    return ret;
}
void debugger(){
    testcase random = generateTestCase();
    int ans1 = bruteForce(random);
    int ans2 = optimizedSolution(random);
    if(ans1 != ans2) {
        cout<<random.a;
        return;
    }
}

int fl(int arr[],int n,int x){
int i=0,j = n-1;
int ans = -1;
while(i<=j){
    int m = (i+j)/2;
    if(arr[m] == x){
        return arr[m];
    }
    else if(arr[m]<x){
        ans = arr[m];
        i = m+1;
    }
    else{
         j = m-1;
    }
}
return ans;
}
int cl(int arr[],int n,int x){
    int i=0,j = n-1;
int ans = -1;
while(i<=j){
    int m = (i+j)/2;
    if(arr[m] == x){
        return arr[m];
    }
    else if(arr[m]>x){
        ans = arr[m];
        j = m-1;
    }
    else{
         i = m+1;
    }
}
return ans;
}
//ll aa[MAX_N],bb[MAX_N];
void solve() {
int n;
cin>>n;
for(int i=0;i<n;i++)
cout<<i<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
    #endif 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        //cout << fixed << setprecision(0) << p
        // cout << "Case #" << t  << ": ";
        solve();
    }
}