/*

https://codeforces.com/contest/1857/problem/A

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




const int N = 200005;
/*

Editorial

Let's analyze the impact of adding odd or even numbers to a set with sum S:
If you add an even element to the set, the parity of S remains unchanged.
If you add an odd element to the set, the parity of S changes.


Based on this observation, let's focus on the coloring of odd elements in the array. The number of odd elements 
colored in blue and the number of odd elements colored in red must have the same parity for a valid coloring. This is because 
we need to divide the odd elements into two parts (blue and red). 

-To achieve the same parity for both blue and red odd elements, the total number of odd elements in the array must be even. If it is not even, we won't be able to create two sets with the same parity.

-Hence, the answer is "YES" if the number of odd elements in the array is even, and "NO" otherwise.


===========================================================================================================================================================================================================================================================================

- Its only the odd number that changes the parity of a seq with sum .
- So lets leave even nos and focus only on odd numbers .The number of odd elements colored in blue and the number of 
odd elements colored in red must have the same parity for a valid coloring. This is because we need to divide the odd 
elements into two parts (blue and red) , and even numbers are useless cause they do not contribute to any parity change.

-Initally both the arrays are empty i.e. sum = 0 i.e. even .
-Now say all even elements are added into first array its parity is unchanged(hence we were not concerned with even nos). 
-Now we need to divide the odd nos into these two arrays such the the parity of inddividual sum of both is same 
-Whenver a odd element is added to any of the arrar parity of its sum changes 
-So in order to keep the parity same for both the array we must add same or equal number of odd elements on both the arrays 
=> this will be possible when no. of odd elements initially present is even so that div by 2 and hence equal no. of odd elements could be distributed between both the arrays

-Hence, the answer is "YES" if the number of odd elements in the array is even, and "NO" otherwise.




*/
bool is_odd(int n){
    return n%2==1;
}
void solve() {
    int n;
    cin>>n;
    int m_o_count=0;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(is_odd(temp)) m_o_count++;
    }
    
    is_odd(m_o_count)?cout<<"NO\n":cout<<"YES\n";

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
