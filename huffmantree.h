#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include <string>
#include <map>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char character, int frequency);
    ~Node();
};

class HuffmanTree {
private:
    Node* root;
    map<char, string> codes;

    void buildCodes(Node* node, const string& prefix);
    void deleteTree(Node* node);

public:
    HuffmanTree();
    ~HuffmanTree();

    void build(const string& text);
    map<char, string> getCodes() const;
    string encode(const string& text) const;
    string decode(const string& encoded) const;
};

#endif // HUFFMANTREE_H
