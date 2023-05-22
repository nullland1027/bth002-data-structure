//
// Created by Whoami on 2021/4/9.
//

#ifndef LAB1_CIRCLE_H
#define LAB1_CIRCLE_H

#include "PeopleNode.h"

class Circle {
private:
    PeopleNode *head;
    int currentPeople;
    int numberOfPass;
    int numberOfPeople;
public:
    Circle(int numberOfPeople, int numberOfPass) {
        this->numberOfPeople = numberOfPeople;
        this->numberOfPass = numberOfPass;
        head = nullptr;
        currentPeople = 0;
    }

    ~Circle() {

    };

    /**
     * Add player into the circle
     * @param peopleNumber
     */
    void addPeople(int peopleNumber) {
        PeopleNode *node = new PeopleNode(peopleNumber);
        if (head == nullptr) {
            head = node;
        } else {
            PeopleNode *trav = head;
            for (int i = 0; i < currentPeople - 1; i++) {
                trav = trav->getNextPeople();
            }
            trav->setNextPeople(node); // add people to the tail
            node->setNextPeople(head); // tail points to head
        }
        currentPeople++;
    }

    /**
     * After one turn, one man leave
     */
    void removePeople() {
        PeopleNode *trav = head;
        if (numberOfPass == 0) {
            head = head->getNextPeople();
            delete trav;
        } else {
            PeopleNode *trav2 = head;

            for (int i = 0; i < numberOfPass; i++) {
                trav2 = trav2->getNextPeople();
            }
            for (int i =0; i < numberOfPass - 1; i++) {
                trav = trav->getNextPeople();
            }
            head = trav2->getNextPeople();
            delete trav2;
            trav->setNextPeople(head);
        }
        currentPeople--;
    }

    int getCurrentPeople() const {
        return currentPeople;
    }

    int getPeopleNumber() const {
        int res = head->getData();
        delete head;
        return res;
    }
};


#endif //LAB1_CIRCLE_H
