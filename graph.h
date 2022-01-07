#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Graph
{
    private:
        bool** adjacencyMatrix; // Tablica dynamiczna przechowuj¹ca wartoœci grafu.
        int numVertices; // Zmienna przechowuj¹ca liczbê wierzcho³ków.

    public:
        Graph(int numVertices); // Konstruktor.
        Graph(string fileName); // Konstruktor (wczytywanie grafu z pliku).

        ~Graph(); // Destruktor.

        string GetIsolatedVertices(); // Wierzcho³ki izolowane.
        string GetLoops(); // Pêtle.
        string GetBiDirectionalEdges(); // Krawêdzie dwukierunkowe.
        string GetInDegrees(); // Stopnie wchodz¹ce wszystkich wierzcho³ków.
        string GetOutDegrees(); // Stopnie wychodz¹ce wszystkich wierzcho³ków.
        string ToString(); // Graf jako string (w wersji macierzowej).
        string GetNeighborsOfAllVertices(); // Wszyscy s¹siedzi dla ka¿dego wierzcho³ka grafu.
        string GetVerticesThatAreNeighborsOfEachVertex(); // Wszystkie wierzcho³ki, które s¹ s¹siadami ka¿dego wierzcho³ka.

        void AddEdge(int i, int j); // Dodawanie krawêdzi.
        void RemoveEdge(int i, int j); // Usuwanie krawêzi.
};

#endif // GRAPH_H
