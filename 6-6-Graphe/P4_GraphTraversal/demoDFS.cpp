#include <stdlib.h>
#include <iostream>
//#include <string.h>
using namespace std;

#define NUM 6
struct gNode{
	char name;
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
}

int main()
{
	gNode g[NUM];
	g[0].name = 'A'; g[0].ngb[0] = 2; g[0].ngb[1] = 4; g[0].ngb[2] = -1;
	g[1].name = 'B'; g[1].ngb[0] = 2; g[1].ngb[1] = 5; g[1].ngb[2] = -1;
	g[2].name = 'C'; g[2].ngb[0] = 0; g[2].ngb[1] = 1; g[2].ngb[2] = 3; g[2].ngb[3] = 5; g[2].ngb[4] = -1;
	g[3].name = 'D'; g[3].ngb[0] = 2; g[3].ngb[1] = 5; g[3].ngb[2] = -1;
	g[4].name = 'E'; g[4].ngb[0] = 0; g[4].ngb[1] = 5; g[4].ngb[2] = -1;
	g[5].name = 'F'; g[5].ngb[0] = 1; g[5].ngb[1] = 2; g[5].ngb[2] = 3; g[5].ngb[3] = 4; g[5].ngb[4] = -1;

	for(int i=0; i<NUM; i++){
		g[i].visited = false;
		for(int j=0; g[i].ngb[j]!=-1; j++)
			cout<< g[i].name << "---" << g[g[i].ngb[j]].name << "   ";
		cout << "\n";
	}

	DFS(g, NUM, 0);

	return 0;
}

