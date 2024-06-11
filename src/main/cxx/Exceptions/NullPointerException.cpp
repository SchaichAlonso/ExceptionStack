#include "NullPointerException.hpp"

namespace Exceptions
{

NullPointerException::NullPointerException(QString message) : RuntimeException(message)
{
}

void NullPointerException::raise() const
{
    throw *this;
}

QException *NullPointerException::clone() const
{
    return new NullPointerException(*this);
}

} // namespace Exceptions