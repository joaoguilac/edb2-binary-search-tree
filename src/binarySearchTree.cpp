#include "../include/binarySearchTree.h"

namespace bst {

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
binarySearchTree<DataType, KeyType>::binarySearchTree(void) : raw_pointer{nullptr} {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
binarySearchTree<DataType, KeyType>::binarySearchTree(DataConstReference _data, KeyConstReference _key)
    : binarySearchTree() {
    raw_pointer = new node(_data, _key);
}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
binarySearchTree<DataType, KeyType>::~binarySearchTree(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
binarySearchTree<DataType, KeyType>::Node* binarySearchTree<DataType, KeyType>::insert(DataConstReference _data,
                                                                                       KeyConstReference _key) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
binarySearchTree<DataType, KeyType>::Node* binarySearchTree<DataType, KeyType>::remove(DataConstReference _data,
                                                                                       KeyConstReference _key) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
binarySearchTree<DataType, KeyType>::Node* binarySearchTree<DataType, KeyType>::clear(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
DataType binarySearchTree<DataType, KeyType>::median(void) {}
//87265134
// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
int binarySearchTree<DataType, KeyType>::findPositionOfElement(KeyConstReference _key) {
     Node* pointerFather = raw_pointer;
    int control = -1;
    search(_key, pointerFather, control, iterator);
    //Private Search needs return the control position
    if(control == 0){
        return -2;
        //-2 -> Empty tree.
    }else if(control == 1){
        return iterator;
        //iterator must be the index of element.
        //1 -> Element found.
    }else{
        return 0;
        //0 -> Element not found.
    }
}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
DataType binarySearchTree<DataType, KeyType>::elementInPosition(int position) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
bool binarySearchTree<DataType, KeyType>::isComplete(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
bool binarySearchTree<DataType, KeyType>::isFull(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
std::string binarySearchTree<DataType, KeyType>::toString(void) {
    queue<DataType> MyQueue;
    Node* node = raw_pointer;
    string print_tree;
    MyQueue.push(node);
    if(!MyQueue.Empty){
        while(!MyQueue.Empty){
            node = MyQueue.pop(); //try 'front'
            print_tree += toString(node->data) + " ";
            if(node->left != nullptr){
                MyQueue.push(node->left);
            }
            if(node->right != nullptr){
                MyQueue.push(node->right);
            }
            return print_tree;
        }
    }else{
        return "Empty tree"
    }
}

// TODO: Fazer documentação doxygen
/*
template <typename DataType, typename KeyType>
int binarySearchTree<DataType, KeyType>::simetric(Node* source, KeyConstReference key, int iteration) {
    if (source != NULL) {
        cout << "Value:" << source->data << endl;
        if (source->data == key) {
            return iteration;
        }
        iteration++ this->simetric(source->left, key, iteration);
        this->simetric(source->right, key, iteration);
    }
    return 0;
}
*/

}  // namespace bst