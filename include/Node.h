#pragma once

#include <memory>

class Node {
  public:
    char symbol;
    int frequency;
    std::unique_ptr<Node> left = nullptr;
    std::unique_ptr<Node> right = nullptr;

    Node(char symbol, int frequency, std::unique_ptr<Node> leftChild,
         std::unique_ptr<Node> rightChild)
        : symbol(symbol), frequency(frequency), left(std::move(leftChild)),
          right(std::move(rightChild)) {}
};

// Comparator for Node
struct CompareNode {
    bool operator()(const std::unique_ptr<Node> &a,
                    const std::unique_ptr<Node> &b) const {
        return a->frequency > b->frequency; // Min-heap based on frequency
        // If false is returned for a node, it goes higher in the queue
    }
};
