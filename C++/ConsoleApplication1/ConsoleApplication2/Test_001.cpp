/*
功能：图的邻接矩阵实现
参考文献：殷人昆《数据结构(用面向对象方法与C++语言描述)(第2版)》,
版次：2007年6月第2版
页码：PP351-355
编译环境：Dev-C++ 5.11
编辑日期：2020年11月30日
调试实现：徐浩
*/
#include <iostream>
using namespace std;

const int maxVertices = 100;						// 最大顶点数
const int DefaultVertices = 30;						// 默认顶点数

													// Dev-C++要求的声明 Declaration required by Dev-C++
template <class T, class E>
class Graph;

template <class T, class E>
istream& operator >> (istream& in, Graph<T, E>& G);

template <class T, class E>
ostream& operator<< (ostream& out, Graph<T, E>& G);

//	P351 程序8.3 图的类定义
template <class T, class E>
class Graph
{
	friend istream& operator >> <> (istream& in, Graph<T, E>& G);		// 输入
	friend ostream& operator << <> (ostream& out, Graph<T, E>& G);		// 输出
public:
	const E maxWeight = 1000;
	Graph();										// 构造函数
	Graph(T _vtxNull, E _wtNull, E _wtMax);		// （补充）构造函数重载
	~Graph();										// 析构函数
	int NumberOfVertices();
	int NumberOfEdges();
	T getValue(int i);								// 取顶点 i 的值
	E getWeight(int v1, int v2);					// 取边上权值
	int getFirstNeighbor(int v);					// 取顶点 v 的第一个邻接顶点
	int getNextNeighbor(int v, int w);				// 取邻接顶点 w 的下一邻接顶点
	bool insertVertex(const T& vertex);			// 插入一个顶点vertex
	bool insertEdge(int v1, int v2, E cost);		// 插入边(v1, v2), 权为cost
	bool removeVertex(int v);						// 删去顶点 v 和所有与相关联边
	bool removeEdge(int v1, int v2);				// 在图中删去边(v1,v2)
protected:											// P349 程序8.2
	int maxVertices;	// 图中最大顶点数
	int numEdges;		// 当前边数
	int numVertices;	// 当前顶点数
	T vtxNull;			// 空顶点 
	E wtNull;			// 权重零值（无环） 
	E wtMax;			// 权重最大值（无边） 
private:
	T * VerticesList;								// 顶点表 (各边链表的头结点)
	E * *Edges;										// 邻接矩阵保存边
	int getVertexPos(T vertex);					// 给出顶点vertex在图中位置
};

//	P352 成员函数 程序8.3 构造函数 (补充 构造函数 重载)
template <class T, class E>
Graph<T, E>::Graph(T _vtxNull, E _wtNull, E _wtMax)
{
	maxVertices = DefaultVertices;	// 初始化 最大顶点数 
	numVertices = 0;				// 初始化 顶点个数 
	numEdges = 0;					// 初始化 边数 

	vtxNull = _vtxNull;	// 初始化 空顶点 
	wtNull = _wtNull;	// 初始化 权重零值 
	wtMax = _wtMax;		// 初始化 权重最大值 

	VerticesList = new T[maxVertices];				// 创建顶点表数组
	Edges = (E **) new E*[maxVertices];				// 创建邻接矩阵数组
	for (int i = 0; i<maxVertices; i++)
		Edges[i] = new E[maxVertices];
	for (int i = 0; i<maxVertices; i++)
		for (int j = 0; j<maxVertices; j++)
			Edges[i][j] = (i == j) ? wtNull : wtMax;		// 邻接矩阵主对角线元素为0；顶点对间无边则权重无穷大
};

//	P352 成员函数 程序8.3 析构函数
template <class T, class E>
Graph<T, E>::~Graph()
{
	delete[] VerticesList;
	delete[] Edges;
	// Add codes on P352 ...
};

//	P352 成员函数 程序8.3 返回顶点个数
template <class T, class E>
int Graph<T, E>::NumberOfVertices()
{
	return numVertices;
	// Add codes on P352 ...
}

//	P352 成员函数 程序8.3 返回边的条数
template <class T, class E>
int Graph<T, E>::NumberOfEdges()
{
	return numEdges;
	// Add codes on P352 ...
}

//	P352 成员函数 程序8.3 取顶点的值 (有修改)
template <class T, class E>
T Graph<T, E>::getValue(int i)
{
	return i >= 0 && i <= numVertices ? VerticesList[i] : NULL;
	// Add codes on P352 ...
}

//	P352 成员函数 程序8.3 取边的权值 (有修改)
template <class T, class E>
E Graph<T, E>::getWeight(int v1, int v2)
{
	return v1 != -1 && v2 != -1 ? Edges[v1][v2] : 0;
	// Add codes on P352 ...
}

//	P352 成员函数 程序8.3 查找顶点的在图的顺序号
template <class T, class E>
int Graph<T, E>::getVertexPos(T Vertex)
{
	for (int i = 0; i<numVertices; i++)
		if (VerticesList[i] == Vertex)
			return i;

	return -1;
	// Add codes on P352 ...
};

