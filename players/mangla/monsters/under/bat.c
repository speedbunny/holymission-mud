inherit "obj/monster";

#include "/players/mangla/defs.h"

static int j;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("Night Hunter");
    set_alt_name("hunter");
    set_alias("bat");
    set_race("mammal");
    set_size(1);
    set_level(5);
    set_short("Dragazhar bat");
    set_long("This formidable creature stalks the underdark in large pack\n" +
             "prepared to kill anything they can possibly kill.\n");
    set_number_of_arms(4);
    set_n_wc(5);
    set_ac(5);
    set_dex(15);
    set_hp(25+random(50));
    set_al(-100);
    set_dex(10);
    set_aggressive(1);
    add_money(0);
    set_chance(90);
    set_spell_dam(10);
    set_spell_mess2("The dragazhar whips its wings forward and scratches you badly.");
    set_spell_mess1("The dragazhar strikes with its wings.");
  }
}

int attack() {

    int i;
    string str;
    object *ob;

    if( !::attack() ) return 0;

    if(random(100) < 30) {
        ::attack();
        ::attack();
    }
// Mangla: the above will cause the bat to make double attacks 30 percent
//         of the time, and the below will make it change up attacker
//         at the end of the round.
    while(!j) {
        ob = all_inventory(ENV(TO));
        j = 1;
        i = random(sizeof(ob));
        if(living(ob[i]) && ob[i] != TO &&
                     !ob[i]->query_npc()) {
            change_attacker(ob[i]);
        }
    }
}
