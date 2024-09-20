
/*

https://codeforces.com/problemset/problem/1374/B

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

If the number consists of other primes than 2 and 3 then the answer is -1. Otherwise, let cnt2 be the 
number of twos in the factorization of n and cnt3 be the number of threes in the factorization of n. 
If cnt2>cnt3 then the answer is -1 because we can't get rid of all twos. Otherwise, the answer is 
cnt3−cnt2)+cnt3.

Time complexity: O(logn).

----------------------------------------------------------------------------------------------------------

The editorial is just perfect , now let me groove in the idea in my blood with this explaination,

If the number consists of other primes than 2 and 3 then the answer is -1 :- We are dividing by 6 when divisible, 
                                                                             else multiplying by 2 with a hope that
the number becomes divisible after the multiplication. Now the primes which make up 6 are 2 and 3 , so for getting divisible by 6 ,
the prime factorisation of n should have only  2 and 3 and their count should be also be equal , i.e. n=(2^k1) *  (3^k2) ; k1=k2 .
The main claim of this  sentence is if there are other factors then 2 and 3 in the prime factorisation of n , then, we can never reach 
to 1 from n by dividing by 6, eg n = 180 =  36*5 = 2^2 * 3^2 * 5 , so if we divide n by 6 , two times , each time exactly one 2 and one 3 gets exhausted,
reducing n to n/6^2=180/6^2=180/36=5 and no matter what we do this five can never be reduces to 1 by dividing 5 by 6 or multiplying 5 by 2^m never makes it divisible by 
6 cause we need 3 (and 2 only for making it exacly divisible by 6 )  any other primes shall always remain as residue at the end.
so the primes factorisation of n should not contain any other primes other than , 2 and 3. A little confusion remains on k1 and k2 i.e. count of 2 and 3 respectively.
will discuss that but if there is/are other primes, than ofc this division is never gonna reach 1.

Here by divisible I mean divisble till n becomes 1 , residue = 1.

Main Point is to be divisible by 6 it needs only and only two primes 2 and 3 and no other prime should be there and morover their count should be exactly equal. 
In the question 2 can be additionally provided so ,so if the primefactorisation of n has only 2 and 3 , and their frequencies are unequal , then only when 
frequency of 2 is less than 3 , only this condition can be managed , kudos the the supply of 2s which could make the frequencies equal and make n divisible by 
6 till 1.



Now to be exactly divisible 6, k no. of times, the primes factorisation of n should only have 2 and 3 and moreover k1=k2=k i.e. if k1 != k2 then also n is not exatly 
divisble by 6, cause if k1> k2 then at the end n becomes 2^(k1-k2) which is not divisible by 6 and again if k2>k1 then at the end n becomes 3^(k2-k1) which is again not
divisible by 6 , but here in this question the catch is , when the count of nos of 2s is deficit  i.e. k1 < k2 then we could increase that since it we can multiply n by 2
when not divisible by 6. so k1>k2 is not allowed , i.e. excess 2s not allowed since we cant supply 3s to makeup for the excess 2s and make k1=k2 but k1<k2 is allowed cause we can supply
2s to increase k1 and make it equal to k2.

So in this subcase, let the algorithm , be we first supply the dificit no. of twos i.e. we multiple by (k2-k1) no. of twos (moves=k2-k2)
to make k1+(k2-k1)=k2=k(say) so that n becomes and exact power of k i.e. n = 2^k * 3^ k (cause k1' = k2 = k now)= 6^k i.e. now total of k moves are further 
req to make , to make n exactly one , so moves +=k2 as k= nothing by k2 .

so moves = k2-k1 + k2 = 2*k2 - k1

moves = 2*k2 - k1    (where k2-k1 moves are req for multiplication by 2 and further k2 moves are req for division by 6)


----------------------------------------------------------------------------------------------For Gist after this read the editorial--------------------------------



const int N = 200005;


void solve() {
    int n;cin>>n;
    int k1=0, k2=0;
    //calculating k1;
    while(n%2==0){
        n/=2;
        ++k1;
    }
    //calnculating k2 ;
    while(n%3==0){
        n/=3;
        ++k2;
    }

    if(n==1){   //it means it has only 2 and 3 in its prime factorisation and no other primes

        int diff=k2-k1; //diff = the dificit of 2s
        if(diff<0){ //if the dificit of 2s is -ve it means  2 is in excess => ans =-1
            cout<<-1<<endl;
        }
        else{
            cout<<k2+diff<<endl;
        }
    }
    else{
        cout<<-1<<endl;
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




*/
