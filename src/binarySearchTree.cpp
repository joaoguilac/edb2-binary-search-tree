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
void binarySearchTree<DataType, KeyType>::search(KeyConstReference _key, Node* pointerSon, int& controlVariable) {
    Node* pointerFather = nullptr;
    int position = 0;

    search(_key, pointerFather, pointerSon, position, controlVariable);
}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
void binarySearchTree<DataType, KeyType>::search(KeyConstReference _key, Node* pointerFather, Node* pointerSon,
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
binarySearchTree<DataType, KeyType>::Node* binarySearchTree<DataType, KeyType>::clear(void) {}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
DataType binarySearchTree<DataType, KeyType>::median(void) {
    vector<int>elements;
    int control,median;
    if(raw_pointer != nullptr){
        this->Pre_order(raw_pointer->left);
        elements.push_back(raw_pointer);
        this->Pre_order(raw_pointer->right);
    }
    int vector_Size = elements.size();
    int j,k;
    for(int i = 2; i <= vector_Size; i++){
        k = elements[i];
        j = i-1;
        elements[0] = k;
        while(k < elements[j]){
            elements[j+1] = elements[j];
            j--;
        }
        elements[j+1] = k;
    }
    if(vector_Size % 2 == 0){
        median = vector_Size/2;
        return elements[median-1];
    }else{
        median = (vector_Size+1)/2;
        return elements[median];
    }
}

// TODO: Fazer documentação doxygen
template <typename DataType, typename KeyType>
int binarySearchTree<DataType, KeyType>::findPositionOfElement(KeyConstReference _key) {
    int temp = simetric(tree, _data, 0);
    if (temp == 0) {
        cout << "Element not found!" << endl;
    } else {
        cout << "Element in position : " << temp << endl;
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
std::string binarySearchTree<DataType, KeyType>::toString(void) {}

// TODO: Fazer documentação doxygen
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

}  // namespace bst