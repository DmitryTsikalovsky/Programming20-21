#include "Graph.h"


int main(){
    Node A(0);
    Node B(1);
    Node C(2);
    A.addEadge(1, 1);
    A.addEadge(2, 1);
    B.addEadge(2, 1);
    std::vector<Node> Node;
    Node.push_back(A);
    Node.push_back(B);
    Node.push_back(C);
    round(Node);
    // A->C<-B
}
