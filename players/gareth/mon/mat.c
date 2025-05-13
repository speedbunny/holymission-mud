inherit "/obj/npc";
#include "/players/mangla/defs.h"
object lamp;

static int j;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("Night Hunter");
    set_alt_name("hunter");
    set_alias("bat");
    set_race("mammal");
    set_level(50);
    set_size(1);
    set_short("Dragazhar bat");
    set_long("This formidable creature stalks the underdark in large pack\n" +
             "prepared to kill anything they can possibly kill.\n");
    set_wc(50);
    set_ac(55);
    set_hp(random(2000));
    set_al(-100);
    set_dex(65);
    set_aggressive(1);
    add_money(0);
    set_chance(90);
    set_spell_dam(45);
    set_spell_mess2("The dragazhar whips its wings forward and scratches you badly.");
    set_spell_mess1("The dragazhar strikes with its wings.");
    set_dodge(25);
    set_attacks(10);
    set_attacks_change(45);
     lamp = transfer(clone_object("/players/gareth/obj/lamp"), this_object());
    
  }
}

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
                     !ob[i]->query_npc()) {
            change_attacker(ob[i]);
        }
    }
}
