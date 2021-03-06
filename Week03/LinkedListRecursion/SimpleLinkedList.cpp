#include "SimpleLinkedList.h"

#include <iostream>

using namespace std;

#define while heckno
#define for youshouldntneedme

int ListNode::nodeCount = 0;

//---------------------------------------------
//ListNode
//---------------------------------------------
ListNode::ListNode(int value) {
    data = value;
    nodeCount++;
}

ListNode::~ListNode() {
    nodeCount--;
}

//---------------------------------------------

void SimpleLinkedList::insertStart(int value) {
    ListNode* newNode = new ListNode(value);

    newNode->next = head;
    head = newNode;
}

//---------------------------------------------

//Assumes there is at least one node to work with
string recursiveToString(ListNode* current) {
    if(current->next == nullptr)
        return to_string(current->data);

    string rest = recursiveToString(current->next);
    string result = to_string(current->data) + " " + rest;

    return result;
}

string SimpleLinkedList::toString() {
    if(head == nullptr)
        return "";
    return recursiveToString(head);
}

//---------------------------------------------

int recursiveGetTotal(ListNode* current) {
    if(current == nullptr)
        return 0;
    else {
        int everyoneElse = recursiveGetTotal(current->next);
        int total = current->data + everyoneElse;
        return total;
    }
}


int SimpleLinkedList::getTotal()
{
    return recursiveGetTotal(head);
}

//---------------------------------------------


int recursiveRetrieveAt(ListNode* current, int stepsLeft) {
    if(stepsLeft == 0)
        return current->data;
    else {
        return recursiveRetrieveAt(current->next, stepsLeft - 1);
    }
}

int SimpleLinkedList::retrieveAt(int index) {
    return recursiveRetrieveAt(head, index);
}


//---------------------------------------------

ListNode* recursiveRemoveLast(ListNode* current) {
    if(current->next == nullptr) {
        delete current;
        return nullptr;
    }
    else {
        current->next = recursiveRemoveLast(current->next);
        return current;
    }
}

void SimpleLinkedList::removeLast() {
    if(head != nullptr)
        head = recursiveRemoveLast(head);
}



//---------------------------------------------
//---------------------------------------------
//---------------------------------------------

string recursiveReverseToString(ListNode* current) {
    //TODO: Fix me
    return "";
}

string SimpleLinkedList::reverseToString() {
    if(head == nullptr)
        return "";
    return recursiveReverseToString(head);
}

//---------------------------------------------

int recursiveMax(ListNode* current) {
    //TODO: Fix me
    return 0;
}


int SimpleLinkedList::getMaxValue() {
    return recursiveMax(head);
}


//---------------------------------------------

void recursiveDelete(ListNode* current) {
    //TODO: Fix me
}


SimpleLinkedList::~SimpleLinkedList()
{
    recursiveDelete(head);
    head = nullptr;
}