//	P352 成员函数 程序8.4 取顶点 v 的第一个邻接顶点
template <class T, class E>
int Graph<T, E>::getFirstNeighbor(int v)
{

	// Add codes on P352 ...
}

//	P353 成员函数 程序8.4 取邻接顶点 w 的下一邻接顶点
template <class T, class E>
int Graph<T, E>::getNextNeighbor(int v, int w)
{
	//给出顶点V的某邻接顶点W的下一个邻接顶点
	if (v != 0 && w != -1)
	{
		for (int col = w + 1; col<numVertices; col++)
		{
			if (Edges[v][col]>0 && Edges[v][col]<maxWeight)
				return col;
		}
		return -1;
	}
	// Add codes on P353 ...
}

//	P353 成员函数 程序8.4 插入顶点
template <class T, class E>
bool Graph<T, E>::insertVertex(const T& vertex)
{
	if (numVertices == maxVertices)
	{
		return false;        //顶点表满，不能插入 
	}
	VerticesList[numVertices++] = vertex;
	return true;
	// Add codes on P353 ...
}

//	PP353-4 成员函数 程序8.4 插入边
template <class T, class E>
bool Graph<T, E>::insertEdge(int v1, int v2, E cost)
{
	//插入边（v1,v2），权值为cost
	if (v1 > -1 && v1<numVertices && v2 >-1 && v2<numVertices&& Edges[v1][v2] >= maxWeight)
	{
		//插入条件
		Edges[v1][v2] = Edges[v2][v1] = cost;
		numEdges++;
		return true;
	}
	else
		return false;
	// Add codes on PP353-4 ...
}

//	P353 成员函数 程序8.4 删除顶点（以及和它相关联的边）
template <class T, class E>
bool Graph<T, E>::removeVertex(int v)
{
	if (v<0 || v >= numVertices)      //v 不在图中 
		return false;                 // 只剩一个节点，不删除 
	if (numVertices == 1)
		return false;
	int i, j;
	VerticesList[v] = VerticesList[numVertices - 1];   //顶点表中删除此节点
	for (i = 0; i<numVertices; i++)
	{                //删去与v 相关的边数 
		if (Edges[i][v]> 0 && Edges[i][v] < maxWeight)
		{
			numEdges--;
		}
	}
	for (i = 0; i<numVertices; i++)
	{               //用最后一列填补第v 列 
		Edges[i][v] = Edges[i][numVertices - 1];
	}
	numVertices--;
	for (j = 0; j<numVertices; j++)
	{                   //用最后一行填补第v 行 
		Edges[v][j] = Edges[numVertices][j];
	}
	return true;
	// Add codes on P353 ...
}

//	P354 成员函数 程序8.4 删除边
template <class T, class E>
bool Graph<T, E>::removeEdge(int v1, int v2)
{
	// Add codes on P354 ...
}

// Page 354 Prog. 8.5 Overload stream input function >>
// 第354页 程序8.5 重载流输入函数 >>
template <class T, class E>
istream & operator >> (istream& in, Graph<T, E>& G)
{
	int i, j, k, n, m;
	T v1, v2;
	E weight;

	//cout << "Input the number of vertices and edges:" << endl; 
	in >> n >> m;									// 输入点数和边数

													//cout << "Input the vertices:" << endl; 
	for (i = 0; i<n; i++)								// 输入n个顶点
	{
		in >> v1;
		G.insertVertex(v1);
	}

	//cout << "Input the number of Graph vertices and edges:" << endl; 
	i = 0;
	while (i<m)										// 输入m条边
	{
		in >> v1 >> v2 >> weight;					// 输入边的“点-点-权”
		j = G.getVertexPos(v1);						// 查顶点号
		k = G.getVertexPos(v2);
		if (i == -1 || k == -1)
			cout << "Wrong vertex number, retry:" << endl;
		else
		{
			G.insertEdge(j, k, weight);				// 按照“点-点-权”插入边
			i++;
		}
	}

	return in;
}

//	P355 成员函数 程序8.5 输出图的所有顶点和边的信息
template <class T, class E>
ostream& operator << (ostream& out, Graph<T, E>& G)
{
	int n, m;
	T e1, e2;
	E w;
	n = G.NumberOfVertices();
	m = G.NumberOfEdges();

	//out << "Numbers of vertices and edges:" << endl;
	//out << n << ", " << m << endl;					// 输出顶点数与边数

	//out << "All " << m << " edges with end-end-weight:" << endl;
	for (int i = 0; i<n; i++)
		for (int j = i + 1; j<n; j++)
		{
			w = G.getWeight(i, j);
			if (w>G.wtNull && w<G.wtMax)
			{
				e1 = G.getValue(i);
				e2 = G.getValue(j);
				out << "(" << e1 << "," << e2 << "," << w << ")" << endl;
			}
		}

	cout << endl;
	return out;
}

//	########################  程序主入口  ########################
int main01()
{
	Graph<char, int> g('\0', 0, 9999);		// 定义一个Graph实例
	cin >> g;									// 从键盘创建图
	cout << g;									// 输出创建的图
	return 0;									// 返回退出
}

/*
测试数据
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





