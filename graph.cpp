#include "graph.h"

Graph::Graph(int numVertices)
{
	this->numVertices = numVertices;
	adjacencyMatrix = new bool* [numVertices];

	for (int i = 0, j; i < numVertices; i++)
	{
		adjacencyMatrix[i] = new bool[numVertices];

		for (j = 0; j < numVertices; j++)
			adjacencyMatrix[i][j] = false;
	}
}

Graph::Graph(string fileName)
{
	ifstream file(fileName, fstream::in);

	if (file.good())
	{
		file >> numVertices;
		adjacencyMatrix = new bool* [numVertices];

		for (int i = 0, j; i < numVertices; i++)
		{
			adjacencyMatrix[i] = new bool[numVertices];

			for (j = 0; j < numVertices; j++)
				file >> adjacencyMatrix[i][j];
		}

		file.close();
	}
	else cout << "Plik " << fileName << " nie istnieje!" << endl;
}

Graph::~Graph()
{
	for (int i = 0; i < numVertices; i++)
		delete[] adjacencyMatrix[i];

	delete[] adjacencyMatrix;
}

string Graph::GetIsolatedVertices()
{
	string results;
	bool isIsolated;

	for (int i = 0, j; i < numVertices; i++)
	{
		isIsolated = true;

		for (j = 0; j < numVertices; j++)
		{
			if ((adjacencyMatrix[i][j] + adjacencyMatrix[j][i]) > 0)
			{
				isIsolated = false;
				break;
			}
		}

		if (isIsolated)
			results += "\n" + to_string(i + 1);
	}

	results = (!results.size()) ? "Zaden wierzcholek nie jest izolowany!" : ("Lista wierzcholkow izolowanych:" + results);
	return results;
}

string Graph::GetLoops()
{
	string results;

	for (int i = 0; i < numVertices; i++)
	{
		if (adjacencyMatrix[i][i])
			results += "\n" + to_string(i + 1);
	}

	results = (!results.size()) ? "Nie znaleziono zadnych petli!" : ("Lista petli:" + results);
	return results;
}

string Graph::GetBiDirectionalEdges()
{
	string results;

	for (int i = 0, j; i < numVertices - 1; i++)
	{
		for (j = i + 1; j < numVertices; j++)
		{
			if (adjacencyMatrix[i][j] && adjacencyMatrix[j][i])
				results += "\n" + to_string(i + 1) + ": " + to_string(j + 1);
		}
	}
	
	results = (!results.size()) ? "Nie znaleziono krawedzi dwukierunkowych!" : ("Lista krawedzi dwukierunkowych:" + results);
	return results;
}

string Graph::GetInDegrees()
{
	string results = "Stopnie wchodzace wszystkich wierzcholkow:";

	for (int i = 0, j, degree; i < numVertices; i++)
	{
		degree = 0;

		for (j = 0; j < numVertices; j++)
			degree += adjacencyMatrix[j][i];

		results += "\n" + to_string(i + 1) + ": " + to_string(degree);
	}

	return results;
}

string Graph::GetOutDegrees()
{
	string results = "Stopnie wychodzace wszystkich wierzcholkow:";

	for (int i = 0, j, degree; i < numVertices; i++)
	{
		degree = 0;

		for (j = 0; j < numVertices; j++)
			degree += adjacencyMatrix[i][j];

		results += "\n" + to_string(i + 1) + ": " + to_string(degree);
	}

	return results;
}

string Graph::ToString()
{
	string results = "Macierz sasiedztwa:";

	for (int i = 0, j; i < numVertices; i++)
	{
		results += "\n" + to_string(i + 1) + ":";

		for (j = 0; j < numVertices; j++)
			results += " " + to_string(adjacencyMatrix[i][j]);
	}

	return results;
}

void Graph::AddEdge(int i, int j)
{
	adjacencyMatrix[i][j] = true;
	adjacencyMatrix[j][i] = true;
}

void Graph::RemoveEdge(int i, int j)
{
	adjacencyMatrix[i][j] = false;
	adjacencyMatrix[j][i] = false;
}

string Graph::GetNeighborsOfAllVertices()
{
	string results = "Wszyscy sasiedzi dla kazdego wierzcholka grafu:";

	for (int i = 0, j; i < numVertices; i++)
	{
		results += "\n" + to_string(i + 1) + ":";

		for (j = 0; j < numVertices; j++)
			if (adjacencyMatrix[i][j]) results += " " + to_string(j + 1);
	}

	return results;
}

string Graph::GetVerticesThatAreNeighborsOfEachVertex()
{
	string results;

	for (int i = 0, j, counter; i < numVertices; i++)
	{
		counter = 0;

		for (j = 0; j < numVertices; j++)
			if (adjacencyMatrix[i][j]) ++counter;

		if (counter == numVertices)
			results += "\n" + to_string(i + 1);
	}

	results = (!results.size()) ? "Nie znaleziono zadnego wierzcholka, ktory jest sasiadem kazdego wierzcholka!" : ("Lista wierzcholkow, ktore sa sasiadami kazdego wierzcholka:" + results);
	return results;
}