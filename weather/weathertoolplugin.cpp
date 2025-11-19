/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "weathertoolplugin.h"
#include "weathertoolplugindialog.h"
#include "weathertoolpluginjob.h"
#include "weathertoolpluginutils.h"
#include <KPluginFactory>
K_PLUGIN_CLASS_WITH_JSON(WeatherToolPlugin, "textautogeneratetext_weatherplugin.json")

using namespace Qt::Literals::StringLiterals;
WeatherToolPlugin::WeatherToolPlugin(QObject *parent, const QVariantList &)
    : TextAutoGenerateTextToolPlugin{parent}
{
    mToolNameId = "weather_tool"_ba;
    {
        TextAutoGenerateText::TextAutoGenerateTextToolPluginProperty prop;
        prop.setDescription(kli18n("The name of the city"));
        prop.setName(u"city"_s);
        prop.setTypeElements({
            WeatherToolPluginUtils::convertWeatherEnumToString(WeatherToolPluginUtils::Full),
            WeatherToolPluginUtils::convertWeatherEnumToString(WeatherToolPluginUtils::Temperature),
        });

        mProperties.append(prop);
    }
}

WeatherToolPlugin::~WeatherToolPlugin() = default;

QString WeatherToolPlugin::displayName() const
{
    return i18n("Ask Weather Report");
}

QString WeatherToolPlugin::description() const
{
    return i18n("Use this tools, only on meteo. Get the current weather for a city");
}

void WeatherToolPlugin::showConfigureDialog(QWidget *parent)
{
    auto dlg = WeatherToolPluginDialog(this, parent);
    dlg.exec();
}

TextAutoGenerateText::TextAutoGenerateTextToolPluginJob *WeatherToolPlugin::callTool()
{
    return new WeatherToolPluginJob(this);
}

int WeatherToolPlugin::order() const
{
    return 30;
}

#include "moc_weathertoolplugin.cpp"
#include "weathertoolplugin.moc"
