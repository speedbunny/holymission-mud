
inherit "room/room";

reset(arg) {

  if (!arg) {
    set_light(1);
    dest_dir=({"players/rasta/room/path61","south",
	     "players/rasta/room/archway1","west"});

 short_desc="Valley of Decision";
   long_desc="Get some experience here and become a vigilant Rastafarian!\n";
  }
}
