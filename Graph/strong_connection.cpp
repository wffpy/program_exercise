#include <iostream>
#include <map>
#include <vector>
// #include "graph.hpp"

using namespace std;

typedef std::map<int, std::vector<int>> Graph;
enum COLOR {WHITE, GRAY, BLACK};

struct VertexInfo{
	VertexInfo(): vertex_color(WHITE), vertex_fa(-1), vertex_d(0), vertex_f(0) {}
	COLOR vertex_color;
	int vertex_fa;
	int vertex_d;
	int vertex_f;
};

typedef std::map<int, VertexInfo> VertexInfoMap;

void printGraph(Graph& graph) {
	for (auto iter : graph) {
		std::cout << "start: " << iter.first << ": ";
		for (auto end : iter.second) {
			std::cout << end << ", ";
		}
		std::cout << endl;
	}
}

Graph reverseGraph(Graph& graph) {
	Graph reverse_graph;
	for (auto iter : graph) {
		for (auto end : iter.second) {
			reverse_graph[end].push_back(iter.first);
		}
	}
	return reverse_graph;
}

void DFSVisit(Graph& graph, VertexInfoMap& info_map, int& time, std::vector<int>& seq, int vertex) {
	if (info_map[vertex].vertex_color != WHITE) return;
	time = time + 1;	
	info_map[vertex].vertex_d = time;
	info_map[vertex].vertex_color = GRAY;
	// std::cout << "visit Vertex: " << vertex << std::endl;
	for (auto ver : graph[vertex]) {
		if (info_map[ver].vertex_color == WHITE) {
			info_map[ver].vertex_fa = vertex;
			DFSVisit(graph, info_map, time, seq, ver);
		}
	}
	info_map[vertex].vertex_color = BLACK;
	time = time + 1;
	info_map[vertex].vertex_f = time;
	seq.push_back(vertex);
	std::cout << "visit Vertex: " << vertex << std::endl;
}

VertexInfoMap DFS(Graph& graph, std::vector<int>& seq) {
	VertexInfoMap info_map;
	for (auto iter : graph) {
		VertexInfo info;
		info_map[iter.first] = info;
	}
	int time = 0;
	for (auto iter : graph) {
		DFSVisit(graph, info_map, time, seq, iter.first);
	}
	return info_map;
}

void DFSTwo(Graph& graph, std::vector<int>& seq) {
	VertexInfoMap info_map;
	for (auto iter : graph) {
		VertexInfo info;
		info_map[iter.first] = info;
	}
	int time = 0;
	while (!seq.empty()) {
		std::vector<int> local_seq;
		DFSVisit(graph, info_map, time, local_seq, seq.back());
		seq.pop_back();
	}
}

int main() {
	Graph graph;
	graph[0] = {1};
	graph[1] = {2, 3, 5};
	graph[2] = {0};
	graph[3] = {4, 6};
	graph[4] = {3, 7};
	graph[5] = {6};
	graph[6] = {5, 7};
	graph[7] = {7};
	printGraph(graph);
	std::cout << "graph vertex size: " << graph.size() << std::endl;
	std::vector<int> seq;
	seq.reserve(graph.size());

	DFS(graph, seq);

	Graph rev_graph = reverseGraph(graph);
	printGraph(rev_graph);
	DFSTwo(rev_graph, seq);

	std::cout << "strong connection test!!!" << std::endl;
	return 0;
}