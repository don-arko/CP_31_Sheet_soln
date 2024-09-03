/*
https://codeforces.com/problemset/problem/1761/A

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
- when p=p=n ans is Yes cause for such cases both pair cant look diff they have to look same and i.e. is valid pair as well
    eg 2 2 2 , the peumations are {1,2}
                                  {1,2} here the prefix of 2 and suffix of two are common and is equal to the length of the permutaion
- else
- there should be atleast 2 gaps availble in the midlle cause first p and last p elements are to be same for both the permutations and if there is only gap availble then both permuation also becomes same so if atleast gaps area avaiable we can swap positions of elements and the permutation will become different
---- eg p a q= n 
          -
        p a q= n    here both permutaion becomes same when only one gap is available 
          -

---- eg p a b q= n 
          - -
        p b a q= n    here both permutaion becomes diff since now we can swap
          - -

so here condition is n-(p+q)>1;
*/



const int N = 200005;


void solve() {
    int n , p,q;
    cin>>n>>p>>q;
    if(n==p and n==q){  //n=p=q
        cout<<"YES\n";
        return;
    }

    if(n-(p+q)>1){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
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
