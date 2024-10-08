#include "multilist.h"
#include <iostream>
#include <string>
#include <cctype>

void upper(std::string& str){ 
    for (size_t index = 0; index < str.length(); index++){
        str[index] = toupper(str[index]);
    }
}

Multilist::Node::Node(int id, std::string name, int age):
id(id), name(name), age(age),
prev_id(nullptr), next_id(nullptr),
prev_name(nullptr), next_name(nullptr),
prev_age(nullptr), next_age(nullptr) {};

Multilist::Multilist() {
    first = new Node(-1, "first", -1);
    last = new Node(-1, "last", -1);

    first->next_id = last;
    first->next_age = last;
    first->next_name = last;
    
    last->prev_id = first;
    last->prev_age = first;
    last->prev_name = first;
    
}

Multilist::~Multilist() {
    Node* current = first;
    Node* next;
    while (current) {
        next = current->next_id;
        delete current;
        current = next;
    }
    first = nullptr;
    last = nullptr;
}

bool Multilist::insert(int id, std::string name, int age) {
    upper(name);
    Node* newNode = new Node(id, name, age);
    Node* head = first;
    Node* temp;
    bool id_found = false;
    bool age_found = false;
    bool name_found = false;
    while (!id_found && head) {
        if (head->id != -1){
            if (id < head->id && !id_found){
                temp = head->prev_id; 

                head->prev_id = newNode;
                newNode->next_id = head;

                newNode->prev_id = temp;
                temp->next_id = newNode;

                id_found = true;
            }
        }
        head = head->next_id;
    }
    if (!id_found){
        temp = last->prev_id;

        last->prev_id = newNode;
        newNode->next_id = last;

        temp->next_id = newNode;
        newNode->prev_id = temp;
    }

    head = first;
    while (!age_found && head){
        if (head->id != -1){
            if (age < head->age && !age_found){
                temp = head->prev_age; 

                head->prev_age = newNode;
                newNode->next_age = head;

                newNode->prev_age = temp;
                temp->next_age = newNode;

                age_found = true;
            }
        }
        head = head->next_age;
    }
    if (!age_found){
        temp = last->prev_age;

        last->prev_age = newNode;
        newNode->next_age = last;

        temp->next_age = newNode;
        newNode->prev_age = temp;
    }

    head = first;
    while(!name_found && head){
        if (head->id != -1){
            if (name < head->name && !name_found){
                temp = head->prev_name; 

                head->prev_name = newNode;
                newNode->next_name = head;

                newNode->prev_name = temp;
                temp->next_name = newNode;

                name_found = true;
            }
        }
        head = head->next_name;
    }
    if (!name_found){
        temp = last->prev_name;

        last->prev_name = newNode;
        newNode->next_name = last;

        temp->next_name = newNode;
        newNode->prev_name = temp;
    }
    return true;
}

bool Multilist::remove(int id){
    Node* head = first;
    while (head){
        if (head->id == id){
            head->next_id->prev_id = head->prev_id; 
            head->prev_id->next_id = head->next_id;

            head->next_name->prev_name = head->prev_name; 
            head->prev_name->next_name = head->next_name;

            head->next_age->prev_age = head->prev_age; 
            head->prev_age->next_age = head->next_age;
            delete head;
            head = nullptr;
            return true;
        }
        head = head->next_id;
    }
    return false;
}

void Multilist::print_by_ID() {
    std::cout << "printing by ID number:\n";
    Node* head = first;
    while (head) {
        if (head != first && head != last) {
            std::cout << "(" << head->name << " " << head->id << " " << head->age << ")\n";
        }
        head = head->next_id;
    }
}

void Multilist::print_by_ID_reverse(){
    std::cout << "printing by ID number reverse:\n";
    Node* head = last;
    while (head) {
        if (head != first && head != last) {
            std::cout << "(" << head->name << " " << head->id << " " << head->age << ")\n";
        }
        head = head->prev_id;
    }
}

void Multilist::print_by_name(){
    std::cout << "printing by name:\n";
    Node* head = first;
    while (head) {
        if (head != first && head != last) {
            std::cout << "(" << head->name << " " << head->id << " " << head->age << ")\n";
        }
        head = head->next_name;
    }
}

void Multilist::print_by_name_reverse(){
    std::cout << "printing by name reverse:\n";
    Node* head = last;
    while (head) {
        if (head != first && head != last) {
            std::cout << "(" << head->name << " " << head->id << " " << head->age << ")\n";
        }
        head = head->prev_name;
    }
}

void Multilist::print_by_age(){
    std::cout << "printing by age\n";
    Node* head = first;
    while (head) {
        if (head != first && head != last) {
            std::cout << "(" << head->name << " " << head->id << " " << head->age << ")\n";
        }
        head = head->next_age;
    }
}

void Multilist::print_by_age_reverse(){
    std::cout << "printing by age reverse\n";
    Node* head = last;
    while (head) {
        if (head != first && head != last) {
            std::cout << "(" << head->name << " " << head->id << " " << head->age << ")\n";
        }
        head = head->prev_age;
    }
}