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




const int N = 200005;

/*
Concept 

observations
-since anna starts first she get ceil(c) buttons from c and katie gets (int)c/2
-so overall anna has m (= a+ceil(c/2)) buttons to press while katie has n(=b+int(c/2) )bottons to press 
-now imagine the game where anna starts it and has k bottons to press while katie follows and has l bottons to press

-clearly evident
-when m=n , after mth round (or nth round ) both are exhausted of bottons but now anna need to start and she doesnt have bottons so she will lose 
 => m=n => Second or katie wins 

-when m>n , after n th round (n=min(m,n)) katie is exhausted of bottons and in in the (n+1)th round anna could press but katie couldn't so anna wins 
 =>m>n => First or anna wins

-when m<n , after m th round (m=min(m,n)) anna is exhausted of bottons and in in the (m+1)th round anna couldn't press but katie could so katie wins 
 =>m<n => Socond or katie wins

 clear rules
 - m = a+ceil(c/2)
 - n = b+int(c/2)
 - m>n => First or anna wins
 - else i.e.  m<=n => Second or katie wins

Verdict :- Not accept a particular test case is failing think of that ..


*/
void solve() {
    float a,b,c;
    cin>>a>>b>>c;
 
    float m=a+ceil(c/2);            
    float n=c/2;
    n+=b;


    if(m>n) cout<<"First\n";
    else cout<<"Second\n";

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
