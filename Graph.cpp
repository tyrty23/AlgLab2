#include "Graph.h"

Graph::Graph(vector<Edge> e,int n)
{
	this->Edges = e;
	this->CountV = n;
	
	//AdjMatrix = new int* [n];
	//for (int i = 0; i < n; i++)
	//	AdjMatrix[i] = new int[n];
	//for (int i = 0; i < n; i++)
	//	for (int j = 0; j < n; j++)
	//		AdjMatrix[i][j] = 1023;
	//for (Edge e : Edges) {
	//	AdjMatrix[e.V1][e.V2] = e.weight;
	//	AdjMatrix[e.V2][e.V1] = e.weight;
	//}
}


vector<Edge> Graph::Kraskal()
{
	vector<set<int>> komponent;
	vector<Edge> answer;
	sort(Edges.begin(), Edges.end(), [](Edge e1, Edge e2){return e1.weight < e2.weight; });

	answer.push_back(Edges[0]);
	komponent.push_back({ Edges[0].V2 });
	komponent[0].insert(Edges[0].V1);

	int count = 1;

	for (int i = 1; i < Edges.size(); i++) {
		vector<int> flag;
		bool flag2 = true;
		for (int j = 0; j < count; j++)
		{
			int countV = 0;
			int a;

			if (komponent[j].find(Edges[i].V2) != komponent[j].end()) { countV++; a = Edges[i].V1; }
			if (komponent[j].find(Edges[i].V1) != komponent[j].end()) { countV++; a = Edges[i].V2; }

			if (countV == 1)
			{
				komponent[j].insert(a);
				flag.push_back(j);
			}
			if (countV == 2) { flag2 = false; }
		}

		switch (flag.size()) {
		case 0:
			if (flag2) {
				komponent.push_back({ Edges[i].V2, Edges[i].V1 });
				count++;
				answer.push_back(Edges[i]);
			}
			break;
		case 1:
			answer.push_back(Edges[i]);
			break;
		case 2:
			komponent[flag[0]].insert(komponent[flag[1]].begin(), komponent[flag[1]].end());
			answer.push_back(Edges[i]);
			komponent[flag[1]].clear();
			break;
		}
	}




	return answer;
}



vector<Edge> Graph::Prima()
{
	vector<Edge> answer;
	set<int> komponent;
	Edge e;
	komponent.insert(Edges[0].V1);
	while (answer.size() < CountV-1) {
		e = MinEdge( komponent);
		if (!(e.V1 == -1)) {
			answer.push_back(e);
			komponent.insert(e.V1);
			komponent.insert(e.V2);
		}
		else {break;}
	}
	return answer;
}

Edge Graph::MinEdge(set<int> komp)
{
	Edge rm;
	for (int v : komp) {
		for (Edge e : Edges) {
			if ((e.V1 == v || e.V2 == v) && (komp.find( e.V1) == komp.end() || komp.find(e.V2) == komp.end())) {
				if (rm.weight > e.weight) {rm = e;}
			}
		}
	}
	return rm;
}


