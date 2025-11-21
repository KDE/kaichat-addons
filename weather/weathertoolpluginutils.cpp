/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/
#include "weathertoolpluginutils.h"
#include "weather_tool_debug.h"
using namespace Qt::Literals::StringLiterals;
QString WeatherToolPluginUtils::convertWeatherEnumToString(WeatherEnum type)
{
    switch (type) {
    case Full:
        return u"full"_s;
    case Temperature:
        return u"temperature"_s;
    case Unknown:
        break;
    }
    Q_UNREACHABLE();
    return {};
}

WeatherToolPluginUtils::WeatherEnum WeatherToolPluginUtils::convertStringToWeatherEnum(const QString &str)
{
    if (str == "full"_L1) {
        return WeatherToolPluginUtils::WeatherEnum::Full;
    } else if (str == "temperature"_L1) {
        return WeatherToolPluginUtils::WeatherEnum::Temperature;
    } else {
        qCWarning(WEATHER_TOOL_LOG) << "Invalid weather type:" << str;
        return WeatherToolPluginUtils::WeatherEnum::Unknown;
    }
    return WeatherToolPluginUtils::WeatherEnum::Unknown;
}

QString WeatherToolPluginUtils::convertPropertyNameEnumToString(WeatherToolPluginUtils::PropertyNameEnum type)
{
    switch (type) {
    case WeatherToolPluginUtils::PropertyNameEnum::City:
        return u"city"_s;
    case WeatherToolPluginUtils::PropertyNameEnum::WeatherInfo:
        return u"weatherinfo"_s;
    }
    Q_UNREACHABLE();
    return {};
}

WeatherToolPluginUtils::PropertyNameEnum WeatherToolPluginUtils::convertStringToPropertyNameEnum(const QString &str)
{
    if (str == "city"_L1) {
        return WeatherToolPluginUtils::PropertyNameEnum::City;
    } else if (str == "weatherinfo"_L1) {
        return WeatherToolPluginUtils::PropertyNameEnum::WeatherInfo;
    } else {
        qCWarning(WEATHER_TOOL_LOG) << "Invalid property name type:" << str;
        return WeatherToolPluginUtils::PropertyNameEnum::City;
    }
    return WeatherToolPluginUtils::PropertyNameEnum::City;
}
