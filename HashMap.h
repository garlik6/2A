#include <iostream>
namespace HashTable{
    class Element{
    public:
        Element();
        Element(int, char info[]);
        int getBusy();
        int getKey();
        char *getInfo();
        void setBusy(int busy);
        void setKey(int key);
        void setInfo(char *info);
        void print();
        void insert();
    private:
        char info[10];
        int busy;
        int key;
    };

    class HashMap{
    public:
        HashMap();
        HashMap(Element *HashMap);
        int hash(int key);
        HashMap insert(Element newElement);
        Element *search(int key);
        HashMap erase(int key);
        char* extract(int key);
        Element* Find(int key);
        void print();
        void trashCollect();
    private:
        Element array[10];
        const int capacity = 10;
    };
}
