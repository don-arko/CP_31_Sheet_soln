/*

https://codeforces.com/problemset/problem/1690/D

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
Before Reading the editorial read CP_Notes/Combinatorics/No. of subarrays within an array : more precisely no. of sub-arrays of size k 
within and aray of size n is n-k+1 and its visualisation to understand the editorial and the code solution


Editorial

To obtain a segment of k cells of black color, we need to paint all the white cells of the segment black. 
Then go through all the segments of length k (there are only n−k+1) and choose such a segment among them 
that the number of white cells on it is minimal. You can quickly find out the number of white cells in the 
segment by prefix sums.


*/


const int N = 200005;


void solve() {
    int n,k;cin>>n>>k;
    string s;cin>>s;

    //Prefix sum creation
    //w[i] = no. of 'W' chars till the ith index(1 based Indexing)
    vector<int> w(n+1); // creates a vector of size n+1 (1 based indexing (handy for creating prefix sum creation)) witih all values 0
    for(int i=1;i<=n;i++){
        w[i] = w[i-1]+(s[i-1]=='W'); //adds one if the condition is true i.e. if the char is 'W' also s is 0 based and w is 1 based indexing so mapping  w->s: is i->i-1 instead of i->i.
    }

    int ans = INT_MAX;

    //1 based Indexing
    // 1st Subarray of size k ends and kth index and as we move the slot the last sub-array of size k ends at nth index
    // and total there are n-k+1 sub-arrays of size k.
    //we iterate through all of them.
    for(int i= k ; i<=n;i++){ 
        ans=min(ans,w[i]-w[i-k]); 
        //i      : represents the end index of the current subarray 
        //i-k    : represents the end index of the prev subarray
        //w[i]   : total w chars till ith index : last index of the current subarray
        //w[i-k] : total w chars till  the last of the prev sub-array
        //w[i]-w[i-k] : gives the no. of w chars in the range i-k+1(starting index of the curr subarray) to ith index (end of the current sub-array)
        //so basically this gives the no. of w chars in the current sub-array.
    }
    cout<<ans<<endl;
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
