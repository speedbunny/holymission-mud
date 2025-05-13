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
        i = random(sizeof(ob));
        if(living(ob[i]) && ob[i] != TO &&
                !ob[i]->query_npc() && ob[i]->LEVEL < 30) {
            j = 1;
            change_attacker(ob[i]);
            ob[i]->hold(ob[i],5);
        }
    }
}

reset(arg) {

  ::reset(arg);
  if (!arg) {
    j = 1;
    set_name("Cloaker");
    set_alias("cloaker");
    set_race("mammal");
    set_size(4);
    set_level(30);
    set_short("Cloaker");
    set_long("This appears to be a cloak lying on the ground, but as you approach\n" +
             "it comes to life and you notice the all to obvious red glowing eyes\n" +
             "staring at you, moving forward to engulf its victim.\n");
    set_wc(15);
    set_ac(5);
    set_hp(400);
    set_al(-600);
    set_dex(10);
    set_aggressive(1);
    add_money(0);
    set_cha(10);
  }
}
