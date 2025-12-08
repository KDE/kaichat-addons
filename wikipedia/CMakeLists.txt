# SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>
# SPDX-License-Identifier: BSD-3-Clause

add_definitions(-DTRANSLATION_DOMAIN=\"kaichat-wikipedia-tool-plugin\")

kcoreaddons_add_plugin(textautogeneratetext_wikipediatoolplugin INSTALL_NAMESPACE autogeneratetext/toolplugins)

ecm_qt_declare_logging_category(textautogeneratetext_wikipediatoolplugin HEADER wikipedia_tool_debug.h IDENTIFIER WIKIPEDIA_TOOL_LOG CATEGORY_NAME org.kde.kaichat.addons.wikipediaplugin
    DESCRIPTION "KAIChat Addons Wikipedia Tool Plugin" EXPORT KAICHAT-ADDONS
)

target_sources(
    textautogeneratetext_wikipediatoolplugin
    PRIVATE
        wikipediatoolplugin.h
        wikipediatoolplugin.cpp
        wikipediatoolplugindialog.h
        wikipediatoolplugindialog.cpp
        wikipediatoolpluginwidget.h
        wikipediatoolpluginwidget.cpp
        wikipediatoolpluginjob.h
        wikipediatoolpluginjob.cpp
        wikipediatoolutils.h
        wikipediatoolutils.cpp
)
target_link_libraries(
    textautogeneratetext_wikipediatoolplugin
    KF6::TextAutoGenerateText
    KF6::KIOCore
)

## TODO add autotests
