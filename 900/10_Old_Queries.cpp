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

Note that for each question, the resulting array is[a1,a2,…,al−1,k,…,k,ar+1,ar+2,…,an].So, the sum of the elements of the new array 
after each question isa1+⋯+al−1+(r−l+1)⋅k+ar+1+⋯+an.We can compute a1+⋯+al−1 and ar+1+⋯+an in O(1) time by precomputing the sum of
all prefixes and suffixes, or alternatively by using the prefix sums technique. So we can find the sum each time in O(1) per question, and
just check if it's odd or not. The time complexity is O(n+q)

Explaination

All know stuff just the way of implementing seperate prefix array i have learned and then that initially global arrays like
that are 0 initialsed like that I learned.


still

1 based Indexing


pref[r]           = a1+a2+...a[l-1]+a[l]+....a[r]
pref[l-1]         = a1+a2+...a[l-1]
---------------------------------------
pref[r]-pref[l-1] = a[l]+a[l+1]+...a[r]=> sum from l to r

In 0 based indexing 
sum from l to r is pref[r-1]-pref[(l-1)-1] i.e. pref[r-1]-pref[l-2]   just -1 due to 0 based indexing





.*/


const int N = 200005;
int a[N],pref[N];   //arrays are initialised with zero by default

void solve() {
    int n,q;cin>>n>>q;
    //using 1 based indexing
    for(int i=1;i<=n;i++){
        cin>>a[i];

        //prefix sum
        //dont worry about a[0] or pref[0] cause they both are 0 as declaring static array like declared here gives by default vals as 0 read gfg to know more

        pref[i]=pref[i-1];  //pref[i-1] is sum till i-1
        //so at this point pref[i]=sum till i-1
        pref[i]+=a[i];//sum i-1 + a[i]=> sum till i
    }

    while(q--){
        int l,r,k;cin>>l>>r>>k;
        int ans=pref[n]-(pref[r]-pref[l-1])+k*(r-l+1);

        //no. of k added is (r-l+1) from al to ar
        //pref[n]=sum of the array
        //pref[r]-pref[l-1]=sum from l to r
        //k*(r-l+1) is the sum of the added (r-l+1) elements whose values are k
      
        (ans%2==1)?cout<<"YES\n":cout<<"NO\n";
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
