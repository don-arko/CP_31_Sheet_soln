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

Let's look at the first and the last characters of s. Note that if s1=sn (where n=|s|), then AB(s) is always equal to BA(s).

It can be proved, for example, by induction: if s consists of equal characters then AB(s)=BA(s)=0; if s has a structure 
like abb...ba (or baa...ab) then AB(s)=BA(s)=1.

Otherwise, there is at least one character si in the middle that equal to s1 and sn. So we can split string s in s[1..i]
and s[i..n]. Both these string has AB=BA (by induction), so our string s also has AB(s)=BA(s).

As a result, if s1=sn then the answer is 0, and we print the string untouched. Otherwise, we replace either s1
or sn and get the desired string.

(It also can be proved that if s1≠sn then AB(s)≠BA(s))

---------------------------------------------------------------------------------------------------------------------------------------------------
Observation 
It is observed that whenever s[0]=s[n-1] AB(s) = BA(s)  or BA(s) = AB(s)
                                         _        _        _        _     these underscores shall help to get the observation

eg 
a_a   :- now no matter what u put in between AB(S) will always be equal to BA(S) if put b
     a b a 
     ___     AB(s)=1
      ____   BA(s)=1

     a a a 
     ___     AB(s)=0
      ____   BA(s)=0


This observation can also be proved  read the editorial for the proof

So when s[0] is equal to s[n-1] then Always AB(s)==BA(s) so we keep s unchanged 
else we make s[0] equal to s[n-1] in one operation 
      


*/

const int N = 200005;


void solve() {
    string s; cin>>s;
    if(s[0]!=s[s.size()-1]){
        if(s[0]=='a') s[0]='b';
        else s[0]='a';
    }
    cout<<s<<endl;
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
