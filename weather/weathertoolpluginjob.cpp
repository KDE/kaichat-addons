/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "weathertoolpluginjob.h"
#include "weather_tool_debug.h"
#include "weathertoolpluginutils.h"
#include <KWeatherCore/LocationQuery>
#include <KWeatherCore/LocationQueryReply>
#include <KWeatherCore/WeatherForecastSource>
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
                if (arg == WeatherToolPluginUtils::convertPropertyNameEnumToString(WeatherToolPluginUtils::PropertyNameEnum::City)) {
                    city = value;
                    qCDebug(WEATHER_TOOL_LOG) << "City: " << city;
                } else if (arg == WeatherToolPluginUtils::convertPropertyNameEnumToString(WeatherToolPluginUtils::PropertyNameEnum::WeatherInfo)) {
                    qCDebug(WEATHER_TOOL_LOG) << "weather info: " << value;
                }
            }
        }
    }
    if (city.isEmpty()) {
        const TextAutoGenerateText::TextAutoGenerateTextToolPlugin::TextToolPluginInfo info{
            .content = i18n("No city found."),
            .messageUuid = mMessageUuid,
            .chatId = mChatId,
            .toolIdentifier = mToolIdentifier,
            .attachementInfoList = {},
        };
        Q_EMIT finished(info);
        deleteLater();
        return;
    }
    KWeatherCore::LocationQuery *locationSource = new KWeatherCore::LocationQuery(this);
    auto reply = locationSource->query(city);
    connect(reply, &KWeatherCore::LocationQueryReply::finished, this, [this, reply]() {
        reply->deleteLater();
        if (reply->error() != KWeatherCore::LocationQueryReply::NoError) {
            qCDebug(WEATHER_TOOL_LOG) << "can't find this place";
            deleteLater();
            return;
        }

        const auto result = reply->result();
        if (!result.empty()) {
            getWeatherFromCity(result.front());
        } else {
            const TextAutoGenerateText::TextAutoGenerateTextToolPlugin::TextToolPluginInfo info{
                .content = {},
                .messageUuid = mMessageUuid,
                .chatId = mChatId,
                .toolIdentifier = mToolIdentifier,
                .attachementInfoList = {},
            };
            Q_EMIT finished(info);
            deleteLater();
        }

        // for (auto location : reply->result()) {
        //     qDebug() << location.toponymName();
        // }
    });
}

void WeatherToolPluginJob::getWeatherFromCity(const KWeatherCore::LocationQueryResult &city)
{
    auto weatherForecastSource = new KWeatherCore::WeatherForecastSource(this);
    KWeatherCore::PendingWeatherForecast *reply = weatherForecastSource->requestData(city);
    connect(reply, &KWeatherCore::PendingWeatherForecast::finished, this, [this, reply]() {
        const auto result = reply->value();
        qDebug() << " result " << result.dailyWeatherForecast().front().weatherDescription();

        // TODO create correct i18n
        const TextAutoGenerateText::TextAutoGenerateTextToolPlugin::TextToolPluginInfo info{
            .content = result.dailyWeatherForecast().front().weatherDescription(),
            .messageUuid = mMessageUuid,
            .chatId = mChatId,
            .toolIdentifier = mToolIdentifier,
            .attachementInfoList = {},
        };

        Q_EMIT finished(info);
        deleteLater();
    });
}

#include "moc_weathertoolpluginjob.cpp"
