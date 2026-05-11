#ifndef PANIMALTYPE_H
#define PANIMALTYPE_H

#include "IEntityType.h"

class PAnimalType : public IEntityType {
public:
    PAnimalType() = default;
    bool load(PEntityType &entity) override;
    bool isValid() const override;
};

#endif // PANIMALTYPE_H