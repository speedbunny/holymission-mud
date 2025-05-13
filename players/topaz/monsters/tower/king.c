inherit "obj/monster";

#include "/players/topaz/defs.h"

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("black Demon King");
    set_alt_name("king");
    set_alias("eriskull");
    set_race("demon");
    set_short("The ugly demon king, Eriskull");
    set_long("The ugly Demon King, Eriskull!\n" +
             "The Demon King is the ugliest creature you have ever seen!\n" +
             "It sits upon its throne in smug arrogance.  It is\n" +
             "wearing a white crown on its head.  The king returns\n" +
             "your gaze and you are forced to look away.\n");
    set_aggressive(1);
    set_level(40);
    set_wc(51);
    set_ac(32);
    set_al(-1000);
    set_hp(4685);
    move_object(clone_object(ARMR + "tower/dplatemail"),this_object());
    move_object(clone_object(ARMR + "tower/dwhitecrown"),this_object());
    move_object(clone_object(WEAP + "tower/RoD"), this_object());
    command("wear platemail");
    command("wear crown");
    command("wield rod");
    set_chance(80);
    set_spell_dam(60+(random(60)));
    set_spell_mess2("The king SMOTES you with sheer P O W E R !!!!!!!\n");
    set_spell_mess1("The king SMOTES his opponent with sheer P O W E R !!!!!!!\n");
}
