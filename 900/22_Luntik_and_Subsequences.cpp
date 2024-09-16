/*

https://codeforces.com/problemset/problem/1582/B

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
It can be noticed that all subsequences with sum s−1 appear if we erase some 0-es from the array and also erase exactly one 1.
We can independently calculate the number of ways to erase some 0-es from the array (that way the sum will remain the same), 
then calculate the number of ways to erase exactly one 1 from the array (that way the sum will become equal to s−1), and 
then multiply these two numbers. Therefore, the answer is equal to 2^c0⋅c1, where c0 is the number of 0-es in the array, and c1
is the number of 1-s.



 Note:- A sequence x is a subsequence of a sequence y if x can be obtained from y by deletion of several (possibly, zero or all) elements.
        i.e. subsequence doesnt mean segments of the array that has to be contiguous.

ans = _ x _   the first place is to be filled A and Second by A where

A= no. of ways to erase exactly one 1 from the array = c1 (no. of ones in the array )
B=no. of ways to erase 0 or more 0s from the array 
    _ _ _ _ _ _ (total of c0 slots) each of the slots can be filled in 2 ways either we could select the zero or we cannot so B= 2^c0

so ans = A X B= c1* 2^c0 


*/



const int N = 200005;


void solve() {
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    int c0=0,c1=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==0) c0++;
        if(a[i]==1) c1++;
    }

    cout<<c1*power(2,c0)<<endl;
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
