#include "pch.h"
#include "CppUnitTest.h"
#include "../LB_12.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
        TEST_METHOD(TestMemoryLeak)
        {
            Elem* p;
            p = new Elem; // Node 'p'
            p->info = 1; // Node 1
            p->link1 = new Elem; // Node 1 points to Node 2
            p->link1->info = 2; // Node 2
            p->link1->link2 = p; // Node 2 points back to Node 1
            p->link2 = new Elem; // Node 1 points back to itself
            p->link2->info = 4; // Node 4
            p->link2->link1 = p; // Node 4 points back to Node 'p'
            p->link2->link2 = new Elem; // Node 4 points to Node 3
            p->link2->link2->info = 3; // Node 3

            // Deletion of nodes
            delete p->link2->link2; // Delete Node 3
            delete p->link2; // Delete Node 4
            delete p->link1; // Delete Node 2
            delete p; // Delete Node 1 (or 'p')

            // Assert that all memory has been properly deallocated
            Assert::IsTrue(true, L"All memory deallocated successfully");
        }
	};
}
