#include <iostream>
#include <vector>
#include <assert.h>
#include <string>
#include <memory.h>
#include <stdlib.h>
char VertexType[4];
int VRType;
#define MaxSize	50
using namespace std;
class Node
{
public:
	Node(char data = 0)
	{
		m_cData = data;
		m_bVisited = false;
	}
	Node(const Node& node)
	{
		if (this == &node)
			return;
		*this = node;
	}


	Node& operator=(const Node& node)
	{
		if (this == &node)
			return *this;
		this->m_cData = node.m_cData;
		this->m_bVisited = node.m_bVisited;
		return *this;
	}
public:
	char m_cData; 
	bool m_bVisited; 
};

class Edge
{
public:
	Edge(int nodeIndexA = 0, int nodeIndexB = 0, int weightValue = 0) :
		m_iNodeIndexA(nodeIndexA),
		m_iNodeIndexB(nodeIndexB),
		m_iWeightValue(weightValue),
		m_bSelected(false) {}
	Edge(const Edge& edge)
	{
		if (this == &edge)
			return;
		*this = edge;
	}

	Edge& operator=(const Edge& edge)
	{
		if (this == &edge)
			return *this;
		this->m_iNodeIndexA = edge.m_iNodeIndexA;
		this->m_iNodeIndexB = edge.m_iNodeIndexB;
		this->m_iWeightValue = edge.m_iWeightValue;
		this->m_bSelected = edge.m_bSelected;
		return *this;
	}

public:
	int m_iNodeIndexA; 
	int m_iNodeIndexB; 
	int m_iWeightValue; 
	bool m_bSelected; 
};

class CMap
{

private:
	int m_iCapacity; 
	int m_iNodeCount; 
	Node *m_pNodeArray; 
	int *m_pMatrix; 
	Edge *m_pEdgeArray; 
public:
	CMap(int iCapacity)
	{
		m_iCapacity = iCapacity;
		m_iNodeCount = 0;
		m_pNodeArray = new Node[m_iCapacity];
		m_pMatrix = new int[m_iCapacity*m_iCapacity];
		memset(m_pMatrix, 0, m_iCapacity*m_iCapacity * sizeof(int));
		m_pEdgeArray = new Edge[m_iCapacity - 1];
	}
	~CMap(void)
	{
		delete[]m_pNodeArray;
		delete[]m_pMatrix;
		delete[]m_pEdgeArray;
	}

private:
	void breadthFirstTraverseImpl(vector<int> preVec)
	{
		int val = 0;
		vector<int> curVec;
		for (int i = 0; i < (int)preVec.size(); i++)
		{
			for (int j = 0; j < m_iCapacity; j++)
			{
				getValueFromMatrix(preVec[i], j, val);
				if (/*1 == val*/0 != val)
				{
					if (m_pNodeArray[j].m_bVisited)
						continue;
					cout << m_pNodeArray[j].m_cData << " ";
					m_pNodeArray[j].m_bVisited = true;
					curVec.push_back(j);
				}
				else
					continue;
			}
		}

		if (curVec.empty())
			return;
		else
			breadthFirstTraverseImpl(curVec);
	}

	int getMinEdge(const vector<Edge>& edgeVec)
	{
		int min = 0, minEdge = 0;

		for (int i = 0; i < (int)edgeVec.size(); i++)
		{
			if (edgeVec[i].m_bSelected)
				continue;
			min = edgeVec[i].m_iWeightValue;
			minEdge = i;
		}

		for (int i = 0; i < (int)edgeVec.size(); i++)
		{
			if (edgeVec[i].m_bSelected)
				continue;
			if (min > edgeVec[i].m_iWeightValue)
			{
				min = edgeVec[i].m_iWeightValue;
				minEdge = i;
			}
		}

		if (0 == min)
			return -1;

		return minEdge;
	}

	bool isInSet(const vector<int>& nodeSet, int target)
	{
		for (int i = 0; i < (int)nodeSet.size(); i++)
		{
			if (nodeSet[i] == target)
				return true;
		}

		return false;
	}

