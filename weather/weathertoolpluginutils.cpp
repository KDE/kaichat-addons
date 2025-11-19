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
