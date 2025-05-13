/* Changed #include to be after inherit Colossus 040394 */

inherit "obj/monster";

#include "../garden.h"
reset (arg) {
    ::reset(arg);

    if (!arg) {

	set_name("mother fox");
	set_alt_name("fox");
	set_short("The mother fox");
	set_long("She looks very angry.\n");
	set_level(2);
	set_size(2);
	set_aggressive(1);
	set_spell_mess1("The mother fox bites you in your leg");
	set_spell_mess2("The mother fox hits you with it's claw");
	set_chance(80);
	set_spell_dam(2);
	set_dead_ob(this_object());
	move_object(clone_object("players/whisky/garden/obj/fox_jacket2"),
	  this_object());
    }
}
monster_died(ob) {
    write("Angrily father fox arrives\n");
    move_object(clone_object("players/whisky/garden/monster/f_fox"),
      environment(this_object()));
    return 0;
}
