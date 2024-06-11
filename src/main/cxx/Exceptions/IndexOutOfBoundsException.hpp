#pragma once

#include <QtCore/QString>

#include "ExceptionsAPI.hpp"
#include "RuntimeException.hpp"

namespace Exceptions
{

struct ExceptionsAPI IndexOutOfBoundsException : RuntimeException
{
    IndexOutOfBoundsException(QString message);

    void raise() const override;
    QException *clone() const override;
};

} // namespace Exceptions