#include "PAnimalType.h"
#include "PEntityType.h"

bool PAnimalType::load(PEntityType &entity)
{
    entity.ztdPath = path;
    entity.type = PEntityType::Type::Animal;

    settings.beginGroup("Global");
    entity.id = settings.value("Type").toString();
    settings.endGroup();

    if (entity.id.isEmpty())
    {
        qDebug() << "Entity type id is empty for path:" << path;
    }

    settings.beginGroup("m/Icon");
    if (settings.contains("Type"))
    {
        QString aniPath = settings.value("Type").toString();
        if (!aniPath.isEmpty())
        {
            entity.iconAniPaths.insert(entity.id, aniPath);
        }
        else
        {
            qDebug() << "m/Icon .ani path is empty for:" << path;
        }
    }
    settings.endGroup();

    settings.beginGroup("f/Icon");
    if (settings.contains("Type"))
    {
        QString aniPath = settings.value("Type").toString();
        if (!aniPath.isEmpty())
        {
            entity.iconAniPaths.insert(entity.id, aniPath);
        }
        else
        {
            qDebug() << "f/Icon .ani path is empty for:" << path;
        }
    }
    settings.endGroup();
}