/*

https://codeforces.com/contest/1537/problem/B


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
We can notice that the optimal strategy is to put the yoyos in the corners of the board. One solution 
may be checking the best distance for all pairs of corners. But, if we think a bit more, we can notice 
that placing the yoyos in opposite corners the distance will always be maximum possible (the distance 
always being 2⋅(n−1)+2⋅(m−1)). So, one possible answer is to always place the first yoyo in the top-left
cell and the second one in the bottom-right cell. This is always optimal because, for any initial
position of Anton, the distance will still be the same (2⋅(n−1)+2⋅(m−1)), this being the largest
possible distance. The distance can not get larger than that, because if we move one of the yoyos it
will get closer to the other yoyo and the distance will decrease by 1 or won't decrease, but it's 
impossible for it to increase.
          y  (j-1)
          __________
          |        |
          |   (n-i)|    (m-j)
       |  |       i,j--------------|
       n  |                        |
          |                        |(i-1)
    (n-1) |                        |
          |                        |
  (1,1)  ------------------------> m   x
                    (m-1)
Explaination

-for visualisation watch the youtube video cp31 solutions
-from (i,j) we first try to find out the most distant point to i,j for that we try to 
     move max horizontal dist(along x) i.e. max(i-1,m-i) = m-i say i.e. we move right , then
     then we cover the max vertical dist i.e. max(i-1,n-i)= i-1 say i.e. we move down , so here the 
     first distanct yoyo is at bottom right corner,
-from bottom right corner the farther point is 1,1 at a distance of (m-1)+(n-1) {since we cant move diagonally} 
- overall distance covered is (m-1)+(n-1) + (m-j)+(i-1)+(j-1)+(n-i)= (n-1)+(m-1)+ (m-1)+(n-1) = 2(n-1)+2(m-1)



Now it is always optimal to put the two yoyos at the opposite corners so the that path is maximum and is actually indipendent of the initial position of Anton
cause the total distant is always goin to be 2 (m-1) + 2 (n-1) which is the maximum distance = one circle of the grid ... i.e. basically when we place the two yoyos
at the opposite corners the total distance covered is max cause it is equal to the distance covered in one complete trip along the edges = 2(m-1)+2(n-1).



*/

const int N = 200005;


void solve() {
    int n,m,i,j;cin>>n>>m>>i>>j;
    cout<<"1 1 "<<n<<" "<<m<<endl;

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
