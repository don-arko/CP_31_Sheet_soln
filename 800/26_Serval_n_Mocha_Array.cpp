/*
    
    https://codeforces.com/contest/1789/problem/A
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

Editorial

Considering an array a of n (n≥2) positive integers, the following 
inequality holds for 2≤i≤n:
gcd(a1,a2,⋯,ai)≤gcd(a1,a2)≤2        {thinking about this inequality is the game }

Therefore, when the prefix [a1,a2] of a is good, we can show that all the prefixes
 of a whose length is no less than 2 are good, then a is beautiful. It is obvious that [a1,a2]
 is good when a is beautiful. So we get the conclusion that a is beautiful if and only if the 
 prefix [a1,a2] is good.

We can check if there exist ai,aj (i≠j) such that gcd(ai,aj)≤2. If so, we can move ai,aj
 to the front of a to make it beautiful, then the answer is Yes. If not, the answer is No.

Time complexity: O(n2log106).
*/

const int N = 200005;

//implementation taken from cp algorithms
int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
void solve() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];


    // choosing all possible a[i],a[j]
    
    //i = 0->n-1;
    //and j =i+1->n-1;      shall pick all possible a[i] and a[j] without considering the order.
    for(int i=0;i<n;i++){
        for(int j=1;j<n;j++){
            if(gcd(a[i],a[j])<=2) {
                cout<<"YES\n";
                return;
            }
        }
    }
    cout<<"NO\n";

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
