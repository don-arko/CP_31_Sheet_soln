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




const int N = 200005;

/*
Concept 

POV-1
-visualise the array 'a' on graph 
-clearly if the array 'a' is non strictly increasing then all a[i] ; i>0 gets pushed into b as a[i-1]<=a[i] for all i> 0 hence a[i] gets pushed and b also looks increasing
-now suppose at some point there is a dip on the graph (it may continue for more than one point) but lets analyse for one point only, then later we shall generalise it .
-so there is dip for one point say for the point a[i] & then again the array rises i.e a[i]<= a[i+1] .
- now two cases arrise
- (i)  a[i] > a[i+1]    rise less than initial dip
- (ii) a[i] < a[i+1]    rise greater then initial dip

-in case (i)  :- b wont contain a[i](skipped) but b graph still appears increasing a[i-1]<a[i+1]
-in case (ii) :- b wont contain a[i](skipped) but here in b graph there is a dip a[i-1]>a[i+1]

- now we have two types of b in front of us 
-case (ii) b graph which shows a dip , it is sure that if there is a dip then there was an element for sure between a[i-1] and a[i+1] an hence we can always insert 1(trivial element) in between them
-case (i) b  graph no dip can also be obtained from an possible 'a' where a[i-1] and a[i+1] are consecutive elements and no a[i] was there
----and the 'a' we took initially is also an possible 'a' so for case (i) we need not do anything can we still get a possible "a"

-------------------------------------------------
POV-2 (same concept diff pov)(more refined approach)

-for any b[i] ; i>0 since it is present in b it implies that it has a smaller or equal element just before it in 'a' which made it eligible for b  

-b[i-1] was there in 'a', now 
---two cases
 i)---- if b[i-1]<= b[i] then even if there was no element between b[i-1] and b[i] in 'a' i.e. if b[i-1] and b[i] were consecutive in 'a' then also b[i-1] alone is sufficient to make b[i] eligible to be in b as b[i-1]<=b[i],(ye bhi ho sakta hain b[k] was there between them ; p<=b[i] and p <b[i-1] which made b[i] eligible for b and skipped p to enter b , so can push  such 'p' or do nothing
ii)---now if b[i-1]>b[i] , then b[i-1] is for sure, not the prev element of b[i] in 'a' cause b[i-1] doesnt make b[i] eligible for b but since b[i] is in b there was some element  p just before b[i] or between them i.e. { b[i-1] , p , b[i] } in 'a' ; p<= b[i] which made b[i] eligible for b, and also p>b[i-1] so that p is not pushed into b from 'a'



--choice of p  so that p is insertable making b[i] eligible, as well as p itself ineligible, for b
------ b[i-1] ! <= p (so that p is not pushed )=> b[i-1]>p =>  p <b[i-1]
-------and, also p<=b[i] (so that b[i] is pushed) 

 


algo1 : solve()
-- since it is only necessary to put p before such b[i] when b[i]<b[i-1] , we could only insert p before these b[i]s and we get a possible 'a'

constrint on p
--  p <  b[i-1] and
--  p <= b[i]

--here b[i] < b[i-1]

updated constraint on p 
=> p<=b[i] so taking p as min b[i] possible i.e 1  will always satify this constraint so we have a trivial solution for p which is p=1


algo2  solve1()
(extended discussion not needed but ekbar socha e tha to document kr e deta hun)
--so we could also insert p before all b[i]  ; i>0 and we will get an possible 'a';  (looks kinda more trivial solution but complication is there ), Size of the array will be 2x+1


-case(i)  :-  so in algo2 whenever  b[i] < b[i-1] inserting p=1 is ok proved in algo1 
-case(ii) :-  but inserting p before b[i]  when b[i] ! < b[i-1]  (kyu karenge kyuki ham sochre the har b[i] k age p=1 ghusa denge tobhi chalega i.e. ek possible 'a' milega)
                b[i] ! < b[i-1] => b[i]>=b[i-1] => b[i-1] <= b[i] 
                and 

                constrint on p to be insertablle between 
                --  p <  b[i-1] and ....(i)
                --  p <= b[i]       ....(ii)

                here  b[i-1] <= b[i].....(iii) 

                updated constrant on p 
                i.e  p< b[i-i]<=b[i]

                so min possible b[i-1] is 1 so for b[i-1]=1 we dont have  any valid p satisfying the constraint . 

                -if we take p=1 then for b[i-1] =1 p is also inserted into b . which would be a blunder

                so conclusion is for algo 2 : case(ii) b[i-1]<=b[i] we cannot insert p before b[i] if b[i-1] =1 , for values of b[i-1] !=1  we could insert p=1 before all b[i]
                                -- entire  case(ii) b[i-1]<=b[i] can be skipped due to which algo2 comes into picture ,,,insertion for it abosulutely not neccessary but we are discussion this case because we thorught, for b[i] we could insert p before it and solution becomes super trivial so this case(ii) comes into picture 


*/



void solve() {
    int n;
    cin>>n;
    //bug(n);
    vi b(n);
    for(int i=0;i<n;i++) cin>>b[i];
    //print(b);
    vi ans;
    ans.pb(b[0]);
    for(int i=1;i<n;i++){
        if(b[i]<b[i-1]){
            ans.pb(1);
        }
        ans.pb(b[i]);
    }
    cout<<ans.size()<<endl;

    print(ans);
}

void solve1() {
    int n;
    cin>>n;
    //bug(n);
    vi b(n);
    for(int i=0;i<n;i++) cin>>b[i];
    //print(b);
    vi ans;
    ans.pb(b[0]);
    for(int i=1;i<n;i++){
        if(b[i-1]!=1) ans.pb(1);
        ans.pb(b[i]);

    }
    cout<<ans.size()<<endl;

    print(ans);
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
    while (t--) solve1();

    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;


/*-------------------------------------------------------------------------------------------------*/
}
