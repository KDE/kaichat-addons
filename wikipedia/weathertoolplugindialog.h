/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/
#pragma once
#include <QDialog>
namespace TextAutoGenerateText
{
class TextAutoGenerateTextToolPlugin;
}
class WeatherToolPluginWidget;
class WeatherToolPluginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit WeatherToolPluginDialog(TextAutoGenerateText::TextAutoGenerateTextToolPlugin *plugin, QWidget *parent = nullptr);
    ~WeatherToolPluginDialog() override;

private:
    WeatherToolPluginWidget *const mExampleTextToolPluginWidget;
};
