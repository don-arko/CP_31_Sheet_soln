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

-Lets select the collection of integer S such that it doesnt have 0 in it , i.e. it has elements from 1 onwards
then max(S)=0 (smallest non negatve integer not present in S)

-Kinda we need to find the no. of segments which are devoid of zero i.e. count the no. of non zero segments
-basically 0 kinda acts as partition

eg 1
7
0 2 3 0 1 2 0
  ---   --
   1     2          so basically two swaps are needed

eg 2
7
0 2 3 0 1 2 0 2 3
  ---   --    ---
   1     2     3     so basically three swaps are needed
-----------------------------------------------------------------

Unfortunately there is a better trivial way than this 


actually atmost only 2 ops are req to make all the array elements as zero
--here we can always select all the elements l=1, r=n i.e. [1,n] and then
     if it doesnt have a 0 then w=mex(s)=0 and in 1 op the array could be reduced into zero
    

     else if it has zero in it then in one op entire array would be converted into a non zero value and then in the second op the entire array could be converted into 0.
     eg:2
     7
     0 2 3 0 1 2 0 2 3
     l               r    w1=mex(S)=4

    op1:-   4 4 4 4 4 4 4   w2=mex(S1)=0
    op2:-   0 0 0 0 0 0 0

The first method is a subcase of method 2 for no. of ops <=2, i.e. for no. non zero subsequences less than equal to 2 both the
methods give same result but after that method 1 doesnt work optimally, main point is the method one in any case is not more optimal 
than method 2 i.e. for no. of ops <=2 method 1 is not more optimal matlab kabhi aisa nei hoga ki for ops <=2 method 1 ka ans 1 hain 
while method 2 ka ans 2 hain


------------x---------------x----------Discussions till here are very vague and non accurate just 
noted the thought process for the sake of noting focus on the editorial



Editorial (Precise and accurate)


The answer is at most 2, because doing the operation on [1,n] at most twice will always work. (If the array contains at least one zero, we need 2
operations. Otherwise we need 1 operation.)

-If the array consists of zeroes, the answer is 0.

-If all non-zero elements form a contiguous segment in the array, the answer is 1. To check this, you can find the leftmost and rightmost occurrence
 of non-zero elements and check if elements in the middle of them are also non-zero.

-Otherwise the answer is 2.

Time complexity is O(n).


*/

const int N = 200005;
int a[N];
//non zero  tester
bool test(int l, int r){
    for(int i=l+1;i<r;i++){
        if (a[i]==0) return false;
    }
    return true;
}

void solve() {
    int n;cin>>n;
    
    for(int i=0;i<n;i++) cin>>a[i];

    int count=0;
    
    for(int i=0;i<n;i++){
        if(a[i]==0) count++;
    }
    //bug(count);
    //case 1
    if(count==n){    //all elements are already zero
        cout<<0<<endl;
        return;
    }
    //case 2 : if a single contigous segment of non zero elements is present then ans is 1.
    // eg 00045458700
        //finding l
    int l;
    for(int i=0;i<n;i++){
        if(a[i]!=0){
            l=i;
            break;
        }
    }
      //finding r
    int r;
    for(int i=n-1;i>=0;i--){
        if(a[i]!=0){
            r=i;
            break;
        }
    }


    (test(l,r))?cout<<1<<endl:cout<<2<<endl;    //if true then case 2 else case 3





        
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
