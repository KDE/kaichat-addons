/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "wikipediatoolpluginjob.h"
#include <QDebug>
using namespace Qt::Literals::StringLiterals;
WikipediaToolPluginJob::WikipediaToolPluginJob(QObject *parent)
    : TextAutoGenerateText::TextAutoGenerateTextToolPluginJob{parent}
{
}

WikipediaToolPluginJob::~WikipediaToolPluginJob() = default;

void WikipediaToolPluginJob::start()
{
    qDebug() << " void WikipediaToolPluginJob::start() ";
    if (!canStart()) {
        qWarning() << " Impossible to start WikipediaToolPluginJob" << *this;
        deleteLater();
        return;
    }
    // qDebug() << " TextAutoGenerateText::TextAutoGenerateTextToolPlugin::TextToolPluginInfo " << info;
    Q_EMIT finished({});
    deleteLater();
}

#include "moc_wikipediatoolpluginjob.cpp"
