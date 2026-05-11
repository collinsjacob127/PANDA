#pragma once

#include <QAbstractListModel>

class PAbstractListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit PAbstractListModel(QObject* parent = nullptr)
        : QAbstractListModel(parent)
    {
    }

    int rowCount(const QModelIndex& parent = QModelIndex()) const override
    {
        Q_UNUSED(parent);
        return itemCount();
    }

    QVariant data(const QModelIndex& index, int role) const override
    {
        if (!isValidIndex(index)) {
            return {};
        }

        return dataForRow(index.row(), role);
    }

    bool setData(
        const QModelIndex& index,
        const QVariant& value,
        int role) override
    {
        if (!isValidIndex(index)) {
            return false;
        }

        bool changed = setDataForRow(
            index.row(),
            value,
            role);

        if (changed) {
            emit dataChanged(index, index, { role });
        }

        return changed;
    }

protected:
    virtual int itemCount() const = 0;

    virtual QVariant dataForRow(
        int row,
        int role) const = 0;

    virtual bool setDataForRow(
        int row,
        const QVariant& value,
        int role) = 0;

    bool isValidIndex(const QModelIndex& index) const
    {
        return index.isValid()
            && index.row() >= 0
            && index.row() < itemCount();
    }
};
