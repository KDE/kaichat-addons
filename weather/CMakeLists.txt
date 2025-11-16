# SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

kcoreaddons_add_plugin(textautogeneratetext_weathertoolplugin INSTALL_NAMESPACE autogeneratetext/toolplugins)

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
)
