// 틀린 코드

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100100 // 홍보할 때 대는 비용 100 * c의 개수 1,000 + c보다 커지는 최대값 100
using namespace std;

int dp[MAX]={0,};
vector <pair<int,int>> v; // cost client

// 비용 기준으로 오름차순 정렬
bool compare(const pair<int,int>& a, const pair<int,int>& b){
    return a < b;
}

int main(){
    int c, n, cost, client, temp;
    cin >> c >> n;

    for (int i=0;i<n;i++){
        cin >> cost >> client;
        v.push_back(make_pair(cost,client));
    }

    sort(v.begin(), v.end(), compare);

    // dp[비용] = 사람 수
    for (int i=0;i<n;i++){
        for (int j=1;j<=100000;j++){
            cost = v[i].first*j;
            client = v[i].second*j;
            dp[cost] = max(dp[cost],client);
        }
    }

    for (int j=1;j<=100000;j++){
        dp[j] = max(dp[1]+dp[j-1],dp[j]);

        if (dp[j]>=c){
            cout << j << '\n';
            return 0;
        }
    }
}
