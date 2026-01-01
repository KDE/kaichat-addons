/*
  SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/

#include "wikipediatoolplugin.h"
#include "wikipediatoolplugindialog.h"
#include "wikipediatoolpluginjob.h"
#include "wikipediatoolutils.h"
#include <KPluginFactory>
K_PLUGIN_CLASS_WITH_JSON(WikipediaToolPlugin, "textautogeneratetext_wikipediatoolplugin.json")

using namespace Qt::Literals::StringLiterals;
WikipediaToolPlugin::WikipediaToolPlugin(QObject *parent, const QVariantList &)
    : TextAutoGenerateTextToolPlugin{parent}
{
    mToolNameId = WikipediaToolUtils::nameToolId();
    {
        TextAutoGenerateText::TextAutoGenerateTextToolPluginProperty prop;
        prop.setDescription(kli18n("The name of wikipedia title."));
        prop.setName(WikipediaToolUtils::propertyTitle());
        mProperties.append(prop);
    }
}

WikipediaToolPlugin::~WikipediaToolPlugin() = default;

QString WikipediaToolPlugin::displayName() const
{
    return i18n("Ask Wikipedia Page from Title");
}

QString WikipediaToolPlugin::description() const
{
    return i18n("Use this tools for getting wikipedia page from title.");
}

void WikipediaToolPlugin::showConfigureDialog(QWidget *parent)
{
    auto dlg = WikipediaToolPluginDialog(this, parent);
    dlg.exec();
}

TextAutoGenerateText::TextAutoGenerateTextToolPluginJob *WikipediaToolPlugin::callTool()
{
    return new WikipediaToolPluginJob(this);
}

int WikipediaToolPlugin::order() const
{
    return 30;
}

#include "moc_wikipediatoolplugin.cpp"
#include "wikipediatoolplugin.moc"
