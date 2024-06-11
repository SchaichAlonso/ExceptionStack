#include "IllegalArgumentException.hpp"

namespace Exceptions
{

IllegalArgumentException::IllegalArgumentException(QString message) : RuntimeException(message)
{
}

void IllegalArgumentException::raise() const
{
    throw *this;
}

QException *IllegalArgumentException::clone() const
{
    return new IllegalArgumentException(*this);
}

} // namespace Exceptions