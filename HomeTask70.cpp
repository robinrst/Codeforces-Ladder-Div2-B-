#include "bits/stdc++.h"

using namespace std;

#define  f first
#define  lgn 25
#define  endl '\n'
#define  sc second
#define  N (int)2e5+5
#define  sz(x) x.size()
#define  int long long int
#define  ld long double
#define  vi vector<int>
#define  vs vector<string>
#define  vc vector<char>
#define  mii map<int,int>
#define  pii pair<int,int>
#define  vpii vector<pii>
#define  test(x) while(x--)
#define  pb push_back
#define  eb emplace_back
#define  pq priority_queue
#define  mod 1000000007
#define  fo(i,a,n) for(int i=a;i<n;i++)
#define  rfo(i,n,a) for(int i=n;i>=a;i--)
#define  mst(a,v,n) fo(i,0,n) a[i]=v
#define  all(x) begin(x),end(x)
#define  allr(x) rbegin(x),rend(x)
#define  rev(x) reverse(begin(x),end(x))
#define  db(x) cout<<#x <<" : "<< x <<endl;
#define time() cerr << "Time : " << (double)clock() / (double)CLOCKS_PER_SEC << "s\n"

const int inf = 0x3f3f3f3f;
const int INF = 0x3f3f3f3f3f3f3f3f;

int n,m,k;
vi adj[N];
string s="";
int vis[N],par[N],a[N];


void go()
{
    cin>>n;
    int sum = 0;
    fo(i,0,n) 
    {
        cin>>a[i];
        s += to_string(a[i]);
    }
    bool _0 = 0;

    fo(i,0,sz(s))
    {
        if(s[i] == '0') _0 = 1;
        sum += (int)(s[i]-'0');
    }

    if( !_0 )
    {
        cout << -1 << endl;
        return;
    }

    int md = sum % 3;

    sort(all(s));

    if(md == 0)
    {
        if(s[n-1] == '0') cout << 0 << endl;
        else 
        {
            rfo(i,sz(s)-1,0) cout << s[i];
            cout << endl;
        }
    }
    else if( md == 1)
    {
        int _1 = 0;

        fo(i,0,sz(s))
        {
            int no = s[i]-'0';
            if( no % 3 == 1)
            {
                s[i] = '$';
                _1 = 1;
                break;
            }
        }
        if( !_1 )
        {
            int cn=0;

            fo(i,0,sz(s))
            {
                int no = s[i]-'0';
                if( no % 3 == 2)
                {
                    s[i] = '$';
                    cn++;
                    if( cn >= 2)
                    break;
                }
            }
        }
        sort(all(s),[](char a, char b)->bool{
            return a>b;
        });
        if(s[0] == '0') cout << 0 << endl;
        else 
        {
            fo(i,0,sz(s))
            {
                if(s[i] == '$' ) continue;
                cout<<s[i];
            }
            cout << endl;
        }
    }
    else 
    {
        int _2 = 0;
        fo(i,0,sz(s))
        {
            int no = s[i]-'0';
            if(( no % 3 == 2))
            {
                s[i] = '$';
                _2 = 1;
                break;
            }
        }
        if( !_2 )
        {
            int cn=0;
            fo(i,0,sz(s))
            {
                int no = s[i]-'0';
                if( no % 3 == 1)
                {
                    s[i] = '$';
                    cn++;

                    if(cn >= 2) break;
                }
            }
        }
        sort(all(s),[](char a, char b)->bool{
            return a>b;
        });

        if(s[0] == '0') cout << 0 << endl;
            else 
            {
                fo(i,0,sz(s))
                {
                    if(s[i] == '$' ) continue;
                    cout<<s[i];
                }
                cout << endl;
            }
        }
}

int32_t main()
{    
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=1; 
    // cin>>t;
    test(t) go();
}