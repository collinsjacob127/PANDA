#ifndef SCENERYTYPELOADER_H
#define SCENERYTYPELOADER_H

#include "IEntityTypeLoader.h"

class SceneryTypeLoader : public IEntityTypeLoader
{
public:
    void load(PEntityType &entity, QSettings &settings, const QString &path) override;
};

#endif