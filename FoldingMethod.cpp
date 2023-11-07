#include <iostream>
#include <cstring>

using namespace std;

int fold_hash(char* key, int size) {
    int hash = 0;
    int len = strlen(key);

    int num_chunks = len / size;
    int last_chunk_size = len % size;

    int start = 0;
    int end = size - 1;

    for (int i = 0; i < num_chunks; i++) {
        int chunk_val = 0;
        for (int j = start; j <= end; j++) {
            chunk_val += key[j];
        }
        hash += chunk_val;
        start += size;
        end += size;
    }

    if (last_chunk_size > 0) {
        int chunk_val = 0;
        end = len - 1;
        start = end - last_chunk_size + 1;
        for (int j = start; j <= end; j++) {
            chunk_val += key[j];
        }
        hash += chunk_val;
    }

    return hash % size;
}

int main() {
    char key[100];
    int size;

    cout << "Enter the key: ";
    cin >> key;

    cout << "Enter the size: ";
    cin >> size;

    int hash = fold_hash(key, size);

    cout << "Hash value of " << key << " is " << hash << endl;

    return 0;
}
