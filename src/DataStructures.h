#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

#include "models.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1. Hashing: Hash Table for Artifact Identification
class ArtifactHashTable {
private:
    static const int TABLE_SIZE = 100;
    struct HashNode {
        int key;
        Artifact value;
        HashNode* next;
        HashNode(int k, Artifact v) : key(k), value(v), next(nullptr) {}
    };
    HashNode* table[TABLE_SIZE];

    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    ArtifactHashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) table[i] = nullptr;
    }

    void insert(Artifact artifact) {
        int hashVal = hashFunction(artifact.id);
        HashNode* prev = nullptr;
        HashNode* entry = table[hashVal];

        while (entry != nullptr && entry->key != artifact.id) {
            prev = entry;
            entry = entry->next;
        }

        if (entry == nullptr) {
            entry = new HashNode(artifact.id, artifact);
            if (prev == nullptr) {
                table[hashVal] = entry;
            } else {
                prev->next = entry;
            }
        } else {
            entry->value = artifact; // Update
        }
    }

    Artifact* search(int id) {
        int hashVal = hashFunction(id);
        HashNode* entry = table[hashVal];
        while (entry != nullptr) {
            if (entry->key == id) return &(entry->value);
            entry = entry->next;
        }
        return nullptr;
    }
};

// 2. Stack: Restore previous historical classifications
class ClassificationStack {
private:
    struct StackNode {
        PreviousClassification data;
        StackNode* next;
        StackNode(PreviousClassification d) : data(d), next(nullptr) {}
    };
    StackNode* topNode;

public:
    ClassificationStack() : topNode(nullptr) {}

    void push(PreviousClassification classification) {
        StackNode* newNode = new StackNode(classification);
        newNode->next = topNode;
        topNode = newNode;
    }

    bool pop(PreviousClassification& outData) {
        if (isEmpty()) return false;
        StackNode* temp = topNode;
        outData = topNode->data;
        topNode = topNode->next;
        delete temp;
        return true;
    }

    bool isEmpty() {
        return topNode == nullptr;
    }
};

// 3. Queue: Process excavation reports systematically
class ReportQueue {
private:
    struct QueueNode {
        ExcavationReport data;
        QueueNode* next;
        QueueNode(ExcavationReport d) : data(d), next(nullptr) {}
    };
    QueueNode *front, *rear;

public:
    ReportQueue() : front(nullptr), rear(nullptr) {}

    void enqueue(ExcavationReport report) {
        QueueNode* newNode = new QueueNode(report);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    bool dequeue(ExcavationReport& outReport) {
        if (front == nullptr) return false;
        QueueNode* temp = front;
        outReport = front->data;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
        return true;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

// 4. BST: Store artifact records ordered by age efficiently
class ArtifactBST {
private:
    struct TreeNode {
        Artifact data;
        TreeNode* left;
        TreeNode* right;
        TreeNode(Artifact d) : data(d), left(nullptr), right(nullptr) {}
    };
    TreeNode* root;

    TreeNode* insertRec(TreeNode* node, Artifact data) {
        if (node == nullptr) return new TreeNode(data);
        if (data.age < node->data.age)
            node->left = insertRec(node->left, data);
        else if (data.age > node->data.age)
            node->right = insertRec(node->right, data);
        return node;
    }

    void inorderRec(TreeNode* node, vector<Artifact>& result) {
        if (node != nullptr) {
            inorderRec(node->left, result);
            result.push_back(node->data);
            inorderRec(node->right, result);
        }
    }

public:
    ArtifactBST() : root(nullptr) {}

    void insert(Artifact artifact) {
        root = insertRec(root, artifact);
    }

    vector<Artifact> getInorder() {
        vector<Artifact> result;
        inorderRec(root, result);
        return result;
    }
};

#endif
