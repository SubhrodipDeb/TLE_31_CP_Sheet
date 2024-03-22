#include <bits/stdc++.h>
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
using namespace std;
typedef long long ll;
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
const long long int MOD=1e9+7;
int gcd(int a, int b)
{
if (a == 0) return b;
if (b==0) return a;
if (a > b) return gcd(a-b, b);
return gcd(a,b-a);
}
int parallelopiped(int x,int y,int z)
{
int a=sqrt((x*y)/z);
int b=sqrt((z*y)/x);
int c=sqrt((x*z)/y);
return a,b,c;
}
bool ispalindrome(string s){
int start=0;
int end=s.size()-1;
while(start<=end){
if(s[start++]!=s[end--]){
return false;
}
}
return true;
}
int pwr(int x,int n,int mo)
{
int res=1;
if(n==0)
return 1;
if(n==1)
return (x%mo);
if(n%2)
res=x%mo;
int temp=pwr(x,n/2,mo);
return (res*((temp*temp)%mo))%mo;
}
int modInverse(int a, int m)
{
return pwr(a,m-2,m);
}
 int nCrModp(int n, int r, int p)
{
 if (r > n - r)
r = n - r;
int C[r + 1];
memset(C, 0, sizeof(C));
C[0] = 1;
for (int i = 1; i <= n; i++) {
for (int j = min(i, r); j > 0; j--)
C[j] = (C[j] + C[j - 1]) % p;
}
 return C[r];
}
vector<int> SieveOfEratosthenes(int n)
 {
 bool prime[n + 1];
vector<int> prie;
memset(prime, true, sizeof(prime));
for (int p = 2; p * p <= n; p++)
{
 if (prime[p] == true)
{
for (int i = p * p; i <= n; i += p)
prime[i] = false;
}
}
for (int p = 2; p <= n; p++)
 if (prime[p])
 prie.push_back(p);
return prie;
}
ll binpowIt(int a,int b,long long int M){
ll ans=1;
while(b){
if(b&1){
ans=(ans*a)%M;
}
 a=(a*a)%M;
 b>>=1;
 }
return ans;
}
 void dfs(int node,vector<ll> vis,vector<ll> adj[],vector<ll> dfs1){
vis[node]=1;
dfs1.push_back(node);
for(auto it: adj[node]){
if(vis[it]!=1){
dfs(node,vis,adj,dfs1);
}
}
cout<<endl;
}
class DisJointSet{
vector<int> rank,parent,size;
public:
DisJointSet(int n){
rank.resize(n+1,0);
parent.resize(n+1,0);
size.resize(n+1,0);
for(int i=0;i<n;i++){
parent[i]=i;
}
}
 int findUPar(int node){
if(node==parent[node]) return node;
 else return parent[node]=findUPar(parent[node]);
}
void union_by_rank(int u,int v){
int ultimate_parent_u=findUPar(u);
int ultimate_parent_v=findUPar(v);
if(ultimate_parent_u==ultimate_parent_v) return;
else if(rank[ultimate_parent_u]<rank[ultimate_parent_v]){
parent[ultimate_parent_u]=ultimate_parent_v;
}
else if(rank[ultimate_parent_v]<rank[ultimate_parent_u]){
 parent[ultimate_parent_v]=ultimate_parent_u;
}
else{
 parent[ultimate_parent_v]=ultimate_parent_u;
 rank[ultimate_parent_u]++;
}
}
void union_by_size(int u,int v){
int ultimate_parent_u=findUPar(u);
int ultimate_parent_v=findUPar(v);
if(ultimate_parent_u==ultimate_parent_v) return;
if(size[ultimate_parent_u]<size[ultimate_parent_v]){
 parent[ultimate_parent_u]=ultimate_parent_v;
size[ultimate_parent_v]+=size[ultimate_parent_u];
}
else{
 parent[ultimate_parent_v]=ultimate_parent_u;
size[ultimate_parent_u]+=size[ultimate_parent_v];
}
}
};
void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n+1),b(n+1);
    vector<ll> v(2e5,0),v1(2e5,0);
    map<ll,ll> mp1,mp2;
    ll ans=0;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    
    // for(ll i=0;i<=10;i++){
    //     cout<<i<<" "<<v[i]<<" ";
    //     cout<<endl;
    // }
    // for (ll i = 0; i <= 10; i++)
    // {
    //     cout << i << " " << v1[i] << " ";
    //     cout << endl;
    // }
    ll p=1,r=1;
    for(ll i=2;i<n+1;i++){
       
        if(a[i]!=a[i-1]){
            mp1[a[i-1]]=max(mp1[a[i-1]],i-p);
            p=i;
        }
    }
    mp1[a[n]]=max(mp1[a[n]],n-p+1);
    for(ll i=2;i<n+1;i++){
       
        if(b[i]!=b[i-1]){
            mp2[b[i-1]]=max(mp2[b[i-1]],i-r);
            r=i;
        }
    } 
      mp2[b[n]]=max(mp2[b[n]],n-r+1);
   
    for(ll i=1;i<=(2*n);i++){
        ans=max(ans,mp1[i]+mp2[i]);
    }
    cout<<ans<<endl;
}
int main()
{
fast_cin();
ll t;
cin >> t;
for(int it=1;it<=t;it++) {
solve();
}
 return 0;
}