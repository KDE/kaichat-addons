/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "weathertoolpluginjob.h"
#include "weather_tool_debug.h"
#include <KWeatherCore/LocationQuery>
#include <KWeatherCore/LocationQueryReply>
#include <QDebug>
using namespace Qt::Literals::StringLiterals;
WeatherToolPluginJob::WeatherToolPluginJob(QObject *parent)
    : TextAutoGenerateText::TextAutoGenerateTextToolPluginJob{parent}
{
}

WeatherToolPluginJob::~WeatherToolPluginJob() = default;

void WeatherToolPluginJob::start()
{
    qCDebug(WEATHER_TOOL_LOG) << " void WeatherToolPluginJob::start() ";
    if (!canStart()) {
        qCWarning(WEATHER_TOOL_LOG) << " Impossible to start WeatherToolPluginJob" << *this;
        deleteLater();
        return;
    }
    Q_EMIT toolInProgress(i18n("Get Current Weather."));
    QString city;
    const QStringList lst = requiredArguments();
    for (const auto &arg : lst) {
        for (const auto &resultTool : std::as_const(mToolArguments)) {
            if (resultTool.keyTool == arg) {
                const QString value = resultTool.value;
                if (arg == "city"_L1) {
                    qDebug() << " CCCCCCCCCCCCC " << value;
                    city = value;
                }
            }
        }
    }
    if (city.isEmpty()) {
        Q_EMIT finished({});
        deleteLater();
        return;
    }
    KWeatherCore::LocationQuery *locationSource = new KWeatherCore::LocationQuery(this);
    auto reply = locationSource->query(city);
    qDebug() << " 1111111111111111111111111111111111";
    connect(reply, &KWeatherCore::LocationQueryReply::finished, this, [this, reply]() {
        reply->deleteLater();
        qDebug() << "END" << reply->error();
        if (reply->error() != KWeatherCore::LocationQueryReply::NoError) {
            qCDebug(WEATHER_TOOL_LOG) << "can't find this place";
            deleteLater();
            return;
        }
        for (auto location : reply->result()) {
            qDebug() << location.toponymName();
        }
        Q_EMIT finished({});
        deleteLater();
    });
    qDebug() << " CCCCCCCCCCCCC";
    /*

    const TextAutoGenerateText::TextAutoGenerateTextToolPlugin::TextToolPluginInfo info{
        .content = u"Temperature is 35°"_s,
        .messageUuid = mMessageUuid,
        .chatId = mChatId,
        .toolIdentifier = mToolIdentifier,
        .attachementInfoList = attachmentInfo,
    };
    */
    // qDebug() << " TextAutoGenerateText::TextAutoGenerateTextToolPlugin::TextToolPluginInfo " << info;
    // TODO Q_EMIT finished(info);
    // deleteLater();
}

#include "moc_weathertoolpluginjob.cpp"
