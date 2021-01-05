#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "MinHeap.h"
using namespace std;

#define NUM 8 

struct gNode{
	int index;
	int ngb[NUM]; // neighbours
	bool visited;
	gNode* root;
};
struct gEdge{
	int nodes[2];
	int dist;
};

class gEdgeCompare{
public:
	static bool lt(gEdge x, gEdge y){ return x.dist < y.dist; }
	static bool eq(gEdge x, gEdge y){ return x.dist == y.dist; }
	static bool gt(gEdge x, gEdge y){ return x.dist > y.dist; }
};

gNode* FindRoot(gNode *nd)
{
	gNode *curr = nd;
	while (curr->root != curr){
		curr = curr->root;
		nd->root = curr->root;
	}
	return curr->root;
}

int main()
{
	int gMat[NUM][NUM];
	for(int i=0; i<NUM; i++)
		for(int j=0; j<NUM; j++)
			gMat[i][j] = -1;
	gMat[0][1] = 18; gMat[1][0] = 18;
	gMat[0][2] = 14; gMat[2][0] = 14;
	gMat[0][3] = 23; gMat[3][0] = 23;
	gMat[1][2] = 8; gMat[2][1] = 8;
	gMat[1][4] = 12; gMat[4][1] = 12;
	gMat[1][7] = 25; gMat[7][1] = 25;
	gMat[2][3] = 10; gMat[3][2] = 10;
	gMat[2][4] = 7; gMat[4][2] = 7;
	gMat[2][5] = 9; gMat[5][2] = 9;
	gMat[3][5] = 11; gMat[5][3] = 11;
	gMat[3][6] = 19; gMat[6][3] = 19;
	gMat[4][5] = 6; gMat[5][4] = 6;
	gMat[4][6] = 13; gMat[6][4] = 13;
	gMat[4][7] = 15; gMat[7][4] = 15;
	gMat[5][6] = 10; gMat[6][5] = 10;
	gMat[6][7] = 17; gMat[7][6] = 17;	

	gNode g[NUM]; 
	gEdge hp[NUM*NUM], eMST[NUM-1], etmp;
	MinHeap<gEdge,gEdgeCompare> hpDist(hp,0, NUM*NUM);

	for(int i=0; i<NUM; i++){
		g[i].index = i;
		g[i].visited = false;
		g[i].root = &g[i];
		int idx=0;
		for(int j=0; j<NUM; j++){
			if (gMat[i][j]>0){
				g[i].ngb[idx++] = j;
				if (i<j){
					etmp.dist = gMat[i][j];
					etmp.nodes[0] = i;
					etmp.nodes[1] = j;
					hpDist.insert(etmp);
				}
			}
		}
		g[i].ngb[idx] = -1;
	}
	for(int i=0; i<NUM; i++){
		cout << "Node " << i << " neighbors : ";
		for(int j=0; g[i].ngb[j]>-1; j++)
			cout << "D(" << i << ","  << g[i].ngb[j] << ")=" << gMat[i][g[i].ngb[j]] << "  ";
		cout << "\n";
	}

	int nEdge=0;
	while(nEdge<NUM-1){
		hpDist.removemin(etmp);
		gNode *root1 = FindRoot(&g[etmp.nodes[0]]), *root2 = FindRoot(&g[etmp.nodes[1]]);
		if (root1 == root2) continue;
		root2->root = root1;
		eMST[nEdge++] = etmp;
		cout << "MST edges :";
		for(int i=0; i<nEdge; i++) cout  << eMST[i].nodes[0] << "--" << eMST[i].nodes[1] << "  ";
		cout << "\n";
	}
	cout<<(0+9)/2;

	return 0;
}


