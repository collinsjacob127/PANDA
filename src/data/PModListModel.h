#pragma once

#include "PAbstractListModel.h"
#include "PModItem.h"

#include <QVector>
#include <QSharedPointer>

class PModListModel : public PAbstractListModel
{
    Q_OBJECT

public:
    explicit PModListModel(QObject* parent = nullptr)
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
        return m_items.size();
    }

    QVariant dataForRow(
        int row,
        int role) const override
    {
        return m_items[row]->getData(role);
    }

    bool setDataForRow(
        int row,
        const QVariant& value,
        int role) override
    {
        m_items[row]->setData(role, value);
        return true;
    }

public:
    void addItem(QSharedPointer<PModItem> item)
    {
        beginInsertRows({}, m_items.size(), m_items.size());
        m_items.append(item);
        endInsertRows();
    }

    void removeItem(int row)
    {
        if (row < 0 || row >= m_items.size()) {
            return;
        }

        beginRemoveRows({}, row, row);
        m_items.removeAt(row);
        endRemoveRows();
    }

    void clear()
    {
        beginResetModel();
        m_items.clear();
        endResetModel();
    }

    QSharedPointer<PModItem> itemAt(int row) const
    {
        if (row < 0 || row >= m_items.size()) {
            return {};
        }

        return m_items[row];
    }

private:
    QVector<QSharedPointer<PModItem>> m_items;
};
