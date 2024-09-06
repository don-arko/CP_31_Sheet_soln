/*

https://codeforces.com/contest/1883/problem/B

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

Let's remember under what conditions we can rearrange the letters of a word to form a palindrome. 
This can be done if the number of letters with odd occurrences is not greater than 1 .

In our problem, it is sufficient to check that the number of letters with odd occurrences (denoted as x
) is not greater than k+1. Let's prove this fact.

If x>k+1, then it is definitely impossible to obtain the answer, because with k operations we cannot make 
the number of letters with odd occurrences not greater than 1. On the other hand, we can simply remove the 
character with an odd number of occurrences on each removal iteration and decrease the number of odd occurrences. 
If there are no such characters, we can choose any character and remove it, thus having 1 character with an odd occurrence


 Explaination

Let's remember under what conditions we can rearrange the letters of a word to form a palindrome. 
This can be done if the number of letters with odd occurrences is not greater than 1.
  because all the disntict chars should have even frequencies so that they could be distributed 
  into two halves in order to form the palindrome and we could have only 1 or 0 elements whose frequency is odd.

Now is the no. of disntint element with odd frequency is say x, our aim is to convert this no. i.e. x=0 or 1 in k ops
or after removing k chars so that they can be rearranged into a palindrome . Now in 1 op or after one char removal we can 
now make the the no of distinct char with odd occurence as x-1, cause suppose there where 3 disntict element a x3, b x5 , c x3
, all of them have odd frequency , so in one operation or after one char removal we can remove 1 c say n now c has even frequency so 
no. of distinct element with odd frequency as two.
 Conclusion is when we have x as the no. of distinct element with odd frequency and k total removals available then we can convert k
 distinct elements with odd frequency into even frequency .


Now , finally x should be atmost 1 so that palindromic re-arrangement is possible i.e. x<=1 finally after k removals 
now x f = x i -k <=1 i.e. x-k<=1 or x <= k+1 for palindromic re-arrangement to be possible or  else it is not possible 





*/


const int N = 200005;


void solve() {
    int n,k ; 
    cin>>n>>k;
    string s;
    cin>>s;
    int a[26]={};   //initialising the freq array with all frequency as 0
    //bug(n,k,s);
    for(auto x: s){
        a[x-97]++;      //a is 97 and z is 122 so x-97 make them suitable for indices 0-25;
    }

    int odd_count=0;
    for(auto x : a){
        if(x%2!=0){
            odd_count++;
        }   
    }

    odd_count<=k+1?cout<<"YES\n":cout<<"NO\n";

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
