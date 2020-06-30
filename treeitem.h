#ifndef __TREEITEM_H__
#define __TREEITEM_H__

#include <QVector>
#include <QVariant>

class TreeItem
{
public:
    explicit TreeItem(const QVector<QVariant> &data, TreeItem *parentItem = nullptr);
    ~TreeItem();

    void appendChild(TreeItem *child);

    TreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    QVariant data(const QModelIndex &index, int role) const;
    int row() const;
    TreeItem *parentItem();
    bool isChecked() const {return checked;};
    void setChecked( bool set ) {checked = set; };

private:
    QVector<TreeItem*> m_childItems;
    QVector<QVariant> m_itemData;
    TreeItem *m_parentItem;
    bool checked;
};

#endif /* __TREEITEM_H__ */
