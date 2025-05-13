#include "/players/tinman/defs.h"
inherit "room/room";

reset (arg)
{
	if (!arg)
	{
  move_object(clone_object("/players/sherman/hills/dplate"),this_object());
  move_object(clone_object("/players/llort/secure/wscroll"),this_object());
  move_object(clone_object("/players/llort/secure/lwscroll"),this_object());
  move_object(clone_object("/players/padrone/obj/wizardshat"),this_object());
  move_object(clone_object("/players/llort/guild/obj/regring"),this_object());
  move_object(clone_object("/players/llort/guild/obj/regamulet"),this_object());
  move_object(clone_object("/players/whisky/obj/jeweled_earrings"),this_object());
  move_object(clone_object("/players/whisky/obj/ruby_bracelet"),this_object());
move_object(clone_object("players/tinman/monsters/anica.c"),this_object());
  move_object(clone_object("/players/llort/animals_stuff/diring"),this_object());
  move_object(clone_object("/players/whisky/obj/tower_shield"),this_object());
  move_object(clone_object("/players/sherman/hills/fsword"),this_object());
  move_object(clone_object("/players/sherman/hills/crystal"),this_object());
  move_object(clone_object("/players/kawai/obj/orb.c"),this_object());
  move_object(clone_object("/players/kawai/obj/statue.c"),this_object());
  move_object(clone_object("/players/kawai/obj/qsword.c"),this_object());
  move_object(clone_object("/players/matt/newworld/forestb/objects/seed.c"),this_object());
  move_object(clone_object("/players/matt/newworld/forestb/objects/lifefruit.c"),this_object());
  move_object(clone_object("/players/matt/newworld/plains/monsters/old_dwarf.c"),this_object());
  move_object(clone_object("/players/airborne/weapons/hellfire.c"),this_object());
  move_object(clone_object("/players/llort/secure/girdle"),this_object());
  move_object(clone_object("/players/whisky/obj/red_bull_potion"),this_object());
	set_light(1);
	short_desc=("Tinman's treasury room");
	long_desc=("This is Tinman's treasury room.  He keep all his\n"+
		   "valuable stuff here.  Don't even think about stealing\n"+
		   "his stuff.  He will get very angry if you do.\n");

	dest_dir=({
		"/players/tinman/workroom","west",
		});
	hidden_dir=({
		"/players/tinman/rooms/t","priss",
		});

	property = ({
			"no_sneak","no_steal",
			});
	smell = "you smell gold here.\n";
	}
}
init()
{
::init();
    add_action("blah","blah");
	add_action("blah2","blah2");
}
blah() {
	object ob;
	ob=clone_object("/players/airborne/obj/badge.c");
	transfer(ob,this_player());
	write("You get a badge.\n");
	return 1;
	}
