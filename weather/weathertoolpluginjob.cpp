/*
  SPDX-FileCopyrightText: 2025 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "weathertoolpluginjob.h"
#include <QDebug>
using namespace Qt::Literals::StringLiterals;
WeatherToolPluginJob::WeatherToolPluginJob(QObject *parent)
    : TextAutoGenerateText::TextAutoGenerateTextToolPluginJob{parent}
{
}

WeatherToolPluginJob::~WeatherToolPluginJob() = default;

void WeatherToolPluginJob::start()
{
    qDebug() << " void WeatherToolPluginJob::start() ";
    if (!canStart()) {
        qWarning() << " Impossible to start WeatherToolPluginJob" << *this;
        deleteLater();
        return;
    }
    /*
    // TODO Need to implement job
    QList<TextAutoGenerateText::TextAutoGenerateAttachmentUtils::AttachmentElementInfo> attachmentInfo;
    {
        const TextAutoGenerateText::TextAutoGenerateAttachmentUtils::AttachmentElementInfo attInfo{
            .mimeType = "text/plain"_ba,
            .content = "foo bla kde"_ba,
            .name = u"test-file1"_s,
            .attachmentType = TextAutoGenerateText::TextAutoGenerateAttachment::AttachmentType::File,
        };
        attachmentInfo.append(attInfo);
    }
    const TextAutoGenerateText::TextAutoGenerateTextToolPlugin::TextToolPluginInfo info{
        .content = u"Temperature is 35°"_s,
        .messageUuid = mMessageUuid,
        .chatId = mChatId,
        .toolIdentifier = mToolIdentifier,
        .attachementInfoList = attachmentInfo,
    };
    */
    qDebug() << " TextAutoGenerateText::TextAutoGenerateTextToolPlugin::TextToolPluginInfo " << info;
    // TODO Q_EMIT finished(info);
    deleteLater();
}

#include "moc_weathertoolpluginjob.cpp"
