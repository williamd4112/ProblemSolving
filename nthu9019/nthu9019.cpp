#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>

#define N 512
#define M 512

using namespace std;

typedef struct Cell
{
    int i, j;
    int id;
}Cell;

Cell map[N][M];

int dir[4][2] = {
    {1, 0},
    {-1, 0},
    {0, -1},
    {0, 1}
};

int n, m;

void show()
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            printf("%d",map[i][j].id);
        }
        printf("\n");
    }
    printf("\n");
}

void expand(queue<Cell> *qs)
{
    int cnt = 0;
    int i = 0;

    while(cnt < 10)
    {
        if(!qs[i].empty())
        {
            int popCnt = qs[i].size();
            while(popCnt--)
            {
                Cell cell = qs[i].front();
                qs[i].pop();

                for(int k = 0; k < 4; k++)
                {
                    int ci = cell.i + dir[k][0];
                    int cj = cell.j + dir[k][1];

                    if(ci < 0 || ci >= n || cj < 0 || cj >= m)
                        continue;

                    if(map[ci][cj].id == 0)
                    {
                         map[ci][cj].id = cell.id;
                         qs[i].push(map[ci][cj]);
                    }
                }
            }
        }
        else
            cnt++;
        i++;

        if(i == 10 && cnt != 10)
            i = 0, cnt = 0;
    }
}

int main(void)
{
    int nCase;
    scanf("%d",&nCase);

    while(nCase--)
    {
        scanf("%d%d",&n,&m);

        cin.ignore();

        int k = 0;
        char c;

        queue<Cell> country[10];
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> c;

                int id = int(c - '0');
                map[i][j].i = i;
                map[i][j].j = j;
                map[i][j].id = id;

                if(id)
                    country[id].push(map[i][j]);
            }
        }
        expand(country);
        show();
    }

    return 0;
}
