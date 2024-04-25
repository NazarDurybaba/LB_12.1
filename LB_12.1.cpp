#include <iostream>
using namespace std;

struct Elem
{
    Elem* link1,
        * link2;
    int info;
};

int main()
{
    Elem* p;
    p = new Elem; // Node 'p'
    p->info = 1; // Node 1
    p->link1 = new Elem; // Node 1 points to Node 2
    p->link1->info = 2; // Node 2
    p->link1->link2 = nullptr; // Node 2 points to null
    p->link1->link1 = new Elem; // Node 2 points to Node 3
    p->link1->link1->info = 3; // Node 3

    // Deletion of nodes
    delete p->link1->link1; // Delete Node 3
    delete p->link1; // Delete Node 2
    delete p; // Delete Node 1 (or 'p')

    return 0;
}
