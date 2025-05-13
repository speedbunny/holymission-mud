/* 12.11.93 Airborne: Fixed to room/room and clone_list */
/* 3.7.94 Topaz: Changed jailer's wc from -40 to 8 */

inherit "room/room";

reset(arg){
  set_light(1);
  short_desc =  "The dungeons";
  long_desc =
    "A long row of small dirty cells with heavy iron doors lies in front\n"
    "of you. Though the castle has been uninhabited for many hundred years\n"
    "the dungeons seem to have been used not a long time ago...\n";
  dest_dir = ({ "players/topaz/angmar/corridor", "north" });
  clone_list = ({ 1, 1, "jailer", "obj/monster",
			     ({ "set_name", "jailer",
				"set_level", 6,
				"set_hp", 100,
				"set_wc", 8,
				"set_short", "The jailer",
				"set_long", "He guards the dungeons.\n",
				"set_aggressive", 1,
				"add_money", 100 }),
				});

::reset();
replace_program("room/room");
}
