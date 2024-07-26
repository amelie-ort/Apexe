#include "ParserFile.h"

QStringList TextFileToList(QString path) {

    QStringList listOfFileLines;
    QFile file(path);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            listOfFileLines << line;
        }
        file.close();
    }
    return listOfFileLines;
}



QList<QJsonObject> JsonFileToList(QString path) {
    QList<QJsonObject> listOfObjects;
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.errorString();
        return listOfObjects; // Return empty list if file cannot be opened
    }

    QTextStream in(&file);
    QString jsonString = in.readAll();
    file.close();

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(jsonString.toUtf8(), &error);
    if (error.error != QJsonParseError::NoError) {
        qDebug() << "Error parsing JSON:" << error.errorString();
        return listOfObjects; // Return empty list if JSON parsing fails
    }

    if (!doc.isArray()) {
        qDebug() << "JSON document is not an array";
        return listOfObjects; // Return empty list if JSON document is not an array
    }

    QJsonArray jsonArray = doc.array();
    foreach(const QJsonValue & value, jsonArray) {
        if (value.isObject()) {
            QJsonObject obj = value.toObject();
            listOfObjects.append(obj);
        }
    }

    return listOfObjects;
}

QString* extractJsonString(const QJsonObject& obj, const QString& key) {
    QString* string = nullptr;
    if (obj.contains(key) && obj[key].isString()) {
        QString jsonString = obj[key].toString();
        string = new QString(jsonString);
    }
    else {
        string = new QString(); // Chaîne vide par defaut
    }
    return string;
}


QJsonObject* extractJsonObject(const QJsonObject& obj, const QString& key) {
    QJsonObject* jsonObject = nullptr;
    if (obj.contains(key) && obj[key].isObject()) {
        QJsonObject extractedObject = obj[key].toObject();
        jsonObject = new QJsonObject(extractedObject);
    }
    else {
        jsonObject = new QJsonObject(); // Objet JSON vide par defaut
    }
    return jsonObject;
}


QStringList* extractJsonArray(const QJsonObject& obj, const QString& key) {
    QStringList* list = nullptr;
    if (obj.contains(key) && obj[key].isArray()) {
        QJsonArray jsonArray = obj[key].toArray();
        list = new QStringList();
        for (const QJsonValue& val : jsonArray) {
            if (val.isString()) {
                list->append(val.toString());
            }
        }
    }
    else {
        list = new QStringList(); // Liste vide par defaut
    }
    return list;
}
