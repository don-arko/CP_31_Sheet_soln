/*

https://codeforces.com/problemset/problem/1881/A

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

infos
- x is of len n
- s is of len m 
- 


- since this is A question brute force solution really works dont think much above brute

- we will just do the ops x->xx->xxxx... and check if s is now a substr of x or s appears in x or not with the help of x.find(s)
- but till how many ops we should go on ie we need to find the upper limit on no. of ops 

- the ops is max when difference between n and m is maximum cause for s(m) to appear in x(n) n must be >= m.
- and in each ops n becomes 2n 
- so max ops are req when difference is max 
- using 1<=n.m <= 25 we see diff is max when n=1 and m=25 
- so




- q is after how many ops s appears as substring in x;
- now the worst or critical case is when n is smalles and m is largest i.e.
- n=1 and hence m=25;

- say x='a';
- say s='25charlong string'
- in order for s is to apear in x atleast n>=m;
- lenth of x increases with operations as 
-   n->             1 -> 2 -> 4 -> 8 -> 16 -> 32 (>=25) 
- ops               0    1    2    3    4     5
- check if str:     x    x    x    x    x    x/tick     

-if at n=32 , s doesnt appear as substr in x 
then beyond this point bhi nei appear karega try to observe

- i.e. in worst case when n=1 and m=25 ans is either 5 or -1 

-ops = 0 correspond to when s already appears in x;

    Editorial 
Note that the answer is always not greater than 5.
When n=1, m=25, the answer is either 5 or −1, 
it is easy to see that the answer cannot be greater.

This allows us to simply iterate over the number of operations, 
each time checking if s occurs in x. The time complexity of this
 solution is O(25⋅n⋅m)


*/


void solve() {
    int n,m;
    string x,s;
    cin>>n>>m;
    cin>>x;
    cin>>s;

    bool found=false;
    for(int ops = 0;ops<=5;ops++){
        if(x.find(s) != string::npos){  //!= npos => substr hain
            cout<<ops<<endl;
            found=true;
            return;
        }
        //= npos => s is not a substr of x 
        x+=x;
    }
    if(!found) cout<<-1<<endl;

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
