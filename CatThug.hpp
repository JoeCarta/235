#ifndef CATTHUG_H
#define CATTHUG_H
#include <string>

#include "Creature.hpp"
#include <iostream>
#include <vector>

class CatThug : public Creature {
public:
    /**
    A struct representing weapons carried by the CatThug
    The name of the weapon (a string)
    The amount of damage the weapon does (an integer)
    A flag indicating whether the weapon is ranged or not
    */
    struct Weapon {
        std::string wName;
        int wDamage;
        bool wRanged;
    };

    enum Notoriety {ROOKIE, THIEF, ENFORCER, MOB_BOSS};

    /**
    Default constructor.
    Default-initializes all private members.
    Default Cat Thug category: HUMANOID
    Default Cat Thug school: MYTH
    Default Cat Thug weapons: {}
    Default Cat Thug notoriety: ROOKIE

    Booleans are default-initialized to False
    */
    CatThug();
    /**
    Parameterized constructor.
    @param: The name of the Cat Thug (a string)
    @param: The category of the Cat Thug (a Category enum) with a default
    value HUMANOID
    @param: The school of the Cat Thug (a School enum) with a default value
    MYTH
    @param: The health of the Cat Thug (an integer) with default value 1 if not
    provided, or if the value provided is 0 or negative
    @param: The level of the Cat Thug (an integer) with default value 1 if not
    provided, or if the value provided is 0 or negative
    @param: The hostility of the Cat Thug (a boolean) with default value of
    False
    @param: The weapons of the Cat Thug (a vector of Weapons) with a default
    value {}
    @param: The notoriety of the Cat Thug (a Notoriety enum) with default
    value ROOKIE
    @param: A flag indicating whether the Cat Thug is wanted, with default
    value False
    */
    CatThug(const std::string& name, Category category = Creature::HUMANOID, School school = Creature::MYTH, int health = 1, int level = 1, bool isHostile = false, std::vector<Weapon> weapons = {}, Notoriety notoriety = ROOKIE, bool isWanted);
    /**
    @param: The weapons of a Cat Thug
    @post: Sets the Cat Thug’s weapons to the value of the parameter
    */
    void setWeapons(const std::vector<Weapon>& weapons);
    /**

    @return: The weapons (a vector of Weapon structs)
    */
    std::vector<Weapon> getWeapons() const;
    /**
    @param: A weapon to be added to the vector
    @post: Adds the weapon to the vector only if the weapon does not exist in
    the vector
    @post: if weapon exists, update the damage of the weapon in the vector with
    the higher damage number
    @return: true if weapon was added, false otherwise
    Hint: bat and BAT are the same weapon
    */
    bool addWeapon(const Weapon& weapon);
    /**
    @param: A weapon to be removed from the vector
    @post: Removes the weapon from the vector only if the weapon exists
    @return: true if weapon was removed, false otherwise
    Hint: bat and BAT are the same weapon
    */
    bool removeWeapon(const Weapon& weapon);
    /**
    @param: The notoriety of the Cat Thug (an enum)
    @post: Sets the Cat Thug’s notoriety to the value of the parameter
    */
    void setNotoriety(const Notoriety& notoriety);
    /**
    @return: The notoriety of the Cat Thug (in string form)
    */
    std::string getNotoriety() const;

    /**
    @param: A boolean value of whether or not the Cat Thug is wanted by the
    authorities
    @post: Sets the is wanted flag to the value of the parameter
    */
    void setIsWanted(const bool& isWanted);
    /**
    @return: true if the Cat Thug is wanted, false otherwise
    Note: This is still an accessor function and must follow the same
    conventions as all accessor functions even if it not called getIsWanted()
    */
    bool isWanted() const;
    /**
    @post: Displays Cat Thug data in the form:
    “[NAME]\n
    Category: [CATEGORY]\n
    School: [SCHOOL]\n
    Weapons: [WEAPON NAME]: [DAMAGE], [RANGED/NOT RANGED]\n
    Notoriety: [NOTORIETY]\n
    Health: [HEALTH]\n
    Level: [LEVEL]\n
    Is Wanted: [TRUE/FALSE]\n
    Hostile: [TRUE/FALSE]”
    */
    void display() const;
    /**
    @post: Checks to see if two cat thugs are equal
    @post: Checks names, notoriety, and is wanted
    */
    friend bool operator==(const CatThug& catThug1, const CatThug& catThug2)
protected:
    //The weapons the Cat Thug carries
    std::vector<Weapon> weapons_;
    //The rank of the Cat Thug (enum)
    //Notoriety {ROOKIE, THIEF, ENFORCER, MOB_BOSS}
    Notoriety notorietyLevel_;
    //Flag that indicates if the Cat Thug is currently wanted by the authorities
    bool isWanted_;
};
#endif