#include <iostream>
#include "huffmantree.h"

using namespace std;

int main() {
    string text;
    cout << "Enter text to encode: ";
    getline(cin, text);

    HuffmanTree tree;
    tree.build(text);

    cout << "Huffman Codes:\n";
    for (auto& pair : tree.getCodes()) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    string encoded = tree.encode(text);
    cout << "Encoded string:\n" << encoded << "\n";

    string decoded = tree.decode(encoded);
    cout << "Decoded string:\n" << decoded << "\n";

    if (decoded == text) {
        cout << "Success: Decoded text matches original.\n";
    } else {
        cout << "Error: Decoded text does not match original.\n";
    }

    return 0;
}
