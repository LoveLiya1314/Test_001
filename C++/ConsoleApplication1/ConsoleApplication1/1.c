#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char charType[20];//������Ϣ�����������
int visit[20];//�����Ƿ񱻷��ʹ��ı�־����

			  //����
typedef struct EdgeNode
{
	int            adjvex;//�洢�õ��Ӧ���±�
	int            weight;//�洢Ȩֵ
	struct EdgeNode * next;//ָ����һ���ڽӵ�
} EdgeNode;

//����
typedef struct TopNode
{
	charType       data;//�洢������Ϣ
	int            dist;//�洢���·��(����)
	int            len;//�洢x��y�������ٸ�����
	int            path[20];//�洢���·���±������
	EdgeNode       * firstedge;//�߱�ͷָ��
} TopNode, AdjList[20];

//ͼ��Ϣ
typedef struct Chart
{
	AdjList        vertices;//�洢���������
	int            topnum;//������
	int            arcnum;//����
} Chart;

void GetNewPathWay(Chart * G, int k, int i)
{
	int j;
	for (j = 0; j <= G->vertices[k].len; j++)
		G->vertices[i].path[j] = G->vertices[k].path[j];
	G->vertices[i].path[j] = i;//Ϊ�������·����ʱ���ж��Ƿ������Դ�㵽i�����·��
}

//���·������
int ShowPathWay(Chart * G, int y)
{
	int i, j;
	for (i = 0; i <= G->vertices[y].len; i++)
		if (G->vertices[y].path[i] == y)//��������path�ҵ������·����i�±꣬������·��ÿ���±�
		{
			printf("���·���ǣ�\n");
			for (j = 0; j < i; j++)
			{
				printf("%s->", G->vertices[G->vertices[y].path[j]].data);//G->vertices[G->vertices[y].path[j]]����Դ�㵽y��·���±�
			}
			printf("%s\n\n", G->vertices[G->vertices[y].path[j]].data);
			printf("��̾���Ϊ��\n");
			printf("%d\n\n", G->vertices[y].dist);
			return 1;
		}
	printf("\nERROR:\n");
	printf("û��ͨ·\n\n");
	return 0;
}


//ת��(����)
int Change(Chart * G, charType v)
{
	int i;
	for (i = 0; i < G->topnum; i++)
	{
		if ((strcmp(v, G->vertices[i].data)) == 0)//���ҵ�����������ϵ�Ķ���ĳ�����������붥����Ϣʱĳ���������ʱ�����ظö�����±�(��ʵ�����ַ�ת����������)
			return i;
	}
	return 0;
}

//�ڽӱ�������ͼ����
void CreateAdjList(Chart * G)
{
	int i, j, k, weight;
	charType v1, v2;
	EdgeNode * p;
	int m;
	scanf("%d %d", &G->topnum, &G->arcnum);
	for (m = 0; m < G->topnum; m++)
	{
		scanf("%s", &G->vertices[m].data);
		G->vertices[m].firstedge = NULL;
	}
	for (k = 0; k < G->arcnum; k++)
	{
		scanf("%s %s %d", &v1, &v2, &weight);
		i = Change(G, v1);//���ַ�ת����������
		j = Change(G, v2);//���ַ�ת����������
		EdgeNode * e = (EdgeNode *)malloc(sizeof(EdgeNode));//���ڴ�����ռ�,���ɱ߱���
		e->adjvex = j; //�����±�
		e->weight = weight;//����Ȩֵ
		e->next = NULL;//�ñ�����ʱû����һ������
		p = G->vertices[i].firstedge;//����i������ı߱�ͷָ�븳ֵ������ָ��p

									 //β��
		if (p == NULL)//���pΪ��(����i������ı߱���Ϊ��)
		{
			G->vertices[i].firstedge = e;//�����㸳ֵ����i�������firstedge(��ʵ����������)
		}
		else//�����i������ı߱��㲻Ϊ��
		{
			while (p->next)//ֱ��p==null
			{
				p = p->next;
			}
			p->next = e;//��β���������
		}
	}
}


