#include "CppUnitTest.h"
#include "../2. 2/Array.h"
#include "Windows.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace VectorTests
{
    TEST_CLASS(VectorTest)
    {
    public:

        TEST_METHOD_INITIALIZE(SetupRussian)
        {
            SetConsoleCP(1251);
            SetConsoleOutputCP(1251);
        }

        TEST_METHOD(DefaultConstructor) {
            vector v;
            Assert::AreEqual(static_cast<int>(v.getSize()), 0);
            Assert::IsTrue(v.isEmpty());
            Assert::AreEqual(v.toString(), string("Пусто"));
        }

        TEST_METHOD(InitializerListConstructor) {
            vector v = { 1, 2, 3 };
            Assert::AreEqual(static_cast<int>(v.getSize()), 3);
            Assert::AreEqual(v[0], 1);
            Assert::AreEqual(v[1], 2);
            Assert::AreEqual(v[2], 3);
        }

        TEST_METHOD(CopyConstructor) {
            vector v1 = { 1, 2, 3 };
            vector v2 = v1;
            Assert::AreEqual(v2.toString(), v1.toString());
            v2[0] = 99;
            Assert::AreNotEqual(v2[0], v1[0]);
        }

        TEST_METHOD(CopyAssignment) {
            vector v1 = { 1, 2, 3 };
            vector v2;
            v2 = v1;
            Assert::AreEqual(v2.toString(), v1.toString());
            v2[0] = 99;
            Assert::AreNotEqual(v2[0], v1[0]);
        }

        TEST_METHOD(SelfAssignment) {
            vector v = { 1, 2, 3 };
            v = v;
            Assert::AreEqual(v.toString(), string("1 2 3"));
        }

        TEST_METHOD(EqualityOperators) {
            vector v1 = { 1, 2, 3 };
            vector v2 = { 1, 2, 3 };
            vector v3 = { 1, 2, 4 };
            Assert::IsTrue(v1 == v2);
            Assert::IsTrue(v1 != v3);
        }

        TEST_METHOD(OperatorIndex) {
            vector v = { 10, 20, 30 };
            Assert::AreEqual(v[0], 10);
            Assert::AreEqual(v[2], 30);
        }

        TEST_METHOD(OperatorIndexWrite) {
            vector v = { 1, 2, 3 };
            v[1] = 99;
            Assert::AreEqual(v[1], 99);
        }

        TEST_METHOD(PushAtBegin) {
            vector v = { 1, 2, 3 };
            v.push(0, 99);
            Assert::AreEqual(v.toString(), string("99 1 2 3"));
        }

        TEST_METHOD(PushAtEnd) {
            vector v = { 1, 2, 3 };
            v.push(v.getSize(), 99);
            Assert::AreEqual(v.toString(), string("1 2 3 99"));
        }

        TEST_METHOD(PopAtMiddle) {
            vector v = { 1, 2, 3 };
            v.pop(1);
            Assert::AreEqual(v.toString(), string("1 3"));
        }

        TEST_METHOD(PopUntilEmpty) {
            vector v = { 1 };
            v.pop(0);
            Assert::IsTrue(v.isEmpty());
            Assert::AreEqual(v.toString(), string("Пусто"));
        }

        TEST_METHOD(ReplaceElement) {
            vector v = { 1, 2, 3 };
            v.replace(1, 42);
            Assert::AreEqual(v[1], 42);
            Assert::AreEqual(static_cast<int>(v.getSize()), 3);
        }
    };
}