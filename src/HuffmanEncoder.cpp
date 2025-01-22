#include "HuffmanEncoder.h"
#include <stdexcept>

HuffmanEncoder::HuffmanEncoder(std::string text) : text(std::move(text)) {
    if (this->text.empty()) {
        throw std::runtime_error("Text fed into HuffmanEncoder is empty");
    }
    this->calculateFrequencies();
    this->generateTree();
    this->generateCodes();
}

void HuffmanEncoder::calculateFrequencies() {
    for (const char &symbol : this->text) {
        this->freqMap[symbol]++;
    }
}

void HuffmanEncoder::generateTree() {
    // Generate initial PQ
    for (auto const &[symbol, freq] : this->freqMap) {
        this->pq.push(std::make_unique<Node>(symbol, freq, nullptr, nullptr));
    }

    while (this->pq.size() >= 2) {
        this->mergeNodes();
    }
}

void HuffmanEncoder::generateCodes() {
    std::string code;
    this->generateCodesHelper(this->pq.top().get(), code);
}

void HuffmanEncoder::generateCodesHelper(Node *currNode,
                                         std::string &currCode) {
    if (!currNode->left && !currNode->right) {
        this->codes[currNode->symbol] = currCode;
    }

    if (currNode->left) {
        currCode.append("0");
        this->generateCodesHelper(currNode->left.get(), currCode);
        currCode.pop_back();
    }

    if (currNode->right) {
        currCode.append("1");
        this->generateCodesHelper(currNode->right.get(), currCode);
        currCode.pop_back();
    }
}

void HuffmanEncoder::mergeNodes() {
    // Pop two lowest freq nodes
    auto nodeOne = std::move(const_cast<std::unique_ptr<Node> &>(pq.top()));
    pq.pop();
    auto nodeTwo = std::move(const_cast<std::unique_ptr<Node> &>(pq.top()));
    pq.pop();

    int parentFreq = nodeOne->frequency + nodeTwo->frequency;
    this->pq.push(std::make_unique<Node>('\0', parentFreq, std::move(nodeOne),
                                         std::move(nodeTwo)));
}

auto HuffmanEncoder::encode() -> std::string { return ""; }

auto HuffmanEncoder::decode() -> std::string { return ""; }
