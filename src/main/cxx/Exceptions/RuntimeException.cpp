#include "RuntimeException.hpp"

namespace Exceptions
{

RuntimeException::RuntimeException(QString message) : m_message(message)
{
}

void RuntimeException::raise() const
{
    throw *this;
}

QException *RuntimeException::clone() const
{
    return new RuntimeException(*this);
}

QString RuntimeException::message() const
{
    return m_message;
}

} // namespace Exceptions