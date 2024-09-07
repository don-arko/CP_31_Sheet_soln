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
Editorial

Let's calculate the maximum number of problems we can take, and the answer will be n subtracted by that count.
An arrangement that always minimizes the absolute difference between adjacent pairs is the array in sorted order. 
What we notice, is that if the array is sorted, we will always take a subarray (all taken elements will be consecutive).
So, the problem converts to finding the largest subarray for which ai−ai−1≤k. It's easy to see that all the subarrays are 
totally different (don't share any intersection of elements), thus, we can maintain a count variable of the current number 
of elements in the current subarray, and iterate through array elements from left to right. If we currently
are at i and ai−ai−1>k then we just set the count to 1 since we know a new subarray starts, otherwise, we just increase
our count by 1. The answer will be n subtracted by the largest value that our count has achieved.


Beautiful Editorial.....

*/


const int N = 200005;


void solve() {
    int n,k; cin>>n>>k;
    //bug(n,k);
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];


    if(n==1){
        cout<<0<<endl;
        return;

    }

    sort(a,a+n);
    //print(a);
    int maxx=INT_MIN; 
    int count =1;   //we are starting from i=1 and not i=0 so count ini=1
    for(int i=1;i<n;i++){
        int diff=a[i]-a[i-1];
        //bug(count);
        if(diff<=k){
            count++;
        }
        else{
            maxx=max(maxx,count);
            count=1;
        }
    }
    maxx=max(maxx,count); //when till the very last we dont face diff>k then out maxx is never updated and remains at INT_MIN
    //bug(maxx);


    cout<<n-maxx<<endl;

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
