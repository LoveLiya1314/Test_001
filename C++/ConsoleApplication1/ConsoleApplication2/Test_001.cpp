/*
���ܣ�ͼ���ڽӾ���ʵ��
�ο����ף������������ݽṹ(��������󷽷���C++��������)(��2��)��,
��Σ�2007��6�µ�2��
ҳ�룺PP351-355
���뻷����Dev-C++ 5.11
�༭���ڣ�2020��11��30��
����ʵ�֣����
*/
#include <iostream>
using namespace std;

const int maxVertices = 100;						// ��󶥵���
const int DefaultVertices = 30;						// Ĭ�϶�����

													// Dev-C++Ҫ������� Declaration required by Dev-C++
template <class T, class E>
class Graph;

template <class T, class E>
istream& operator >> (istream& in, Graph<T, E>& G);

template <class T, class E>
ostream& operator<< (ostream& out, Graph<T, E>& G);

//	P351 ����8.3 ͼ���ඨ��
template <class T, class E>
class Graph
{
	friend istream& operator >> <> (istream& in, Graph<T, E>& G);		// ����
	friend ostream& operator << <> (ostream& out, Graph<T, E>& G);		// ���
public:
	const E maxWeight = 1000;
	Graph();										// ���캯��
	Graph(T _vtxNull, E _wtNull, E _wtMax);		// �����䣩���캯������
	~Graph();										// ��������
	int NumberOfVertices();
	int NumberOfEdges();
	T getValue(int i);								// ȡ���� i ��ֵ
	E getWeight(int v1, int v2);					// ȡ����Ȩֵ
	int getFirstNeighbor(int v);					// ȡ���� v �ĵ�һ���ڽӶ���
	int getNextNeighbor(int v, int w);				// ȡ�ڽӶ��� w ����һ�ڽӶ���
	bool insertVertex(const T& vertex);			// ����һ������vertex
	bool insertEdge(int v1, int v2, E cost);		// �����(v1, v2), ȨΪcost
	bool removeVertex(int v);						// ɾȥ���� v ���������������
	bool removeEdge(int v1, int v2);				// ��ͼ��ɾȥ��(v1,v2)
protected:											// P349 ����8.2
	int maxVertices;	// ͼ����󶥵���
	int numEdges;		// ��ǰ����
	int numVertices;	// ��ǰ������
	T vtxNull;			// �ն��� 
	E wtNull;			// Ȩ����ֵ���޻��� 
	E wtMax;			// Ȩ�����ֵ���ޱߣ� 
private:
	T * VerticesList;								// ����� (���������ͷ���)
	E * *Edges;										// �ڽӾ��󱣴��
	int getVertexPos(T vertex);					// ��������vertex��ͼ��λ��
};

//	P352 ��Ա���� ����8.3 ���캯�� (���� ���캯�� ����)
template <class T, class E>
Graph<T, E>::Graph(T _vtxNull, E _wtNull, E _wtMax)
{
	maxVertices = DefaultVertices;	// ��ʼ�� ��󶥵��� 
	numVertices = 0;				// ��ʼ�� ������� 
	numEdges = 0;					// ��ʼ�� ���� 

	vtxNull = _vtxNull;	// ��ʼ�� �ն��� 
	wtNull = _wtNull;	// ��ʼ�� Ȩ����ֵ 
	wtMax = _wtMax;		// ��ʼ�� Ȩ�����ֵ 

	VerticesList = new T[maxVertices];				// �������������
	Edges = (E **) new E*[maxVertices];				// �����ڽӾ�������
	for (int i = 0; i<maxVertices; i++)
		Edges[i] = new E[maxVertices];
	for (int i = 0; i<maxVertices; i++)
		for (int j = 0; j<maxVertices; j++)
			Edges[i][j] = (i == j) ? wtNull : wtMax;		// �ڽӾ������Խ���Ԫ��Ϊ0������Լ��ޱ���Ȩ�������
};

//	P352 ��Ա���� ����8.3 ��������
template <class T, class E>
Graph<T, E>::~Graph()
{
	delete[] VerticesList;
	delete[] Edges;
	// Add codes on P352 ...
};

//	P352 ��Ա���� ����8.3 ���ض������
template <class T, class E>
int Graph<T, E>::NumberOfVertices()
{
	return numVertices;
	// Add codes on P352 ...
}

//	P352 ��Ա���� ����8.3 ���رߵ�����
template <class T, class E>
int Graph<T, E>::NumberOfEdges()
{
	return numEdges;
	// Add codes on P352 ...
}

//	P352 ��Ա���� ����8.3 ȡ�����ֵ (���޸�)
template <class T, class E>
T Graph<T, E>::getValue(int i)
{
	return i >= 0 && i <= numVertices ? VerticesList[i] : NULL;
	// Add codes on P352 ...
}

//	P352 ��Ա���� ����8.3 ȡ�ߵ�Ȩֵ (���޸�)
template <class T, class E>
E Graph<T, E>::getWeight(int v1, int v2)
{
	return v1 != -1 && v2 != -1 ? Edges[v1][v2] : 0;
	// Add codes on P352 ...
}

