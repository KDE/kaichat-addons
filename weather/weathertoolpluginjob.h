/*
  SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/
#pragma once
#include "weathertoolpluginutils.h"
#include <KWeatherCore/LocationQueryResult>
#include <QObject>
#include <TextAutoGenerateText/TextAutoGenerateTextToolPluginJob>
class WeatherToolPluginJob : public TextAutoGenerateText::TextAutoGenerateTextToolPluginJob
{
    Q_OBJECT
public:
    explicit WeatherToolPluginJob(QObject *parent = nullptr);
    ~WeatherToolPluginJob() override;

    void start() override;

private:
    void getWeatherFromCity(const KWeatherCore::LocationQueryResult &city, WeatherToolPluginUtils::WeatherEnum weatherInfo);
};
