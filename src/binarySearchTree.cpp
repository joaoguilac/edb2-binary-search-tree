#include "../include/binarySearchTree.h"

namespace bst {

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
BinarySearchTree<DataType, KeyType>::BinarySearchTree(void) : raw_pointer{nullptr} {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
BinarySearchTree<DataType, KeyType>::BinarySearchTree(DataConstReference _data, KeyConstReference _key)
    : BinarySearchTree() {
    raw_pointer = new node(_data, _key);
}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
BinarySearchTree<DataType, KeyType>::~BinarySearchTree(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
BinarySearchTree<DataType, KeyType>::Node* BinarySearchTree<DataType, KeyType>::insert(DataConstReference _data,
                                                                                       KeyConstReference _key) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
BinarySearchTree<DataType, KeyType>::Node* BinarySearchTree<DataType, KeyType>::remove(DataConstReference _data,
                                                                                       KeyConstReference _key) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
void BinarySearchTree<DataType, KeyType>::search(KeyConstReference _key, Node* pointerSon, int& controlVariable) {
    Node* pointerFather = nullptr;
    int position = 0;

    search(_key, pointerFather, pointerSon, position, controlVariable);
}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
void BinarySearchTree<DataType, KeyType>::search(KeyConstReference _key, Node* pointerFather, Node* pointerSon,
                                                 int& position, int& controlVariable) {
    if (pointerSon != nullptr) {
        if (pointerSon->key == _key) {
            controlVariable = 1;
        } else {
            if (_key < pointerSon->key) {
                if (pointerSon->left == nullptr) {
                    controlVariable = 2;
                } else {
                    pointerFather = pointerSon;
                    pointerSon = pointerSon->left;
                    position++;
                }
            } else {
                if (pointerSon->right == nullptr) {
                    controlVariable = 3;
                } else {
                    pointerFather = pointerSon;
                    pointerSon = pointerSon->right;
                    position++;
                }
            }
            if (controlVariable < 1) {
                search(_key, pointerFather, pointerSon, position, controlVariable);
            }
        }
    }
}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
BinarySearchTree<DataType, KeyType>::Node* BinarySearchTree<DataType, KeyType>::clear(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
DataType BinarySearchTree<DataType, KeyType>::median(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
int BinarySearchTree<DataType, KeyType>::findPositionOfElement(KeyConstReference _key) {
    int temp = simetric(tree, _data, 0);
    if (temp == 0) {
        cout << "Element not found!" << endl;
    } else {
        cout << "Element in position : " << temp << endl;
    }
}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
DataType BinarySearchTree<DataType, KeyType>::elementInPosition(int position) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
bool BinarySearchTree<DataType, KeyType>::isComplete(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
bool BinarySearchTree<DataType, KeyType>::isFull(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
std::string BinarySearchTree<DataType, KeyType>::toString(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
int BinarySearchTree<DataType, KeyType>::simetric(Node* source, KeyConstReference key, int iteration) {
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

}  // namespace bst