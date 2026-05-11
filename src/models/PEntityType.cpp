#include "PEntityType.h"


// Determine direction of icon from ani path
QString PEntityType::determineViewFromPath(const QString& aniPath) {
    if (aniPath.contains("NE")){
        return "NE";
    } else if (aniPath.contains("NW")) {
        return "NW";
    } else if (aniPath.contains("SE")) {
        return "SE";
    } else if (aniPath.contains("SW")) {
        return "SW";
    } else {
        return "NA";
    }
}

// Finalize the icon paths using the .ani paths
void PEntityType::loadAniPaths(QStringList& iconPaths) {
//
}

// Load the icon paths from the ani paths
void PEntityType::loadIconPath(QString& iconPath) {
    // // get view i.e NE, NW, SE, SW
    // QString view = PEntityType::determineViewFromPath(iconPath);

    // // get the config from path
    // std::unique_ptr<QSettings> config = PConfigMgr::getKnownConfigInZtd(ztdpath, iconPath + ".ani");

    // config.get()->beginGroup("animation");
    // // check if id is set
    // if (this->id.isEmpty() || this->id == "") {
    //     this->id = config.get()->value("dir1").toString();
    // }

    // // get finalized graphics paths
    // QString dir0 = config.get()->value("dir0").toString();
    // QString dir1 = config.get()->value("dir1").toString();
    // QString dir2 = config.get()->value("dir2").toString();
    // QString animation = config.get()->value("animation").toString();
    // QString aniPath = dir0 + "/" + dir1 + "/" + dir2 + "/" + animation;

    // // check if ani path is empty
    // if (aniPath.isEmpty()) {
    //     qDebug() << "Ani path is empty for:" << iconPath;
    // } else {
    //     // add the ani path to the list of icon ani paths
    //     PIconData icon;
    //     icon.id = this->id;
    //     icon.resolvedPath = aniPath;
    //     icon.aniPath = aniPath;
    //     icon.isResolved = true;
    //     this->icons.push_back(icon);
    // }
}

