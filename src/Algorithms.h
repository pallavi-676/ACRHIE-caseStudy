#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include "models.h"
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

// 1. Sorting Algorithm: Quick Sort for Artifacts based on significanceScore
class Sorter {
public:
    static void quickSort(vector<Artifact>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }

private:
    static int partition(vector<Artifact>& arr, int low, int high) {
        int pivot = arr[high].significanceScore;
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            // Sorting descending so highest score is first
            if (arr[j].significanceScore >= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return (i + 1);
    }
};

// 2. Searching Algorithm: Binary Search (assumes array is sorted by ID)
class Searcher {
public:
    static int binarySearchById(const vector<Artifact>& arr, int l, int r, int targetId) {
        if (r >= l) {
            int mid = l + (r - l) / 2;
            if (arr[mid].id == targetId) return mid;
            if (arr[mid].id > targetId) return binarySearchById(arr, l, mid - 1, targetId);
            return binarySearchById(arr, mid + 1, r, targetId);
        }
        return -1;
    }
};

// 3. Graph Algorithms: Analyze relationships and trade routes
class CivilizationGraph {
private:
    // Adjacency list: Map civilization name to list of pairs (neighbor, weight)
    map<string, vector<pair<string, int>>> adjList;

public:
    void addRoute(string from, string to, int distance) {
        adjList[from].push_back({to, distance});
        adjList[to].push_back({from, distance}); // Undirected graph
    }

    // BFS to find connected civilizations
    void BFS(string startNode) {
        if (adjList.find(startNode) == adjList.end()) return;

        set<string> visited;
        queue<string> q;

        visited.insert(startNode);
        q.push(startNode);

        cout << "BFS Traversal from " << startNode << ": ";
        while (!q.empty()) {
            string curr = q.front();
            cout << curr << " ";
            q.pop();

            for (auto neighbor : adjList[curr]) {
                if (visited.find(neighbor.first) == visited.end()) {
                    visited.insert(neighbor.first);
                    q.push(neighbor.first);
                }
            }
        }
        cout << endl;
    }

    // DFS
    void DFS(string startNode) {
        set<string> visited;
        cout << "DFS Traversal from " << startNode << ": ";
        DFSRec(startNode, visited);
        cout << endl;
    }

private:
    void DFSRec(string curr, set<string>& visited) {
        visited.insert(curr);
        cout << curr << " ";
        for (auto neighbor : adjList[curr]) {
            if (visited.find(neighbor.first) == visited.end()) {
                DFSRec(neighbor.first, visited);
            }
        }
    }

public:
    // Dijkstra's Algorithm for Shortest Path
    void Dijkstra(string startNode, string endNode) {
        map<string, int> dist;
        map<string, string> parent;
        for (auto pair : adjList) dist[pair.first] = INT_MAX;
        
        dist[startNode] = 0;
        
        // Min-heap
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        pq.push({0, startNode});

        while (!pq.empty()) {
            string u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto neighbor : adjList[u]) {
                string v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }

        if (dist[endNode] == INT_MAX || dist.find(endNode) == dist.end()) {
            cout << "No route found from " << startNode << " to " << endNode << endl;
        } else {
            cout << "Shortest route distance: " << dist[endNode] << endl;
            cout << "Path: ";
            string curr = endNode;
            vector<string> path;
            while (curr != startNode && parent.find(curr) != parent.end()) {
                path.push_back(curr);
                curr = parent[curr];
            }
            path.push_back(startNode);
            reverse(path.begin(), path.end());
            for (size_t i = 0; i < path.size(); i++) {
                cout << path[i] << (i == path.size() - 1 ? "" : " -> ");
            }
            cout << endl;
        }
    }
};

#endif
