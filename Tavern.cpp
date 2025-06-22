#include "Tavern.hpp"
#include <cmath>
#include <iomanip>

Tavern::Tavern() : MagicalBag<Creature*>() {
    totalLevel_ = 0;
    creatureCount_ = 0;
}

bool Tavern::enterTavern(Creature* newCreature) {
    if(add(newCreature)) {
        totalLevel_ += newCreature->getLevel();
        creatureCount_++;
        return true;
    }
    return false;
}

bool Tavern::exitTavern(Creature* newCreature) {
    if(remove(newCreature)) {
        totalLevel_ -= newCreature->getLevel();
        creatureCount_--;
        return true;
    }
    return false;
}

int Tavern::getLevelSum() const {
    return totalLevel_;
}

int Tavern::getCreatureCount() const {
    return creatureCount_;
}

int Tavern::getHostileCount() const {
    int count = 0;
    for(int i = 0; i < item_count_; ++i) {
        if(items_[i]->isHostile()) {
            count++;
        }
    }
    return count;
}

double Tavern::calculateHostilePercentage() const {
    if(creatureCount_ == 0) {
        return 0.0;
    }
    double percentage = static_cast<double>(getHostileCount()) / creatureCount_ * 100.0;
    percentage = std::round(percentage * 100.0) / 100.0;
    return percentage;
}

static std::string toUpperStr(const std::string& str) {
    std::string result;
    for(char c : str) {
        result += std::toupper(static_cast<unsigned char>(c));
    }
    return result;
}

int Tavern::tallyCategory(const std::string& category) const {
    std::string cat = toUpperStr(category);
    if(cat != "MAGICAL" && cat != "UNDEAD" && cat != "ANIMAL" && cat != "HUMANOID" && cat != "CATEGORY_UNKNOWN" && cat != "UNKNOWN")
        return 0;
    int count = 0;
    for(int i = 0; i < item_count_; ++i) {
        std::string c = items_[i]->getCategory();
        if((cat == "CATEGORY_UNKNOWN" || cat == "UNKNOWN") ? (c == "UNKNOWN") : (c == cat))
            count++;
    }
    return count;
}

int Tavern::tallySchool(const std::string& school) const {
    std::string sch = toUpperStr(school);
    if(sch != "FIRE" && sch != "ICE" && sch != "STORM" && sch != "LIFE" && sch != "MYTH" && sch != "DEATH" && sch != "SCHOOL_UNKNOWN" && sch != "UNKNOWN")
        return 0;
    int count = 0;
    for(int i = 0; i < item_count_; ++i) {
        std::string s = items_[i]->getSchool();
        if((sch == "SCHOOL_UNKNOWN" || sch == "UNKNOWN") ? (s == "UNKNOWN") : (s == sch))
            count++;
    }
    return count;
}

int Tavern::releaseCreaturesBelowLevel(int level) {
    if(level <= 0) return 0;
    int removed = 0;
    for(int i = 0; i < item_count_; ) {
        if(items_[i]->getLevel() < level) {
            Creature* ptr = items_[i];
            exitTavern(ptr);
            removed++;
            continue; // check same index again since elements shifted
        }
        ++i;
    }
    return removed;
}

int Tavern::releaseCreaturesOfCategory(const std::string& category) {
    std::string cat = toUpperStr(category);
    if(cat == "ALL") {
        int removed = creatureCount_;
        clear();
        totalLevel_ = 0;
        creatureCount_ = 0;
        return removed;
    }
    if(cat != "MAGICAL" && cat != "UNDEAD" && cat != "ANIMAL" && cat != "HUMANOID" && cat != "CATEGORY_UNKNOWN" && cat != "UNKNOWN")
        return 0;
    int removed = 0;
    for(int i = 0; i < item_count_; ) {
        std::string c = items_[i]->getCategory();
        if((cat == "CATEGORY_UNKNOWN" || cat == "UNKNOWN") ? (c == "UNKNOWN") : (c == cat)) {
            Creature* ptr = items_[i];
            exitTavern(ptr);
            removed++;
            continue;
        }
        ++i;
    }
    return removed;
}

int Tavern::releaseCreaturesOfSchool(const std::string& school) {
    std::string sch = toUpperStr(school);
    if(sch == "ALL") {
        int removed = creatureCount_;
        clear();
        totalLevel_ = 0;
        creatureCount_ = 0;
        return removed;
    }
    if(sch != "FIRE" && sch != "ICE" && sch != "STORM" && sch != "LIFE" && sch != "MYTH" && sch != "DEATH" && sch != "SCHOOL_UNKNOWN" && sch != "UNKNOWN")
        return 0;
    int removed = 0;
    for(int i = 0; i < item_count_; ) {
        std::string s = items_[i]->getSchool();
        if((sch == "SCHOOL_UNKNOWN" || sch == "UNKNOWN") ? (s == "UNKNOWN") : (s == sch)) {
            Creature* ptr = items_[i];
            exitTavern(ptr);
            removed++;
            continue;
        }
        ++i;
    }
    return removed;
}

void Tavern::tavernReport() const {
    std::cout << "CATEGORY COUNT:" << std::endl;
    std::cout << "MAGICAL: " << tallyCategory("MAGICAL") << std::endl;
    std::cout << "UNDEAD: " << tallyCategory("UNDEAD") << std::endl;
    std::cout << "ANIMAL: " << tallyCategory("ANIMAL") << std::endl;
    std::cout << "HUMANOID: " << tallyCategory("HUMANOID") << std::endl;
    std::cout << "CATEGORY_UNKNOWN: " << tallyCategory("CATEGORY_UNKNOWN") << std::endl;
    std::cout << "SCHOOL COUNT:" << std::endl;
    std::cout << "FIRE: " << tallySchool("FIRE") << std::endl;
    std::cout << "ICE: " << tallySchool("ICE") << std::endl;
    std::cout << "STORM: " << tallySchool("STORM") << std::endl;
    std::cout << "LIFE: " << tallySchool("LIFE") << std::endl;
    std::cout << "MYTH: " << tallySchool("MYTH") << std::endl;
    std::cout << "DEATH: " << tallySchool("DEATH") << std::endl;
    std::cout << "SCHOOL_UNKNOWN: " << tallySchool("SCHOOL_UNKNOWN") << std::endl;
    int avgLevel = (creatureCount_ > 0) ? totalLevel_ / creatureCount_ : 0;
    std::cout << "AVERAGE LEVEL: " << avgLevel << std::endl;
    std::cout << "HOSTILE: " << calculateHostilePercentage() << std::endl;
}

void Tavern::displayCreatures() const {
    for(int i = 0; i < item_count_; ++i) {
        items_[i]->display();
    }
}

