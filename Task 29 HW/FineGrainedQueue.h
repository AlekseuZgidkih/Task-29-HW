#pragma once
#include <thread>
#include <mutex>
#include <iostream>

struct Node
{
    Node(int data) : value(data), next(nullptr) { node_mutex = new std::mutex; }
    ~Node()
    {
        delete node_mutex;
    }
    int value;
    Node* next;
    std::mutex* node_mutex;
};

class FineGrainedQueue
{

    std::mutex* queue_mutex = new std::mutex;

public:
    Node* head;
    ~FineGrainedQueue();

    /// @brief ��������� ������� � ������ ������. �� ����������������.
    void push_front(int data);
    /// @brief ��������� ������� � ����� ������. �� ����������������.
    void push_back(int data);

    /// @brief ��������� ������� � �������� ������. ����������������.
    void insertIntoMiddle(int pos, int data);
    void remove(int value);
    void show();
};