/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/
#pragma once
#include <QString>

namespace WeatherToolPluginUtils
{
enum WeatherEnum : int8_t {
    Unknown = 0,
    Full,
    Temperature,
    Humidity,
    // TODO add more
};

enum PropertyNameEnum : int8_t {
    City = 0,
    WeatherInfo,
};

[[nodiscard]] QString convertWeatherEnumToString(WeatherToolPluginUtils::WeatherEnum type);
[[nodiscard]] WeatherToolPluginUtils::WeatherEnum convertStringToWeatherEnum(const QString &str);

[[nodiscard]] QString convertPropertyNameEnumToString(WeatherToolPluginUtils::PropertyNameEnum type);
[[nodiscard]] WeatherToolPluginUtils::PropertyNameEnum convertStringToPropertyNameEnum(const QString &str);
};
