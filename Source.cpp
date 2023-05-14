#include"Graph.h"





void main()
{
	vector<Edge> Edges;
	vector<Edge> prima;
	vector<Edge> kraskal;

	Edges.push_back(Edge::Edge(1, 2, 14));
	Edges.push_back(Edge::Edge(1, 6, 8));
	Edges.push_back(Edge::Edge(2, 3, 5));
	Edges.push_back(Edge::Edge(2, 4, 10));
	Edges.push_back(Edge::Edge(2, 5, 2));
	Edges.push_back(Edge::Edge(2, 6, 2));
	Edges.push_back(Edge::Edge(2, 8, 9));
	Edges.push_back(Edge::Edge(3, 8, 11));
	Edges.push_back(Edge::Edge(4, 5, 3));
	Edges.push_back(Edge::Edge(4, 6, 6));
	Edges.push_back(Edge::Edge(4, 7, 5));
	Edges.push_back(Edge::Edge(5, 7, 8));
	Edges.push_back(Edge::Edge(5, 8, 1));
	Edges.push_back(Edge::Edge(6, 7, 5));
	Edges.push_back(Edge::Edge(7, 8, 7));
	Graph g(Edges,8);
	kraskal = g.Kraskal();



	auto begin = chrono::steady_clock::now();
	prima = g.Prima();
	auto end = chrono::steady_clock::now();
	auto elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
	cout << "\nThe time of prima: " << elapsed_ms.count() << " mcss\n";

	begin = chrono::steady_clock::now();
	kraskal = g.Kraskal();
	end = chrono::steady_clock::now();
	elapsed_ms = chrono::duration_cast<chrono::microseconds>(end - begin);
	cout << "\nThe time of kraskal: " << elapsed_ms.count() << " mcss\n";

	cout << "\nPrima: "<<endl;
	for (int i = 0; i < prima.size(); i++) {
		cout<<prima[i].V1 << '-' << prima[i].V2 << endl;
	}

	cout << "\nKraskal: " << endl;
	for (int i = 0; i < kraskal.size(); i++) {
		cout << kraskal[i].V1 << '-' << kraskal[i].V2 << endl;
	}

}