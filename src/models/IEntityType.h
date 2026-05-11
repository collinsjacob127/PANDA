#ifndef IENTITYTYPE_H
#define IENTITYTYPE_H

#include <QSettings>
#include <QString>

class PEntityType;

class IEntityType {
public:
    virtual bool load(PEntityType &entity) = 0;
    virtual bool isValid() const = 0;
};

#endif // IENTITYTYPE_H