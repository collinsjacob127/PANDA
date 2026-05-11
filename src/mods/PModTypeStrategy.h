#pragma once

#include <QString>
#include <QSharedPointer>
#include <unordered_map>
#include <functional>

#include "PFileData.h"

class ModTypeStrategy {
public:
    virtual ~ModTypeStrategy() = default;

    virtual QString determineCategory(
        const QSharedPointer<PFileData>& fileData) const = 0;
};

class BuildingStrategy : public ModTypeStrategy {
public:
    QString determineCategory(
        const QSharedPointer<PFileData>&) const override
    {
        return "Building";
    }
};

class SceneryStrategy : public ModTypeStrategy {
public:
    QString determineCategory(
        const QSharedPointer<PFileData>&) const override
    {
        return "Scenery";
    }
};

class AnimalStrategy : public ModTypeStrategy {
public:
    QString determineCategory(
        const QSharedPointer<PFileData>&) const override
    {
        return "Animals";
    }
};

class AIStrategy : public ModTypeStrategy {
public:
    QString determineCategory(
        const QSharedPointer<PFileData>& fileData) const override
    {
        QStringList pathParts = fileData->path.split("/");

        if (pathParts.isEmpty()) {
            return "Unknown";
        }

        QString category = pathParts[0];

        // Proper-case category
        return category.left(1).toUpper()
             + category.mid(1).toLower();
    }
};

class UnknownStrategy : public ModTypeStrategy {
public:
    QString determineCategory(
        const QSharedPointer<PFileData>&) const override
    {
        return "Unknown";
    }
};

class ModTypeStrategyFactory {
public:
    using Creator = std::function<std::unique_ptr<ModTypeStrategy>()>;

    static std::unique_ptr<ModTypeStrategy> create(const QString& ext)
    {
        static const std::unordered_map<QString, Creator> registry = {
            { "ucb", [] { return std::make_unique<BuildingStrategy>(); } },
            { "ucs", [] { return std::make_unique<SceneryStrategy>(); } },
            { "uca", [] { return std::make_unique<AnimalStrategy>(); } },
            { "ai",  [] { return std::make_unique<AIStrategy>(); } }
        };

        auto it = registry.find(ext);

        if (it != registry.end()) {
            return it->second();
        }

        return std::make_unique<UnknownStrategy>();
    }
};
