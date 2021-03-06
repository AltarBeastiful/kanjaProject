#ifndef DOMAIN_EPISODE_H
#define DOMAIN_EPISODE_H

#include <QDate>
#include <QObject>
#include <QSharedDataPointer>
#include <QString>

namespace Domain {

class Episode : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int number READ number WRITE setNumber NOTIFY numberChanged)
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int season READ season WRITE setSeason NOTIFY seasonChanged)
    Q_PROPERTY(QDate diffusion READ diffusion WRITE setDiffusion NOTIFY diffusionChanged)

public:
    typedef QSharedPointer<Episode> Ptr;
    typedef QList<Episode::Ptr> List;

    explicit Episode(QObject *parent = 0);
    virtual ~Episode();

    int number() const;
    QString name() const;
    int season() const;
    QDate diffusion() const;
    QDate lastViewed() const;

public slots:
    void setNumber(const int number);
    void setName(const QString &name);
    void setSeason(const int season);
    void setDiffusion(const QDate &diffusion);

signals:
    void numberChanged(int number);
    void nameChanged(QString &name);
    void seasonChanged(int season);
    void diffusionChanged(QDate &diffusion);

private:
    int number_m;
    QString name_m;
    int season_m;
    QDate diffusion_m;
    QDate lastViewed_m;
};

}

#endif // DOMAIN_EPISODE_H