	void mergeNodeSet(vector<int>& nodeSetA, const vector<int>& nodeSetB)
	{
		for (size_t i = 0; i < (int)nodeSetB.size(); i++)
		{
			nodeSetA.push_back(nodeSetB[i]);
		}
	}
public:
	void addNode(Node *node)
	{
		assert(node);
		m_pNodeArray[m_iNodeCount].m_cData = node->m_cData;
		m_iNodeCount++;
	}

	void resetNode()
	{
		for (int i = 0; i < m_iNodeCount; i++)
			m_pNodeArray[i].m_bVisited = false;
	}

	bool setValueToMatrixForDirectedGraph(int row, int col, int val = 1)
	{
		if (row < 0 || row >= m_iCapacity)
			return false;
		if (col < 0 || col >= m_iCapacity)
			return false;
		m_pMatrix[row*m_iCapacity + col] = val;
		return true;
	}


	bool setValueToMatrixForUndirectedGraph(int row, int col, int val = 1)
	{
		if (row < 0 || row >= m_iCapacity)
			return false;
		if (col < 0 || col >= m_iCapacity)
			return false;
		m_pMatrix[row*m_iCapacity + col] = val;
		m_pMatrix[col*m_iCapacity + row] = val;
		return true;
	}

	bool getValueFromMatrix(int row, int col, int& val)
	{
		if (row < 0 || row >= m_iCapacity)
			return false;
		if (col < 0 || col >= m_iCapacity)
			return false;
		val = m_pMatrix[row*m_iCapacity + col];
		return true;
	}

	void printMatrix()
	{
		for (int i = 0; i < m_iCapacity; i++)
		{
			for (int j = 0; j < m_iCapacity; j++)
				cout << m_pMatrix[i*m_iCapacity + j] << " ";
			cout << endl;
		}
	}


	void depthFirstTraverse(int index)
	{
		int val = 0;
		cout << m_pNodeArray[index].m_cData << " ";
		m_pNodeArray[index].m_bVisited = true;

		for (int i = 0; i < m_iCapacity; i++)
		{
			getValueFromMatrix(index, i, val);
			if (/*1 == val*/0 != val)
			{
				if (m_pNodeArray[i].m_bVisited)
					continue;
				depthFirstTraverse(i);
			}
			else
				continue;
		}
	}


	void breadthFirstTraverse(int index)
	{
		cout << m_pNodeArray[index].m_cData << " ";
		m_pNodeArray[index].m_bVisited = true;

		vector<int> curVec;
		curVec.push_back(index);

		breadthFirstTraverseImpl(curVec);
	}


	void primTree(int index)
	{
		int val = 0;
		int iEdgeCount = 0;
		vector<Edge> edgeVec;
		vector<int> nodeIndexVec;
		nodeIndexVec.push_back(index);
		while (iEdgeCount < m_iCapacity - 1)
		{
			int row = nodeIndexVec.back();
			cout << m_pNodeArray[row].m_cData << endl;
			m_pNodeArray[row].m_bVisited = true;

			for (int i = 0; i < m_iCapacity; i++)
			{
				getValueFromMatrix(row, i, val);
				if (0 == val)
					continue;
				if (m_pNodeArray[i].m_bVisited)
					continue;
				Edge edge(row, i, val);
				edgeVec.push_back(edge);
			}


			int retIndex = getMinEdge(edgeVec);
			if (-1 != retIndex)
			{

				edgeVec[retIndex].m_bSelected = true;
				m_pEdgeArray[iEdgeCount] = edgeVec[retIndex];
				cout << m_pNodeArray[m_pEdgeArray[iEdgeCount].m_iNodeIndexA].m_cData << " - ";
				cout << m_pNodeArray[m_pEdgeArray[iEdgeCount].m_iNodeIndexB].m_cData << " (";
				cout << m_pEdgeArray[iEdgeCount].m_iWeightValue << ") " << endl;
				iEdgeCount++;
				int iNodeIndex = edgeVec[retIndex].m_iNodeIndexB;
				m_pNodeArray[iNodeIndex].m_bVisited = true;
				nodeIndexVec.push_back(iNodeIndex);
			}
		}

	}


