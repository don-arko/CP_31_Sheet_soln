/*

https://codeforces.com/problemset/problem/1475/A

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

If the number x has an odd divisor, then it has an odd prime divisor. To understand this
fact, we can consider what happens when multiplying even and odd numbers:

even ∗ even = even;
even ∗ odd = even;
odd ∗ even = even;
odd ∗ odd = odd.

--Real Editorial Starts in here -

There is only one even prime number — 2. So, if a number has no odd divisors, then it must 
be a power of two. To check this fact, for example, you can divide n by 2 as long as it is
divisible. If at the end we got 1, then n — the power of two. => no odd div =>N0



Bonus: You can also use the following condition to check:n&(n−1)==0. If the number — is a 
power of two, then it contains only one unit(1) in the binary notation. Then (n−1) contains units(1)
in all positions except the one in which the unit in n is located. So their bitwise "AND" does not 
contain units.

let n=128 = 1 0 0 0 0 0 0 0
            _ _ _ _ _ _ _ _
n-1=127 =   0 1 1 1 1 1 1 1      {Observed in while learning Computer Networks RBR} 
            _ _ _ _ _ _ _ _
n&(n-1) =   0 0 0 0 0 0 0 0 = 0 or else if n is not a power of 2 then n&(n-1) is exactly 0 

Implementation details
n&(n-1) = 0  = false => when n is a power of 2 this means it has no odd divisors => NO
        != 0 = true => when is not a power of 2 this means it has odd divisors => YES
*/
const int N = 1e7;




void solve() {
    int n; cin>>n;
    (n&(n-1))?cout<<"YES\n":cout<<"NO\n";
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