void Dijkstra(Chart * G)
{
	int x, y;
	while ((scanf("%d", &x)) != EOF, x != -1 && x != 0 && x <= G->topnum)//��ʼ��(Ҫ�󣺿�ʼ�㲻Ϊ-1,0,�����ڶ�����)
	{
		int i, j, k,  min = 0, t;

		//��ʼ��·��,��ʼ�����ж����״̬����δ���ʹ���״̬
		for (i = 0; i <G->topnum; i++)
		{
			visit[i] = 0;
			G->vertices[i].dist = 65535;
			G->vertices[i].len = 0;
			for (j = 0; j < G->topnum; j++)
				G->vertices[i].path[j] = 65535;
		}



		G->vertices[x - 1].dist = 0;
		G->vertices[x - 1].path[0] = x - 1;//Դ�㵽�䱾���������·��
		k = x - 1;//ÿ���ҵ���С·��������±�
		EdgeNode * p;
		//ÿ�����x��ĳ����������·��
		for (i = 0; i < G->topnum; i++)
		{
			t = 65535;
			p = G->vertices[k].firstedge;
			visit[k] = 1;
			while (p)
			{
				if (!visit[p->adjvex])
				{
					if (G->vertices[k].dist == 65535)//˵����k��֮ǰ����û�б��ҵ�������
					{
						G->vertices[p->adjvex].dist = p->weight;//��x����ĵ�һ������(ǰ����ڸñ���)��Ȩֵ��ֵ���ý���dist(Ŀ�ģ�Ϊ������СȨֵ)
						G->vertices[p->adjvex].len = G->vertices[k].len + 1;//��x�����len+1��ֵ�������len����¼x��ĳ�����·����
						GetNewPathWay(G, k, p->adjvex);//����·�����洢���·���±�
					}
					else if (G->vertices[k].dist + p->weight < G->vertices[p->adjvex].dist)//���Դ��->k->p��adjvexС��Դ��->p��adjvex����������ǰ���·����Ȩֵ(x��k����ʱp��ȨֵС��x��p�ĵ�Ȩֵ��ִ��)
					{
						G->vertices[p->adjvex].dist = G->vertices[k].dist + p->weight;
						G->vertices[p->adjvex].len = G->vertices[k].len + 1;
						GetNewPathWay(G, k, p->adjvex);
					}
				}
				p = p->next;//��һ����kֱ�������Ķ���
			}
			//Ѱ����k����Ķ���
			for (j = 0; j < G->topnum; j++)
			{
				if (G->vertices[j].dist < t && !visit[j])//jû�б����ʹ�
				{
					t = G->vertices[j].dist;//j�������k����
					min = j;
				}
			}
			k = min;//�ҵ�Դ�㵽min������ĸôε����·������һ�ξʹ�min��ʼ��
		}
		while ((scanf("%d", &y)) != EOF, y != -1 && y != 0 && y <= G->topnum)
		{
			ShowPathWay(G, y - 1);
			printf("������%d--> ����һ������(-1����): \n", x);
		}
		printf("������ ��ʼ�� �ͽ����� (-1����):\n");
	}
}

//����·������(�洢���·��ÿ���±�)


//��ȱ�������
void Dfs(Chart * G, int i)
{
	visit[i] = 1;
	printf("%s ", G->vertices[i].data);//��ӡ����
	EdgeNode * p;
	p = G->vertices[i].firstedge;
	while (p)
	{
		if (!visit[p->adjvex])
			Dfs(G, p->adjvex);//��δ���ʵ��ڽӶ���ݹ����
		else
			p = p->next;
	}
}

void DfsTraverse(Chart * G)
{
	int i, j;
	//��ʼ��·��,��ʼ�����ж����״̬����δ���ʹ���״̬
	for (i = 0; i <G->topnum; i++)
	{
		visit[i] = 0;
		G->vertices[i].dist = 65535;
		G->vertices[i].len = 0;
		for (j = 0; j < G->topnum; j++)
			G->vertices[i].path[j] = 65535;
	}
	//��δ���ʹ��Ķ������DFS
	for (i = 0; i <G->topnum; i++)
		if (!visit[i])
			Dfs(G, i);
}


int main()
{
	Chart G;
	CreateAdjList(&G);
	DfsTraverse(&G);
	Dijkstra(&G);
	system("pause");
	return 0;
}


/*
6 10

A B C D E F

A B 6

A C 1

A D 5

B C 5

B E 3

C D 5

C E 6

C F 4

D F 2

E F 6

*/