#pragma once

#include <QtCore/QException>
#include <QtCore/QString>

#include "ExceptionsAPI.hpp"

namespace Exceptions
{

struct ExceptionsAPI RuntimeException : QException
{
    RuntimeException(QString message);

    void raise() const override;
    QException *clone() const override;

    QString message() const;

  private:
    QString m_message;
};

} // namespace Exceptions