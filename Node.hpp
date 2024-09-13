// Matan Markovits 322318080
// matanmarkovits@gmail.com

#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
#include <utility>

using namespace std;

// Class representing a generic node in a tree
template <typename T> 
class Node {
    private:
        T data;  // Value stored in the node
        vector<Node<T> *> children;  // List of children nodes

    public:
        // Constructor with an optional list of children
        Node(const T &val, const vector<Node<T> *> &childrenList = {}) : data(val), children(childrenList) {}

        // Move constructor for efficient copying of nodes
        Node(const T &val, vector<Node<T> *> &&childrenList) : data(val), children(move(childrenList)) {}

        // Destructor: Default behavior, as no dynamic memory needs to be freed
        virtual ~Node() = default;

        // Add a child to this node
        void add_child(Node<T> *child) {
            children.push_back(child);
        }

        // Get the children of this node
        vector<Node<T> *> get_children() const {
            return children;
        }

        // Get the number of children
        size_t get_children_size() const {
            return children.size();
        }

        // Getter for the value (constant)
        const T &get_value() const {
            return data;
        }

        // Getter for the value (non-const)
        T &get_value() {
            return data;
        }

        // Set the value of the node
        void set_value(const T &newVal) {
            data = newVal;
        }
};

#endif // NODE_HPP
