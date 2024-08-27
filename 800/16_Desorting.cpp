/*

https://codeforces.com/problemset/problem/1853/A

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
Concept 
- the idea is that min difference between any two consecutive elements shall be our target , min diff me sabse min ops lagega array ko unsorted krne me 
- In one ops ,  gap is reduced by 2 , final aim is to make a[i] strictly greater than a[i+1] i.e. a[i]>a[i+1]

- if diff is even then diff by 2 ,no. of ops , shall make a[i]=a[i+1], so (diff/2)+1 ops are req to make a[i]>a[i+1]
- if diff is odd then diff by 2 (actually floor(diff/2) as per compiler), no. of ops shall make a[i] exactly one less than a[i+1] so in 
ops= (diff/2) + 1, a[i] is exactly one greater than a[i+1] hence a[i]>a[i+1]

- hence min no. of ops = (min diff)/2 +1; to make a[i]>a[i+1] and hence the array unsorted (cause a[i+1]-a[i] is min)
- also check if the arary is already unsorted i.e. if diff becomes negative then 0 ops are needed 
*/
const int N = 200005;


void solve() {
    int n;
    cin>>n;
    vi a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    int min_diff=INT_MAX;
    for(int i=1;i<n;i++){
        int diff=a[i]-a[i-1];
        if(diff<0){
            cout<<0<<endl;
            return ;
        }
        min_diff=min(min_diff,diff);
    }
    int min_ops=min_diff/2+1;
    cout<<min_ops<<endl;

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
