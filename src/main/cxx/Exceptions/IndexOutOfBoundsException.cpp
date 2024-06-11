#include "IndexOutOfBoundsException.hpp"

namespace Exceptions
{

IndexOutOfBoundsException::IndexOutOfBoundsException(QString message) : RuntimeException(message)
{
}

void IndexOutOfBoundsException::raise() const
{
    throw *this;
}

QException *IndexOutOfBoundsException::clone() const
{
    return new IndexOutOfBoundsException(*this);
}

} // namespace Exceptions