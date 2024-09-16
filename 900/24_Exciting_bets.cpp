/*

https://codeforces.com/problemset/problem/1543/A

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



Hint 1
-GCD(a,b)=GCD(a−b,b) if a>b


Hint 2
- a−b does not change by applying any operation. However, b can be changed arbitrarily.


Editorial

If a=b, the fans can get an infinite amount of excitement, and we can achieve this by applying the first operation infinite times.
Otherwise, the maximum excitement the fans can get is g=|a−b| and the minimum number of moves required to achieve it is min(a mod g,g−a mod g).


Proof

Without loss of generality, assume a>b otherwise we can swap a and b. We know that GCD(a,b)=GCD(a−b,b). 
Notice that no matter how many times we apply any operation, the value of a−b does not change. We can 
arbitrarily change the value of b to a multiple of a−b by applying the operations. In this way, we can 
achieve a GCD equal to a−b. Now, since GCD(x,y)≤min(x,y) for any positive x and y, 
GCD(a−b,b) can never exceed a−b   (? why min(a-b,b) is a-b how ). So, we cannot achieve a higher GCD by any means.

To achieve the required GCD, we need to make b a multiple of g=a−b using as few operations as possible. There are 
two ways to do so − decrease b to the largest multiple of g less than or equal to b or increase b to the smallest 
multiple of g greater than b. The number of operations required to do so are b mod g and g−b mod g respectively.
We will obviously choose the minimum of the two. Also notice that a mod g=b mod g since a=b+g. So, it doesn't 
matter if we use either a or b to determine the minimum number of operations.



-------------------------------------------------------------
Read modular arithematic and try to understand each line of this editorial...

*/
const int N = 200005;


void solve() {
    int a,b;cin>>a>>b;
    if(a==b){
        cout<<0<<" "<<0<<endl;
        return ;
    }

    int diff=abs(a-b);  //diff is also referred as g

    b=min(a,b);

    int rem=b%diff;


    //now we gonna check which is closer largest multiple of g=abs(a-b)
    //less than or equal to b
    //or smallest multiple of g
    //greater than b base on r and diff-r

    
    cout<<diff<<" "<<min(rem,diff-rem)<<endl;





    
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
