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
Editorial:-

Let's note that for each second of color c in the traffic light, we need to find the rightmost green time(because time goes lift to right only), and 
then find the largest distance between color c(all such) and the nearest green from that c. 

Also, let's not forget that traffic light states are cyclical.To get rid of cyclicity, you can write the string s twice and for each cell of color c
from the first half, find the nearest green color (thus we solved the problem with cyclicity). And now we can just follow this line from right to 
left and maintain the index of the last occurrence of green. If we encounter color c, then we try to update our answer ans=max(ans,last−i), where ans
is our answer, last is the nearest time that green was on color, i — current time.

Pretty simple yet brilliant editorial.

*/



const int N = 200005;


void solve() {
    int n;cin>>n;
    char ch;cin>>ch;
    string s;cin>>s;
    s+=s; //considering s two times.
    //cout<<s;
    int last=2*n; //g always exists so this indices will for sure get updated.
    int ans=0; //the min distance between ch and g is 0 when ch=g
    for(int i=2*n-1;i>-1;i--){
        if(s[i]=='g') last =i;
        if(s[i]==ch){
            ans=max(ans,last-i);
        }
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
