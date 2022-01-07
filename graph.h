#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Graph
{
    private:
        bool** adjacencyMatrix; // Tablica dynamiczna przechowująca wartości grafu. 
        int numVertices; // Zmienna przechowująca liczbę wierzchołków.

    public:
        Graph(int numVertices); // Konstruktor.
        Graph(string fileName); // Konstruktor (wczytywanie grafu z pliku).

        ~Graph(); // Destruktor.

        string GetIsolatedVertices(); // Wierzchołki izolowane.
        string GetLoops(); // Pętle.
        string GetBiDirectionalEdges(); // Krawędzie dwukierunkowe.
        string GetInDegrees(); // Stopnie wchodzące wszystkich wierzchołków.
        string GetOutDegrees(); // Stopnie wychodzące wszystkich wierzchołków.
        string ToString(); // Graf jako string (w wersji macierzowej).
        string GetNeighborsOfAllVertices(); // Wszyscy sąsiedzi dla każdego wierzchołka grafu.
        string GetVerticesThatAreNeighborsOfEachVertex(); // Wszystkie wierzchołki, które są sąsiadami każdego wierzchołka.

        void AddEdge(int i, int j); // Dodawanie krawędzi.
        void RemoveEdge(int i, int j); // Usuwanie krawędzi.
};

#endif // GRAPH_H