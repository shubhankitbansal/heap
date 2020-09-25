#include<bits/stdc++.h>
#define ll long long
#define int long long
#define mod1 1000000007
using namespace std;

ll add1(ll x,ll y){
    ll res=(x%mod1+y%mod1)%mod1;
    return res;
}

ll sub(ll x,ll y){
    ll res=0;
    res=(x%mod1-y%mod1+mod1)%mod1;
    return res;
}

ll mul(ll x,ll y){
    ll res=0;
    x=x%mod1;
    while(y){
        if(y&1)
            res=(res+x)%mod1;
        x=(x+x)%mod1;
        y=y>>1;
    }
    return res;
}

ll power(ll x,ll y){
    ll res=1;
    x=x%mod1;
    while(y){
        if(y&1)
            res=(res*x)%mod1;
        x=(x*x)%mod1;
        y=y>>1;
    }
    return res;
}

ll invflt(ll x){
    return power(x,mod1-2);
}

ll div1(ll x,ll y){
    y=invflt(y);
    return (x*y)%mod1;
}

void maxheapify(ll i,ll arr[],ll n){
    ll largest;
    ll left=i*2;
    ll right=i*2+1;
    if(left<=n && arr[left]>arr[i]){
        largest=left;
    }
    else{
        largest=i;
    }
    if(right<=n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        maxheapify(largest,arr,n);
    }
}

void buildmaxheap(ll arr[],ll n){
    for(ll i=n/2;i>=1;i--){
        maxheapify(i,arr,n);
    }
}

void insertmaxheap(ll val,ll arr[],ll n){
    n++;
    arr[n]=val;
    for(ll i=n/2;i>=1;i=i/2){
        maxheapify(i,arr,n);
    }
}

void maxheapsort(ll arr[],ll n){
    buildmaxheap(arr,n);
    for(ll i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    ll size=n;
    for(ll i=n;i>=2;i--){
        swap(arr[1],arr[i]);
        size--;
        maxheapify(1,arr,size);
    }
}

void minheapify(ll i,ll arr[],ll n){
    ll smallest;
    ll left=i*2;
    ll right=i*2+1;
    if(left<=n && arr[left]<arr[i]){
        smallest=left;
    }
    else{
        smallest=i;
    }
    if(right<=n && arr[right]<arr[smallest]){
        smallest=right;
    }
    if(smallest!=i){
        swap(arr[smallest],arr[i]);
        minheapify(smallest,arr,n);
    }
}

void buildminheap(ll arr[],ll n){
    for(ll i=n/2;i>=1;i--){
        minheapify(i,arr,n);
    }
}

void insertminheap(ll val,ll arr[],ll n){
    n++;
    arr[n]=val;
    for(ll i=n/2;i>=1;i=i/2){
        minheapify(i,arr,n);
    }
}

void minheapsort(ll arr[],ll n){
    buildminheap(arr,n);
    for(ll i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    ll size=n;
    for(ll i=n;i>=2;i--){
        swap(arr[1],arr[i]);
        size--;
        minheapify(1,arr,size);
    }
}

void solve(){
    ll n;
    cin>>n;
    ll a[100];
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    buildmaxheap(a,n);
    insertmaxheap(19,a,n);
    n++;
    for(ll i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

signed main(){
	ll t;
	cin>>t;
	while(t--){
        solve();
    }
}