//
// Created by Dmitry Tsikalovsky on 08.12.2021.
//обход в глубину обход в шинрину

#ifndef INC_2SEMPROGA_GRAPH_H
#define INC_2SEMPROGA_GRAPH_H
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <queue>

struct Eadge{
    int to;
    int weight;
    Eadge(int intputTo, int intputWeight) {
        this->to = intputTo;
        this->weight = intputWeight;
    }
};
struct Node{
    int id;
    std::vector<Eadge> eadges;
    void addEadge(int to, int weight){
        eadges.emplace_back(to, weight);
    }
    Node(int inputId){
        this->id = inputId;
    }
};

void check(std::vector<Node>& Graph, int nodeId, std::vector<bool>& isVisited){
    isVisited[nodeId] = true;
    std::cout<<nodeId <<std::endl;
        for (int i = 0; i < Graph[nodeId].eadges.size(); ++i) {
            if (!isVisited[Graph[nodeId].eadges[i].to]) {
                check(Graph,Graph[nodeId].eadges[i].to , isVisited);
            }
        }
}

void round(std::vector<Node>& Graph){
    std::vector<bool> isVisited(Graph.size(), false);
    for (int i = 0; i < Graph.size(); ++i) {
        if (!isVisited[i]) {
            check(Graph, i, isVisited);
        }
    }

}

void bfs(std::vector<Node>& Graph) { // ширина
    std::queue<int> q;
    std::vector<bool> isVisited(Graph.size(), false);

    for (int i = 0; i < Graph.size(); ++i) {
        if (!isVisited[i]){
            isVisited[i] = true;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                std::cout << u << std::endl;
                q.pop();
                for (int j = 0; j < (int) Graph[u].eadges.size(); j++) {
                    if (!isVisited[Graph[u].eadges[j].to]) {
                        isVisited[Graph[u].eadges[j].to] = true;
                        q.push(Graph[u].eadges[j].to);

                    }
                }
            }
        }


    }

}

void dfs(std::vector<Node>& Graph) { // глубина
    std::stack<int> s;
    std::vector<bool> isVisited(Graph.size(), false);

    for (int i = 0; i < Graph.size(); ++i) {
        if (!isVisited[i]){
            isVisited[i] = true;
            s.push(i);

            while (!s.empty()) {
                int u = s.top();
                s.pop();
                std::cout << u << std::endl;
                for (int j = 0; j < (int) Graph[u].eadges.size(); j++) {
                    if (!isVisited[Graph[u].eadges[j].to]) {
                        isVisited[Graph[u].eadges[j].to] = true;
                        s.push(Graph[u].eadges[j].to);

                    }
                }
            }
        }


    }

}

void dijkstra(std::vector<Node>& Graph, int u) {
    std::vector <std::vector <int> > Matrix(Graph.size(), std::vector <int> (Graph.size(), INT16_MAX) );
    for (int i = 0; i < Graph.size(); ++i) {
        for (int j = 0; j < Graph[i].eadges.size(); ++j) {
            if (i == j) {
                Matrix[i][j] = 0;
            } else {
                Matrix[i][Graph[i].eadges[j].to] = Graph[i].eadges[j].weight;
            }
        }
    }
    std::vector<int> dist(Graph.size(), INT16_MAX);
    std::priority_queue< std::pair<int, int>, std::vector< std::pair<int, int> >, std::greater< std::pair<int, int> > > q;
    dist[u] = 0;

    q.push(std::make_pair(0, u));
    while (!q.empty()) {
        std::pair<int, int> u = q.top();
        q.pop();
        if (u.first > dist[u.second]) continue;
        for (int i = 0; i < (int) Graph.size(); i++) {
            int v = i, len = Matrix[u.second][i];
            if (dist[v] > dist[u.second] + len) {
                dist[v] = dist[u.second] + len;
                q.push(std::make_pair(dist[v], v));
            }
        }
    }
    int k = 0;
}

void floid(std::vector<Node>& Graph, int u) {
    std::vector <std::vector <int> > Matrix(Graph.size(), std::vector <int> (Graph.size(), INT16_MAX) );
    for (int i = 0; i < Graph.size(); ++i) {
        for (int j = 0; j < Graph[i].eadges.size(); ++j) {
            if (i == j) {
                Matrix[i][j] = 0;
            } else {
                Matrix[i][Graph[i].eadges[j].to] = Graph[i].eadges[j].weight;
            }
        }
    }
    for (int k = 0; k < Graph.size(); k++) {	//Пробегаемся по всем вершинам и ищем более короткий путь через вершину k
        for (int i = 0; i < Graph.size(); i++) {
            for (int j = 0; j < Graph.size(); j++) {
                Matrix[i][j] = std::min(Matrix[i][j], Matrix[i][k] + Matrix[k][j]);	//Новое значение ребра равно минимальному между старым ребром и суммой ребер
            }
        }
    }
    std::vector<int>dist = Matrix[u];
    int k = 0;
}

#endif //INC_2SEMPROGA_GRAPH_H
