#include <iostream>
#include <vector>
#include <assert.h>
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

//==============================================================================================================
//==============================================================================================================

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

//==============================================================================================================
//==============================================================================================================


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
		//memset(m_pMatrix, 0, m_iCapacity*m_iCapacity * sizeof(int));
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
				if (0 != val)
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
			if (0 != val)
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


//==============================================================================================================
//==============================================================================================================

const int maxVertices = 20;		
const int DefaultVertices = 10;						

template <class T, class E>
class Graph;

template <class T, class E>
istream& operator>> (istream& ResData, Graph<T, E>& G);

template <class T, class E>
ostream& operator<< (ostream& out, Graph<T, E>& G);


template <class T, class E>
class Graph
{
	friend istream& operator >> <> (istream& ResData, Graph<T, E>& G);		
	friend ostream& operator << <> (ostream& out, Graph<T, E>& G);		
public:
	const E maxWeight = 1000; 
	Graph ();										
	Graph (T _vtxNull, E _wtNull, E _wtMax);		
	~Graph();										
	int NumberOfVertices();
	int NumberOfEdges();
	T getValue (int i);								
	E getWeight (int v1, int v2);					
	int getFirstNeighbor (int res);
	int getNextNeighbor (int res, int Test003);	
	bool insertVertex (const T& vertex);
	bool insertEdge (int v1, int v2, E cost);
	bool removeVertex (int res);
	bool removeEdge (int v1, int v2);
protected:
	int maxVertices;
	int numEdges;
	int numVertices;
	T vtxNull;			 
	E wtNull;			
	E wtMax;			
private:
	T * VerticesList;			
	E * *Edges;								
 	int getVertexPos (T vertex);					
};


template <class T, class E>
Graph<T, E>::Graph(T _vtxNull, E _wtNull, E _wtMax) 
{
	maxVertices = DefaultVertices;	
	numVertices = 0;				
	numEdges = 0;				
	
	vtxNull =_vtxNull;	
	wtNull =_wtNull;	
	wtMax =_wtMax;		
	
	VerticesList = new T[maxVertices];				
	Edges = (E **) new E*[maxVertices];				
	for (int i = 0; i<maxVertices; i++)
		Edges[i] = new E[maxVertices];
	for (int i = 0; i<maxVertices; i++)
		for (int j = 0; j<maxVertices; j++)
			Edges[i][j] = (i==j)?wtNull:wtMax;		
};

template <class T, class E>
Graph<T, E>::~Graph()
{
     delete [] VerticesList;
	 delete [] Edges; 
};

template <class T, class E>
int Graph<T, E>::NumberOfVertices()
{ 
     return numVertices;
} 

template <class T, class E>
int Graph<T, E>::NumberOfEdges()
{ 
	return numEdges;
} 

template <class T, class E>
T Graph<T, E>::getValue(int i)
{ 
     return i>=0 && i<= numVertices?VerticesList[i] : NULL;
} 
template <class T, class E>
E Graph<T, E>::getWeight(int v1, int v2)
{
	return v1!= -1 && v2 != -1 ? Edges[v1][v2] : 0;
}
template <class T, class E>
int Graph<T, E>::getVertexPos (T Vertex)
{
	for(int i=0;i<numVertices;i++)
	  if(VerticesList[i] == Vertex)
	    return i;
	    
	return -1;

};

template <class T, class E>
int Graph<T, E>::getFirstNeighbor (int res)
{

}

template <class T, class E>
int Graph<T, E>::getNextNeighbor (int res, int Test003)
{
	if(res != 0 && Test003 != -1)
	{
		for(int col = Test003+1;col<numVertices;col++)
		{
			if(Edges[res][col]>0 && Edges[res][col]<maxWeight)
			return col; 
		} 
		return -1;
	 } 

}

template <class T, class E>
bool Graph<T, E>::insertVertex(const T& vertex)
{  
    if(numVertices == maxVertices)
    {
    	return false;
	}
	VerticesList[numVertices++] = vertex;
	return true; 
}  

template <class T, class E>
bool Graph<T, E>::insertEdge(int v1, int v2, E cost)
{  
	if(v1 > -1 && v1<numVertices && v2 >-1 && v2<numVertices&& Edges[v1][v2] >= maxWeight )
	{
		Edges[v1][v2] = Edges[v2][v1] = cost;
		numEdges++;
		return true;
	}
	else
	return false;
}

template <class T, class E>
bool Graph<T, E>::removeVertex(int res)
{
	if(res<0 || res>= numVertices)
	  return false; 
	if(numVertices == 1)
	  return false;
	int i,j;
	VerticesList[res] = VerticesList[numVertices - 1];
	for(i=0;i<numVertices;i++)
	{
		if(Edges[i][res]> 0 && Edges[i][res] < maxWeight)
		{
			numEdges--;
		}
	 } 
	 for(i=0 ;i<numVertices; i++)
	 { 
	 	Edges[i][res] = Edges[i][numVertices-1];
	  } 
	  numVertices--;
	  for(j=0;j<numVertices; j++)
	  {
	  	Edges[res][j] = Edges[numVertices][j];
	  } 
	  return true; 
}  
template <class T, class E>
bool Graph<T, E>::removeEdge(int v1, int v2)
{
}  
template <class T, class E>
istream & operator>> (istream& ResData, Graph<T, E>& G)
{
	int i,j,k,Src001,Src002;
	T v1, v2;
	E weight;
	ResData >> Src001 >> Src002;

	for (i=0; i<Src001; i++)	
	{
		ResData >> v1;
		G.insertVertex(v1);
	}
	i = 0;
	while (i<Src002)									
	{
		ResData >> v1 >> v2 >> weight;				
		j = G.getVertexPos(v1);						
		k = G.getVertexPos(v2);
		if (i==-1 || k==-1)
			cout << "Wrong vertex number, retry:" << endl;
		else
		{
			G.insertEdge(j,k,weight);			
			i++;
		}
	}

	return ResData;
}
template <class T, class E>
ostream& operator << (ostream& out, Graph<T, E>& G)
{
	int Src001,Src002;
	T Test001, Test002;
	E Test003;
	Src001 = G.NumberOfVertices();
	Src002 = G.NumberOfEdges();
	for (int i=0; i<Src001; i++)
		for (int j=i+1; j<Src001; j++)
		{
			Test003 = G.getWeight(i,j);
			if (Test003>G.wtNull && Test003<G.wtMax)
			{
				Test001 = G.getValue(i);
				Test002 = G.getValue(j);
				out << "(" << Test001 << "," << Test002 << "," << Test003 << ")" << endl;
			}
		}

	cout << endl;
	return out;
}
void function(){
		Graph<char, int> View('\0', 0, 9999);	

	cin >> View;	


	cout << View;
}


int main()
{
	function();
	return 0;									
}



