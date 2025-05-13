inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="A dimly lit forest";
    long_desc="You are in a part of a dimly lit forest.\n"
	+ "A small path leads east into the bushes.\n";
    smell="The forest smells very old.";
    items=({"forest","It looks green",
            "path","It looks almost invisible"});
    set_light(1);
    dest_dir=({"room/south/sforst15","north",
               "room/south/sforst17","south",
               "room/south/sforst19","west",
               "players/sherman/entrance","east"});
  }
}

