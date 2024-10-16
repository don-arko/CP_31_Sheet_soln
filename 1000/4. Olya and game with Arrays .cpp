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


/*
Editorial (Excellent one):- crystal clear idea


To increase the answer for each array separately, it is necessary to move the minimum to another array. 
Then, notice that it is optimal to move all the minimums to one array. Let's figure out which array. 
After moving the minimum from an array, the second minimum in the original array becomes the new minimum. 
Then, it is easy to notice that it is optimal to move all the minimums to the array with the smallest 
second minimum. After all the movements, we will have one array where the minimum element is the smallest 
number among all the arrays, and n−1 arrays where the minimum element is the second minimum in the original array.

Therefore, the answer to the problem will be M+K−S, where M is the minimum element among all the arrays, K is 
the sum of all the second minimums, and S is the smallest second minimum.

*/

const int N = 200005;


void solve() {
    int n;cin>>n;
    int s=1e9+1; //minimum of second min of each of the n arrays
    int M=1e9+1; //min of 1st min or minest of the all
    int k=0;//sum of all the 2nd mins
    
//bug(n);
    while(n--){
        int m;cin>>m;
        int a[m];
        for(int i=0;i<m;i++){
            cin>>a[i];  
        }
        sort(a,a+m);
  //      print(a);
        k+=a[1];
        s=min(s,a[1]);
        M=min(M,a[0]);
//        bug(a[0],M);
    }
    //bug(s,M,k);
    cout<<(k-s)+M<<endl;

    
    
    
    
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
