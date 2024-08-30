/*

    https://codeforces.com/problemset/problem/1806/A
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
CONCEPT

- It is impossible to reach (x,y) from (a,b) when the point (x,y) is below the horizontal line on which (a,b) lies
because we can move only leftward or upward on the right diagonal so any point below the horizontal line is impossible to reach
=> y<b

- when point (x,y) on or above the horizontal line 
- aim is to first cover delta y i.e  y-b . then while covering this I will get shifted rightward by (y-b) as well since I am moving rightside diagonally .
so my new x coordinate when am on on same horizontal level with the point (x,y) is  a + (y-b).
-Now if (x,y) is in left of (a+(y-b),y) then we could reach (x,y) or else not  
--- can reach if (x<=a+y-b) or else not 

--if we can reach then the steps are delta y + delta x i.e.(y-b)+({a+(y-b)}-x)= 2(y-b) + (a-x)




*/

const int N = 200005;


void solve() {

    //(a,b)->(x,y)
    int a,b,x,y;
    cin>>a>>b>>x>>y;
    if(y<b) {
        cout<<-1<<endl;
        return ;
    }   
    if(x>a+y-b){
        cout<<-1<<endl;
    }
    else{
        cout<<2*(y-b)+(a-x)<<endl;
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
