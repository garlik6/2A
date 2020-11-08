#include"HashMap.h"
#include<cstring>
#include <iostream>
namespace HashTable {
    const char INFO[10] = {0,0,0,0,0,0,0,0,0,0};

    Element::Element() {
        this->busy = 0;
        strcpy(this->info,INFO);
        this->key = 0;
    }

    Element::Element(int key, char info[]) {
        this->busy = 1;
        strcpy(this->info,info);
        this->key = key;
    }


    HashMap::HashMap()  {
        for (auto & i : this->array)
            i = Element();
    }

    HashMap::HashMap(Element *HashMap) {
        for (int i = 0; i < 10; ++i)
            this->array[i] = HashMap[i];
    }

    void Element::print() {
        std::cout << busy << ";" << key << ";"<< info << ";"<<"\n";
    }

    void Element::insert() {
        std::cin >> key >> info;
    }

    void HashMap::print() {
        for (auto & i : array) {
            i.print();
        }
        std::cout << "\n";
    }

    int HashMap::hash(int key)  {
        int capacity = 10;
        return key%capacity;
    }

    int Element::getBusy(){
        return busy;
    }

    int Element::getKey(){
        return key;
    }

    char *Element::getInfo() {
        return info;
    }

    void Element::setBusy(int a) {
        busy = a;
    }

    void Element::setKey(int a) {
        key = a;
    }

    void Element::setInfo(char *inf) {
        strcpy(this->info,inf);
    }

    void HashMap::trashCollect() {
        int i = 0, j;
        while (i < this->capacity - 1) {
            if (this->array[i].getBusy() != -1) {}
            else {
                j = i;
                while (j < this->capacity - 1 && this->array[j + 1].getBusy() != 0 && this->hash(j) != this->hash(this->array[j].getKey())) {
                    this->array[j] = this->array[j + 1];
                    j++;
                }
                this->array[j-1] = Element();
            }
            i++;
        }
    }

    HashMap  HashMap::insert(Element Element) {
        int key = Element.getKey();
        char *info = Element.getInfo();
        int h = hash(Element.getKey());
        int i = 0;
        while (array[(h + i) % capacity].getBusy() == 1) {
            i++;
            if (i > capacity) {
                std::cout << "Full table";
                return *this;
            }
            if (array[(h + i) % capacity].getKey() == key)
                Element.setInfo(info);
            return *this;
        }
        array[(h + i) % capacity] = Element;
        return *this;
    }

    Element*  HashMap::search(int key)
    {
        int h = HashMap::hash(key);
        int i = 0;
        while (array[(h + i)%capacity].getBusy())
        {

            if(i > capacity){
                std::cout<<"Not found";
                return nullptr;
            }
            if (array[(h + i)%capacity].getKey() == key)
                return &array[(h + i)%capacity];
            i++;
        }
        return nullptr;
    }



    HashMap HashMap::erase(int key){
        Element *Element = search(key);
        if (Element == nullptr) {
            std::cout << "Not Found";
            return *this;
        } else {
            Element->setBusy(-1);
            trashCollect();
        }
        return *this;
    }

    char* HashMap::extract(int key) {
        Element* a = search(key);
        char * b = nullptr;
        return a->getInfo();
    }

    Element* HashMap::Find (int index) {
        Element* a = search(index);
        return a;
    }
}