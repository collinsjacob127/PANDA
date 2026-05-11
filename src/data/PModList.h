#ifndef PMODLIST_H
#define PMODLIST_H

#include <QAbstractListModel>
#include <QSharedPointer>
#include <QVector>
#include <QDebug>

#include "PModItem.h"

class PModList : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit PModList(QObject* parent = nullptr) : QAbstractListModel(parent) {}

    // size of the list
    int rowCount(const QModelIndex& parent = QModelIndex()) const override
    {
        Q_UNUSED(parent);
        return m_items.size();
    }

    // return the data for the given index and role
    QVariant data(const QModelIndex& index, int role) const override
    {
        qDebug() << "Fetching data for index:" << index.row() << ", role:" << role;
        if (!isValidIndex(index)) {
            // Return empty if the index is invalid
            qDebug() << "Invalid index:" << index.row() << ", returning empty QVariant";
            return {};
        }
        return dataForRow(index.row(), role);
    }

    // set the data for the given index and role
    bool setData(const QModelIndex& index, const QVariant& value, int role) override
    {
        if (!isValidIndex(index)) { return false; }
        bool changed = setDataForRow(index.row(), value, role);
        if (changed) { emit dataChanged(index, index, { role }); }
        return changed;
    }

    // return the role names for the model
    QHash<int, QByteArray> roleNames() const override
    {
        return PModItem::roleNames();
    }

    // add item to the list
    void addItem(QSharedPointer<PModItem> item)
    {
        beginInsertRows(
            QModelIndex(),
            m_items.size(),
            m_items.size());

        m_items.append(item);

        endInsertRows();
    }

    // remove item from the list
    void removeItem(int index)
    {
        if (index < 0 || index >= m_items.size()) {
            return;
        }

        beginRemoveRows(QModelIndex(), index, index);

        m_items.removeAt(index);

        endRemoveRows();
    }

    // remove multiple items from the list
    void removeItems(
        const QVector<QSharedPointer<PModItem>>& items)
    {
        beginResetModel();

        for (const auto& item : items) {
            m_items.removeOne(item);
        }

        endResetModel();
    }

    // replace item in the list
    void replaceItem(
        int row,
        QSharedPointer<PModItem> item)
    {
        if (row < 0 || row >= m_items.size()) {
            return;
        }

        beginResetModel();

        m_items[row] = item;

        endResetModel();
    }

    void replaceList(
        const QVector<QSharedPointer<PModItem>>& list)
    {
        beginResetModel();

        m_items = list;

        endResetModel();
    }

    // Clear the list
    void clearList()
    {
        beginResetModel();

        m_items.clear();

        endResetModel();
    }

    int size() const
    {
        return m_items.size();
    }

    int indexOf(QSharedPointer<PModItem> item) const
    {
        return m_items.indexOf(item);
    }

    QSharedPointer<PModItem> getItem(int index) const
    {
        if (index >= 0 && index < m_list.size()) {
            return m_list[index];
        }
        return nullptr; // Return null if index is out of bounds
    }

    QModelIndex getIndex(int index) const
    {
        if (index >= 0 && index < m_list.size()) {
            return createIndex(index, 0);
        }
        return QModelIndex(); // Return invalid index if out of bounds
    }

protected:
    virtual QVariant dataForRow(
        int row,
        int role) const
    {
        return m_items[row]->getData(role);
    }

    virtual bool setDataForRow(
        int row,
        const QVariant& value,
        int role)
    {
        m_items[row]->setData(role, value);
        return true;
    }

    bool isValidIndex(const QModelIndex& index) const
    {
        return index.isValid()
            && index.row() >= 0
            && index.row() < m_items.size();
    }

protected:
    QVector<QSharedPointer<PModItem>> m_items;
};

#endif // PMODLIST_H
