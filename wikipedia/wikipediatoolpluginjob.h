/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/
#pragma once
#include <QObject>
#include <TextAutoGenerateText/TextAutoGenerateTextToolPluginJob>
class WikipediaToolPluginJob : public TextAutoGenerateText::TextAutoGenerateTextToolPluginJob
{
    Q_OBJECT
public:
    explicit WikipediaToolPluginJob(QObject *parent = nullptr);
    ~WikipediaToolPluginJob() override;

    void start() override;

private:
    void downloadWikipediaContent(const QString &title);
};
