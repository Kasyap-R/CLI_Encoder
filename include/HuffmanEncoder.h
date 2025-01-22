#pragma once

#include "Node.h"
#include <cassert>
#include <memory>
#include <queue>
#include <unordered_map>

class HuffmanEncoder {
  private:
    std::priority_queue<std::unique_ptr<Node>,
                        std::vector<std::unique_ptr<Node>>, CompareNode>
        pq;
    const std::string text;
    std::unordered_map<char, int> freqMap;
    std::unordered_map<char, std::string> charToCode;
    std::unordered_map<std::string, char> codeToChar;

    void calculateFrequencies();

    void generateTree();

    void generateCodes();

    void generateCodesHelper(Node *currNode, std::string &currCode);

    void mergeNodes();

  public:
    HuffmanEncoder(std::string text);

    auto encode() -> std::string;

    auto decode(std::string encodedText) -> std::string;
};
