/*
  SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/
#include "wikipediatoolplugindialog.h"
#include "wikipediatoolpluginwidget.h"
#include <QBoxLayout>
#include <QDialogButtonBox>
#include <TextAutoGenerateText/TextAutoGenerateTextToolPlugin>
using namespace Qt::Literals::StringLiterals;
WikipediaToolPluginDialog::WikipediaToolPluginDialog(TextAutoGenerateText::TextAutoGenerateTextToolPlugin *plugin, QWidget *parent)
    : QDialog(parent)
    , mWikipediaToolPluginWidget(new WikipediaToolPluginWidget(plugin, this))
{
    setWindowTitle(plugin ? plugin->displayName() : i18n("Configure Wikipedia Tool Plugin"));

    auto mainLayout = new QVBoxLayout(this);
    mainLayout->setObjectName(u"mainLayout"_s);

    mWikipediaToolPluginWidget->setObjectName(u"mWikipediaToolPluginWidget"_s);
    mainLayout->addWidget(mWikipediaToolPluginWidget);

    auto button = new QDialogButtonBox(QDialogButtonBox::Close, this);
    button->setObjectName(u"button"_s);
    mainLayout->addWidget(button);
    connect(button, &QDialogButtonBox::rejected, this, &WikipediaToolPluginDialog::reject);
}

WikipediaToolPluginDialog::~WikipediaToolPluginDialog() = default;

#include "moc_wikipediatoolplugindialog.cpp"
