/*
  SPDX-FileCopyrightText: 2025-2026 Laurent Montel <montel@kde.org>

  SPDX-License-Identifier: GPL-2.0-or-later
*/
#include "wikipediatoolutils.h"
using namespace Qt::Literals::StringLiterals;
QByteArray WikipediaToolUtils::nameToolId()
{
    return "wikipedia_tool"_ba;
}

QString WikipediaToolUtils::propertyTitle()
{
    return u"title"_s;
}
