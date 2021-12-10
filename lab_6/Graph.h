//
// Created by Dmitry Tsikalovsky on 08.12.2021.
//

#ifndef INC_2SEMPROGA_GRAPH_H
#define INC_2SEMPROGA_GRAPH_H
#include <vector>
struct Eadge{
    int from;
    int to;
    int weight;
    Eadge(int intputFrom, int intputTo, int intputWeight) {
        this->to = intputTo;
        this->from = intputFrom;
        this->weight = intputWeight;
    }
};
struct Node{
    int id;
    std::vector<Eadge> eadges;
    void addEadge(int from, int to, int weight ){
        eadges.emplace_back(from, to, weight);
    }
};

void round(std::vector<Node>& Graph){
    for (auto iter = Graph.begin(); iter != Graph.end(); ++iter) {

    }
}
#endif //INC_2SEMPROGA_GRAPH_H
