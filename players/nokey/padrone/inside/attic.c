/* 12.05.92 Airborne - Re-written to allow use of clone_list and
   replace_program. Changed over to inherit "room/room" as well. */
/* 170794: Nokey: strict typed */
#pragma strict_types

inherit "room/room";

void reset(int arg)
  {
  if(!present("piece of paper"))
    {
    object note;
    note = clone_object("players/padrone/obj/thing");
    note->set_name("paper");
    note->set_alias("piece of paper");
    note->set_short("A piece of paper");
    note->set_long("This is a small piece of paper, with something written on it.\n");
    note->set_can_get(1);
    note->set_weight(1);
    note->set_value(1);
    note->set_read("The writing on the paper has a strangely other-worldly quality about it.\n"+
    "It says: \"Email: padrone@lysator.liu.se\".\n");
    transfer(note,this_object());
    }
  ::reset(arg);
  if(arg) return;
  set_light(1);
  short_desc = "Attic";
  long_desc = "You are in the attic.\n"
	"This is a spacious, airy loft. It is very empty.\n";
  dest_dir = ({ "players/padrone/inside/stairs2", "down" });
replace_program("room/room");
}
