/*

https://codeforces.com/contest/1859/problem/A

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


/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------*/

const int N = 200005;

/*

concept 

    Q criteria 
 i)  both b and c should be non empty
ii) c[j] should not divide b[i]


- idea is : x can't be a divisor of y if x > y
- Put max element of a ( all max if more than one present) into c & remaining element into c

- atlast check if check if size of b and c >0 or not if not then print -1

- an observation is that if all elements are same then all elements are max and hence shifted to c then b becomes empty and hence -1 is printed  

*/
void solve() {
    int n;
    cin>>n;
    vi a(n);
    //vi b;
    vi c;
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
  
    sort(a.begin(),a.end());    

    c.pb(a[n-1]);
    a.pop_back();

    //taking max elements out from a and and into c
    while(a[a.size()-1]==c[c.size()-1]){
        c.pb(a[a.size()-1]);
        a.pop_back();
    }

    //a array is now reduced to b array 
    if(a.size()>0 and c.size()>0){ //technically c array is never 0 sized unless n=0 so to check size of a is sufficient
        cout<<a.size()<<" "<<c.size()<<endl;
        print(a);
        print(c);
    }
    else{
        cout<<-1<<endl;
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
