// Matan Markovits 322318080
// matanmarkovits@gmail.com

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <vector>
#include <stack>
#include <queue>
#include "Node.hpp"

using namespace std;

// Pre-Order Iterator (visits parent first, then children from left to right)
template <typename T> class preOrderIterator {
    private:
        stack<Node<T> *> nodes; // Stack to store nodes for traversal

    public:
        // Constructor: Initializes the iterator with the root node
        preOrderIterator(Node<T> *root) {
            if (root != nullptr) {
                nodes.push(root);
            }
        }

        // Get the current node's value
        T operator*() const { return nodes.top()->get_value(); }

        // Compare iterators (inequality)
        bool operator!=(const preOrderIterator<T> &other) const { return nodes != other.nodes; }

        // Compare iterators (equality)
        bool operator==(const preOrderIterator<T> &other) const { return nodes == other.nodes; }

        // Advance to the next node (visits children in left-to-right order)
        preOrderIterator<T> &operator++() {
            Node<T> *current = nodes.top();
            nodes.pop();
            
            // Push children in reverse order to ensure left-to-right traversal
            for (int i = current->get_children_size() - 1; i >= 0; --i) {
                nodes.push(current->get_children()[i]);
            }
            return *this;
        }
};

// Post-Order Iterator (visits children first, then parent)
template <typename T> class postOrderIterator {
    private:
        stack<Node<T> *> firstStack, secondStack; // Two stacks for correct post-order traversal

    public:
        // Constructor: Initializes with the root node
        postOrderIterator(Node<T> *root) {
            if (root != nullptr) {
                firstStack.push(root);
                while (!firstStack.empty()) {
                    Node<T> *current = firstStack.top();
                    firstStack.pop();
                    secondStack.push(current);

                    // Push children of the current node
                    for (auto &child : current->get_children()) {
                        firstStack.push(child);
                    }
                }
            }
        }

        // Get current node's value
        T operator*() const { return secondStack.top()->get_value(); }

        // Compare iterators (inequality)
        bool operator!=(const postOrderIterator<T> &other) const { return secondStack != other.secondStack; }

        // Advance to the next node (pop from the second stack)
        postOrderIterator<T> &operator++() {
            secondStack.pop();
            return *this;
        }
};

// In-Order Iterator (visits left child, parent, right child)
template <typename T> class inOrderIterator {
    private:
        stack<Node<T> *> nodeStack;

        // Helper function to push all left children to the stack
        void pushLeft(Node<T> *node) {
            while (node) {
                nodeStack.push(node);
                if (!node->get_children().empty()) {
                    node = node->get_children()[0]; // Visit left child
                } else {
                    node = nullptr;
                }
            }
        }

    public:
        // Constructor: Initializes with the root node
        inOrderIterator(Node<T> *root) {
            pushLeft(root);
        }

        // Get current node's value
        T operator*() const { return nodeStack.top()->get_value(); }

        // Compare iterators (inequality)
        bool operator!=(const inOrderIterator<T> &other) const { return nodeStack != other.nodeStack; }

        // Advance to the next node
        inOrderIterator &operator++() {
            Node<T> *current = nodeStack.top();
            nodeStack.pop();

            // If right child exists, push its left children to the stack
            if (current->get_children_size() > 1) {
                pushLeft(current->get_children()[1]);
            }
            return *this;
        }
};

// BFS Iterator (Breadth-First Search)
template <typename T> class bfsIterator {
    private:
        queue<Node<T> *> nodesQueue; // Queue for BFS traversal

    public:
        // Constructor: Initializes with the root node
        bfsIterator(Node<T> *root) {
            if (root) {
                nodesQueue.push(root);
            }
        }

        // Get current node's value
        T operator*() const { return nodesQueue.front()->get_value(); }

        // Compare iterators (inequality)
        bool operator!=(const bfsIterator<T> &other) const { return nodesQueue != other.nodesQueue; }

        // Advance to the next node
        bfsIterator &operator++() {
            Node<T> *current = nodesQueue.front();
            nodesQueue.pop();

            // Push all children of the current node to the queue
            for (auto &child : current->get_children()) {
                nodesQueue.push(child);
            }
            return *this;
        }
};

// DFS Iterator (Depth-First Search)
template <typename T> class dfsIterator {
    private:
        stack<Node<T> *> nodeStack; // Stack for DFS traversal

    public:
        // Constructor: Initializes with the root node
        dfsIterator(Node<T> *root) {
            if (root) {
                nodeStack.push(root);
            }
        }

        // Get current node's value
        T operator*() const { return nodeStack.top()->get_value(); }

        // Compare iterators (inequality)
        bool operator!=(const dfsIterator<T> &other) const { return nodeStack != other.nodeStack; }

        // Advance to the next node
        dfsIterator &operator++() {
            Node<T> *current = nodeStack.top();
            nodeStack.pop();

            // Push children in reverse order to ensure left-to-right traversal
            for (int i = current->get_children_size() - 1; i >= 0; --i) {
                nodeStack.push(current->get_children()[i]);
            }
            return *this;
        }
};

// Min-Heap Iterator
template <typename T> class heapIterator {
    private:
        vector<Node<T> *> heap; // Vector for heap representation

    public:
        // Constructor: Initializes with the root node and builds the heap
        heapIterator(Node<T> *root) {
            if (root) {
                queue<Node<T> *> nodeQueue;
                nodeQueue.push(root);

                // Push all nodes to the vector
                while (!nodeQueue.empty()) {
                    Node<T> *current = nodeQueue.front();
                    nodeQueue.pop();
                    heap.push_back(current);

                    for (auto &child : current->get_children()) {
                        nodeQueue.push(child);
                    }
                }

                // Transform into a min-heap
                make_heap(heap.begin(), heap.end(), [](Node<T> *a, Node<T> *b) {
                    return a->get_value() > b->get_value();
                });
            }
        }

        // Compare iterators (inequality)
        bool operator!=(const heapIterator &other) const { return heap != other.heap; }

        // Get current node's value
        T operator*() const { return heap.front()->get_value(); }

        // Advance to the next node
        heapIterator &operator++() {
            pop_heap(heap.begin(), heap.end(), [](Node<T> *a, Node<T> *b) {
                return a->get_value() > b->get_value();
            });
            heap.pop_back();
            return *this;
        }
};

#endif // ITERATOR_HPP
