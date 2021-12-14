//
// Created by Dmitry Tsikalovsky on 08.12.2021.
//обход в глубину обход в шинрину

#ifndef INC_2SEMPROGA_GRAPH_H
#define INC_2SEMPROGA_GRAPH_H
#include <vector>
#include <unordered_map>
#include <iostream>

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
#endif //INC_2SEMPROGA_GRAPH_H
