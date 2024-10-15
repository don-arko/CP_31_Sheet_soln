/*
https://codeforces.com/problemset/problem/1913/B

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
Editorial  (Brilliant )

Let's count the number of 0-s and 1-s in s as cnt0 and cnt1 correspondingly. Since t consists of characters from s then t will contain no more than cnt0 zeros and cnt1 ones.
Let's build t greedily, since we always compare t with prefix of s(cause t s k equal ya chota hain length me). Suppose the length of t is at least one, it means that t1 must be different from s1, so if s1 = 0 we must set t1 = 1. 
So let's check that we have at least one 1 (or cnt1>0), take 1 and place it at t1. Case s1 = 1 is the same.After placing t1 we can analogically try to place t2 and so on until we run 
out of necessary digits or build the whole string of length |s|.
We've built the longest possible string t in O(|s|) time, so the answer is |s|−|t|.


My Explaination:- Read the editorial (self explainatory) and question carefully especially the mathematical part wherein t is good is defined. if t[i] != s[i] for i <- [1,|t|] why this |t| , cause always |t|<=|s| due to the type of operation we 
will be performing. And why |s|-|t| is the ans cause, it is equal to the number of chars deleted from s each of which costed one coin. 
*/

 
const int N = 200005;


void solve() {
    string s;cin>>s;
    //bug(s);
    int count_0=0;
    int count_1=0;
    for(auto x : s){
        if(x=='0') count_0++;
        else count_1++;
    }
    //bug(count_0,count_1);
    int t=0;
    for(auto x: s){
        if(x=='0'){
            if( count_1>0) {
                count_1--;
                t++;
            }
            else{
                break;
            }
        }
        else{
            if(count_0>0){
                count_0--;
                t++;
            }else{
                break;
            }
        }
    }
    cout<<s.size()-t<<endl;

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
