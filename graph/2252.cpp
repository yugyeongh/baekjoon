#include <iostream>
#include <queue>
#include <vector>
// 틀린 코드
#include <algorithm>
using namespace std;

vector <pair<int,int>> graph;
queue <int> q;

void topology(vector <int> indegree){
    for (int i=0;i<indegree.size();i++){
        if (indegree[i]==0) q.push(i+1);
    }

    for (int i=0;i<graph.size();i++){
        int x = graph[i].second-1;

        if (indegree[x]!=0) indegree[x]--;
        if (indegree[x]==0) q.push(x+1);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,m,a,b;
    cin >> n >> m;

    vector <int> indegree(n);

    while (m--){
        cin >> a >> b;
        graph.push_back(make_pair(a,b));
        indegree[b-1]++;
    }

    topology(indegree);

    while(!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}
