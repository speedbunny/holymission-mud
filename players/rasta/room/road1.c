
inherit "room/room";

object sign;
reset(arg) {

  if (!arg) {
    set_light(1);
  dest_dir=({"room/vill_track","south",
   "players/rasta/room/bulletin","east",
	     "players/rasta/room/archway","northwest"});

 short_desc="Dire Road";
   long_desc="This is a dire road leading further south.\n";

sign=clone_object("players/rasta/obj/sign2");
transfer(sign,"room/road1");
  }
}
