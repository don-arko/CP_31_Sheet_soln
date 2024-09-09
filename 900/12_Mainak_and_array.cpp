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

There are four candidates of the maximum value of an−a1 achievable, each of which can be found in O(n)time.

--No subarray is chosen: Answer would be an−a1 in this case.

-Chosen subarray contains an and a1 : Answer would be maxi=1n{a(i−1)−ai} where a0 is same as an (notice that the previous case is included in this case as well).

-Chosen subarray doesn't contain an : Answer would be maxi=1n−1{an−ai}.

-Chosen subarray doesn't contain a1 : Answer would be maxi=2n{ai−a1}.

Finally we report the maximum of all of these four values in total time O(n).

---first of all q aur editorial anubhav ka hai

--Q is kinda twelve ka probality combinotorics type  ans=max(Ans1,Ans2,Ans3,Ans4)

----------------------------------------------------------
Implementation trick 

cyclic traversal

idx = (idx+1)%n    anticlockwise
idx = (idx-1+n)%n  cloackwise 

learnt from "Competitive Programming 4 book"
-----------------------------------------------------------------


Also in case 2 we need to check for all distinct consecutive a[i] and a[i+1] pairs that we can encounter in cyclic traversal  and actually a[1] is on the right of a[n] .


|a1 a2 a3...an a1 | a2 a3 ... the elements with |.| covers all distinct consecutive pairs in cyclic traversal , from a2 onwards the pairs start repeating
    
    in implementation we gonna use 0 based indexing

*/

const int N = 200005;


void solve() {
    int n;cin>>n;
    
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //case 1 and case 2 as c1 is a subcase of c2
    //case 2 when a1 and an are in the subaraay to be rotated .. this means a1 and an are consecutive elements(why consecutive because they are in the same subarray so their relative position cant be changed so is they are in the same subarray then only two consecutive pairs can make an and a1 cause they are consecutive when looked from cyclic traversal perspective)
      //where an will be on the left and a1 on the right for any pair considered so possible an-a0 will be
       // a[i]-a[i+1] or a[i-1]-a[i] lets use the former
            //so here possible ans = max(a[i]-a[i+1]) and i is from 0 to n-1 (0 based indexing) so that a[i+1] goes to a[n]= an+1 or a1 (cycle) (1 based indexing)


    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        ans=max(ans,a[i]-a[(i+1)%n]);   //when i+1 = n they modulo will make it 0
    }

    //case 3 : subarray doesnt have an so here ans = max(an-a[i]) and i goes from 1-n-1 or in 0 based indexing 0->n-2
    for(int i=0;i<n-1;i++){
        ans=max(a[n-1]-a[i],ans);
    }


    //case 4: subarray doesnt have a0 so here ans= max(a[i]-a1)
    for(int i=1;i<n;i++){
        ans=max(ans,a[i]-a[0]);
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
