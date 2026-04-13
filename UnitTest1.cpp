#include "CppUnitTest.h"
#include "../2. 2/Piquet.h"
#include "../2. 2/Slope.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Tests
{
    TEST_CLASS(PiquetTests)
    {
    public:
        TEST_METHOD(Piquet_Create_Success)
        {
            Piquet p(12, 28.37, true);
            Assert::AreEqual(12, p.getNumber());
            Assert::AreEqual(28.37, p.getShift(), 0.001);
            Assert::IsTrue(p.getIsStandard());
        }

        TEST_METHOD(Piquet_ToString_Positive)
        {
            Piquet p(12, 28.37, true);
            string expected = "ой 12+28.37";
            Assert::AreEqual(expected, p.toString());
        }

        TEST_METHOD(Piquet_ToString_Negative)
        {
            Piquet p(-12, 28.37, true);
            string expected = "ой 012+28.37";
            Assert::AreEqual(expected, p.toString());
        }

        TEST_METHOD(Piquet_Compare_Less)
        {
            Piquet p1(10, 0, true);
            Piquet p2(20, 0, true);
            Assert::IsTrue(p1 < p2);
        }

        TEST_METHOD(Piquet_Compare_Equal)
        {
            Piquet p1(10, 50.0, true);
            Piquet p2(10, 50.0, true);
            Assert::IsTrue(p1 == p2);
        }
    };

    TEST_CLASS(SlopeTests)
    {
    public:
        TEST_METHOD(Slope_Create_Success)
        {
            Piquet start(10, 0);
            Piquet end(20, 0);
            Slope s(25, start, end);

            Assert::AreEqual(25.0, s.getValue(), 0.001);
            Assert::IsTrue(s.getStart() == start);
            Assert::IsTrue(s.getEnd() == end);
        }

        TEST_METHOD(Slope_ToString_ContainsData)
        {
            Slope s(25, Piquet(10, 0), Piquet(20, 0));
            string str = s.toString();

            Assert::IsTrue(str.find("25") != string::npos);
            Assert::IsTrue(str.find("ой 10+0") != string::npos);
            Assert::IsTrue(str.find("ой 20+0") != string::npos);
        }

        TEST_METHOD(Slope_ValidValue_ReturnsTrue)
        {
            Slope s(25, Piquet(), Piquet());
            Assert::IsTrue(s.isValid());
        }

        TEST_METHOD(Slope_InvalidValue_ReturnsFalse)
        {
            Slope s(75, Piquet(), Piquet());
            Assert::IsFalse(s.isValid());
        }

        TEST_METHOD(Slope_SetValue_Valid_Success)
        {
            Slope s;
            s.setValue(30);
            Assert::AreEqual(30.0, s.getValue(), 0.001);
        }

        TEST_METHOD(Slope_SetValue_Invalid_ThrowsException)
        {
            Slope s;
            auto func = [&s]() { s.setValue(100); };
            Assert::ExpectException<std::invalid_argument>(func);
        }
    };
}