/*
     ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् |
     उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय माऽमृतात् ||
*/

#include <bits/stdc++.h>

using namespace std;

#define int            long long int
#define F              first
#define S              second
#define pb             push_back
#define si             set <int>
#define vi             vector <int>
#define pii            pair <int, int>
#define vpi            vector <pii>
#define vpp            vector <pair<int, pii>>
#define mii            map <int, int>
#define mpi            map <pii, int>
#define spi            set <pii>
#define endl           "\n"
#define sz(x)          ((int) x.size())
#define all(p)         p.begin(), p.end()
#define double         long double
#define que_max        priority_queue <int>
#define que_min        priority_queue <int, vi, greater<int>>
#define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#define print(a)       for(auto x : a) cout << x << " "; cout << endl
#define print1(a)      for(auto x : a) cout << x.F << " " << x.S << endl
#define print2(a,x,y)  for(int i = x; i < y; i++) cout<< a[i]<< " "; cout << endl

inline int power(int a, int b)
{
    int x = 1;
    while (b)
    {
        if (b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}

template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cout << name << " : " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cout.write (names, comma - names) << " : " << arg1 << " | "; __f (comma + 1, args...);
}


/*-------------------------------------------------------------------------------------------------*/
/*
Editorial (Excellent Classic of Modular Arthmatic)

Let's simulate the game process until the number of health points of each monster becomes k or less. Then we can consider that the i-th monster
has a[i] mod k health instead of a[i] (except for the case when a[i] is divisible by k, then the remaining health is k, not 0).

Now, the health points of all monsters are from 1 to k, so each time we damage a monster, we kill it. Therefore, monsters with k health points 
will die first, then the ones with k−1 health points, and so on. So, let's sort the monsters by their remaining health points in descending 
order (don't forget that, if two monsters have the same health, then they should be compared by index). And the order you get after sorting 
is the answer to the problem.



My Explaination : After simulating the game it is evident that all the health points are kinda different tiers of eq classes of %k , but it doesnt matter what happens in the 
                  upper tier eq classes , everything starts mattering when we enter the last or fundamental eq class [1,k] cause herein one more touch and the monster dies.Now 
                  in the fundamental eq class we can greedily pick the monster with largest health point and he would die first because atmost health point is k. 
                  

Now mind % -> 0-k so to get 1-k as output we should handle the divisible case seperately . Rest follow the editorial. 
*/



const int N = 200005;
int n,k;
bool comp(pair<int ,int> p1, pair<int,int> p2){
    if(p1.first==p2.first){
        return p1.second<p2.second;
    }
    return p1.first>p2.first;
}
void solve() {
    cin>>n>>k;
    vector<pair<int ,int>>v; 
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        if(temp%k==0){
            v.pb({k,i+1});
        }else{
            v.pb({temp%k,i+1});
        }
        
    }
    sort(v.begin(),v.end(),comp);
    //print1(v);
    for(int i=0;i<n;i++){
        cout<<v[i].second<<" ";
    }
    cout<<endl;
}



/*-------------------------------------------------------------------------------------------------*/



int32_t main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


#ifndef ONLINE_JUDGE
    freopen("input.txt",  "r",  stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t z = clock();

/*-------------------------------------------------------------------------------------------------*/


    int t = 1;
     cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;


/*-------------------------------------------------------------------------------------------------*/
}
