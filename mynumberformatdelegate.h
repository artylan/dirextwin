#ifndef MYNUMBERFORMATDELEGATE_H
#define MYNUMBERFORMATDELEGATE_H

#include <QStyledItemDelegate>

class MyNumberFormatDelegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    explicit MyNumberFormatDelegate(QObject *parent = nullptr);
    virtual QString displayText(const QVariant &value, const QLocale&) const;

signals:

};

#endif // MYNUMBERFORMATDELEGATE_H
