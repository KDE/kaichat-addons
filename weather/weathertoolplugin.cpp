/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "weathertoolplugin.h"
#include "weathertoolplugindialog.h"
#include "weathertoolpluginjob.h"
#include <KPluginFactory>
K_PLUGIN_CLASS_WITH_JSON(WeatherToolPlugin, "textautogeneratetext_weatherplugin.json")

using namespace Qt::Literals::StringLiterals;
WeatherToolPlugin::WeatherToolPlugin(QObject *parent, const QVariantList &)
    : TextAutoGenerateTextToolPlugin{parent}
{
    mToolNameId = "example_tool"_ba;
    {
        TextAutoGenerateText::TextAutoGenerateTextToolPluginProperty prop;
        prop.setDescription(kli18n("The name of the city"));
        prop.setName(u"city"_s);
        mProperties.append(prop);
    }
}

WeatherToolPlugin::~WeatherToolPlugin() = default;

QString WeatherToolPlugin::displayName() const
{
    // Don't translate it
    return u"Ask Weather Report"_s;
}

QString WeatherToolPlugin::description() const
{
    // Don't translate it
    return u"Use this tools, only on meteo. Get the current weather for a city"_s;
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
