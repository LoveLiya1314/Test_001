#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char charType[20];//顶点信息存放数据类型
int visit[20];//顶点是否被访问过的标志数组

//表结点
typedef struct EdgeNode
{
    int            adjvex;//存储该点对应的下标
    int            weight;//存储权值
    struct EdgeNode * next;//指向下一个邻接点
} EdgeNode;

//顶点
typedef struct TopNode
{
    charType       data;//存储顶点信息
    int            dist;//存储最短路径(距离)
    int            len;//存储x到y经过多少个顶点
    int            path[20];//存储最短路径下标的数组
    EdgeNode       * firstedge;//边表头指针
} TopNode, AdjList[20];

//图信息
typedef struct Chart
{
    AdjList        vertices;//存储顶点的数组
    int            topnum;//顶点数
    int            arcnum;//边数
} Chart;

//转化(查找)
int Change( Chart * G, charType v )
{
    int i;
    for( i = 0 ; i < G->topnum ; i++)
    {
        if( (strcmp(v, G->vertices[i].data)) == 0 )//当找到输入两两关系的顶点某个顶点与输入顶点信息时某个顶点相等时，返回该顶点的下标(其实就是字符转换成整型数)
            return i;
    }
}

//邻接表建立有向图函数
void CreateAdjList( Chart * G )
{
    int i, j, k, weight;
    charType v1, v2 ;
    EdgeNode * p ;
    int m ;

    //初始化（1）
    //1、顶点数&边数
    //2、顶点信息
    printf("请输入 顶点数 和 边数：\n");
    scanf("%d %d",&G->topnum, &G->arcnum);
    printf("请输入 顶点信息 ：\n");
    for( m = 0 ; m < G->topnum ; m ++)
    {
        scanf("%s",&G->vertices[m].data);
        G->vertices[m].firstedge = NULL;
    }

    //初始化（2）
    //确定顶点与顶点之间的关系(连接方向&边权值)
    printf("请输入%d条弧的 两两关系 及 边权值 ：\n",G->arcnum);
    for( k = 0 ; k < G->arcnum ; k ++)
    {
        scanf("%s %s %d",&v1, &v2, &weight);
        i = Change( G, v1 );//将字符转化成了整型
        j = Change( G, v2 );//将字符转化成了整型
        EdgeNode * e = ( EdgeNode * )malloc(sizeof(EdgeNode));//向内存申请空间,生成边表结点
        e->adjvex = j; //表结点下标
        e->weight = weight;//表结点权值
        e->next = NULL;//该表结点暂时没有下一个表结点
        p = G->vertices[i].firstedge;//将第i个顶点的边表头指针赋值给表结点指针p

        //尾插
        if( p == NULL )//如果p为空(即第i个顶点的边表结点为空)
        {
            G->vertices[i].firstedge = e;//将表结点赋值给第i个顶点的firstedge(即实现两点相连)
        }
        else//如果第i个顶点的边表结点不为空
        {
            while( p->next )//直到p==null
            {
                 p = p->next;
            }
            p->next = e;//在尾部插入表结点
        }
    }
}



