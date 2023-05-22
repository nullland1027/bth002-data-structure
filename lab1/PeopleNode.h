//
// Created by Whoami on 2021/4/9.
//

#ifndef LAB1_PEOPLENODE_H
#define LAB1_PEOPLENODE_H


class PeopleNode {
private:
    int data;
    PeopleNode *nextPeople;
public:
    PeopleNode(int data) {
        this->data = data;
        nextPeople = nullptr;
    }


    int getData() {
        return data;
    }

    void setData(int peopleNumber) {
        data = peopleNumber;
    }

    PeopleNode *getNextPeople() {
        return nextPeople;
    }

    void setNextPeople(PeopleNode *nextPeople) {
        this->nextPeople = nextPeople;
    }
};


#endif //LAB1_PEOPLENODE_H
