#include "widget.h"

void Widget::drawWeb(QPoint center, int radius, QPainter *painter) {
  Web b(center, radius, painter);
}

void Widget::spiderMove() {
  spider_->spiderMove();
  update();
}

Widget::Widget(QWidget *parent) : QWidget(parent) {
  spiderSize_ = 40;
  speed_ = 50;
  modifier_ = 2;
  QPixmap spiderPix(":/img/img/spider.bmp");
  spider_ = new Spider(spiderPix, spiderSize_);

  timer_ = new QTimer(this);
  timer_->start();
  timer_->setInterval(speed_);

  spiderCoord_.setX(
      QRandomGenerator::global()->bounded(0, width() - spiderSize_));
  spiderCoord_.setY(
      QRandomGenerator::global()->bounded(0, height() - spiderSize_));
  spider_->setSpiderCoord(spiderCoord_);

  destPoint_.setX(QRandomGenerator::global()->bounded(0, width() - spiderSize_));
  destPoint_.setY(QRandomGenerator::global()->bounded(0, height() - spiderSize_));
  spider_->setSpiderDestination(destPoint_);

  connect(timer_, SIGNAL(timeout()), this, SLOT(spiderMove()));
}

void Widget::paintEvent(QPaintEvent *event) {
  setWindowTitle("Паучок");

  QPainter painter;

  spiderCoord_ = spider_->getSpiderCoord();
  destPoint_ = spider_->getDestPoint();

  int destPointRad = 5;
  painter.begin(this);
  painter.setBrush(QBrush(QColor(255, 0, 0)));
  painter.drawEllipse(QRect(destPoint_.x() - destPointRad,
                            destPoint_.y() - destPointRad, 2 * destPointRad,
                            2 * destPointRad));
  painter.end();

  painter.begin(this);
  int radius = 30;
  painter.drawPixmap(spiderCoord_.x(), spiderCoord_.y(), spiderSize_, spiderSize_,
                     spider_->getImg());

  if (spiderCoord_.x() == destPoint_.x() && spiderCoord_.y() == destPoint_.y()) {
    destPoint_.setX(destPoint_.x() + (spiderSize_ / 2));
    destPoint_.setY(destPoint_.y() + (spiderSize_ / 2));

    webVec = spider_->getWebVec();
    webVec.append(destPoint_);
    spider_->setWebVec(webVec);
    destPoint_.setX(
        QRandomGenerator::global()->bounded(0, width() - spiderSize_));
    destPoint_.setY(
        QRandomGenerator::global()->bounded(0, height() - spiderSize_));
    spider_->setSpiderDestination(destPoint_);
  }

  for (int i = 0; i < webVec.size(); i++) {
    drawWeb(webVec[i], radius, &painter);
  }

  painter.end();
}

void Widget::wheelEvent(QWheelEvent *event) {
  QPoint angle = event->angleDelta();  // для колёсика мышки
  QPoint pixels = event->pixelDelta(); // для тачпадов

  if (!angle.isNull() && speed_ >= 0) {
    if (angle.y() < 0) {
      speed_ += modifier_;
    } else {
      speed_ -= modifier_;
    }
  } else if (!pixels.isNull() && speed_ >= 0) {
    if (pixels.y() < 0) {
      speed_ += modifier_;
    } else {
      speed_ -= modifier_;
    }
  }

  if (speed_ < 0)
    speed_ = 1;
  timer_->setInterval(speed_);
  event->accept();
}

Widget::~Widget() {}
