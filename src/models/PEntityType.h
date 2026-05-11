#ifndef PENTITYTYPE_H
#define PENTITYTYPE_H

#include <QString>
#include <QStringList>
#include <QMap>
#include <memory>
#include "PIconData.h"
#include <QSettings>

class PEntityType
{
public:
    // Supported types
    enum Type
    {
        Animal,
        Scenery,
        Building,
        AnimalFood,
        TankFilter,
        Fence,
        TankWall,
        Path,
        Rubble,
        Unit,
        Guest,
        Staff,
        MaintenanceWorker,
        Helicopter,
        Guide,
        Keeper,
        Ambient,
        Unknown
    };

    enum MemberTypes
    {
        Entity,
        UnitMember,
        ZTUnit,
        Animals,
        SceneryMember,
        BuildingMember,
        StaffMember,
        AmbientMember,
        ZooFences,
        LowFence,
        FenceMember,
        HabitatFences,
        HighFence,
        Developer,
        ZooGate,
        Foliage,
        Shelters,
        Rocks,
        Trash,
        Poo,
        Structures,
        Toys,
        HabitatFoliage,
        ZooFoliage,
        Dinosaur,
        All,
        Aqua,
        ShowToys,
    };

    enum ClassType
    {
        KeeperClass,
        Maint,
        Tour,
        HelicopterClass,
        Scient,
        Trainer
    };

    QString id;
    Type type = Type::Unknown;
    QList<PIconData> icons;
    QString ztdPath;
    QMap<QString, QString> characteristics;
    QMap<QString, QString> iconAniPaths;

    PEntityType() = default;

    static QString determineViewFromPath(const QString &aniPath);

    void loadAniPaths(QStringList &iconPaths);
    void loadIconPath(QString &iconPath);
};

#endif // PENTITYTYPE_H
