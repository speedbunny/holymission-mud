
inherit "obj/weapon";
#include "/players/kbl/header/T.h"
#define QL query_level()

reset(arg)
{
  if(!arg)
  {
   name_of_weapon = "Any slayer";
    alt_name = "sword";
    alias_name = "slayer";
    short_desc = "Bastard sword";
    long_desc = "Sword has threaded bands of gold and silver inlaid with\n"+
                "precious gems on the hilt. The blade is of the finest\n"+
                "metal created by Kbl. There are inscriptions on the blade.\n";
    read_msg = "Kbl created this sword as a gift to the Light Elemental.\n"+
               "LE provides hope that the future remains bright for our\n"+
               "imaginations to fly! NOT be supressed by the Darkness that\n"+
               "threathens to surround us all. Humans are the basis from\n"+
               "which darkness moves away but only through the mind can we\n"+
               "put darkness in its PLACE!\n";
    class_of_weapon = 15;
    type_of_weapon = 3;
    value = 5000;
    local_weight = 3;
    hit_func = this_object();
  }
}

magic_hit(attacker)
{
    write("You do MEGA damage to "+attacker->query_name()+".\n");
    if(random(random(random(100))) == 0)
     if(attacker->QL > 29)
     {
       say("A flash leaps from the sword and totally vaporizes\n"+
           attacker->QRN+" in a brillant display of light.\n",
           attacker);
       destruct(attacker);
       return;
     }
// special for gods
    return 100;
}

