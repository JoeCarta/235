/*
test.cpp

Joseph Cartafalsa

Main source file, tests the output of the Creature methods and derived Creatures
Unchanged from the code given in the assignment

5/29/2015
*/
#include "Creature.hpp"
#include "Banshee.hpp"
#include "Firecat.hpp"
#include "CatThug.hpp"
#include "MagicalBag.hpp"

int main() {
    //Testing Default Banshee
    Banshee defaultBanshee;
    defaultBanshee.display();
    std::cout << std::endl;

    //Testing Parameterized Banshees
    Banshee parameterizedBanshee("Meheraan", Creature::Category::UNDEAD, Creature::School::DEATH, 10, 2, true, Banshee::Aura::GREEN, 50, false);
    parameterizedBanshee.display();
    std::cout << std::endl;

    Banshee parameterizedDefaultBansheee("Roy");
    parameterizedDefaultBansheee.display();
    std::cout << std::endl;

    //Testing setters and getters
    std::cout << "Parameterized Banshee's Aura: " << parameterizedBanshee.getAura() << std::endl;
    parameterizedBanshee.setAura(Banshee::Aura::BLUE);
    std::cout << "New Aura: " << parameterizedBanshee.getAura() << std::endl << std::endl;

    if (parameterizedBanshee.setScreamVolume(0) == true) {
        std::cout << "Your banshee scream volume is set incorrectly" << std::endl;
    } else {
        std::cout << "Your banshee scream volume is set correctly" << std::endl;
    }

    std::cout << "Parameterized Banshee's Scream Volume: " << parameterizedBanshee.getScreamVolume() << std::endl << std::endl;

    std::cout << "Parameterized Banshee's Fear Inducing Qualities: " << parameterizedBanshee.isFearInducing() << std::endl;
    parameterizedBanshee.setFearInducing(true);
    std::cout << "New Fear Inducing Quality: " << parameterizedBanshee.isFearInducing() << std::endl << std::endl;

    //Testing Default Firecat
    Firecat defaultFirecat;
    defaultFirecat.display();
    std::cout << std::endl;

    //Testing Parameterized Firecats
    Firecat parameterizedFirecat("Laddoo", Creature::Category::ANIMAL, Creature::School::FIRE, 100, 50, false, Firecat::FlameColor::ORANGE, 100000, true);
    parameterizedFirecat.display();
    std::cout << std::endl;

    Firecat parameterizedDefaultFirecat("Michelle");
    parameterizedDefaultFirecat.display();
    std::cout << std::endl;

    //Testing setters and getters
    std::cout << "Parameterized Firecat's Flame Color: " << parameterizedFirecat.getFlameColor() << std::endl;
    parameterizedFirecat.setFlameColor(Firecat::FlameColor::BLUE);
    std::cout << "New Flame Color: " << parameterizedFirecat.getFlameColor() << std::endl << std::endl;

    if (parameterizedDefaultFirecat.setFlameIntensity(0) == true) {
        std::cout << "Your firecat flame intensity is set incorrectly" << std::endl;
    } else {
        std::cout << "Your firecat flame intensity is set correctly" << std::endl;
    }

    std::cout << "Parameterized Firecat's Flame Intensity: " << parameterizedFirecat.getFlameIntensity() << std::endl << std::endl;

    std::cout << "Parameterized Firecat's Arsonist Qualities: " << parameterizedFirecat.isArsonist() << std::endl;
    parameterizedBanshee.setFearInducing(false);
    std::cout << "New Arsonist Qualities: " << parameterizedFirecat.isArsonist() << std::endl << std::endl;

    //Testing Default CatThug
    CatThug defaultCatThug;
    defaultCatThug.display();
    std::cout << std::endl;

    //Testing Parameterized CatThugs
    CatThug::Weapon weapon1{"Syntax Whisk", 100, true};
    CatThug::Weapon weapon2{"The Inkblade", 500, false};
    CatThug::Weapon weapon3{"Bitcrust Shield", 10, false};
    CatThug parameterizedCatThug("Ank", Creature::Category::HUMANOID, Creature::School::LIFE, 1000000, 100, false, {weapon1, weapon2, weapon3}, CatThug::Notoriety::ENFORCER, false);
    parameterizedCatThug.display();
    std::cout << std::endl;

    CatThug parameterizedDefaultCatThug("Hanz");
    parameterizedDefaultCatThug.display();
    std::cout << std::endl;

    //Testing setters and getters
    std::cout << "Parameterized CatThug's Notoriety: " << parameterizedCatThug.getNotoriety() << std::endl;
    parameterizedCatThug.setNotoriety(CatThug::Notoriety::MOB_BOSS);
    std::cout << "New Notoriety: " << parameterizedCatThug.getNotoriety() << std::endl << std::endl;

    std::cout << "Parameterized CatThug's Wanted Status: " << parameterizedCatThug.isWanted() << std::endl;
    parameterizedCatThug.setIsWanted(true);
    std::cout << "New  Wanted Status: " << parameterizedCatThug.isWanted() << std::endl << std::endl;

    CatThug::Weapon newWeapon{"Spellstorm Launcher", 1000, true};
    if (parameterizedCatThug.addWeapon(newWeapon) == true) {
        std::cout << "New weapon added correctly" << std::endl << std::endl;
    } else {
        std::cout << "Weapon added incorrectly" << std::endl << std::endl;
    }

    std::vector<CatThug::Weapon> weaponVector = parameterizedCatThug.getWeapons();
    for (int i = 0; i < weaponVector.size(); i++) {
        std::cout << weaponVector[i].weaponName_ << std::endl;
    }
    std::cout << std::endl;

    if (parameterizedCatThug.removeWeapon(weapon3) == true) {
        std::cout << "Bitcrust Shield removed correctly" << std::endl << std::endl;
    } else {
        std::cout << "Bitcrust Shield not removed" << std::endl << std::endl;
    }

    std::vector<CatThug::Weapon> weaponVectorRemoval = parameterizedCatThug.getWeapons();
    for (int i = 0; i < weaponVectorRemoval.size(); i++) {
        std::cout << weaponVectorRemoval[i].weaponName_ << std::endl;
    }
    std::cout << std::endl;

    //Testing Banshee Bag
    MagicalBag<Banshee> bansheeBag;
    std::cout << "Current size of bag: " << bansheeBag.getCurrentSize() << std::endl << std::endl;

    Banshee mannyBanshee("Manny");
    Banshee brendanBanshee("Brendan");

    if (bansheeBag.add(mannyBanshee) == true) {
        std::cout << "Successfully added Manny to the bag" << std::endl << std::endl;
    } else {
        std::cout << "Check add or operator== logic" << std::endl << std::endl;
    }
    if (bansheeBag.add(brendanBanshee) == true) {
        std::cout << "Successfully added Brendan to the bag" << std::endl << std::endl;
    } else {
        std::cout << "Check add or operator== logic" << std::endl << std::endl;
    }

    std::cout << "Current size of bag: " << bansheeBag.getCurrentSize() << std::endl << std::endl;

    Banshee removeMannyBanshee("Manny");
    if (bansheeBag.remove(removeMannyBanshee) == true) {
        std::cout << "Successfully removed Manny from bag" << std::endl << std::endl;
    } else {
        std::cout << "Check remove or operator== logic" << std::endl << std::endl;
    }

    std::cout << "Current size of bag: " << bansheeBag.getCurrentSize() << std::endl << std::endl;

    if (bansheeBag.contains(brendanBanshee) == true) {
        std::cout << "Successfully contains Brendan" << std::endl << std::endl;
    } else {
        std::cout << "Check contains logic" << std::endl << std::endl;
    }

    bansheeBag.clear();
    std::cout << "Current size of bag after clear: " << bansheeBag.getCurrentSize() << std::endl << std::endl;

    //Testing Firecat bag
    MagicalBag<Firecat> firecatBag;
    std::cout << "Current size of bag: " << firecatBag.getCurrentSize() << std::endl << std::endl;

    Firecat arsenFirecat("Arsen");
    Firecat ritaFirecat("Rita");

    if (firecatBag.add(arsenFirecat) == true) {
        std::cout << "Successfully added Arsen to the bag" << std::endl << std::endl;
    } else {
        std::cout << "Check add or operator== logic" << std::endl << std::endl;
    }
    if (firecatBag.add(ritaFirecat) == true) {
        std::cout << "Successfully added Rita to the bag" << std::endl << std::endl;
    } else {
        std::cout << "Check add or operator== logic" << std::endl << std::endl;
    }

    std::cout << "Current size of bag: " << firecatBag.getCurrentSize() << std::endl << std::endl;

    Firecat removeArsenFirecat("Arsen");
    if (firecatBag.remove(removeArsenFirecat) == true) {
        std::cout << "Successfully removed Arsen from bag" << std::endl << std::endl;
    } else {
        std::cout << "Check remove or operator== logic" << std::endl << std::endl;
    }

    std::cout << "Current size of bag: " << firecatBag.getCurrentSize() << std::endl << std::endl;

    if (firecatBag.contains(ritaFirecat) == true) {
        std::cout << "Successfully contains Rita" << std::endl << std::endl;
    } else {
        std::cout << "Check contains logic" << std::endl << std::endl;
    }

    firecatBag.clear();
    std::cout << "Current size of bag after clear: " << firecatBag.getCurrentSize() << std::endl << std::endl;

    //Testing CatThug bag
    MagicalBag<CatThug> catThugBag;
    std::cout << "Current size of bag: " << catThugBag.getCurrentSize() << std::endl << std::endl;

    CatThug maylynCatThug("Maylyn");
    CatThug JewelCatThug("Jewel");

    if (catThugBag.add(maylynCatThug) == true) {
        std::cout << "Successfully added Maylyn to the bag" << std::endl << std::endl;
    } else {
        std::cout << "Check add or operator== logic" << std::endl << std::endl;
    }
    if (catThugBag.add(JewelCatThug) == true) {
        std::cout << "Successfully added Jewel to the bag" << std::endl << std::endl;
    } else {
        std::cout << "Check add or operator== logic" << std::endl << std::endl;
    }

    std::cout << "Current size of bag: " << catThugBag.getCurrentSize() << std::endl << std::endl;

    CatThug removeMaylynCatThug("Maylyn");
    if (catThugBag.remove(removeMaylynCatThug) == true) {
        std::cout << "Successfully removed Maylyn from bag" << std::endl << std::endl;
    } else {
        std::cout << "Check remove or operator== logic" << std::endl << std::endl;
    }

    std::cout << "Current size of bag: " << catThugBag.getCurrentSize() << std::endl << std::endl;

    if (catThugBag.contains(JewelCatThug) == true) {
        std::cout << "Successfully contains Jewel" << std::endl << std::endl;
    } else {
        std::cout << "Check contains logic" << std::endl << std::endl;
    }

    catThugBag.clear();
    std::cout << "Current size of bag after clear: " << catThugBag.getCurrentSize() << std::endl << std::endl;
    return 0;
}