//Dijkstra
/*Dijkstra的思想就是
1、确定源点
2、找到与源点直接相连的顶点中路径最短的顶点k(源点到k最短路径找到，并且下一次从k点开始找)
3、从k点开始找，如果源点到与k相连的顶点中有比之前源点到与k相连的顶点路径长度更小的则取当前的路径。
4、且找到源点到与k相连结点的最小路径是哪个顶点，下一次就从该顶点开始，往复循环。
*/
void Dijkstra( Chart * G )
{

    printf("请输入 开始点 和 结束点:\n");
    int x,y;
    while( (scanf("%d",&x))!=EOF, x != -1 && x != 0 && x <= G->topnum )//开始点(要求：开始点不为-1,0,不大于顶点数)
    {
        int i, j,  k, m, min = 0, t;

        //初始化路径,初始化所有顶点的状态都是未访问过的状态
        for( i = 0 ; i <G->topnum ; i++)
        {
            visit[i] = 0;
            G->vertices[i].dist = 65535;
            G->vertices[i].len = 0;
            for( j = 0 ; j < G->topnum ; j++ )
                G->vertices[i].path[j] = 65535;
        }



        G->vertices[x-1].dist = 0;
        G->vertices[x-1].path[0] = x-1;//源点到其本身不算入最短路径
        k = x-1;//每次找到最小路径顶点的下标
        EdgeNode * p;
        //每次求得x到某个顶点的最短路径
        for( i = 0 ; i < G->topnum ; i ++)
        {
            t = 65535;
            p = G->vertices[k].firstedge;
            visit[k] = 1;
            while( p )
            {
                if( !visit[p->adjvex])
                {
                    if( G->vertices[k].dist == 65535 )//说明该k点之前是在没有被找到的里面
                    {
                        G->vertices[p->adjvex].dist = p->weight;//将x顶点的第一个表结点(前提存在该表结点)的权值赋值给该结点的dist(目的：为了求最小权值)
                        G->vertices[p->adjvex].len = G->vertices[k].len+1;//将x顶点的len+1赋值给表结点的len（记录x到某顶点的路径）
                        GetNewPathWay( G, k, p->adjvex);//更新路径，存储最短路径下标
                    }
                    else if( G->vertices[k].dist + p->weight < G->vertices[p->adjvex].dist )//如果源点->k->p的adjvex小于源点->p的adjvex，则修正当前最短路径及权值(x到k到此时p的权值小于x到p的的权值则执行)
                    {
                        G->vertices[p->adjvex].dist = G->vertices[k].dist + p->weight;
                        G->vertices[p->adjvex].len = G->vertices[k].len+1;
                        GetNewPathWay( G,k, p->adjvex);
                    }
                }
                p = p->next;//下一个与k直接相连的顶点
            }
            //寻找离k最近的顶点
            for( j = 0 ; j < G->topnum ; j++)
            {
                if( G->vertices[j].dist < t && !visit[j] )//j没有被访问过
                {
                    t = G->vertices[j].dist;//j顶点距离k更近
                    min = j;
                }
            }
            k = min;//找到源点到min是所求的该次的最短路径，下一次就从min开始找
        }
        while((scanf("%d",&y))!=EOF,y != -1 && y != 0 && y <= G->topnum )
        {
            ShowPathWay( G,y-1 );
            printf("请输入%d--> 的下一个顶点(-1结束): \n",x );
        }
        printf("请输入 开始点 和结束点 (-1结束):\n");
    }
}

//更新路径函数(存储最短路径每个下标)
void GetNewPathWay( Chart * G, int k, int i )
{
    int j;
    for( j = 0 ; j <= G->vertices[k].len ; j++ )
        G->vertices[i].path[j] = G->vertices[k].path[j];
    G->vertices[i].path[j] = i;//为了在输出路径的时候判断是否存在有源点到i的最短路径
}

//输出路径函数
void ShowPathWay( Chart * G, int y )
{
    int i, j;
    for( i = 0 ; i <= G->vertices[y].len ; i++)
        if( G->vertices[y].path[i] == y )//遍历数组path找到了最短路径在i下标，输出最短路径每个下标
        {
            printf("最短路径是：\n");
            for( j = 0 ; j < i ; j ++)
            {
                printf("%s->",G->vertices[G->vertices[y].path[j]].data);//G->vertices[G->vertices[y].path[j]]代表源点到y的路径下标
            }
            printf("%s\n\n",G->vertices[G->vertices[y].path[j]].data );
            printf("最短距离为：\n");
            printf("%d\n\n",G->vertices[y].dist);
            return 1;
        }
    printf("\nERROR:\n");
    printf("没有通路\n\n");
    return 0;
}


//深度遍历函数
void Dfs( Chart * G, int i )
{
    visit[i] = 1;
    printf("%s ",G->vertices[i].data);//打印顶点
    EdgeNode * p;
    p = G->vertices[i].firstedge;
    while( p )
    {
        if(!visit[p->adjvex])
            Dfs( G, p->adjvex );//对未访问的邻接顶点递归调用
        else
            p = p->next;
    }
}

void DfsTraverse( Chart * G )
{
    int i,j;
    //初始化路径,初始化所有顶点的状态都是未访问过的状态
     for( i = 0 ; i <G->topnum ; i ++)
     {
        visit[i] = 0;
        G->vertices[i].dist = 65535;
        G->vertices[i].len = 0;
        for( j = 0 ; j < G->topnum ; j ++ )
            G->vertices[i].path[j] = 65535;
     }
     //对未访问过的顶点调用DFS
     for( i = 0 ; i <G->topnum ; i ++)
        if(!visit[i])
            Dfs(G, i);
}


int main()
{
    printf("------------有向图的建立与遍历----邻接表实现---------------------\n");
    Chart G;
    printf("-----------------建立有向图------------------\n");
    CreateAdjList( &G );
    printf("\n\n深度遍历有向图：\n");
    DfsTraverse( &G );
    Dijkstra( &G );
    return 0;
}
