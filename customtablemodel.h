#ifndef CUSTOMTABLEMODEL_H
#define CUSTOMTABLEMODEL_H

#include <QAbstractTableModel>
#include <QTimer>
#include <QObject>

#include "stats.h"

class CustomTableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    CustomTableModel(QObject * parent, std::vector<stats> stats_list);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;//Controls the data that is shown in each cell
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QTimer * timer;
    std::vector<stats> stats_list;
};

#endif // CUSTOMTABLEMODEL_H
