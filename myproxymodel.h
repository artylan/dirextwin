#ifndef MYPROXY_H
#define MYPROXY_H

#include <QObject>
#include <QSortFilterProxyModel>

class MyProxyModel: public QSortFilterProxyModel
{
public:
    MyProxyModel(QObject * parent);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
};

#endif // MYPROXY_H
