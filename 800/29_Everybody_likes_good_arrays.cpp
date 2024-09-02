/*

https://codeforces.com/problemset/problem/1777/A

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
- lets deal in 0 and 1 for odd and even nos 
- final array should be of alternate parity 
- Observations
    odd*odd=odd
    even*even=even

- so when the alterate scheme is not followed we need to pick to like parity elements which are hamering the alternate scheme and repace them with the parity of their product
 eg:- 01|00|101 - > 010101  (00 = 0)  obs is for ops req is nothing but count-1 eg here 2-1 , ... where  count is equivalent to streak
      10|11|0   - > 0010    (11 = 1)    for rest of the part count=1 hence ops = 1-1 =0 ops are req
      

now how do we calculate no of ops 

        a[i]     =   0 0 0| 1| 0 0| 1 0 0 0 
        count=1  =   - 2 3| 1| 1 2| 1 1 2 3
                    -------------------------
        ops      =       2| 0|   1|       2  | Total Ops =2+0+1+2=5 => Ops+= count-1 shall work
        relation =      count-1 also when count=1 then 1-1 i.e. 0 ops are req which is obvious and evident

After this observation rest is just implementation    
*/




const int N = 200005;


void solve() {
    int n;
    cin>>n;
    
    int a[n];


    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(temp%2==0){
            a[i]=1;
        }
        else{
            a[i]=0;
        }
    }
    //if we dont consider the array via cin when n=1 then that value shall be feed to the next solve function causing trouble
    if(n==1){
        cout<<0<<endl;
        return;
    }

    //print(a);

    int count=1;
    int ops=0;
    for(int i=1;i<n;i++){
        if(a[i]==a[i-1]){
            count++;
        }
        else{
            ops+=count-1;
            count=1;
        }
    }
    ops+=count-1;

    cout<<ops<<endl;


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
