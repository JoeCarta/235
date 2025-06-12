#include <cctype>
#include <string>
#include <iostream>

class Creature {
public: 
    enum Category {
        UNKNOWNcat,
        MAGICAL, 
        UNDEAD, 
        ANIMAL, 
        HUMANOID
    };
    enum School {
        UNKNOWNsch,
        FIRE, 
        ICE, 
        STORM, 
        LIFE, 
        MYTH, 
        DEATH
    };
    /**
    Default constructor.
    Default-initializes all private members.
    Default creature name: “NAMELESS”
    Default creature category: UNKNOWN
    Default creature school: UNKNOWN
    Default creature health: 1
    Default creature level: 1
    Booleans are default-initialized to False
    */
    Creature();
    /**
    Parameterized constructor.
    @param: The name of the creature (a string)
    @param: The category of the creature (a Category enum) with a default
    value UNKNOWN
    @param: The school of the creature (a School enum) with a default value
    UNKNOWN
    @param: The health of the creature (an integer) with default value 1 if not
    provided, or if the value provided is 0 or negative
    @param: The level of the creature (an integer) with default value 1 if not
    provided, or if the value provided is 0 or negative
    @param: The hostility of the creature (a boolean) with default value of False
    */
    Creature(const std::string& name, Category category = Category::UNKNOWNcat, School school = School::UNKNOWNsch, int health = 1, int level = 0, bool tame = false);
    /**
    @param: The name of the creature (a string)
    @post: Sets the Creature’s name to the value of the parameter in
    UPPERCASE (convert any lowercase character to uppercase)
    @post: Only alphabetical characters are allowed. If the input contains
    non-alphabetic characters, do nothing
    @return: true if the name was set, false otherwise
    */
    bool setName(const std::string& name);
    /**
    @return: The name of the Creature
    */
    std::string getName() const;
    /**
    @param: The category of the Creature (an enum)
    @post: Sets the Creature’s category to the value of the parameter
    */
    void setCategory(const Category& category);
    /**
    @return: The category of the Creature (in string form)
    */

    std::string getCategory() const;
    /**
    @param: The school of the Creature (an enum)
    @post: Sets the Creature’s school to the value of the parameter
    */
    void setSchool(const School& school);
    /**
    @return: The school of the Creature (in string form)
    */
    std::string getSchool() const;
    /**
    @param: An integer that represents the creature’s health
    @pre: Parameter must be greater than 0, if not, do nothing
    @post: Sets the health private member to the value of the parameter
    @return: true if the health was set, false otherwise
    */
    bool setHealth(const int& health);
    /**
    @return: The health of the Creature
    */
    int getHealth() const;
    /**
    @param: An integer that represents the creature’s level
    @pre: Parameter must be greater than 0, if not, do nothing
    @post: Sets the health private member to the value of the parameter
    @return: true if the level was set, false otherwise
    */
    bool setLevel(const int& level);

    /**
    @return: The level of the Creature
    */
    int getLevel() const;
    /**
    @param: A boolean value of whether or not the Creature is hostile
    @post: Sets the isHostile flag to the value of the parameter
    */
    void setHostility(const bool& isHostile);
    /**
    @return: true if the Creature is hostile, false otherwise
    Note: This is still an accessor function and must follow the same
    conventions as all accessor functions even if it not called getHostile()
    */
    bool isHostile() const;
    /**
    @post: Displays Creature data in the form:
    “[NAME]\n
    Category: [CATEGORY]\n
    School: [SCHOOL]\n
    Health: [HEALTH]\n
    Level: [LEVEL]\n
    Hostile: [TRUE/FALSE]”
    */
    void display() const;
protected:
    //The name of the creature (string)
    std::string name_;
    //The category of the creature (enum)
    //Category {MAGICAL, UNDEAD, ANIMAL, HUMANOID}
    Category category_;
    //The school that the creature belongs to (enum)
    //School {FIRE, ICE, STORM, LIFE, MYTH, DEATH}
    School school_;
    //The health of the creature (a non-zero, non-negative integer)
    int health_;
    //The level of the creature(a non-zero, non-negative integer))
    int level_;
    //Flag that indicates if the creature is hostile or not (boolean)
    bool isHostile_;
};