#include <iostream>
#include <cstdio>
#include <list>
#include <vector>
#include "csce310hw03pt01.h"

using namespace std;

class undirected
{
  int vertexes;
  list<int> *connected;
  bool LoopTest(int vertex, bool visited[], int root);

public:
  undirected(int vertexes);
  void addEdge(int vertex1, int vertex2);
  bool Loop();
};

void undirected::addEdge(int vertex1, int vertex2)
{
  connected[vertex1].push_back(vertex2);
  connected[vertex2].push_back(vertex1);
}

undirected::undirected(int vertexes)
{
  this->vertexes = vertexes;
  connected = new list<int>[vertexes];
}

bool undirected::LoopTest(int vertex, bool visited[], int root)
{
  list<int>::iterator i;
  visited[vertex] = 1;
  for (i = connected[vertex].begin(); i != connected[vertex].end(); ++i)
  {
    if (!visited[*i])
    {
      if (LoopTest(*i, visited, vertex))
      {
        return 1;
      }
    }
    else if (*i != root)
    {
      return 1;
    }
  }
  return 0;
}

bool undirected::Loop()
{
  bool *visited = new bool[vertexes];
  for (int i = 0; i < vertexes; i++)
  {
    visited[i] = false;
  }
  for (int j = 0; j < vertexes; j++)
  {
    if (!visited[j])
    {
      if (LoopTest(j, visited, -1))
      {
        return 1;
      }
    }
  }
  return 0;
}

double maximumST(vector<vector<double>> adjacencyMatrix)
{
  cerr << endl;
  int maximumSpanning = 0;
  int n = adjacencyMatrix[0].size();
  bool nodeVisited[n];
  int maxWeight = 0;
  int edgei, edgej = 0;
  for (int i = 0; i < n; i++)
  {
    nodeVisited[i] = false;
    for (int j = 0; j < n; j++)
    {
      int value = adjacencyMatrix[i][j];
      fprintf(stderr, "% 3d ", value);
    }
    cerr << endl;
  }

  vector<int> edgeWeights;
  vector<vector<int>> pointSet;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (adjacencyMatrix[i][j] != 0)
      {
        edgeWeights.push_back(adjacencyMatrix[i][j]);
        vector<int> points = {i, j};
        pointSet.push_back(points);
      }
    }
  }

  for (int i = 0; i < edgeWeights.size() - 1; i++)
  {
    for (int j = 0; j < edgeWeights.size() - i - 1; j++)
    {
      if (edgeWeights[j] < edgeWeights[j + 1])
      {
        swap(edgeWeights[j], edgeWeights[j + 1]);
        swap(pointSet[j], pointSet[j + 1]);
      }
    }
  }

  for (int i = 0; i < pointSet.size(); i++)
  {
    undirected tester(pointSet.size());

    for (int j = 0; j <= i; j++)
    {
      int pog1 = pointSet[j][0];
      int pog2 = pointSet[j][1];
      if (pog1 == -1)
      {
        continue;
      }
      tester.addEdge(pog1, pog2);
    }

    int flag = tester.Loop();

    if (!flag)
    {
      maximumSpanning += edgeWeights[i];
    }
    else
    {
      pointSet[i][0] = -1;
      pointSet[i][1] = -1;
    }
  }

  return maximumSpanning;
}
