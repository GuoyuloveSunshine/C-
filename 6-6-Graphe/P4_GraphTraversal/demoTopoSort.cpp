#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

#define NUM 7
struct gNode{
	string name;
	int ngb[NUM]; // neighbours
	bool visited;
};

void DFS(gNode* g, int n, int stt)
{
	g[stt].visited = true;
	cout << "Arrive at  " << g[stt].name << endl;
	for(int i=0; g[stt].ngb[i]!=-1; i++)
		if (!g[g[stt].ngb[i]].visited)
			DFS(g, n, g[stt].ngb[i]);
	cout << "=> " << g[stt].name << endl;
}

int main()
{
	gNode g[NUM];
	g[0].name = "Job1"; g[0].ngb[0] = 1; g[0].ngb[1] = 2; g[0].ngb[2] = -1;
	g[1].name = "Job2"; g[1].ngb[0] = 5; g[1].ngb[1] = 4; g[1].ngb[2] = 3; g[1].ngb[3] = -1;
	g[2].name = "Job3"; g[2].ngb[0] = 3; g[2].ngb[1] = -1;
	g[3].name = "Job4"; g[3].ngb[0] = 4; g[3].ngb[1] = -1;
	g[4].name = "Job5"; g[4].ngb[0] = 6; g[4].ngb[1] = -1;
	g[5].name = "Job6"; g[5].ngb[0] = -1;
	g[6].name = "Job7"; g[6].ngb[0] = -1;

	for(int i=0; i<NUM; i++){
		g[i].visited = false;
		for(int j=0; g[i].ngb[j]!=-1; j++)
			cout<< g[i].name << "-->" << g[g[i].ngb[j]].name << "   ";
		cout << "\n";
	}

	DFS(g, NUM, 0);

	return 0;
}

