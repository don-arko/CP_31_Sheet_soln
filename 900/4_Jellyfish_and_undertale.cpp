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

We can use one tool each time the timer reaches to 1, then the answer
will be ∑ni=1min(a−1,xi)+b. This can prove to be optimal. Because for
each tool, if we use it when the timer is c, its contribution to the
answer is min(xi,a−c). We can't use the tool when the timer is less 
than or equal to 0 because the bomb will explode before that, so c=1
is the optimal.

Time complexity: O(n) per test case.

Memory complexity: O(1) per test case.



Explaination 


-Aim is to maximise the time elapsed 
This is a greedy idea , idea is to delay the use of each tool as long as possible , so that the wastage in time due to the upper bound 'a'
can be minimised and it would be optimal to use all the available tools none shall be skipped because we want to maximise the time
- Mind the usage at 1 us only to avoid the wastage due to the upper bound 'a' , if we can ensure that there is no wastage at any other c>1 we can use the tool at that c
and the time elased is again maximised only . But using c =1 is the constant greedy idea of a unit step , which could be implemented now also if xi is sufficiently large that no matter at 
what c you use xi there will be wastage then c=1 will minimise the wastage due to the upper bound . So using the tools at c=1 is the ultimate greedy tactics
eg;

a=10
c=8
then suppose a tool is xi=5
case 1 : use it at c = 8, 
        t = 8 + gain due to usage of tool
        t = 8 + 2  why two not 5 cause we should consider delta t tiggered at c=8 -> min(10,8+5)-8 = 10-8 = 2
        t = 10 secs         wastage of 3 secs cause min(10,13) is 10
         
case 2 : use it at c = 1                                                                Forumula for delta t is very simple = Tf-Ti where Tf= ti+min(a,ti+xi), and ti=c when the tool is used .. trynna imagine this graphically very simple concept this is nothing but delta t def leaned in walker physics
        t = 8 + gain due to tool 
        t = 8 + 5  here gain is 5 cause delta t triggered at c=1 is  min(10,1+5)-1 = 6 - 1 = 5
        t = 13 secs

 so the more lately I use my tool less are the changes of wastage and time will be maximised 

 also observe the formula for gain is min(a,c+xi)-c where c is the time when we use the tool 
 and this formula is equivalent to min(a-c,xi)  just subtracting a constant c from both the variables 



 so t= b(initial time on the bomb) + summation delta gain for all the tools
    t= b+ ∑gains

    where gain=min(x1,a-c)

    proof of why c=1 is the optimal time for tiggering the tools , it is evident from the mathematical formula of gain
    that the gain is maximised when c is minimised and the minimum possible value of c is 1 we cant make c=0 then bomb will explode 
    
    so t max = b + ∑gains where gain max= min(xi,a-1)
    

*/

const int N = 200005;


void solve() {
    int a,b,n;
    cin>>a>>b>>n;
    //bug(a,b,n);

    int x[n];
    for(int i=0;i<n;i++) cin>>x[i];

    int ans=b;
    for(int i=0;i<n;i++){
        int gain= min(x[i],a-1);
        ans+=gain;
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
    // cin >> t;
    while (t--) solve();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;


/*-------------------------------------------------------------------------------------------------*/
}