	void kruskalTree()
	{
		int val = 0;
		int edgeCount = 0;
		vector<vector<int> > nodeSets;
		vector<Edge> edgeVec;
		for (int i = 0; i < m_iCapacity; i++)
		{
			for (int j = i + 1; j < m_iCapacity; j++)
			{
				getValueFromMatrix(i, j, val);
				if (0 == val)
					continue;
				if (m_pNodeArray[i].m_bVisited)
					continue;
				Edge edge(i, j, val);
				edgeVec.push_back(edge);
			}
		}

		while (edgeCount < m_iCapacity - 1)
		{
			int retIndex = getMinEdge(edgeVec);
			if (-1 != retIndex)
			{
				edgeVec[retIndex].m_bSelected = true;
				int nodeAIndex = edgeVec[retIndex].m_iNodeIndexA;
				int nodeBIndex = edgeVec[retIndex].m_iNodeIndexB;
				bool nodeAInSet = false;
				bool nodeBInSet = false;
				int nodeAInSetLabel = -1;
				int nodeBInSetLabel = -1;

				for (int i = 0; i < (int)nodeSets.size(); i++)
				{
					nodeAInSet = isInSet(nodeSets[i], nodeAIndex);
					if (nodeAInSet)
						nodeAInSetLabel = i;
				}

				for (int i = 0; i < (int)nodeSets.size(); i++)
				{
					nodeBInSet = isInSet(nodeSets[i], nodeBIndex);
					if (nodeBInSet)
						nodeBInSetLabel = i;
				}
				if (nodeAInSetLabel == -1 && nodeBInSetLabel == -1)
				{
					vector<int> vec;
					vec.push_back(nodeAIndex);
					vec.push_back(nodeBIndex);
					nodeSets.push_back(vec);
				}
				else if (nodeAInSetLabel == -1 && nodeBInSetLabel != -1)
				{
					nodeSets[nodeBInSetLabel].push_back(nodeAIndex);
				}
				else if (nodeAInSetLabel != -1 && nodeBInSetLabel == -1)
				{
					nodeSets[nodeAInSetLabel].push_back(nodeBIndex);
				}
				else if (-1 != nodeAInSetLabel && -1 != nodeBInSetLabel && nodeAInSetLabel != nodeBInSetLabel)
				{
					nodeSets[nodeAInSetLabel].insert(nodeSets[nodeAInSetLabel].end(),
						nodeSets[nodeBInSetLabel].begin(),
						nodeSets[nodeBInSetLabel].end());
					for (int k = nodeBInSetLabel; k < (int)nodeSets.size() - 1; k++)
					{
						nodeSets[k] = nodeSets[k + 1];
					}
				}
				else if (nodeAInSetLabel != -1 && nodeBInSetLabel != -1 && nodeAInSetLabel == nodeBInSetLabel)
				{
					continue;
				}

				m_pEdgeArray[edgeCount] = edgeVec[retIndex];
				edgeCount++;

				cout << m_pNodeArray[edgeVec[retIndex].m_iNodeIndexA].m_cData << " - ";
				cout << m_pNodeArray[edgeVec[retIndex].m_iNodeIndexB].m_cData << " (";
				cout << edgeVec[retIndex].m_iWeightValue << ") " << endl;
			}
		}
	}
};