//	P352 ��Ա���� ����8.3 ���Ҷ������ͼ��˳���
template <class T, class E>
int Graph<T, E>::getVertexPos(T Vertex)
{
	for (int i = 0; i<numVertices; i++)
		if (VerticesList[i] == Vertex)
			return i;

	return -1;
	// Add codes on P352 ...
};

//	P352 ��Ա���� ����8.4 ȡ���� v �ĵ�һ���ڽӶ���
template <class T, class E>
int Graph<T, E>::getFirstNeighbor(int v)
{

	// Add codes on P352 ...
}

//	P353 ��Ա���� ����8.4 ȡ�ڽӶ��� w ����һ�ڽӶ���
template <class T, class E>
int Graph<T, E>::getNextNeighbor(int v, int w)
{
	//��������V��ĳ�ڽӶ���W����һ���ڽӶ���
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

//	P353 ��Ա���� ����8.4 ���붥��
template <class T, class E>
bool Graph<T, E>::insertVertex(const T& vertex)
{
	if (numVertices == maxVertices)
	{
		return false;        //������������ܲ��� 
	}
	VerticesList[numVertices++] = vertex;
	return true;
	// Add codes on P353 ...
}

//	PP353-4 ��Ա���� ����8.4 �����
template <class T, class E>
bool Graph<T, E>::insertEdge(int v1, int v2, E cost)
{
	//����ߣ�v1,v2����ȨֵΪcost
	if (v1 > -1 && v1<numVertices && v2 >-1 && v2<numVertices&& Edges[v1][v2] >= maxWeight)
	{
		//��������
		Edges[v1][v2] = Edges[v2][v1] = cost;
		numEdges++;
		return true;
	}
	else
		return false;
	// Add codes on PP353-4 ...
}

//	P353 ��Ա���� ����8.4 ɾ�����㣨�Լ�����������ıߣ�
template <class T, class E>
bool Graph<T, E>::removeVertex(int v)
{
	if (v<0 || v >= numVertices)      //v ����ͼ�� 
		return false;                 // ֻʣһ���ڵ㣬��ɾ�� 
	if (numVertices == 1)
		return false;
	int i, j;
	VerticesList[v] = VerticesList[numVertices - 1];   //�������ɾ���˽ڵ�
	for (i = 0; i<numVertices; i++)
	{                //ɾȥ��v ��صı��� 
		if (Edges[i][v]> 0 && Edges[i][v] < maxWeight)
		{
			numEdges--;
		}
	}
	for (i = 0; i<numVertices; i++)
	{               //�����һ�����v �� 
		Edges[i][v] = Edges[i][numVertices - 1];
	}
	numVertices--;
	for (j = 0; j<numVertices; j++)
	{                   //�����һ�����v �� 
		Edges[v][j] = Edges[numVertices][j];
	}
	return true;
	// Add codes on P353 ...
}

//	P354 ��Ա���� ����8.4 ɾ����
template <class T, class E>
bool Graph<T, E>::removeEdge(int v1, int v2)
{
	// Add codes on P354 ...
}

// Page 354 Prog. 8.5 Overload stream input function >>
// ��354ҳ ����8.5 ���������뺯�� >>
template <class T, class E>
istream & operator >> (istream& in, Graph<T, E>& G)
{
	int i, j, k, n, m;
	T v1, v2;
	E weight;

	//cout << "Input the number of vertices and edges:" << endl; 
	in >> n >> m;									// ��������ͱ���

													//cout << "Input the vertices:" << endl; 
	for (i = 0; i<n; i++)								// ����n������
	{
		in >> v1;
		G.insertVertex(v1);
	}

	//cout << "Input the number of Graph vertices and edges:" << endl; 
	i = 0;
	while (i<m)										// ����m����
	{
		in >> v1 >> v2 >> weight;					// ����ߵġ���-��-Ȩ��
		j = G.getVertexPos(v1);						// �鶥���
		k = G.getVertexPos(v2);
		if (i == -1 || k == -1)
			cout << "Wrong vertex number, retry:" << endl;
		else
		{
			G.insertEdge(j, k, weight);				// ���ա���-��-Ȩ�������
			i++;
		}
	}

	return in;
}

//	P355 ��Ա���� ����8.5 ���ͼ�����ж���ͱߵ���Ϣ
template <class T, class E>
ostream& operator << (ostream& out, Graph<T, E>& G)
{
	int n, m;
	T e1, e2;
	E w;
	n = G.NumberOfVertices();
	m = G.NumberOfEdges();

	//out << "Numbers of vertices and edges:" << endl;
	//out << n << ", " << m << endl;					// ��������������

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

//	########################  ���������  ########################
int main01()
{
	Graph<char, int> g('\0', 0, 9999);		// ����һ��Graphʵ��
	cin >> g;									// �Ӽ��̴���ͼ
	cout << g;									// ���������ͼ
	return 0;									// �����˳�
}

/*
��������
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





