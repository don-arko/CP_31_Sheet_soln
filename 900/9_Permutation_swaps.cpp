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

In order to move pi to position i, it is easy to see that |pi−i| has to be divisible by k.

So, |p1−1|,|p2−2|,…,|pn−n| has to be all divisible by k. The largest possible value of k turns 
out to be the greatest common divisor of integers |p1−1|,|p2−2|,…,|pn−n|.

Time complexity: O(n+logn)

Beautiful Aplication of concept 

Explaination:
hints from q
-try to use the fact pi=i in a sorted array (1 based indexing)

-k is the distance between source and destination for any swap to happen in the array or say k is the jump distance i.e. i+k=j or j-i = k (given)
-So the idea is when p1 is given as input then p1 is the destination index of this element but presently it is at index 1.
so it needs travel the distance between d1=|p1-1|, similarly d2=|p2-2|... now i need the greatest k (i.e. greatest jump distance ) so that all these 
swaps of distances d1, d2,... are possible . First of all any d(dist to be covered) should be multiple of k (jump distance) in order for the d distance to be cpossibly covered 
eg if d=4 then possible k values are k=2(2 jumps) or k =4(1 jump) can help reach a distance of d=4 . 
Now the greatest k or jump distance should first of all divide all the d in order for all d to be succesfully covered (or else sorting wont be possible)
which imples k should be common divisor and then we need the greatest k which means k is the greatest common divisior of all d => k= gcd(d1,d2,d3,d4...)

gcd(d1,d2,d3)=gcd(d12,d3)  d12=gcd(d1,d2);  this relation is obvious but still likh diya and this is helpful for coding .
*/

const int N = 200005;


void solve() {
    int n;
    cin>>n;
    int ans=0;// gcd(0,b) =b so 0 is kinda identity no. for gcd

    for(int i=1;i<=n;i++){
        int temp;
        cin>>temp;  //temp is the element and it also tells where the element should go cause a[i] = i in a sorted array in 1 based indexing
        //temp is the index where this element should go 
        //presently it is at i 
        //so the dist between source and destination is 
        int dist=abs(temp-i);
        ans=__gcd(ans,dist);
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
