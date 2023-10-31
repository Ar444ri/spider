#ifndef WEB_H
#define WEB_H

#include <QMouseEvent>
#include <QObject>
#include <QPainter>
class Web : public QObject {
  Q_OBJECT
public:
  explicit Web(QPoint, int, QPainter *, QObject *parent = nullptr);

signals:
private:
  QPainter *painter_;
  QPoint center_;
  int radius_;
  QVector<QPoint> webVec_
  ;
};

#endif // WEB_H
