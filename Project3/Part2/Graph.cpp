/*
 * File: Graph.cpp
 * Course: CS216-002
 * Project: Project 3 Part 1
 * Purpose: Definition of Graph class
 *          This class represents an undirected Graph (no weight on each edge)
 *          using adjacent map representation
 *          It contains one private data memeber: adjMap
 *          which represents the mapping from a Vertex, say u (key) to a set of vertices (value) which directly connect to u 
 * Author: Bryce Grant
 */

// Include guards for .cpp file
#ifndef GRAPH_CPP
#define GRAPH_CPP
#include "Graph.h"
#include <map>
#include <set>
#include <queue>
#include <iostream>
using namespace std;

// statement sequence below, with template parameters added

template <typename T>

Graph<T>::Graph(){

}

// to check if an edge exists between v and w
template <typename T>
bool Graph<T>::hasEdge(T v, T w) const{
	if (adjMap.find(v) == adjMap.end())
		return false;
	if (adjMap.at(v).find(w) != adjMap.at(v).end())
		return true;
	else 
		return false;
}
    
// to add an edge beween v and w to the graph
template <typename T>
void Graph<T>::addEdge(T v, T w){
	adjMap[v].insert(w);
	adjMap[w].insert(v);
}


// Apply BFS traversal to find the shortest path from the given source s to destination t
// return the distnace from s to t
// if s or t does not exist, return INVALID_VERTEX (=-2) 
// if there is no path from s to t, return NOPATH (=-1)
// store the shortest path distance from the given source s  to vertex w in distance map<w, distance>
// store which next vertex to go through on the shortest path to the given source s in go_through map<w, v>. 
// Here a pair <w, v> in go_through map represents on the shortest path from w to the given source s, it needs to take the path: w-->v...-->s
template <typename T>  
int Graph<T>::BFS(T s, T t, map<T, int>& distance, map<T, T>& go_through) const{
   	if (adjMap.find(s) == adjMap.end() || adjMap.find(t) == adjMap.end())
		return INVALID_VERTEX;
	for (auto i = adjMap.begin(); i != adjMap.end(); i++)
		distance[i->first] = NOPATH;
	//create empty T queue Q
	queue<T> Q;
	// enqueue source (insert s into Q)
	Q.push(s);
	
	go_through[s] = s;
	distance[s] = 0;
	T j = s; // j equal to the front of the queue
	//while Q is not empty && current != t
	while(!Q.empty() && j != t){
		j = Q.front();
		// for each vertex i adjacent to current
		set<T> adjVertex = adjMap.at(j);
		for (auto i = adjVertex.begin(); i != adjVertex.end(); i++){
			if(distance[*i] == NOPATH){
				distance[*i] = distance[j]+1; //distance w = distance[current] +1
				go_through[*i] = j;
				Q.push(*i);} // add i to Q
		}
		Q.pop();
	}
	return distance[t]; }

#endif

