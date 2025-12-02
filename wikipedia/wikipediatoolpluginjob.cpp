/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "wikipediatoolpluginjob.h"
#include "wikipedia_tool_debug.h"
#include "wikipediatoolutils.h"

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

    Q_EMIT toolInProgress(i18n("Get Wikipedia Page."));
    QString title;
    const QStringList lst = requiredArguments();
    for (const auto &arg : lst) {
        for (const auto &resultTool : std::as_const(mToolArguments)) {
            if (resultTool.keyTool == arg) {
                const QString value = resultTool.value;
                if (arg == WikipediaToolUtils::propertyTitle()) {
                    title = value;
                    qCDebug(WIKIPEDIA_TOOL_LOG) << "title: " << title;
                }
            }
        }
    }

    if (title.isEmpty()) {
        const TextAutoGenerateText::TextAutoGenerateTextToolPlugin::TextToolPluginInfo info{
            .content = i18n("No title found"),
            .messageUuid = mMessageUuid,
            .chatId = mChatId,
            .toolIdentifier = mToolIdentifier,
            .attachementInfoList = {},
        };
        Q_EMIT finished(info);
        deleteLater();
        return;
    }
    downloadWikipediaContent(title);
}

void WikipediaToolPluginJob::downloadWikipediaContent(const QString &title)
{
    // TODO
    // qDebug() << " TextAutoGenerateText::TextAutoGenerateTextToolPlugin::TextToolPluginInfo " << info;
    Q_EMIT finished({});
    deleteLater();
}

#include "moc_wikipediatoolpluginjob.cpp"
