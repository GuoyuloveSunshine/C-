#include <stdlib.h>
#include <iostream>
#include <string.h>
#include "MinHeap.h"
using namespace std;

#define NUM 8 

#define MAX_DIST 100000
struct gNode{
	int index;
	int ngb[NUM]; // neighbours
	bool visited;
	int dist;
	void print(){cout << index;};
};

class gNodeCompare{
public:
	static bool lt(gNode x, gNode y){ return x.dist < y.dist; }
	static bool eq(gNode x, gNode y){ return x.dist == y.dist; }
	static bool gt(gNode x, gNode y){ return x.dist > y.dist; }
};


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
	gNode g[NUM], hp[NUM], gMin;
	for(int i=0; i<NUM; i++){
		g[i].index = i;
		g[i].dist = MAX_DIST;
		g[i].visited = false;
		int idx=0;
		for(int j=0; j<NUM; j++)
			if (gMat[i][j]>0)
				g[i].ngb[idx++] = j;
		g[i].ngb[idx] = -1;
	}

	for(int i=0; i<NUM; i++){
		cout << "Node " << i << " neighbors : ";
		for(int j=0; g[i].ngb[j]>-1; j++)
			cout << "D(" << i << ","  << g[i].ngb[j] << ")=" << gMat[i][g[i].ngb[j]] << "  ";
		cout << "\n";
	}

	// Create an int minheap tree
	MinHeap<gNode,gNodeCompare> hpDist(hp,0, NUM);
	g[0].dist = 0;
	hpDist.insert(g[0]);

	while (hpDist.heapsize()>0){
		hpDist.removemin(gMin);
		if (g[gMin.index].visited) continue;  // The vertex in most fresh state has already been extracted
		g[gMin.index].visited = true;		
		cout << "Current node "<< gMin.index << " with distance "<< gMin.dist << "\n";
		for(int i=0; g[gMin.index].ngb[i]>-1; i++){
			if (g[g[gMin.index].ngb[i]].visited) continue;
			int tmp_dist = g[gMin.index].dist+gMat[gMin.index][g[gMin.index].ngb[i]];
			if (g[g[gMin.index].ngb[i]].dist>tmp_dist){
				g[g[gMin.index].ngb[i]].dist = tmp_dist;
				hpDist.insert(g[g[gMin.index].ngb[i]]);
			}
		}
		hpDist.print();
	}

	return 0;
}


