#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long int
#define ull unsigned long long
#define ld double
#define lld long double
#define vi vector <int>
#define vll vector <ll>
#define vvll vector <vll>
#define vbool vector <bool>
#define pii pair <int,int>
#define pll pair <ll,ll>
#define vpll vector <pll>
#define fill1(a,x) for (auto &it: a) it=x;
#define fill2(a,x) for (auto &v: a) { for (auto &it: v) it=x; }
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ff first
#define ss second
#define ins insert
#define mkp make_pair
#define lb lower_bound
#define ub upper_bound
#define YY cout<<YES
#define NN cout<<NO
#define set_bits __builtin_popcountll
#define sz(v) (ll)v.size()
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
#define desc() greater <ll>()
#define endl '\n'
#define random(l,r,T) uniform_int_distribution<T>(l,r)(rng)
#define sync ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifndef testing
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif
template<class T> using oset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class key, class value> using omap = tree <key,value,less<key>,rb_tree_tag,tree_order_statistics_node_update>;
const int M = 1e9+7;
const int MM = 998244353;
const int N = 2e5+7;
const ll inf = 1e18;
const ld eps = 1e-9;
#define PI 3.141592653589793238462
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
template<typename T> istream& operator >>(istream &in,vector<T> &v){ for(auto &x:v) in>>x; return in;}
template<typename T> ostream& operator <<(ostream &out,const vector<T> &v){ for(auto &x:v) out<<x<<' '; return out;}
template<typename T1,typename T2> istream& operator >>(istream &in,pair<T1,T2> &p){ in>>p.first>>p.second; return in;}
template<typename T1,typename T2> ostream& operator <<(ostream &out,const pair<T1,T2> &p){ out<<p.first<<' '<<p.second; return out;}
ll gcd(ll a, ll b) { while (b) {a %= b; swap(a,b);} return a; }
ll lcm(ll a, ll b) { ll g=gcd(a,b); ll res=a*(b/g); return res; }
ll extended_gcd(ll a, ll b, ll &x, ll &y) { if (b==0) { x=1; y=0; return a; } ll x1,y1; ll g=extended_gcd(b,a%b,x1,y1); x=y1; y=x1-y1*(a/b); return g; }
ll expo(ll a, ll b, ll m=M) { a = a % m; ll res = 1; while (b) { if (b&1) { res=(res * a) % m; } a=(a * a) % m; b>>=1; } return res; }
ll mod_inv(ll a, ll m=M) { a = a % m; return expo(a,m-2,m); }
ll mod_add(ll a, ll b, ll m=M) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
ll mod_sub(ll a, ll b, ll m=M) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m=M) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
ll mod_div(ll a, ll b, ll m=M) { a = a % m; ll binv = mod_inv(b,m); return (((a * binv) % m) + m) % m; }
ll mminvprime(ll a, ll b) {
return expo(a, b - 2, b);
}
ll combination1(ll n, ll r, ll m, vector<ll>& fact, vector<ll>& ifact){
return mod_mul(fact[n], mod_mul(ifact[r], ifact[n - r], m), m);
}
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
struct custom_hash
{
static uint64_t splitmix64(uint64_t x)
{
x += 0x9e3779b97f4a7c15;
x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
 return x ^ (x >> 31);
}
size_t operator()(uint64_t x) const
{
static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
return splitmix64(x + FIXED_RANDOM);
}
};
template <class T, class H> using umap=unordered_map<T,H,custom_hash>;
template <class T> using uset=unordered_set<T,custom_hash>;
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
struct Interactor{
int hiddenNumber;
int queriesTillNow;
int limitQueries;
bool printInteraction;
Interactor(){
hiddenNumber = getRandomNumber(1, 100);
queriesTillNow = 0;
limitQueries = 10;
printInteraction = false;
}
 void checkTotalQueries(){
 if(queriesTillNow >= limitQueries){
 cout << "Made more than limit queries for " << hiddenNumber << endl;
}
assert(queriesTillNow < limitQueries);
}
char make_query(int x){
checkTotalQueries();
queriesTillNow++;
if(printInteraction)
cout << "? " << x << endl;
if(x < hiddenNumber)
return '<';
if(x > hiddenNumber)
return '>';
return '=';
}
void isValidOutput(int x){
if(x != hiddenNumber){
 cout << "Failed for " << hiddenNumber << endl;
}else{
cout << "Passed for " << hiddenNumber << endl;
}
}
};
void Deb()
{
     ll n,k,q;
     cin>>n>>k>>q;
     ll c=0,ans=0;
     for(ll i=0;i<n;i++){
     	ll x;
     	cin>>x;
     	if(x>q){
     		if(c>=k){
     			ll t=(c-k+1);
     			ans+=(t*(t+1))/2;
     		}
     		c=0;
     	}
     	else{
     		c++;
     	}
     }
     if(c>=k){
     			ll t=(c-k+1);
     			ans+=(t*(t+1))/2;
     		}
     		cout<<ans<<endl;
}
int main()
{
#ifndef ONLINE_JUDGE
freopen("error.txt","w",stderr);
#endif
int t;
cin>>t;
for (int test=1;test<=t;test++)
{
Deb();
}
return 0;
}