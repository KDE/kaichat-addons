# SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_definitions(-DTRANSLATION_DOMAIN=\"kaichat-weather-tool-plugin\")

kcoreaddons_add_plugin(textautogeneratetext_weathertoolplugin INSTALL_NAMESPACE autogeneratetext/toolplugins)

ecm_qt_declare_logging_category(textautogeneratetext_weathertoolplugin HEADER weather_tool_debug.h IDENTIFIER WEATHER_TOOL_LOG CATEGORY_NAME org.kde.kaichat.addons.weatherplugin
    DESCRIPTION "KAIChat Addons Weather Tool Plugin" EXPORT KAICHAT-ADDONS
)

target_sources(
    textautogeneratetext_weathertoolplugin
    PRIVATE
        weathertoolplugin.h
        weathertoolplugin.cpp
        weathertoolplugindialog.h
        weathertoolplugindialog.cpp
        weathertoolpluginwidget.h
        weathertoolpluginwidget.cpp
        weathertoolpluginjob.h
        weathertoolpluginjob.cpp
)
target_link_libraries(
    textautogeneratetext_weathertoolplugin
    KF6::TextAutoGenerateText
    KWeatherCore
)
