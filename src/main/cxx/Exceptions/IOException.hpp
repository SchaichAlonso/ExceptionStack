#pragma once

#include <QtCore/QException>

#include "ExceptionsAPI.hpp"

namespace Exceptions
{

struct ExceptionsAPI IOException : QException
{
};

} // namespace Exceptions
