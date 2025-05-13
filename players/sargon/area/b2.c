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
    short_desc = "The end of a long white hallway";

    long_desc =
    "You have come to the end of a long white hallway.  To the north\n"+
    "there is an archway which passes into a darkened room.  The three\n"+
    "stormtroopers here have orders to kill all intruders.  You feel a\n"+
    "great power of the Force coming from the north.  Maybe it isn't a\n"+
    "good idea to be here.\n";



    dest_dir = ({


      "players/sargon/area/b1.c", "north",
    "players/sargon/area/b3.c", "south"

    });
       property = ({
                      "no_sneak"
                 });

}

init() {
    ::init();
    add_action("north", "north");
}

int north() {

    if(present("stormtrooper",this_object())) {
        write ("Stormtrooper will not let you pass.\n");
        return 1;
    }
    return ::move("north");
}
