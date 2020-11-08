#include <iostream>
#include "HashMap.h"
int main() {
    HashTable::HashMap table;
    HashTable::Element a1(12,"1111111111");
    HashTable::Element a2(13,"22222222");
    HashTable::Element a3(15,"333333333");
    HashTable::Element a4(19,"44444444");
    HashTable::Element a5(16,"5555555555");
    HashTable::Element a6(22,"6666666");
    HashTable::Element a7(37,"77777");
    table.insert(a2).insert(a1);
    table.insert(a3);
    table.insert(a4);
    table.insert(a5);
    table.insert(a6).erase(22).insert(a7);

    table.print();

    a7.insert();
    table.insert(a7);
    table.print();
    std::cout<<table.extract(13);
}
