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

Suppose there is a segment of length k that consists of equal characters in s. This segment implies that there are at least k+1 distinct 
values in the answer: for example, if the segment consists of < signs, the first element should be less than the second element, the second
element should be less than the third element, and so on, so the corresponding segment of the array a contains at least k+1 different elements.

So, the answer is at least m+1, where m is the length of the longest segment of the string that consists of equal characters. Can we construct 
the array a which will contain exactly m+1 distinct values? It turns out we can do it with the following greedy algorithm: let's use integers from 0
 to m (m+1 distinct element )for our array a, and let's construct it from left to right; every time we place an element, we choose either the largest possible integer 0
 we can use (if the next character is >) or the smallest possible integer 0 we can use (if the next character is <). For example, for the 
 string <><<<>, the first 6 elements of the array will be [0,3,0,1,2,3] (and we can use any integer from 0 to 2 in the last position). 
 That way, whenever a segment of equal characters begins, the current value in the array will be either m or 0, and we will be able to
 decrease or increase it m times, so we won't arrive at a situation where, for example, the current value is 0 and we have to find a smaller integer. i.e. always we see 
 we wont be able to use more distinct integes then the m+1 we have chosen so using atleast m+1 distinct integers converges to exactly m+1 distinct integers

So, the problem basically reduces to finding the longest contiguous subsegment of equal characters in s
.
Beautiful editorial

*/
const int N = 200005;


void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    //bug(n,s);

    int count=1;
    int maxx=INT_MIN;
    //counting the largest segment with equal chars

    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            count++;
        }
        else{
            maxx=max(maxx,count);
            count=1;
        }
    }
    maxx=max(maxx,count);

    int ans=maxx+1;

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
