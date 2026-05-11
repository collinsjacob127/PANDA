#pragma once

#include <QString>
#include <QSharedPointer>

#include "PFileData.h"

class ModTypeStrategy {
public:
    virtual ~ModTypeStrategy() = default;

    virtual QString determineCategory(
        const QSharedPointer<PFileData>& fileData) const = 0;
};
