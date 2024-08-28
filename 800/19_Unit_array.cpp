/*

https://codeforces.com/problemset/problem/1834/A

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
CONCEPT
-Clearly observed input array elements are either 1 or -1 . hence named unit array

- so to make the first condition hold .
- we need to make no. of +1 >= no of -1 
- and to make their multiplication result as even we need to have even no. of -1s

- observation whenever we perform one operation
Multiplication :- sign changes 
SUM
- -ve->+ve then Sumf=sumi+2
- +ve->-ve then Sumf=Sumi-2
- 
-Idea is first check and make(-ve to +ve) sum>=0 then check and make multi=1 by changing nos such that sum increases only (-ve to +ve)
    
    -A very strong intution is the first process P1 of making sum >=0 is operationwise is mutually exlusive of P2 making Multi =1 i.e. while doing ops
    of P1 some common of P2 can't be done and vice versa so dont think ki such type of minimisation could exist below line depicts the situation 

    
    and shall make this intution more concrete
    -As ops of P1 Happens sign of Multi alternates . after performing all ops (=op1 say) of P1 if Multi =1 then no further ops are req or else
    one more op is req
*/

void solve() {
    int n;
    cin>>n;
    int c_1=0,c_m1=0;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        if(temp==1) c_1++;
        else c_m1++;
    }

   // bug(c_1,c_m1);

    if(c_1>=c_m1){
        if(c_m1%2!=0){  //Multi=-1
        //only one ops req to change the sign from -ve to +ve which will iincrease the sum 
            cout<<1<<endl;
        }
        else{   //Multi =1
        // no ops are req
            cout<<0<<endl;            
        }
        
    }
    else{
        //sum is negative 
        // we shall change from -ve to +ve to increase the sum 
        int diff=c_m1-c_1;
        //ops to make it non negative
        //  ops = | diff/2   ; diff is even  here sumF becomes =0
        //        | diff/2+1 ; diff is odd   here sumF becomes >0
        int op1;
        if(diff%2==0) op1=diff/2;
        else op1=diff/2+1;

        c_1+=op1;
        c_m1-=op1;
        if(c_m1%2!=0){  //another op req to change the sign which also increase sum
            cout<<op1+1<<endl;
        }
        else{
            cout<<op1<<endl;
        }
    }

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
