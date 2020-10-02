#ifndef CPP_BINARYTREE_H
#define CPP_BINARYTREE_H

/*
 * ��� ���������� ����������� ��������� �������� ������ ������.
 * ����� ���� ��������, � ������� �������������� ����������� ���������� ���.
 * ������, ���� �� ������, ������ �������� ��� ���, ����� ���������� ���� ����� �����.
 * ������, ������ ������ ������ ���, ����� ���������� ���� �� �������, � �� �� ����������.
 * ����� ������� �� 3 ������.
 * lvl_1_IS.txt - ���� ��� �������� ����������������� ������� � ������
 * lvl_2_ISMM.txt - ���� ��� �������� �������, ������, ���������� �������� � ���������
 * lvl_3_ISMMD.txt - ����������� �������� �� ��������
 * ����� ��������� ��� ��� ���� ���� ���������� ������ �������� ��������� ���� ��
 * ������� ����� � ���������� ��������� ������.
 * ������ ���������� ��� ������ ������/������ �� �����.
 *
 */

template<typename T>
struct Node {
    Node* left;
    Node* right;
    T key;

    Node() : left(nullptr), right(nullptr) {};

    explicit Node(T key) : Node() {
        this->key = key;
    };

    ~Node() {
        delete left;
        delete right;
    }
};

template<typename T>
class BinaryTree {
public:
    BinaryTree() : root_(nullptr) {
        size_ = 0;
    };

    ~BinaryTree() {
        delete root_;
    }

    // ������� �������� �� �����
    void insert(T key);

    // ����� �������� �� �����
    bool search(T key);

    // �������� �������� �� �����
    // ���������� ���������, ��� ����� ������� ����, ���� ��� - ������ �� ������
    void remove(T key);

    // ����� ��������
    // ���� ������ ������ - ����������� ����������
    T minimum();

    // ����� ���������
    // ���� ������ ������ - ����������� ����������
    T maximum();

    int size() const {
        return size_;
    }

private:
    void recursiveInsert(T key, Node<T>* pNode);

    bool recursiveSearch(T key, Node<T>* pNode);

    Node<T>* recursiveRemove(T key, Node<T>* pNode);

    T recursiveMinimum(Node<T>* pNode);

    T recursiveMaximum(Node<T>* pNode);

private:
    Node<T>* root_;
    int size_;
};

#include "BinaryTree.hpp"

#endif //CPP_BINARYTREE_H