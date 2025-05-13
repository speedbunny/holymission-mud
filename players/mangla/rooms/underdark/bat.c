inherit "obj/monster";

#include "/players/mangla/defs.h"

int attack() {

    int i,j;
    object *ob;

    j = 0;
    ob = all_inventory(ENV(TO));
    while(!j) {
        i = random(sizeof(ob));
        if(living(ob[i]) && ob[i] != TO &&
                     !ob[i]->query_npc() && ob[i]->LEVEL < 30)) {
            change_attacker(ob[i]);
            j = 1;
        }
    }
    ::attack();
}

void reset(int arg) {

  ::reset(arg);
  if (!arg) {
    set_name("Night Hunter");
    set_alias("bat");
    set_race("mammal");
    set_size(1);
    set_level(5);
    set_short("Dragazhar bat");
    set_long("This formidable creature stalks the underdark in large packs,\n" +
             "prepared to kill anything they can possibly kill.\n");
    set_wc(5);
    set_ac(2);
    set_hp(10+random(24));
    set_al(-100);
    set_dex(30);
    set_aggressive(1);
    add_money(0);
    set_chance(30);
    set_spell_dam(5);
    set_spell_mess2("The dragazhar whips its wings forward and scratches you badly.");
    set_spell_mess1("The dragazhar strikes with its wings.");
  }
}
