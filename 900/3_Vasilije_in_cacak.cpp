/*

https://codeforces.com/problemset/problem/1878/C

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

It is clear that the minimum sum is obtained for the numbers 1,2,3,…,k, and its value is k⋅(k+1)2 (the sum of the first k natural numbers).

Furthermore, it is evident that the maximum sum is achieved for the numbers n,n−1,n−2,…,n−k+1, and its value is n⋅(n+1)−(n−k)⋅(n−k+1)2 (the sum 
of all numbers from 1 to n minus the sum of all numbers from 1 to n−x elements).

Proof that all the sum from [Low,High] are always attainable by picking k distinct elements

Let's prove that among any k numbers (whose sum is not maximal), there exists a number a<n such that a+1 is not among those k numbers.
Let's assume the opposite, that is, there exist k numbers whose sum is not maximal, and for each of those k numbers, k+1 is also among 
those numbers. Let v be the smallest among them. Consequently, v+1 is also among these k numbers. Since v+1 is in these k numbers, then v+2
is also among these k numbers. Similarly, we can conclude that v,v+1,v+2,v+3,… are all among these k numbers. However, since we have k of them, 
these are the k numbers that would yield the maximum sum (n,n−1,n−2,…,n−k+1). This is a contradiction!

So, among any k numbers (whose sum is not maximal), there exists a number a<n such that a+1 is not among those k numbers. Based on this, starting
from the minimum sum S, we can obtain S+1 (by replacing the number a with a+1, the sum increases by 1), then from the sum S+1, we obtain the sum S+2, and so on.

Therefore, by applying the principle of mathematical induction, we can obtain any sum that is greater than or equal to minumum sum and less
than or equal to maximum sum.



Explaination 
-The bound are very cleer that the lower bound of sum is the sum of the first k natural elements and the upper bound is the sum of last k elements from 1 to n
-Later it was observed that we can always pick k elements to form all then sum from low to high by chosing k distinct elements .
- if we get a sum s by chosing k= 3 elements (a1,a2,a3) say then it was observed that s+1 is always attainable by replacing any a[i], by a[i]+1 i.e a[i] and
a[i]+1 both are not included initially within the 3 chosen elementes. This observation form the very basis the proof that all sums from low to high are formable,
after reading this line refer prood for the editorial it would be very much understandable.
----Do see the proof very very very important and beautiful.




*/


const int N = 200005;


void solve() {
    int n,k,x; 
    cin>>n>>k>>x;
    int low = k*(k+1)/2;
    int high = n*(n+1)/2-((n-k)*(n-k+1))/2;;

    //bug(low,high);

    
    (x<=high and x >= low)?cout<<"YES\n":cout<<"NO\n";
    
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
