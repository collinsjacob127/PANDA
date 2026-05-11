#pragma once

#include "PAbstractListModel.h"
#include "PModItem.h"

#include <QVector>
#include <QSharedPointer>

class PModList : public PAbstractListModel
{
    Q_OBJECT

public:
    explicit PModList(QObject* parent = nullptr)
        : PAbstractListModel(parent)
    {
    }

    QHash<int, QByteArray> roleNames() const override
    {
        return PModItem::roleNames();
    }

protected:
    int itemCount() const override
    {
        return m_list.size();
    }

    QVariant dataForRow(
        int row,
        int role) const override
    {
        return m_list[row]->getData(role);
    }

    bool setDataForRow(
        int row,
        const QVariant& value,
        int role) override
    {
        m_list[row]->setData(role, value);
        return true;
    }

public:
    void addItem(QSharedPointer<PModItem> item)
    {
        beginInsertRows({}, m_list.size(), m_list.size());
        m_list.append(item);
        endInsertRows();
    }

    void removeItem(int row)
    {
        if (row < 0 || row >= m_list.size()) {
            return;
        }

        beginRemoveRows({}, row, row);
        m_list.removeAt(row);
        endRemoveRows();
    }

    void clear()
    {
        beginResetModel();
        m_list.clear();
        endResetModel();
    }

    int size() const
    {
        return m_list.size();
    }

    QSharedPointer<PModItem> getItem(int index) const
    {
        if (index >= 0 && index < m_list.size()) {
            return m_list[index];
        }
        return nullptr; // Return null if index is out of bounds
    }

    void replaceItem(int row, QSharedPointer<PModItem> item)
    {
        if (row >= 0 && row < m_list.size()) {
            beginResetModel();
            m_list[row] = item;
            endResetModel();
        }
    }

    void replaceList(QVector<QSharedPointer<PModItem>> list)
    {
        beginResetModel();
        m_list = list;
        endResetModel();
    }

    QModelIndex getIndex(int index) const
    {
        if (index >= 0 && index < m_list.size()) {
            return createIndex(index, 0);
        }
        return QModelIndex(); // Return invalid index if out of bounds
    }


    QSharedPointer<PModItem> itemAt(int row) const
    {
        if (row < 0 || row >= m_list.size()) {
            return {};
        }

        return m_list[row];
    }

    int indexOf(QSharedPointer<PModItem> item) const
    {
        return m_list.indexOf(item);
    }

private:
    QVector<QSharedPointer<PModItem>> m_list;
};
