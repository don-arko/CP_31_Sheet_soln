/*

https://codeforces.com/problemset/problem/1788/A
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
- 1<=k<=n-1 (1 based indexing for k)
-Idea is the array consists of only 1 and 2 where only 2 contribute to the product 
-So we shall count the nos of 2s in the array 
-if count=0 =>  all 1s in the array then all k in the valid range are ans but smallest k is k=1
-if not = 0 
    then
    if count = odd then cant be split into two equal halves hence condition can't be met => -1
    else when count is even then count/2 no. of 2s should be on left part and count by 2 no. of 2s should be on right part
        and the k=1+indices of the last two on the left part (i.e. count/2 th no. of 2's indices +1 is k)

*/
const int N = 200005;


void solve() {
    int n;
    cin>>n;

    int a[n];
    int count=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==2) count++;
    }
    //bug(count);
    if(count==0) {
        cout<<1<<endl;
        return;
    }
    if(count%2!=0){
        cout<<-1<<endl;
    }
    else{ //count is even
        int idx=0;
        int m=count/2; //we are looking for the index of the mth no. of 2 in the array
        //bug(m);
        while(m){   //m>0 also works ... or else like t--,, when m=0 then condition becomes false
            if(a[idx]==2) m--;
            idx++;
        }
        

        cout<<idx<<endl;        //we dont need to do idx+1 cause the last idx++ already does this for us 

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
