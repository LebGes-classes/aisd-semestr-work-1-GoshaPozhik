#include <iostream>
#include "huffmantree.h"

using namespace std;

int main() {
    string text;
    cout << "Изначальный текст: ";
    getline(cin, text);

    HuffmanTree tree;
    tree.build(text);

    cout << "Коды Хаффама:\n";
    for (auto& pair : tree.getCodes()) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    string encoded = tree.encode(text);
    cout << "Закодированный текст:\n" << encoded << "\n";

    string decoded = tree.decode(encoded);
    cout << "Декодированный текст:\n" << decoded << "\n";

    if (decoded == text) {
        cout << "Декодирование прошло успешно!\n";
    } else {
        cout << "Ошибка. Изначальный текст отличается от декодированного!\n";
    }

    return 0;
}
