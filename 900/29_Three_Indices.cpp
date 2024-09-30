/*

https://codeforces.com/problemset/problem/1380/A

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
There are three approaches in total.

First:- Most Eficient one O(n)
 
Since this array is a permutation , all the elements are distinct so for all i the relation between a[i] and a[i+1] is
1.a[i]<a[i+1]
2.a[i]>a[i+1] 
these are the only two possibilies

while going from i=0 -> i<n-1 if only relation 1 occurs than array is strictly increasing and if only 2 occurs array is stricly decreasing.

If peak element exists in the array i.e. for  i<j<k in the array a[i]<a[j] and a[j]>a[k]
My claim is : if peak exists then always one such i,j,k exist which are consecutive 
(non consecutive i,j,k may or may not exist but existence of consecutive i,j,k is more fundamental just 
visualise the peak as mountain range you would realise the fact).Proof is if at any i peak exists 
then a[i-1] < a[i] and a[i]>a[i+1](from visualisation of peak)  . So i=i-1, j=i and k=i+1 are consecutive

So look for such i ; a[i-1]<a[i] and a[i]>a[i+1] and the i is out ans.




Second Approach :- Prefix Min array and Suffix max aray


Bad Me jururat parein to youtube video dekhke sikh lena



Third Aprroach: 2 nested for loop 

Useless just brute force appraoch

*/


const int N = 200005;


void solve1() {
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    for(int i=1;i<n-1;i++){
        if(a[i-1]<a[i] and a[i]>a[i+1]){
            cout<<"YES\n";
            cout<<i<<" "<<i+1<<" "<<i+2<<endl;      //ans should be in 1 based indexing 
            return;
        }
    }
    cout<<"NO\n";
}

void solve2(){
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
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
