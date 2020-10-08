#include<bits/stdc++.h>
using namespace std;

void printDFS(int **edges, int n, bool *visited, int sv) {
	cout<<sv<<" ";
	visited[sv] = true;
	for(int i=0;i<n;i++) {
		if(i == sv) {
			continue;
		}
		if(edges[sv][i] == 1 && !visited[i]) {
			printDFS(edges, n, visited, i);
		}
	}
}

int main() {
	int n, e;
	cout<<"Enter number of vertices: ";
	cin>>n;
	cout<<"Enter number of edges: ";
	cin>>e;
	int **edges = new int*[n];
	for(int i=0;i<n;i++) {
		edges[i] = new int[n];
		for(int j=0;j<n;j++) {
			edges[i][j] = 0;
		}
	}
	for(int i=0;i<e;i++) {
		int f, s;
		cout<<"Enter the first edge: ";
		cin>>f;
		cout<<"Enter the second edge: ";
		cin>>s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	bool *visited = new bool[n];
	for(int i=0;i<n;i++) {
		visited[i] = false;
	}
	printDFS(edges, n, visited, 0);
	return 0;
}
