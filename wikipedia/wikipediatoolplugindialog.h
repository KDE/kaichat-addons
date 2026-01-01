/*
  SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/
#pragma once
#include <QDialog>
namespace TextAutoGenerateText
{
class TextAutoGenerateTextToolPlugin;
}
class WikipediaToolPluginWidget;
class WikipediaToolPluginDialog : public QDialog
{
    Q_OBJECT
public:
    explicit WikipediaToolPluginDialog(TextAutoGenerateText::TextAutoGenerateTextToolPlugin *plugin, QWidget *parent = nullptr);
    ~WikipediaToolPluginDialog() override;

private:
    WikipediaToolPluginWidget *const mWikipediaToolPluginWidget;
};
