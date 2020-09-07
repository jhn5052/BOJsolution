#include <iostream>
#include <vector>
using namespace std;
#define MAX 100002

int n, m;
int value[MAX] = {0};
int ans[MAX] = {0};
vector<int> pre[MAX];

void Solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (value[i] > 0)
        {
            ans[i] += value[i];
            for (int j = 0; j < pre[i].size(); j++)
            {
                value[pre[i][j]] += ans[i];
            }
            value[i] = 0;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << ' ';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //input
    int senior, employee, w;
    cin >> n >> m;

    //[직속선배] - [직속후배]
    cin >> senior;
    for (int i = 2; i <= n; i++)
    {
        cin >> senior;
        pre[senior].push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> employee >> w;
        value[employee] += w;
    }
    Solve();
    return 0;
}