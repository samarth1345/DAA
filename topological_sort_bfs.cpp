//kahn's algorithm
//only for DAG
#include <bits/stdc++.h>
using namespace std;
class graph
{
    int no_of_vertices;
    vector<int> List[MAX];
public:
    graph(int val)
    {
        no_of_vertices = val;
    }
    void input(int vertice1, int vertice2)
    {
        List[vertice1].push_back(vertice2);
        List[vertice2].push_back(vertice1);
    }
    void input_directed(int vertice1, int vertice2)
    {
        List[vertice1].push_back(vertice2);
    }
    void print()
    {
        for(int i=1;i<=no_of_vertices;i++)
        {
            cout<<i<<": ";
            for(int j=0;j<List[i].size();j++)
                cout<<List[i][j]<<" ";
            cout<<endl;
        }
    }
    vector<int> *getList()
    {
        return List;
    }
};
void kahns(vector<int> *List,int vertices)
{
    vector<int> indegree(vertices);
    for(int i=0;i<vertices;i++)
    {
        for(int j=0;j<List[i].size();j++)
        {
            indegree[List[i][j]]++;
        }
    }
    queue<int> q;
    for(int i=0;i<vertices;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        int temp=q.front();
        q.pop();
        for(int i=0;i<List[temp].size();i++)
        {
            indegree[List[temp][i]]--;
            if(indegree[List[temp][i]]==0)
                q.push(List[temp][i]);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    graph *obj=new graph(n);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        obj->input_directed(u,v);
    }
    kahns(obj->getList(),n);
}
