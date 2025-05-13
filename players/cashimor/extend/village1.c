/* VILLAGE1.C - Programmed by Ethereal Cashimor */
/* START : Started programming */
/* AFTER : Portil: Added tree */
/* 121094: Modified code to fit another room into the MUD */

inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="Village track";
    long_desc="You're walking on a track through the village. There "
            + "is green grass growing on the sides of the track. To "
            + "the north you can see the eastern side of the church "
            + "and to the south the sheriff's office. A large tree stands "
             + "on the side of the road.\n";
    set_light(1);
    dest_dir=({"room/vill_green","west",
               "/room/player/sheriff", "south",
               "room/vill_track","east"});
    smell="The smell of grass hangs in the air.";
    items=({"track","There is a lot of grass growing on it",
            "grass","It looks green and healthy",
            "office","Maybe you should enter it",
            "village","It is very old",
            "tree","An ancient elm tree; a ladder is leaning against it",
            "ladder","A well-used wooden ladder. Quite sturdy"});
    no_castle_flag=1;
  }
}

init() {
  ::init();
  add_action("climb_it","climb");
}

climb_it(str) {
  if(str=="ladder") {
     write("You climb up and down the ladder.\n");
/*
     this_player()->move_player("climbs the ladder#players/portil/games/tree");
*/
     return 1;
  }
  else {
    notify_fail("Climb what?\n");
    return 0;
  }
}
