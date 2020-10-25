#include "mynumberformatdelegate.h"

MyNumberFormatDelegate::MyNumberFormatDelegate(QObject *parent) :  QStyledItemDelegate(parent)
{

}

QString MyNumberFormatDelegate::displayText(const QVariant &value, const QLocale&) const
{
     return QString("%L1").arg(value.toLongLong());
}
