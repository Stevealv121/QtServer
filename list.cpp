#include "list.h"

List::List()
{

    head = nullptr;
    tail = nullptr;

}

void List::createnode(std::string value) {

    node *temp=new node;
    temp->data=value;
    temp->next= nullptr;
    if(head== nullptr)
    {
        head=temp;
        tail=temp;
        temp= nullptr;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }

}

void List::display() {

    node *temp=new node;
    temp=head;
    while(temp!= nullptr)
    {
        std::cout<<temp->data<<"\t";
        temp=temp->next;
    }

}

void List::insert(std::string value) {

    node *temp=new node;
    temp->data=value;
    temp->next=head;
    head=temp;
}

std::string List::pop() {

    node *current=new node;
    node *previous=new node;
    std::string pop;

    current=head;
    while(current->next!=nullptr)
    {
        previous=current;
        current=current->next;

    }
    tail=previous;
    previous->next=nullptr;
    pop = current->data;


    delete current;

    return pop;

}
