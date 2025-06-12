/*
Creature.cpp

Joseph Cartafalsa

This is the source file for Creature class,
implements the getter and setter functions given for each creature parameter individually

5/29/2015
*/
#include <cctype>
#include <string>
#include <iostream>
#include "Creature.hpp"

    Creature::Creature() {
        name_ = "NAMELESS";
        category_ = Category::UNKNOWNcat;
        school_ = School::UNKNOWNsch;
        health_ = 1;
        level_ = 1;
        isHostile_ = false;
    }

    //parameterized constructor sets every creature value, default values are in Creature.hpp but arent repeated here
    Creature::Creature(const std::string& name, Category category, School school, int health, int level, bool tame) {
        name_ = "";
        //redoing the loop from setName, i tried just calling setName(name); but it didnt seem to work
        for (char c : name) {
            name_ += std::toupper(c);
        }
        category_ = category;
        school_ = school;
        health_ = health;
        level_ = level;
        isHostile_ = tame;
    }
    
    /*sets the Creature’s name to the value of the parameter in
    UPPERCASE (convert any lowercase character to uppercase)
    @post: Only alphabetical characters are allowed. If the input contains
    non-alphabetic characters, do nothing
    @return: true if the name was set, false otherwise
    to replace name_ it is set to zero and and incremented by each character in uppercase */
    bool Creature::setName(const std::string& name) {
        for (char c : name) {
            if (!std::isalpha(c)) {
                return false;
            }
        }
        name_ = "";
        for (char c : name) {
            name_ += std::toupper(c);
        }
        return true;
    }

    std::string Creature::getName() const {
        return name_;
    }

    void Creature::setCategory(const Category& category) {
        category_ = category;
    }

    //i could have used a switch statement
    //sets string in uppercase msnually based on enum value
    //does not use a parameter
    std::string Creature::getCategory() const {
        if(category_ == 1)
            return "MAGICAL";
        else if (category_ == 2)
            return "UNDEAD";
        else if (category_ == 3)
            return "ANIMAL";
        else if (category_ == 4)
            return "HUMANOID";
        else
            return "UNKNOWN";
    }

    void Creature::setSchool(const School& school) {
        school_ = school;
    }

    //i could have also used a switch statement
    std::string Creature::getSchool() const {
        if(school_ == 1)
            return "FIRE";
        else if (school_ == 2)
            return "ICE";
        else if (school_ == 3) 
            return "STORM";
        else if (school_ == 4) 
            return "LIFE";
        else if (school_ == 5)
            return "MYTH";
        else if (school_ == 6)
            return "DEATH";
        else
            return "UNKNOWN";
    }

    //makes sure health is positive
    bool Creature::setHealth(const int& health) {
        if(health > 0) {
            health_ = health;
            return true;
        }
        return false;
    }

    int Creature::getHealth() const {
        return health_;
    }

    //makes sure level is posiive
    bool Creature::setLevel(const int& level) {
        if(level > 0) {
            level_ = level;
            return true;
        }
        return false;
    }

    int Creature::getLevel() const {
        return level_;
    }
    
    //isHostile_ is the member variable, assigned from isHostile which passes through the parameter
    void Creature::setHostility(const bool& isHostile) {
        isHostile_ = isHostile;
    }

    //true if the Creature is hostile, false otherwise
    //Note: This is still an accessor function and must follow the same
    //conventions as all accessor functions even if it not called getHostile()
    bool Creature::isHostile() const {
        //functionally same as return isHostile_;
        if(isHostile_ == true)
            return true;
        else
            return false;
    }

    void Creature::display() const {
        //ternary if statement to output "TRUE" or "FALSE" instead of 1 or 0
        std::cout << name_ << std::endl << "Category: " << getCategory() << std::endl << "School: " << getSchool() << std::endl << "Health: " << health_ << std::endl << "Level: " << level_ << std::endl << "Hostile: " << (this->isHostile() == 1 ? "TRUE" : "FALSE") << std::endl;
    }