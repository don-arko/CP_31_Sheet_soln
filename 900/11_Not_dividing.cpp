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

First, we add one to all the numbers in the array equal to 1. This uses at most n operations. Then, we iterate through the elements 
of the array from left to right, starting from the second element. At each step, let ax be the element we are iterating. If ax is 
divisible by ax−1, we add one to ax. Now this element is not divisible by ax−1, because otherwise both ax and ax+1 are divisible by ax−1, but 
that means 1 is also divisible by ax−1 which cannot happen since all the elements in the array are at least 2 (because of the first step we did). 
This part also uses at most n operations, so we used at most 2n operations in total. The resulting array will satisfy the statement property.

Intended complexity: O(n) per test case.

Explaination :-

Constructive Algo
-In first step : we convert all 1 to 2 in atmost n ops cause there can be atmost n ones in the array because 1 is a trivial element divides all
-In second step : whenever a[i] is divisible by a[i-1] we do a[i]+=1 now a[i]->a[i]+1 mow a[i]+1 is not divisible by a[i-1] cause two consecutive nos are only divisible by 1 
and a[i-1] is not 1 because as per first step the min value of the array is 2 hence a[i-1]!=1 and can't divide a[i]and a[i]+1 simultaneouslyt since it is not 1 .
-
*/


const int N = 200005;


void solve() {
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];

    for(auto &x : a){
        if(x==1) x++;
    }
    for(int i=1;i<n;i++){
        if(a[i]%a[i-1]==0){
            a[i]++;
        }
    }

    print(a);

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
