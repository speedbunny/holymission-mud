inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("sandworm");
set_race("worm");
set_short("A sandworm");
set_long("Yellow huge sandworm.\n");
set_level(20);
set_wc(18);
set_ac(5);
set_size(4);
set_aggressive(1);
set_spell_mess1("Sandworm bites you with its body.\n");
set_spell_mess2("");
set_chance(33);
set_spell_dam(50);
set_al(-80);
move_object(clone_object("players/goldsun/7-islands/topaz/obj/wormskin"),
	    this_object());
}

