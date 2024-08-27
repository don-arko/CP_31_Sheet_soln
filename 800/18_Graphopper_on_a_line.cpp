/*
https://codeforces.com/problemset/problem/1837/A

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




const int N = 200005;


/*

-k!=1(given in q)  k>=2
-clearly there is no restriction on the size of the jump i.e. as large as possible 
-observation is atmost two jumps are req 


-when n is not divisible by k then only one jump of distance n is req

-else when n divisible by k 1 
    - then one jump could be k-1 or k+1 (k-1 or k+1 is not divisible by k) in positive or negative direction
    - and other could be n-(k-1) or n-(k+1) and this distance is also not divisible by k 

-PROOF
(K-1)/k = 1+1/k and 1/k is not an integer as k!=1 hence 1+1/k is also not an interger


(n-(k-1))/k= ((n-k)+1)/k = (n-k)/k + 1/k  <-> t1+t2
  t1 is a whole number i.e. (n-k) is divisible by k since both n and k are divisible by k 
  t2 isnt a while number as k>=2
  clearly t1+t2 isnt a whole no. then implying (n-k+1) is not divisible by k


-------------------------------------------------------------------------------------------------------------------------------------------


Editorial :- Gives more trivial provable solutions 

When x is not divisible by k, the grasshopper can reach x in just one jump.


Otherwise (x is divisible by k), you can show that two jumps are always enough. For example, jumps 1 and x−1. 
1 is not divisible by any k>1.
Also, x and x−1 can't be divisible by any k>1 at the same time. (consecutive nos ko bas 1 e simultanously divide kr sakta hain), 
and since x is divisible by k hence (x-1) is not divisible by k .


*/
void solve() {
    int n,k;
    cin>>n>>k;
    if(n%k!=0){
        cout<<1<<endl<<n<<endl;
    }
    else{
        cout<<2<<endl;
        cout<<k-1<<" "<<n-k+1<<endl;
    }
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
