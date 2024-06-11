#pragma once

#include <QTest>
#include <QtCore/QObject>

namespace Exceptions
{

struct SmokeTest : QObject
{
  public:
    Q_OBJECT;
  private slots:
    void initTestCase();
    void init();
    void cleanup();
    void cleanupTestCase();
    void fileNotFound();
    void runtimeException();
    void illegalArgumentException();
    void indexOufOfBoundsException();
    void nullPointerException();

  private:
    static int throwFileNotFound();
    static int throwRuntimeException();
    static int throwIllegalArgumentException();
    static int throwIndexOutOfBoundsException();
    static int throwNullPointerException();
};

} // namespace Exceptions