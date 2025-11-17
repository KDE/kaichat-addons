# SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_definitions(-DTRANSLATION_DOMAIN=\"kaichat-wikipedia-tool-plugin\")

kcoreaddons_add_plugin(textautogeneratetext_wikipediatoolplugin INSTALL_NAMESPACE autogeneratetext/toolplugins)

target_sources(
    textautogeneratetext_wikipediatoolplugin
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
    textautogeneratetext_wikipediatoolplugin
    KF6::TextAutoGenerateText
)
