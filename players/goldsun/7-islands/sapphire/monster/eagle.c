inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("eagle");
set_race("bird");
set_short("A Rocky Eagle");
set_long("You see an eagle flying above you.\n");
set_level(6);
set_wc(9);
set_ac(5);
set_size(2);
set_spell_mess1("The eagle flies headlong down to your head.\n");
set_spell_mess2("A eagle flies headlong down.\n");
set_chance(30);
set_spell_dam(35);
set_aggressive(1);
set_al(-50);
move_object(clone_object("players/goldsun/7-islands/sapphire/obj/feathers"),
	    this_object());
}

