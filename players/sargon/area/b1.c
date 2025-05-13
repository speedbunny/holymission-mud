inherit "room/room";

reset(arg) {
    if (arg) return;
  ::reset(arg);
  if(!present("darth vader"))
{
move_object(clone_object("players/sargon/monster/darth.c"),this_object());

}

    set_light(1);
    short_desc = "The end of a long white hallway";

    long_desc =
    "This is the lair of Darth Vader.  It is dark and evil here. \n" + 
 "There is a strong presence of the force in this room.\n" +
  "Don't do anything foolish.  Darth Vader is glaring at you\n";



    dest_dir = ({

      "players/sargon/area/b2.c", "south"

    });
       property = ({
                      "no_sneak","no_telport","no_steal"
                 });

}
