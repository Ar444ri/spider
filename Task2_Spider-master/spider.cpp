#include "spider.h"

Spider::Spider(QPixmap img, int spiderSize, QObject *parent) : QObject{parent} {
  this->img = img;
  this->spiderSize = spiderSize;
}

void Spider::setSpiderCoord(QPoint spiderCoord) {
  this->spiderCoord = spiderCoord;
}

void Spider::setSpiderDestination(QPoint destinationPoint) {
    this->destPoint = destinationPoint;
}

void Spider::setWebVec(QVector<QPoint> newWebVec)
{
    webVec = newWebVec;
}

void Spider::spiderMove() {
  int spiderX = spiderCoord.x();
  int spiderY = spiderCoord.y();

  if (spiderX > destPoint.x()) {
    spiderX -= 1;

  } else if (spiderX == destPoint.x()) {
    if (spiderY > destPoint.y()) {
      spiderY -= 1;

    } else {
      spiderY += 1;
    }

  } else {
    spiderX += 1;
  }

  spiderCoord.setX(spiderX);
  spiderCoord.setY(spiderY);
}

QPoint Spider::getSpiderCoord() { return spiderCoord; }
QPoint Spider::getDestPoint() { return destPoint; }
QPixmap Spider::getImg() { return img; }

QVector<QPoint> Spider::getWebVec()
{
    return webVec;
}
