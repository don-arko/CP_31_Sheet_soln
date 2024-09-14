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
This question is basically the sum of the series 

Observation 

Case-I : when xo is even

TYPE   :     T1    T2    T3        T4          T1          T2       T3        T4          T1        T2         T3     T4
Series       x0   -1     +2        +3      |  - 4          -5       +6        +7     |    -8        -9        +10    +11
steps(n):    0     1      2         3      |    4           5        6         7     |     8         9         10     11
-------------------------------------------|-----------------------------------------|-----------------------------------
sum:         x0  x0-1  x0-1+2     x0+1+3   |  x0+4-4       x0-5    x0-5+6    x0+1+7  |   x0+8-8     x0-9    x0-9+10  x0+1+12
                       =x0+1      =x0+4    |   =x0                 =x0+1      =x0+8  |   =x0                 =x0+1   =x0+12

  
Δx_e:        0     -1     1          4           0          -5       1         8           0         -9        1       12
n:           0      1     2          3           4           5       6         7           8          9        10      11
n%4 :        0      1     2          3           0           1       2         3           0          1         2       3

Δx_e in   
terms of :   0     -n     1          n+1   |     0          -n       1         n+1   |     0          -n        1       n+1                             
n

Form:  
T1 : 4K+0
T2 : 4K+1
T3 : 4k+2
T4 : 4K+3

Case - II : when x0 is odd

here sum looks like 


TYPE   :     T1    T2    T3        T4          T1          T2       T3        T4          T1        T2         T3     T4
Series       x0   +1     -2        -3      |  + 4          +5       -6        -7     |    +8        +9        -10    -11
steps(n):    0     1      2         3      |    4           5        6         7     |     8         9         10     11
-------------------------------------------|-----------------------------------------|-----------------------------------
sum:         x0  x0+1  x0+1-2     x0-1-3   |  x0-4+4       x0+5    x0+5-6    x0-1-7  |   x0-8+8     x0+9    x0+9-10  x0--1-11
                       =x0-1      =x0-4    |   =x0                 =x0-1      =x0-8  |   =x0                 =x0-1   =x0-12

                                            
Δx_o:        0      1    -1         -4           0           5      -1        -8           0          9        -1     -12       |observation Δx_o = - Δx_e
n:           0      1     2          3           4           5       6         7           8          9        10      11
n%4 :        0      1     2          3           0           1       2         3           0          1         2       3

Δx_o in   
terms of :   0      n     1        -(n+1)   |    0           n       1        -(n+1)   |    0         n          1    -(n+1)                            
n

-----------------------------------------------------------------------------------------------------------------------------------------------------------

Conclusion

sum =   | x0+Δx_e                            when x0 is even
        | x0+Δx_o  = x0+(-Δx_e)              when x0 is odd
        
In the below used Implementation 
  D=Δx_e

so ans is x0+D when x0 is even or else x0-D

and 
Δx_e is 


imagine the firt 4 jumps

      Table

      
n%4     Δx_e    Δx_0=-Δx_e

 1      -n          n
 2       1         -1
 3      n+1        -(n+1)
 0       0          0


 =====================X=================================X=============================X========================Now Read the editorial

Editorial


 Consider the first four actions that the grasshopper will perform, starting at a point with coordinate 0:

coordinate 0 is even, jumping left to 1 leads to −1
coordinate −1 is odd, jumping right to 2 leads to 1
coordinate 1 is odd, jumping right to 3 leads to 4
coordinate 4 is even, jumping left to 4 leads to 0


If you look closely at the next four jumps, they follow the same pattern: jump to the left, two jumps to the right, jump to the left. 
In general, making jumps with numbers 4k+1…4k+4, the grasshopper will start from coordinate 0 and move as

                                  0-------⟶ −(4k+1)--------⟶ 1------------⟶ 4k+4----------------------⟶ 0
steps(n) in modulo form       :     −(4k+1)           +(4k+2)       +(4k+3)              -(4k+4)
          in terms of n      =>   0---------> -(n) -----------> 1 ---------->(4k+3+1)---------------------->0                       
                                                                                =n+1
Thus, if x0 were always zero, the answer would be
−n if n≡1mod4
1 if n≡2mod4
n+1 if n≡3mod4
0 if n is divisible by 4


Let's find an answer for the cases when x0≠0. But if x0 is even, then all steps will follow the same 
directions, and the answer will be x0+D, where D is the answer for the same n and starting point 0 (described above). And if x0
 is odd, then all steps will have opposite directions, and the answer will be x0−D.


*/

const int N = 200005;

bool odd_(int n){
    return n%2;     //0 is treated a false and non zero value is treated as true
}


void solve() {
    int xo ,n ; cin>>xo>>n;
    int eq_c=n%4;
    int ans;
    
    if(eq_c==1){
        int D=-n;
        (odd_(xo))?ans=xo-D:ans=xo+D;
    }
    else if(eq_c==2){
        int D=1;
        (odd_(xo))?ans=xo-D:ans=xo+D;
    }
    else if(eq_c==3){
        int D=n+1;
        (odd_(xo))?ans=xo-D:ans=xo+D;
    }
    else if(eq_c==0){
        int D=0;
        (odd_(xo))?ans=xo-D:ans=xo+D;
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
