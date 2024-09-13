/*

https://codeforces.com/problemset/problem/1666/D


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


Problem author: Dmitry Yakutov; problem developer: Roman Elizarov
This problem can be solved in a straightforward way. The key observation is that the order in which the
letters are called out does not matter in this game. We only need to know how many times each letter is
called out in order to go from the initial word s to the final word t.
So first, let us compute the number of occurrences of each letter from ‘A’ to ‘Z’ in both words s and t.
Let’s call them sa and ta for each letter a. Using these numbers, we can calculate how many times each
letter shall be called in order to get a chance of getting to t. That is sa − ta times for each letter a.
If sa − ta < 0 for any letter a, then the answer is “NO”.
Otherwise, there is a chance for a positive answer. However, we also need to verify that the order of
the letters in t is correct. The easy way to verify it is to simulate the game, dropping the first sa − ta
occurrences of each letter a, and then compare the result with t.
*/
const int N = 200005;


void solve() {
    
    string s,t; 
    cin>>s;
    cin>>t;
    //bug();
    //bug(s,t);
    vi f1(26),f2(26),d(26);

    //counting the frequency of each alphabet
    for(int i=0;i<s.size();i++){
        f1[s[i]-65]++;
    }

    for(int i=0;i<t.size();i++){
        f2[t[i]-65]++;
    }

    //filling the d (difference) array 

    for(int i=0;i<26;i++){
        int diff=f1[i]-f2[i];
        if(diff<0){
            cout<<"NO\n";
            return;
        }
        d[i]=diff;
    }
    //print(d);
    
    /* 
    for(int  i=0;i<26;i++){
        char ch=i+65;
        cout<<ch<<" ";
    }
    cout<<endl;

    print(f1);
    print(f2);
    print(d);

    */

    //removing the first d(difference)) occurence of each alphabet from the string s
    for(int i=0;i<s.size();i++){
        if(d[s[i]-65]>0){
            d[s[i]-65]--;   //this line should be at the very first cause s[i] changes in the next line 
            s.erase(s.begin()+i);
            i--;//to undo the effect of decresae in the size of the string         }
        }
    }
    //bug(s);
    
    (s==t)?cout<<"YES\n":cout<<"NO\n";
    


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
