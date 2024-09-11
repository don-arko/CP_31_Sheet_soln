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

Let the number of buses with two axles is x and the number of buses with three axles is y. Then the equality 4x+6y=n (4 wheels bus and 6 wheels bus ) must be true. If n
is odd, there is no answer, because the left part of the equality is always even. Now we can divide each part of the equality by two: 2x+3y=n/2=n'(say or axle).

Let's maximize the number of buses. Then we should make x as large as possible. So, we will get 2+…+2+2=axle if axle is even, and 2+…+2+3=axle otherwise. 
In both cases the number of buses (x+y),is ⌊axle/2⌋.   Case 1 : x=axle/2   y = 0   Case 2 : x = ⌊axle/2⌋-1   y=1  in both case x+y= ⌊axle/2⌋.

Now let's minimize the number of buses. So, we should make y as large is possible. We will get 
                                                x      y          x+y
3+…+3+3+3=axle,if axle is divisible by 3,       0   axle/3       axle/3
3+…+3+3+2|=axle if n≡2(mod3), and               1   ⌈axle/3⌉-1    ⌈axle/3⌉
3+…+3+2+2|=axle if n≡1(mod3).                   2   ⌈axle/3⌉-2    ⌈axle/3⌉
         | 
        till this point it is ⌈axle/3⌉ then suitably minus 1 or 2 based on much less 3s u r using
        
In all cases the number of buses is ⌈axle/3⌉.

Also don't forget the case axle<2 or n<4 — each bus has at least four wheels, so in this case there is no answer.

Time complexity: O(1).

*/


const int N = 200005;


void solve() {
    int n;cin>>n;
    if(n<4 or n%2==1){  
        cout<<-1<<endl;
        return;
    }   

    int axle=n/2 ; //mind axle could be both odd or even

    int max_b= axle/2;
    int min_b;    //min_b is ceil of (axle/3) but there is some implementation details with ceil which i dont know hence facing problem esliye float bina use kare if and else se hi ceil ko  implement kr diya

    (axle%3==0)?min_b=axle/3:min_b=axle/3+1;

    cout<<min_b<<" "<<max_b<<endl;



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
