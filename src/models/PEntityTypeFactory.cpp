// EntityTypeLoaderFactory.cpp
#include "EntityTypeLoaderFactory.h"
#include "AnimalTypeLoader.h"
#include "SceneryTypeLoader.h"

std::unique_ptr<IEntityTypeLoader> EntityTypeLoaderFactory::resolve(const QString &path)
{
    if (path.contains("animal"))
    {
        return std::make_unique<AnimalTypeLoader>();
    }
    else if (path.contains("scenery"))
    {
        return std::make_unique<SceneryTypeLoader>();
    }
    return nullptr;
}