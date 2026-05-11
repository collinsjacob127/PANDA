#include "PSceneryType.h"
#include "PEntityType.h"

void PSceneryType::load(PEntityType &entity, QSettings &settings, const QString &path)
{
    entity.ztdPath = path;
    entity.type = PEntityType::Type::Scenery;

    settings.beginGroup("Global");
    entity.id = settings.value("Type").toString();
    settings.endGroup();

    if (entity.id.isEmpty())
    {
        qDebug() << "Entity type id is empty for path:" << path;
    }

    settings.beginGroup("Icon");
    QStringList iconPaths = settings.allKeys();
    entity.loadAniPaths(iconPaths);
    settings.endGroup();
}