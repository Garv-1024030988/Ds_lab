#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    Node* up;
    Node* down;

    Node(int val) : data(val), right(nullptr), left(nullptr), up(nullptr), down(nullptr) {}
};

Node* matrixToDoublyLinkedList(const vector<vector<int>>& matrix) {
    if (matrix.empty() || matrix[0].empty()) return nullptr;

    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<Node*>> nodeMatrix(rows, vector<Node*>(cols));

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            nodeMatrix[i][j] = new Node(matrix[i][j]);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (j > 0) {
                nodeMatrix[i][j]->left = nodeMatrix[i][j - 1];
                nodeMatrix[i][j - 1]->right = nodeMatrix[i][j];
            }
            if (i > 0) {
                nodeMatrix[i][j]->up = nodeMatrix[i - 1][j];
                nodeMatrix[i - 1][j]->down = nodeMatrix[i][j];
            }
        }
    }
    return nodeMatrix[0][0];
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    Node* head = matrixToDoublyLinkedList(matrix);

    Node* temp = head;
    cout << "First row: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;

    if (head && head->down)
        cout << "Down from 1: " << head->down->data << endl;

    if (head && head->right && head->right->down)
        cout << "Down from 2: " << head->right->down->data << endl;

    return 0;
}
