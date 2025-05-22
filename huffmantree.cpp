#include "huffmantree.h"
#include <queue>
#include <unordered_map>
#include <iostream>

Node::Node(char character, int frequency)
    : ch(character), freq(frequency), left(nullptr), right(nullptr) {}

Node::~Node() {
    delete left;
    delete right;
}

HuffmanTree::HuffmanTree() : root(nullptr) {}

HuffmanTree::~HuffmanTree() {
    deleteTree(root);
}

void HuffmanTree::deleteTree(Node* node) {
    if (node) {
        delete node;
    }
}

struct CompareNode {
    bool operator()(Node* lhs, Node* rhs) {
        return lhs->freq > rhs->freq;
    }
};

void HuffmanTree::build(const string& text) {
    unordered_map<char, int> freqMap;
    for (char ch : text) {
        freqMap[ch]++;
    }

    priority_queue<Node*, vector<Node*>, CompareNode> pq;

    for (auto& pair : freqMap) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    root = pq.top();

    codes.clear();
    buildCodes(root, "");
}

void HuffmanTree::buildCodes(Node* node, const string& prefix) {
    if (!node) return;

    if (!node->left && !node->right) {
        codes[node->ch] = prefix.empty() ? "0" : prefix;
    } else {
        buildCodes(node->left, prefix + "0");
        buildCodes(node->right, prefix + "1");
    }
}

map<char, string> HuffmanTree::getCodes() const {
    return codes;
}

string HuffmanTree::encode(const string& text) const {
    string encoded;
    for (char ch : text) {
        auto it = codes.find(ch);
        if (it != codes.end()) {
            encoded += it->second;
        } 
    }
    return encoded;
}

string HuffmanTree::decode(const string& encoded) const {
    string decoded;
    Node* current = root;
    for (char bit : encoded) {
        if (!current) break;
        if (bit == '0') current = current->left;
        else if (bit == '1') current = current->right;
       
        if (!current->left && !current->right) {
            decoded += current->ch;
            current = root;
        }
    }
    return decoded;
}
