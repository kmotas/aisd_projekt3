#include <iostream>
#include <fstream>
#include "graph.h"

void saveResults(string fileName, string results)
{
    fstream out;
    out.open(fileName, ios::out);

    out << results;
    out.close();

    cout << "Zapisano rezultaty testow funkcji do pliku " << fileName << "." << endl << endl;
}

int main()
{
    // Graf wpisywany w kodzie.
	Graph g(4);

    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 0);
    g.AddEdge(2, 3);

    // Wyświetlamy graf.
    cout << g.ToString() << endl << endl;

    // 1. Wszyscy sąsiedzi dla każdego wierzchołka grafu.
    cout << g.GetNeighborsOfAllVertices() << endl << endl;

    // 2. Wszystkie wierzchołki, które są sąsiadami każdego wierzchołka.
    cout << g.GetVerticesThatAreNeighborsOfEachVertex() << endl << endl;

    // 3. Stopnie wychodzące wszystkich wierzchołków.
    cout << g.GetOutDegrees() << endl << endl;

    // 4. Stopnie wchodzące wszystkich wierzchołków.
    cout << g.GetInDegrees() << endl << endl;

    // 5. Wszystkie wierzchołki izolowane.
    cout << g.GetIsolatedVertices() << endl << endl;

    // 6. Wszystkie pętle.
    cout << g.GetLoops() << endl << endl;

    // 7. Wszystkie krawędzie dwukierunkowe.
    cout << g.GetBiDirectionalEdges() << endl << endl;

    // Zapisywanie danych do pliku testowego.
    saveResults("g_results.txt", g.GetNeighborsOfAllVertices() + "\n\n" + g.GetVerticesThatAreNeighborsOfEachVertex() + "\n\n" + g.GetOutDegrees() + "\n\n" + g.GetInDegrees() + "\n\n" + g.GetIsolatedVertices() + "\n\n" + g.GetLoops() + "\n\n" + g.GetBiDirectionalEdges());


    // Graf wczytywany z pliku.
    Graph f("matrix.txt");

    // Wyświetlamy graf.
    cout << f.ToString() << endl << endl;

    // 1. Wszyscy sąsiedzi dla każdego wierzchołka grafu.
    cout << f.GetNeighborsOfAllVertices() << endl << endl;

    // 2. Wszystkie wierzchołki, które są sąsiadami każdego wierzchołka.
    cout << f.GetVerticesThatAreNeighborsOfEachVertex() << endl << endl;

    // 3. Stopnie wychodzące wszystkich wierzchołków.
    cout << f.GetOutDegrees() << endl << endl;

    // 4. Stopnie wchodzące wszystkich wierzchołków.
    cout << f.GetInDegrees() << endl << endl;

    // 5. Wszystkie wierzchołki izolowane.
    cout << f.GetIsolatedVertices() << endl << endl;

    // 6. Wszystkie pętle.
    cout << f.GetLoops() << endl << endl;

    // 7. Wszystkie krawędzie dwukierunkowe.
    cout << f.GetBiDirectionalEdges() << endl << endl;

    // Zapisywanie danych do pliku testowego.
    saveResults("f_results.txt", f.GetNeighborsOfAllVertices() + "\n\n" + f.GetVerticesThatAreNeighborsOfEachVertex() + "\n\n" + f.GetOutDegrees() + "\n\n" + f.GetInDegrees() + "\n\n" + f.GetIsolatedVertices() + "\n\n" + f.GetLoops() + "\n\n" + f.GetBiDirectionalEdges());

	return 0;
}