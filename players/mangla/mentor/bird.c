inherit "obj/monster";

#include "/players/mangla/defs.h"

int hit_player(int dam,int kind,int elem) {

    if(!random(5)) {
        TELLR(ENV(TO),"The attack is parried.\n");
        return 0;
    }
    else ::hit_player(dam,kind,elem);
    return 1;
}

int follows(string dirs) {

    if (command(dirs,TO)) return 1;
    return 0;
}


int catch_tell(string arg) {

    string dir,who;

    if(sscanf(arg,"%s leaves %s.\n",who,dir)!=2)
        return 0;
//    TELLR(ENV(TO),"Direction is " + dir + ".\n");
    if (!random(3))
        call_out("follows",2,dir);
    return 1;
}

reset(arg) {

    ::reset(arg);
    if (!arg) {
        set_name("bird");
        set_alias("bird");
        set_race("bird");
        set_size(2);
        set_level(6);
        set_short("Bird");
        set_long("A rather average bird except for the very pointy beak.\n");
        set_wc(8);
        set_ac(6);
        set_hp(100);
        set_al(0);
        set_dex(0);
        set_aggressive(0);
        add_money(0);
        set_chance(30);
        set_spell_dam(5);
        set_spell_mess2("The bird swoops up and dive bombs you.");
        set_spell_mess1("The bird drops a load onto its opponent.");
enable_commands();
    }
}

int attack() {
  object att;

  if( !::attack()) return 0;
  att = query_attacker();
  if(objectp(att)) {
    tell_room(environment(this_object()), "Poison!\n");
    att->add_poison(10);
  }
}

