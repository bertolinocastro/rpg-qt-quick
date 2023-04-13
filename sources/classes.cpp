#include<iostream>
#include "classes.h"

Template::Template() {
}

int Template::getMaxHP() {
    return max_hp;
}

int Template::getMaxMP() {
    return max_mp;
}

Samurai::Samurai() : Template()
{
    max_hp = 150;
    max_mp = 30;
}

Ninja::Ninja() : Template()
{
    max_hp = 80;
    max_mp = 100;
}

Mystic::Mystic() : Template()
{
    max_hp = 30;
    max_mp = 200;
}


