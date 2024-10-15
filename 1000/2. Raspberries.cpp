/*

https://codeforces.com/problemset/problem/1883/C

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
//modular Arithematic: 
m*k <= a[i] <= (m+1)*k ; d1=a[i]-mk and d2 = (m+1)*k -a[i]
- d1=a[i]%k gives d1: distance of a[i] from the largest multiple of k    ;  m*k <= a[i]
- d2=(k-a[i]%k)%k  gives d2:  distance of a[i] from the smallest multiple of k ; a[i] <= (m+1)*k

Explaination of ()%k in d2:
a[i]%k belongs to [0,k-1]  {Think of clock} 
so k - a[i]%k belongs to [1,k] so when d2=0 our formula d2= k - a[i]%k gives k as the distance hence we should again do this %k to get the accurate distance which is 0


Editorial:-

Let's notice that if k=2,3,5, since these are prime numbers, the product of the numbers will be divisible by k
 if any number in the array is divisible by k. From this, we can conclude that it is advantageous to perform operations only on one number.

If k=4, we have several cases, and we need to take the minimum among them. Again, we can perform operations on one number 
and make it divisible by 4, or we need to perform operations such that there are two even numbers in the array 
(there is a special case when n=1). To have two even numbers, let's count the number of even numbers in the original array as cnt, and
if 2≤n, we can say that the answer is max(0,2−cnt).







My explaination : As per the operation we can only increase a[i] by 1 at each operation.
Case-1 : k!=4
k=2,3,5 are prime so for the product of a[i]s to be multiple of k , any of the a[i] has to become multiple of k, 
because k= prime means , it cant be further decomposed which means, in the product of a[i]s , k cannot 
be formed by any two or more a[i]s merged together so for the product to be divisible by k , it should directly  have k  avaiable as one of the a[i]s , 
then the products of a[i]s look like k*something which is divisible by k.

In this case, since a[i]s can only be increased we find all the distances between a[i] and the smallest multiple of k >= a[i] which is k-a[i]%k
then we consider the minimum among them that shall be out ans.

Case -2 : K = 4 :
    here have several cases because making a[i]=k is not he only way to make product of a[i]s divisible by k, we shall find the ans for all the cases and consider minimum of all of them.
    i) the min distance between a[i] and smallest multiple of k <=a[i] (ans1)
    or
    ii)  As k=4=2*2(further decomposable , so for divisibility by k;  we can need two 2s or more generally two even nos)
            a) when n(even)=>2 then here ans2 = 0 (already divisible by 4) so final ans = min(ans2=0,ans1)| ans=0 because ans2=0 and the minimum possible value of ans 1 is 0 when an a[i] is already a multiple of k 
            or
            b)when n(even)=1 then here ans2=1(ek odd no. ko 1 increase kro then even count 2 ho jayega which means product divisible by 4) here ans=min(2,ans1) ans 1 can be zero when any a[i] already of the form
            or 
            c)when n(even)=2 then here ans2=2(do odd number ko ek ek increase kro ans no. of ops=2 to make two even nos ) here ans=min(2,ans1) ans1 minimum value is 0 when a[i]=4m



*/
const int N = 200005;


void solve() {
    int n,k;cin>>n>>k;
    int ans=k-1; //the maximum distance between a[i] and the smallest multiple of k >=a[i] is k-1 : imagine the modular arthematic clock 0-(k-1)
    int e_cnt=0;
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        //bug(temp);
        if(!(temp&1)) {
            //bug(temp);
            e_cnt++;
        }
        int d=(k-temp%k)%k;
        //bug(d);
        ans=min(ans,d);

    }


    if(k!=4){
        cout<<ans<<endl;
    }
    else{//we make make the product divisible by k in other method too, what if they require less operations
        //
        int ans2;   
        if(e_cnt>=2){
            ans2=0;
        }
        else if(e_cnt==1){
            ans2=1;
        }
        else{ //e_cnt=0;
            //cout<<"here\n";
            ans2=2;
        }
        //bug(ans2,e_cnt);
        ans=min(ans2,ans);
        cout<<ans<<endl;
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
