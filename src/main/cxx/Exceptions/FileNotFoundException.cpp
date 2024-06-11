#include "FileNotFoundException.hpp"

namespace Exceptions
{

FileNotFoundException::FileNotFoundException(QString filename) : m_filename(filename)
{
}

void FileNotFoundException::raise() const
{
    throw *this;
}

FileNotFoundException *FileNotFoundException::clone() const
{
    return new FileNotFoundException(*this);
}

QString FileNotFoundException::filename() const
{
    return m_filename;
}

} // namespace Exceptions