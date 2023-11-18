#include <iostream>
using namespace std;

long long num;
long long arr[31];

void initialize(){
    num=0;
    fill(arr,arr+31,1);
}

int main(){
    int t, n, m;
    cin >> t;

    while (t--){
        initialize();

        cin >> n >> m;

        for (int i=1;i<=n;i++){
            arr[i] = arr[i-1] * (m-num) / i;
            num++;
        }
        cout << arr[n] << '\n';
    }

}
