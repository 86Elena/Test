#include "APIManager.h"
namespace name {
  const QString URL = "https://openweathermap.org/api";
}

APIManager::APIManager(QObject *parent) : QObject(parent) {
  m_manager = new QNetworkAccessManager(this);
}

QString APIManager::city() const
{
  return m_city;
}

void APIManager::setCity(const QString &city) {
  m_city = city;
}

quint16 APIManager::dayNum() const {
  return m_dayNum;
}

void APIManager::setDayNum(const quint16 &dayNum)
{
  m_dayNum = dayNum;
}


