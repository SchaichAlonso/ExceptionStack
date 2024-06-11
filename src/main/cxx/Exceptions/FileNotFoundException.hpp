#pragma once

#include <QtCore/QString>

#include "ExceptionsAPI.hpp"
#include "IOException.hpp"

namespace Exceptions
{

struct ExceptionsAPI FileNotFoundException : IOException
{
    FileNotFoundException(QString filename);

    void raise() const override;
    FileNotFoundException *clone() const override;

    QString filename() const;

  private:
    QString m_filename;
};

} // namespace Exceptions