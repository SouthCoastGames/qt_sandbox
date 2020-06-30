#include "treeitem.h"
#include <QModelIndex>

TreeItem::TreeItem(const QVector<QVariant> &data, TreeItem *parent)
    : m_itemData(data), m_parentItem(parent)
{
}

TreeItem::~TreeItem()
{
    qDeleteAll(m_childItems);
}

void TreeItem::appendChild(TreeItem *item)
{
    m_childItems.append(item);
}

TreeItem *TreeItem::child(int row)
{
    if (row < 0 || row >= m_childItems.size())
    {
        return nullptr;
    }

    return m_childItems.at(row);
}

int TreeItem::childCount() const
{
    return m_childItems.count();
}

QVariant TreeItem::data(int column) const
{
    if (column < 0 || column >= m_itemData.size())
    {
        return QVariant();
    }

    return m_itemData.at(column);
}

QVariant TreeItem::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());

    if (role == Qt::CheckStateRole && index.column() == 0)
    {
        return static_cast<int>(item->isChecked() ? Qt::Checked : Qt::Unchecked);
    }

    if (role != Qt::DisplayRole)
    {
        return QVariant();
    }

    return item->data(index.column());
}

TreeItem *TreeItem::parentItem()
{
    return m_parentItem;
}

int TreeItem::row() const
{
    if (m_parentItem)
    {
        return m_parentItem->m_childItems.indexOf(const_cast<TreeItem*>(this));
    }

    return 0;
}

int TreeItem::columnCount() const
{
    return m_itemData.count();
}
