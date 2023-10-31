#ifndef WIDGET_H
#define WIDGET_H

#include <QDebug>
#include <QPainter>
#include <QRandomGenerator>
#include <QTimer>
#include <QWheelEvent>
#include <QWidget>

#include "spider.h"
#include "web.h"
class Widget : public QWidget {
  Q_OBJECT

public slots:
  void spiderMove();

public:
  Widget(QWidget *parent = nullptr);
  void drawWeb(QPoint, int, QPainter *);
  ~Widget();

private:
  QTimer *timer_;
  Spider *spider_;
  QPoint spiderCoord_, destPoint_;
  int spiderX_, spiderY_, spiderSize_, speed_, modifier_;
  QVector<QPoint> webVec;

protected:
  void paintEvent(QPaintEvent *event) override;
  void wheelEvent(QWheelEvent *event) override;
};
#endif // WIDGET_H
