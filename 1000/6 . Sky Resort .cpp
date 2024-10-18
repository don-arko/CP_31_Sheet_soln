/*

https://codeforces.com/problemset/problem/1840/C

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
For understanding the combination part refer to CP_Notes/combinatorics/subarrays within an array

Editorial (Super Classic)

To simplify the task, let's replace all numbers in the array a. If the value of ai is greater than q, then replace it with 0. 
Otherwise, replace it with 1.
Now Dima can go on this day if ai=1. Therefore, we need to consider segments consisting only of 1.

Note that if the segment consists of less than k ones, then Dima will not be able to go on these dates, so the segment can be ignored.

For all remaining segments, we need to calculate the number of ways for Dima to choose travel dates on this segment. 
And for a segment of length l, the number of ways to choose a trip of at least length k is (l−k+2 C l−k). {combination}

The answer to the problem will be the sum of the number of ways to choose travel dates for all segments.

*/


const int N = 200005;
int subarray_atles_k(int k, int l){
    //no. of sub-arrays of size atleast k is (n-k+1)(n-k+2)/2
    return(l-k+1)*(l-k+2)/2;
}

void solve() {
    int n,k,q;cin>>n>>k>>q;
    //bug(n,k,q);
    int a[n];
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        if(temp<=q)a[i]=1;
        else a[i]=0;
    }
    //print(a);
    int ans=0;
    int count=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            if(count>=k){
                ans+=subarray_atles_k(k,count);
            }
            count=0;
        }
        else{
            count++;
        }
    }

    if(count>=k){
        ans+=subarray_atles_k(k,count);
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
