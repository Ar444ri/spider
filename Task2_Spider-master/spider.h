#ifndef SPIDER_H
#define SPIDER_H

#include <QObject>
#include <QPixmap>

class Spider : public QObject {
  Q_OBJECT
public:
  explicit Spider(QPixmap, int, QObject *parent = nullptr);
  void setSpiderCoord(QPoint);
  void setSpiderDestination(QPoint);
  void setWebVec(QVector<QPoint>);
  void spiderMove();
  QPoint getSpiderCoord();
  QPoint getDestPoint();
  QPixmap getImg();
  QVector<QPoint> getWebVec();

private:
  QPixmap img;
  QPoint spiderCoord, destPoint;
  int spiderSize;
  QVector<QPoint> webVec;

signals:
};

#endif // SPIDER_H
