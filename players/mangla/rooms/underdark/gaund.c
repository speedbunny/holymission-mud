inherit "obj/monster";

#include "/players/mangla/defs.h"

static int j;

int attack() {

    int i;
    string str;
    object *ob;

    ::attack();
    while(!j) {
        ob = all_inventory(ENV(TO));
        j = 1;
        i = random(sizeof(ob));
        if(living(ob[i]) && ob[i] != TO &&
                !ob[i]->query_npc() && ob[i]->LEVEL < 30) {
            change_attacker(ob[i]);
        }
    }
}

reset(arg) {

  ::reset(arg);
  if (!arg) {
    set_name("Gaund");
    set_alias("gaund");
    set_race("reptile");
    set_size(3);
    set_level(15);
    set_short("Gaund");
    set_long("This formidable creature stalks the underdark in large packs\n" +
             "prepared to kill anything that it comes across.\n");
    set_wc(15);
    set_ac(6);
    set_hp(60+random(40));
    set_al(-100);
    set_dex(10);
    set_aggressive(1);
    set_move_at_reset();
    add_money(300);
    set_chance(40);
    set_spell_dam(20);
    set_spell_mess2("You see a flash as the gaund's razor tail lashes out to cut you.");
    set_spell_mess1("The gaund whips it tail to attack.");
    set_cha(10);
  }
}
