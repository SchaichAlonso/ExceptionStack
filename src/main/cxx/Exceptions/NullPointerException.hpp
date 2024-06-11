#pragma once

#include <QtCore/QString>

#include "ExceptionsAPI.hpp"
#include "RuntimeException.hpp"

namespace Exceptions
{

struct ExceptionsAPI NullPointerException : RuntimeException
{
    NullPointerException(QString message = "NullPointerException");

    void raise() const override;
    QException *clone() const override;
};

} // namespace Exceptions