#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include <string>  // std::string

namespace bst {  // binary search tree

/**
 * @brief A class representing a binary search tree.
 *
 * @tparam DataType Type of data the container will store.
 * @tparam KeyType Type of key the container will store.
 */
template <typename DataType, typename KeyType>
class binarySearchTree {
   private:
    //=== The data node.
    struct Node {
        DataType data;  //!< Information to be stored in the container.
        KeyType key;    //!< Key to my Nome.
        Node* left;     //!< Pointer to left Node.
        Node* right;    //!< Pointer to right Node.

        Node(const DataType& _data = DataType{}, const KeyType& _key = KeyType{}, Node* l = nullptr, Node* r = nullptr)
            : data{_data}, key{_key}, left{l}, right{r} {}
    };

    //=== Some aliases to help writing a clearer code.
   public:
    using DataReference = DataType&;             //!< reference to the data value.
    using DataConstReference = const DataType&;  //!< const reference to the data value.
    using KeyReference = KeyType&;               //!< reference to the key value.
    using KeyConstReference = const KeyType&;    //!< const reference to the key value.

    //=== Private members.
   private:
    Node* raw_pointer;

   public:
    //=== Public interface

    //=== Constructors and Destructors
    binarySearchTree(void);
    binarySearchTree(DataConstReference _data, KeyConstReference _key) : binarySearchTree();
    ~binarySearchTree(void);

    //=== Methods Modifiers
    Node* insert(DataConstReference _data, KeyConstReference _key);
    Node* remove(DataConstReference _data, KeyConstReference _key);
    Node* clear(void);

    //=== Methods Acess
    DataType median(void);
    int findPositionOfElement(KeyConstReference _key);
    DataType elementInPosition(int position);
    bool isComplete(void);
    bool isFull(void);
    std::string toString(void);
    int simetric(Node* source, KeyConstReference key, int iteration);
};

}  // namespace bst

#endif  // _BINARY_SEARCH_TREE_H_