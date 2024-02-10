#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<size_t> graph[10002];
size_t components[10002]{0};

void dfs(size_t v,size_t compIndex)
{
    if(components[v]!=0)
    {
        return;
    }
    components[v] = compIndex;
    for(auto& n: graph[v])
    {
        dfs(n,compIndex);
    }
}

int main() {

    size_t N,M,from,to,Q,req;
    cin>>N>>M;
    for(size_t i=0;i<M;i++)
    {
        cin>>from>>to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    size_t compIndex = 1;
    for (size_t i = 1; i <= N; i++)
    {
        dfs(i, compIndex);
        compIndex++;
    }
    
    cin>>Q;
    for(size_t i=0;i<Q;i++)
    {
        cin>>req>>from>>to;
        if(req==1)
        {
            cout<<(components[from]==components[to]);
        }
        if(req==2)
        {
            if (components[from] == components[to])
                continue;

            size_t toChangeComp = components[to];
            for (size_t j = 1; j <= N; j++)
            {
                if (components[j] == toChangeComp)
                    components[j] = components[from];
            }
        }
    }
    
    
    return 0;
}
