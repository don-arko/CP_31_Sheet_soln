/*

https://codeforces.com/problemset/problem/1440/B


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

We will consider a greedy approach. We take the ⌈n2⌉ biggest numbers from the end of the array and 
the ⌊n2⌋ smallest numbers from the beginning. We take these elements as one group, erase them from 
our array and then continue the same procedure on the remaining array. This can be done in a loop 
of O(k), by taking every ⌈n2⌉th character. We can also prove this claim. Imagine we have marked k 
elements to be the medians of these arrays. Each one of these elements need at least ⌈n2⌉−1 elements 
bigger than them and at least ⌊n2⌋ elements smaller than them to form a group in which it they are 
the median. So we can always push the biggest of these k numbers forward until we have exactly ⌈n2⌉−1
 elements bigger than them, and by pushing forward the sum of medians either doesn't change or gets 
 larger. So our algorithm will always give the biggest possible answer.



 My idea : - Watch the Youtube Video

 -The initial array of size n*k is sort in increasing order.
 -My aim is to maximise the ⌈n/2⌉ positin of each of the array of size n and each of these needs to be 
 increasing order which means all the elements after ⌈n/2⌉ th position are greater the element at the ⌈n/2⌉ th 
 position . 
 -So my greedy aim is to maximise the ⌈n/2⌉ postion in each of the array in order to maximise the sum .
 -So I will take (n-⌈n/2⌉+1 = (l-r+1)) from the last (biggest elements cause the array is sorted) of the initial n*k sized 
 array and fill my first n sized array from ⌈n/2⌉ pos to nth pos.
 - and  I will take (⌈n/2⌉-1) elements from the first (smaller) of the initial n*k sized array and the fill starting 
 ⌈n/2⌉-1 positions and thereby not wasting the big valued elements from the initial n*k sized sorted array
 -Repeat this step for the remaining k-1 arrays and fill them.
-Since there are n*k elements in the initial array and we got to make k arrays of size n , we never gonna fall sort of elements.


- So this the optimal in each of the stage to maximise the median in each of the case .

n=5, k=3

⌈n/2⌉=3 


     _   _    _      _     _
i->          ⌈n/2⌉          n  => no. of elements = n-⌈n/2⌉ + 1  = 5-3+1=3
             


1 2 3 4 5 6 7 8 9  10 11 12  13 14 15 
  
        k=1        k=2           k=2                    k=3                         k=2                        k=3
       _   _  ||   _     _||     _     _  ||.|  _          _         _   |    _       _       _  |     _       _         _ 
                                                ^                             ^                        ^                        ^
                                                |-----> n-⌈n/2⌉ +1 ----------->|                        |                        | 

                                                ⌈n/2⌉                 n       ⌈n/2⌉             n      ⌈n/2⌉               n
                              interval=n-⌈n/2⌉+1     =      1          2        3                                 1        2       3

i->    0   1       2     3       4     5                        ...                         ---                         nk-1     nk


- Now we see the from the last of the initial array then all the medians lie after an interval of (n-⌈n/2⌉+1) from each other and we should start from 
one element after the last elements to maintain uniform interal.

-------------------------------------|
Another mathematical Observation 

n-⌈n/2⌉ = ⌊n/2⌋
 
i.e.  

n = ⌊n2⌋ + ⌈n/2⌉

Proof

CASE-I : When n is even then 
         ⌈n/2⌉ = ⌊n2⌋ = n/2 AND RHS = 2*n/2 = n = LHS 
         
CASE-II: When n is odd then : when n is odd n/2 is always something.5
        ⌊n/2⌋  = n/2 - 0.5
        ⌈n/2⌉  = n/2 + 0.5
        Therefore RHS = n/2 + 0.5 + n/2 - 0.5 = 2*n/2 = n = LHS
--------------------------------------------------------------------------------------     

Hence Interval =(n-⌈n/2⌉  )+ 1= ⌊n/2⌋ +1 = n/2 +1 because n/2 is actually floor of n/2 in c++

 
*/



const int N = 200005;


void solve() {
    int n,k; cin >> n>>k;
    int a[n*k];
    for(int i=0;i<n*k;i++){
        cin>>a[i];
    }

    int ans=0;
    int i=n*k;
    while(k--){
        i-=(n/2)+1;
        ans+=a[i];
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
