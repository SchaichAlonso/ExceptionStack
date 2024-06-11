#include <QtConcurrent>

#include <Exceptions/FileNotFoundException>
#include <Exceptions/IllegalArgumentException>
#include <Exceptions/IndexOutOfBoundsException>
#include <Exceptions/NullPointerException>
#include <Exceptions/RuntimeException>

#include "SmokeTest.hpp"

namespace Exceptions
{

void SmokeTest::init()
{
}

void SmokeTest::cleanup()
{
}

void SmokeTest::initTestCase()
{
}

void SmokeTest::cleanupTestCase()
{
}

int SmokeTest::throwFileNotFound()
{
    throw FileNotFoundException("hello world");
}

void SmokeTest::fileNotFound()
{
    QVERIFY_THROWS_EXCEPTION(FileNotFoundException, throwFileNotFound());
    QVERIFY_THROWS_EXCEPTION(IOException, QtConcurrent::run(throwFileNotFound).result());
    QVERIFY_THROWS_EXCEPTION(FileNotFoundException, QtConcurrent::run(throwFileNotFound).result());

    QString filename;
    try
    {
        QFuture<int> future = QtConcurrent::run(throwFileNotFound);
        future.result();
    }
    catch (const FileNotFoundException &ex)
    {
        filename = ex.filename();
    }
    QCOMPARE(filename, "hello world");
}

int SmokeTest::throwRuntimeException()
{
    throw RuntimeException("hello world");
}

void SmokeTest::runtimeException()
{
    QVERIFY_THROWS_EXCEPTION(RuntimeException, throwRuntimeException());
    QVERIFY_THROWS_EXCEPTION(RuntimeException, QtConcurrent::run(throwRuntimeException).result());

    QString message;
    try
    {
        QFuture<int> future = QtConcurrent::run(throwRuntimeException);
        future.result();
    }
    catch (RuntimeException &ex)
    {
        message = ex.message();
    }
    QCOMPARE(message, "hello world");
}

int SmokeTest::throwIllegalArgumentException()
{
    throw IllegalArgumentException("hello world");
}

void SmokeTest::illegalArgumentException()
{
    QVERIFY_THROWS_EXCEPTION(IllegalArgumentException, throwIllegalArgumentException());
    QVERIFY_THROWS_EXCEPTION(RuntimeException, QtConcurrent::run(throwIllegalArgumentException).result());
    QVERIFY_THROWS_EXCEPTION(IllegalArgumentException, QtConcurrent::run(throwIllegalArgumentException).result());

    QString message;
    try
    {
        QFuture<int> future = QtConcurrent::run(throwIllegalArgumentException);
        future.result();
    }
    catch (IllegalArgumentException &ex)
    {
        message = ex.message();
    }
    QCOMPARE(message, "hello world");
}

int SmokeTest::throwIndexOutOfBoundsException()
{
    throw IndexOutOfBoundsException("hello world");
}

void SmokeTest::indexOufOfBoundsException()
{
    QVERIFY_THROWS_EXCEPTION(IndexOutOfBoundsException, throwIndexOutOfBoundsException());
    QVERIFY_THROWS_EXCEPTION(RuntimeException, QtConcurrent::run(throwIndexOutOfBoundsException).result());
    QVERIFY_THROWS_EXCEPTION(IndexOutOfBoundsException, QtConcurrent::run(throwIndexOutOfBoundsException).result());

    QString message;
    try
    {
        QFuture<int> future = QtConcurrent::run(throwIndexOutOfBoundsException);
        future.result();
    }
    catch (IndexOutOfBoundsException &ex)
    {
        message = ex.message();
    }
    QCOMPARE(message, "hello world");
}

int SmokeTest::throwNullPointerException()
{
    throw NullPointerException();
}

void SmokeTest::nullPointerException()
{
    QVERIFY_THROWS_EXCEPTION(NullPointerException, throwNullPointerException());
    QVERIFY_THROWS_EXCEPTION(RuntimeException, QtConcurrent::run(throwNullPointerException).result());
    QVERIFY_THROWS_EXCEPTION(NullPointerException, QtConcurrent::run(throwNullPointerException).result());
}

} // namespace Exceptions

QTEST_MAIN(Exceptions::SmokeTest);
