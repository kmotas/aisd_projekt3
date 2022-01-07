#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Graph
{
    private:
        bool** adjacencyMatrix; // Tablica dynamiczna przechowuj�ca warto�ci grafu.
        int numVertices; // Zmienna przechowuj�ca liczb� wierzcho�k�w.

    public:
        Graph(int numVertices); // Konstruktor.
        Graph(string fileName); // Konstruktor (wczytywanie grafu z pliku).

        ~Graph(); // Destruktor.

        string GetIsolatedVertices(); // Wierzcho�ki izolowane.
        string GetLoops(); // P�tle.
        string GetBiDirectionalEdges(); // Kraw�dzie dwukierunkowe.
        string GetInDegrees(); // Stopnie wchodz�ce wszystkich wierzcho�k�w.
        string GetOutDegrees(); // Stopnie wychodz�ce wszystkich wierzcho�k�w.
        string ToString(); // Graf jako string (w wersji macierzowej).
        string GetNeighborsOfAllVertices(); // Wszyscy s�siedzi dla ka�dego wierzcho�ka grafu.
        string GetVerticesThatAreNeighborsOfEachVertex(); // Wszystkie wierzcho�ki, kt�re s� s�siadami ka�dego wierzcho�ka.

        void AddEdge(int i, int j); // Dodawanie kraw�dzi.
        void RemoveEdge(int i, int j); // Usuwanie kraw�zi.
};

#endif // GRAPH_H
