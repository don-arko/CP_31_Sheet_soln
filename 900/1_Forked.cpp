/*

    https://codeforces.com/problemset/problem/1904/A
    
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

There are at most 8 positions of the knight that can attack a single cell. Therefore, we can find all 8
positions that attack the king and the 8 positions that attack the queen and count the number of positions 
that appear in both of these lists.

Explaination 

From a given square knight can attack to atmost 8 diff squares (why atmost -depending upon the  
value of a,b in some cases say when a=1 and b=1{knight move diagonally, attacks 4 sq only }, these 8 sqs are not distint some coincides hence the disnt sq on which a knight 
can attack from a single sq is <=8  ), now if I place the king or queen on the initial sq where the knight is placed 
and the kight is placed in any of these 8 sq then it attacks the king/queen .
Conclusion is a single sq can be attacked by knigt from 8 different sqs


 */

const int N = 200005;


void solve() {
    int a,b,xk,yk,xq,yq;
    cin>>a>>b;
    cin>>xk>>yk;
    cin>>xq>>yq;
    
    vector<pair<int, int>> dirs = {{a, b}, {a, -b}, {-a, b}, {-a, -b}, {b, a}, {b, -a}, {-b, a}, {-b, -a}};
   //think your knight is in the origin then on which 8 sq it can atck think that and you will get these coordinates


    set<pair<int,int>> s1,s2;//s1 stores the 8(atmost sq) from where king can be attacked and s2 does the same for queen 

    //now filling both the sets with the 8 possible points from where king and queen can be attacked respectively
    for(auto d: dirs){

        //find the atck sq for king first and then queen for each direction at a time
        int x = xk + d.first;
        int y = yk + d.second;

        s1.insert(make_pair(x,y));  //or use s1.insert({x,y});

        x = xq + d.first;
        y = yq + d.second;

        s2.insert(make_pair(x,y));  //or use s2.insert({x,y});
    }

    int ans=0;
    for(auto sq: s1){
        if(s2.find(sq)!=s2.end()){  //the sq from s1 is found in s2 => common sq found
            ans++;
        }
    }

    cout<<ans<<endl;
/*    */

    

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
