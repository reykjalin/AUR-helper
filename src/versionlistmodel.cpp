#include "versionlistmodel.h"

VersionListModel::VersionListModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

QVariant VersionListModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
    // if(role == Qt::DisplayRole) {
        // if(orientation == Qt::Horizontal) {
            switch(section) {
                case 0: return QString("Package"); break;
                case 1: return QString("Local version"); break;
                case 2: return QString("Online version"); break;
                default: break;
            }
    //     }
    // }
    return QVariant();
}

bool VersionListModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int role)
{
    if (value != headerData(section, orientation, role)) {
        // FIXME: Implement me!
        emit headerDataChanged(orientation, section, section);
        return true;
    }
    return false;
}


int VersionListModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 5;

    // FIXME: Implement me!
    return 7;
}

int VersionListModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 3;

    // FIXME: Implement me!
    return 2;
}

QVariant VersionListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}

bool VersionListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags VersionListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

bool VersionListModel::insertRows(int row, int count, const QModelIndex &parent)
{
    beginInsertRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endInsertRows();
    return false;
}

bool VersionListModel::insertColumns(int column, int count, const QModelIndex &parent)
{
    beginInsertColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endInsertColumns();
    return false;
}

bool VersionListModel::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    // FIXME: Implement me!
    endRemoveRows();
    return false;
}

bool VersionListModel::removeColumns(int column, int count, const QModelIndex &parent)
{
    beginRemoveColumns(parent, column, column + count - 1);
    // FIXME: Implement me!
    endRemoveColumns();
    return false;
}
