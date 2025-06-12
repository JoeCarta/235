#ifndef FIRECAT_H
#define FIRECAT_H
#include <string>

#include "Creature.hpp"
#include <iostream>
class Firecat : public Creature {
public:
    //The flame color of the Firecat (enum)
    //FlameColor {RED, ORANGE, BLUE, WHITE}
    enum FlameColor {
        RED,
        ORANGE,
        BLUE,
        WHITE
    };
    /**
    Default constructor.
    Default-initializes all private members.
    Default Firecat category: ANIMAL
    Default Firecat school: FIRE
    Default Firecat flame color: ORANGE
    Default Firecat flame intensity: 1
    Booleans are default-initialized to False
    */
    Firecat();
    /**
    Parameterized constructor.
    @param: The name of the Firecat (a string)
    @param: The category of the Firecat (a Category enum) with a default value ANIMAL
    @param: The school of the Firecat (a School enum) with a default value FIRE
    @param: The health of the Firecat (an integer) with default value 1 if not
    provided, or if the value provided is 0 or negative
    @param: The level of the Firecat (an integer) with default value 1 if not
    provided, or if the value provided is 0 or negative
    @param: The hostility of the Firecat (a boolean) with default value of False
    @param: The flame color of the Firecat (an FlameColor enum) with a
    default value ORANGE
    @param: The flame intensity of the Firecat (an integer) with default value 1
    if not provided, or if the value provided is 0 or negative
    @param: A flag indicating whether the Firecat is an arsonist, with default
    value False
    */
    Firecat(const std::string& name, Category category = Category::ANIMAL, School school = School::FIRE, int health = 1, int level = 1, bool isHostile = false, FlameColor flameColor_ = FlameColor::ORANGE, int flameIntensity = 1, bool arsonist = false);
    /**
    @param: The flame color of the Firecat (an enum)
    @post: Sets the Firecat’s flame color to the value of the parameter
    */
    void setFlameColor(const FlameColor& flameColor);
    /**
    @return: The flame color of the Firecat (in string form)
    */
    std::string getFlameColor() const;

    /**
    @param: An integer that represents the Firecat’s flame intensity
    @pre: Parameter must be greater than 0, if not, do nothing
    @post: Sets the flame intensity private member to the value of the parameter
    @return: true if the flame intensity was set, false otherwise
    */

    bool setFlameIntensity(const int& flameIntensity);
    /**
    @return: The flame intensity of the Firecat
    */
    int getFlameIntensity() const;
    /**
    @param: A boolean value of whether or not the Firecat is an arsonist
    @post: Sets the arsonist flag to the value of the parameter
    */
    void setArsonist(const bool& arsonist);
    /**
    @return: true if the Firecat is an arsonist, false otherwise
    Note: This is still an accessor function and must follow the same
    conventions as all accessor functions even if it not called getArsonist()
    */
    bool isArsonist() const;
    /**
    @post: Displays Firecat data in the form:
    “[NAME]\n
    Category: [CATEGORY]\n
    School: [SCHOOL]\n
    Flame Color: [FLAME COLOR]\n
    Flame Intensity: [FLAME INTENSITY]\n
    Health: [HEALTH]\n
    Level: [LEVEL]\n
    Arsonist: [TRUE/FALSE]\n
    Hostile: [TRUE/FALSE]”
    */
    void display() const;

    /**
    @post: Checks to see if two firecats are equal
    @post: Checks names, flame color, and if they are both arsonists
    */
    friend bool operator==(const Firecat& firecat1, const Firecat& firecat2);

protected:
    //The flame color of the Firecat (enum)
    FlameColor flameColor_;
    //The flame intensity level of the Firecat’s flames
    int flameIntensity_;
    //Flag that indicates if the Firecat is an arsonist
    bool arsonist_;
};
#endif