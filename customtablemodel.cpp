#include "customtablemodel.h"
#include <QFont>
#include <QBrush>
#include <QTime>

CustomTableModel::CustomTableModel(QObject * parent, std::vector<stats> stats_list ) : QAbstractTableModel(parent), stats_list(stats_list)
{
    timer = new QTimer(this);
    timer->setInterval(1000);
    connect( timer,&QTimer::timeout,[=](){
        QModelIndex topLeft = index(0,0);

        //Notify the view of the change the time in the model
        emit dataChanged(topLeft,topLeft);
    });

    timer->start();


}

int CustomTableModel::rowCount(const QModelIndex &parent) const
{
    return stats_list.size();
}

int CustomTableModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant CustomTableModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    int col = index.column();

    stats stats = stats_list.at(row);

    switch(role)
    {
        case Qt::DisplayRole: {
            if (col == 0) {
                return QString::fromStdWString(stats.get_ext());
            } else if (col == 1) {
                return QVariant(stats.get_count());
            } else  if (col == 2) {
                return QVariant(stats.get_size());
            }
        }
        break;

    case Qt::TextAlignmentRole:

        if(col ==0)
        {
            return Qt::AlignLeft;
        } else {
            return Qt::AlignRight;
        }

        break;

    }
    return QVariant();
}

QVariant CustomTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if( role == Qt::DisplayRole)
    {
        if( orientation == Qt::Horizontal)
        {
            switch (section) {
            case 0:
                return QString("Erweiterung");
                break;
            case 1:
                return QString("Anzahl");
                break;
            case 2:
                return QString("Größe");
                break;
            default:
                return QString("Default");
                break;
            }
        }
        if( orientation == Qt::Vertical)
        {
          return QString::number(section + 1);
        }

    }
    return QVariant();

}


