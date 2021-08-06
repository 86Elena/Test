#pragma once

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>

enum class Status {
  Clear,
  Cloudy,
  PartlyCloudy,
  SmallRain,
  Rain,
  Shower,
  Thunderstorm
};

enum class Direction {
  North,
  East,
  South,
  West,
  NordEast,
  NrdWest,
  SouthEast,
  SouthWest
};

struct SimpleDayWeather {
  qreal temperature {0.0};
  Status status {Status::Clear};
  qreal wind {0.0};
  Direction windDirection {Direction::North};
};


class APIManager : public QObject{
  QNetworkAccessManager *m_manager {nullptr};
  QString m_city {"Moscow"};
  quint16 m_dayNum {0};
public:
  explicit APIManager(QObject *parent = nullptr);
  QString city() const;
  void setCity(const QString &city);
  quint16 dayNum() const;
  void setDayNum(const quint16 &dayNum);
  void currentWeatherData() {}
};

