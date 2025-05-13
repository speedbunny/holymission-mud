inherit "room/room";

reset(arg) {
    if (arg) return;
  ::reset(arg);
  if(!present("stormtrooper"))
{

}

    set_light(1);
    short_desc = "A long white hallway";

    long_desc =
    "You are in a long white hallway with light illuminating from above\n"+
    "and below.  The hallway continues northeast and south.\n";



    dest_dir = ({


      "players/sargon/area/b7.c", "northeast",
      "players/sargon/area/b9.c", "south"
     

    });

}
