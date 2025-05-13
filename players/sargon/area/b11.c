inherit "room/room";

reset(arg) {
    if (arg) return;
  ::reset(arg);
  if(!present("stormtrooper"))
{
move_object(clone_object("players/sargon/monster/storm.c"),this_object());
move_object(clone_object("players/sargon/monster/storm.c"),this_object());
move_object(clone_object("players/sargon/monster/storm.c"),this_object());
}

    set_light(1);
    short_desc = "A long white hallway";

    long_desc =
    "You are in a wide open enterance to an all white corridor\n"+
    "which leads to the north.  To the south is a large archway.\n"+
    "with a large white door.  This area is heavily guarded.\n";


    dest_dir = ({
      "players/sargon/area/b10.c", "north",
      "players/sargon/area/b12.c", "south"




    });

}
