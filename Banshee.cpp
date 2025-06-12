#include "Banshee.hpp"

/**
Default constructor.
Default-initializes all private members.
Default Banshee category: UNDEAD
Default Banshee school: DEATH
Default Banshee aura: RED
Default Banshee scream volume: 1
Booleans are default-initialized to False
*/
Banshee::Banshee() : Creature() {
    setCategory(UNDEAD);
    setSchool(DEATH);
    spectralAura_ = Aura::RED;
    screamVolume_ = 1;
    fearInducing_ = false;
}

/**
parameterized constructor.
@param: The name of the Banshee (a string)
@param: The category of the Banshee (a Category enum) with a default
value UNDEAD

@param: The school of the Banshee (a School enum) with a default value
DEATH
@param: The health of the Banshee (an integer) with default value 1 if not
provided, or if the value provided is 0 or negative
@param: The level of the Banshee (an integer) with default value 1 if not
provided, or if the value provided is 0 or negative
@param: The hostility of the Banshee (a boolean) with default value of
False
@param: The spectral aura of the Banshee (an Aura enum) with a default
value RED
@param: The decibel level of the Banshee (an integer) with default value 1
if not provided, or if the value provided is 0 or negative
@param: A flag indicating whether the Banshee can induce fear, with
default value False
*/
Banshee::Banshee(const std::string& name, Category category, School school, int health, int level, bool isHostile, Aura spectralAura, int screamVolume, bool fearInducing) {
    name_ = name;
    category_ = category;
    school_ = school;
    health_ = (health > 0) ? health : 1;
    level_ = level;
    isHostile_ = isHostile;
    spectralAura_ = spectralAura;
    screamVolume_ = screamVolume;
    fearInducing_ = fearInducing;
}
/**
@param: The aura of the Banshee (an enum)
@post: Sets the Banshee’s aura to the value of the parameter
*/
void Banshee::setAura(const Aura& spectralAura) {
    spectralAura_ = spectralAura;
}
/**
@return: The aura of the Banshee (in string form)
*/
std::string Banshee::getAura() const {
    //manually return a string for each case in Aura enum
    switch (spectralAura_) {
    case 0:
        return "RED";
        break;
    case 1:
        return "BLUE";
        break;
    case 2:
        return "GRAY";
        break;
    case 3:
        return "GREEN";
        break;
    }
}

/**
@param: An integer that represents the Banshee’s decibel level
@pre: Parameter must be greater than 0, if not, do nothing
@post: Sets the scream volume private member to the value of the parameter
@return: true if the scream volume was set, false otherwise

*/
bool Banshee::setScreamVolume(const int& screamVolume) {
    //parameter volume is greater than 0
    if(screamVolume > 0) {
        screamVolume_ = screamVolume;
        return true;
    }
    //otherwise do nothing (false otherwise)
    return false;
}
/**
@return: The scream volume of the Banshee
*/
int Banshee::getScreamVolume() const {
    return screamVolume_;
}
/**
@param: A boolean value of whether or not the Banshee is fear inducing
@post: Sets the fear inducing flag to the value of the parameter
*/
void Banshee::setFearInducing(const bool& fearInducing) {
    fearInducing_ = fearInducing;
}
/**
@return: true if the Banshee is fear inducing, false otherwise
Note: This is still an accessor function and must follow the same
conventions as all accessor functions even if it not called getFearInducing()
*/
bool Banshee::isFearInducing() const {
    return fearInducing_;
}
/**
@post: Displays Banshee data in the form:
“[NAME]\n
Category: [CATEGORY]\n
School: [SCHOOL]\n
Aura Color: [AURA]\n
Scream Level: [SCREAM LEVEL]\n
Health: [HEALTH]\n
Level: [LEVEL]\n
Fear Inducing: [TRUE/FALSE]\n
Hostile: [TRUE/FALSE]”
*/
void Banshee::display() const {
    std::cout << name_ << "\n Category: " << category_ << "\n School: " << school_ << "\n Aura Color: " << spectralAura_ << "\n Scream Level: " << screamVolume_ << "\n Health: " << health_ << "\n Level: " << level_ << "\n Fear Inducing: " << fearInducing_ << "\n Hostile: " << isHostile_;
}

/**
@post: Checks to see if two banshees are equal
@post: Checks names, aura color, and fear inducing qualities
*/
bool operator==(const Banshee& banshee1, const Banshee& banshee2) {
    if(banshee1.name_ == banshee2.name_ && banshee1.spectralAura_ == banshee2.spectralAura_ && banshee1.fearInducing_ == banshee2.fearInducing_)
        return true;
    return false;
}