#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;

// Node structure for Huffman tree
struct HuffmanNode {
    char data;
    unsigned frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Comparison function for priority queue
struct CompareNodes {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->frequency > right->frequency;
    }
};

// Build Huffman tree and return the root
HuffmanNode* buildHuffmanTree(const map<char, unsigned>& frequencies)
{


    priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> minHeap;

    // Create a leaf node for each character and add it to the priority queue
    for (const auto& pair : frequencies) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    // Build the Huffman tree
    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top();
        minHeap.pop();

        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* internalNode = new HuffmanNode('$', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(internalNode);
    }

    return minHeap.top();
}

// Traverse the Huffman tree and generate codes
void generateCodes(HuffmanNode* root, const string& code, map<char, string>& codes) {
    if (root) {
        if (root->data != '$') {
            codes[root->data] = code;
        }
        generateCodes(root->left, code + "0", codes);
        generateCodes(root->right, code + "1", codes);
    }
}

// Encode the input text using Huffman codes
string huffmanEncode(const string& input, const map<char, string>& codes) {
    string encoded = "";
    for (char c : input) {
        encoded += codes.at(c);
    }
    return encoded;
}

int main() {
    // Example usage
    string input = "hello world";
    map<char, unsigned> frequencies;

    // Count frequencies of each character in the input
    for (char c : input) {
        
        frequencies[c]++;
    }

    // Build the Huffman tree
    HuffmanNode* root = buildHuffmanTree(frequencies);

    // Generate Huffman codes
    map<char, string> codes;
    generateCodes(root, "", codes);

    // Encode the input text
    string encoded = huffmanEncode(input, codes);

    // Display the results
    cout << "Original text: " << input << endl;
    cout << "Huffman encoded text: " << encoded << endl;

    return 0;
}