void main01(int argc, char**argv)
{
	int node = 0,edge=0;
	cin >> node;
	cin >> edge;
	CMap *pMap = new CMap(node);
	char node_data[10];
	for (int i = 0; i < node; i++) {
		cin >> node_data[i];
	}
	
	for (int i =0 ; i < node; i++)
	{
		Node *pNode = new Node(node_data[i]);
		pMap->addNode(pNode);
	}
	char getFirst[10],getSecond[10];
	int getData[10];
	for (int i = 0; i < edge; i++)
	{

		int j ,k;
		cin >> getFirst[i];
		cin >> getSecond[i];
		cin >> getData[i];
		for (j =0;j<node;j++){
			if(getFirst[i]==node_data[j]){
				break;
			}
		}
		for (k =0;k<node;k++){
			if(getFirst[i]==node_data[k]){
				break;
			}
		}
		pMap->setValueToMatrixForUndirectedGraph(j, k, getData[i]);
		
	}
}

//================================================================================================================//
//================================================================================================================//
//================================================================================================================//

typedef struct TestArc_001
{
	int adjvex;
	struct TestArc_001* nextarc;
}TestArc_001;
typedef struct View_test_001
{
	char data;
	TestArc_001* FirstStract;
	int Test_002;
}View_test_001, ADT_List[MaxSize];
typedef struct
{
	ADT_List View_001;
	int View_002, View_003;
}ADTGraph_Test_001;

int LocateVertex_Test_001(ADTGraph_Test_001 Graph_Data, char v)
{
	int i;
	for (i = 0; i < Graph_Data.View_002; i++)
		if (Graph_Data.View_001[i].data == v)
			return i;
	return -1;
}

void Create_Graph_Test_001(ADTGraph_Test_001* Graph_Data)
{
	int i, j, k;
	char Get_data_001, Get_data_002;
	TestArc_001* Get_Arc_001;
	cin>>Graph_Data->View_002>>Graph_Data->View_003;
	for (i = 0; i < Graph_Data->View_002; i++)
	{
		cin>> Graph_Data->View_001[i].data;
		Graph_Data->View_001[i].Test_002 = i;
		Graph_Data->View_001[i].FirstStract = NULL;

	}
	for (k = 0; k < Graph_Data->View_003; k++)

	{	
		cin>>Get_data_001>>Get_data_002;		
		i = LocateVertex_Test_001(*Graph_Data, Get_data_001);
		j = LocateVertex_Test_001(*Graph_Data, Get_data_002);
		Get_Arc_001 = (TestArc_001*)malloc(sizeof(TestArc_001));
		Get_Arc_001->adjvex = j;
		Get_Arc_001->nextarc = Graph_Data->View_001[i].FirstStract;
		Graph_Data->View_001[i].FirstStract = Get_Arc_001;
		Get_Arc_001 = (TestArc_001*)malloc(sizeof(TestArc_001));
		Get_Arc_001->adjvex = i;
		Get_Arc_001->nextarc = Graph_Data->View_001[j].FirstStract;
		Graph_Data->View_001[j].FirstStract = Get_Arc_001;
	}
}



void Display_Graph_Test_001(ADTGraph_Test_001 Graph_Data)
{
	int i, j,k;	
	TestArc_001* Get_Arc_001;
    char start;
	cin >> start;
	for ( k = 0; k < 30; k++) {
		if (start == Graph_Data.View_001[k].data) {
			break;
		}
	}
	for (i = 0; i < Graph_Data.View_002; i++)
	{
		Get_Arc_001 = Graph_Data.View_001[k].FirstStract;
		j = 0;
		while (Get_Arc_001 != NULL)
		{
			if (j == 0)
				cout<<Graph_Data.View_001[k].Test_002<<" "<< Graph_Data.View_001[k].data<<"-->" <<Graph_Data.View_001[Get_Arc_001->adjvex].Test_002;
			else
				cout<<"-->"<< Graph_Data.View_001[Get_Arc_001->adjvex].Test_002;
			j++;
			Get_Arc_001 = Get_Arc_001->nextarc;
		}
		k++;
		cout << endl;
	}
	for (i = 0; i < Graph_Data.View_002; i++)
		cout<<Graph_Data.View_001[i].data<<" ";
	cout << endl;
}

int main()
{

	ADTGraph_Test_001 Graph_Data;
	Create_Graph_Test_001(&Graph_Data);
	Display_Graph_Test_001(Graph_Data);
	return 0;
}


