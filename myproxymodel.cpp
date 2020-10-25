#include "myproxymodel.h"

MyProxyModel::MyProxyModel(QObject * parent): QSortFilterProxyModel(parent)
{

}

QVariant MyProxyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(orientation!=Qt::Vertical || role!=Qt::DisplayRole)
      return QSortFilterProxyModel::headerData(section, orientation, role);

    return section+1;
}


