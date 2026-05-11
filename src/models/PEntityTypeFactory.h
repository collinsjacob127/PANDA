#ifndef ENTITYTYPELOADERFACTORY_H
#define ENTITYTYPELOADERFACTORY_H

#include <memory>
#include <QString>
#include "IEntityTypeLoader.h"

class EntityTypeLoaderFactory
{
public:
    static std::unique_ptr<IEntityTypeLoader> resolve(const QString &path);
};

#endif