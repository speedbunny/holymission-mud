inherit "/obj/monster";

void reset(int arg)
 {

 ::reset(arg);
if (arg) return;
set_name("beaver");
set_race("animal");
set_short("A beaver");
set_long("A brown beaver.\n");
set_level(9);
set_wc(12);
set_ac(5);
set_size(2);
set_aggressive(1);
set_al(-30);
move_object(clone_object("players/goldsun/7-islands/sapphire/obj/headband"),
	    this_object());
}

