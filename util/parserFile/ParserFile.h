#ifndef PARSERFILE_H
#define PARSERFILE_H

#include <QStringList>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QFile>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QTextStream>

QStringList TextFileToList(QString path);
QList<QJsonObject> JsonFileToList(QString path);

QString* extractJsonString(const QJsonObject& obj, const QString& key);
QJsonObject* extractJsonObject(const QJsonObject& obj, const QString& key);
QStringList* extractJsonArray(const QJsonObject& obj, const QString& key);

#endif PARSERFILE_H