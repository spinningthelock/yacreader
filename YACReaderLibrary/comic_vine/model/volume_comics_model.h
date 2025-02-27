#ifndef VOLUME_COMICS_MODEL_H
#define VOLUME_COMICS_MODEL_H

#include "json_model.h"

class VolumeComicsModel : public JSONModel
{
    Q_OBJECT
public:
    explicit VolumeComicsModel(QObject *parent = nullptr);
    void load(const QString &json) override;
    // void load(const QStringList & jsonList);

    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
signals:

public slots:
    QString getComicId(const QModelIndex &index) const;
    QString getComicId(int row) const;
    QString getCoverURL(const QModelIndex &index) const;
    void addExtraRows(int numRows);

private:
    int numExtraRows;
    QList<QList<QString>> _data;

    enum Column {
        ISSUE = 0,
        TITLE,
        COVER_URL,
        ID
    };
};

#endif // VOLUME_COMICS_MODEL_H
