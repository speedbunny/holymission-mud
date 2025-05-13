inherit "room/room";

#define TPN this_player()->query_name()

void reset(int arg) {

  if (arg) return;

  set_light(1);

  short_desc="Wooded area";
  long_desc="This is a bright and open area surrounded by woods.  The " +
            "trees appear to be aspen trees and are in their full beauty.  "+
            "Many animals have come and gone here, as there are many " +
            "tracks in this area.\n";

  items=({"tracks","The tracks lead north into the woods.  Perhaps you " +
                   "should follow them",
          "trees","The trees are small, young aspen trees",
          "aspen","A delicate-looking tree",
          "woods","They surround the area",
        });

  dest_dir=({"players/emerald/good/light/light12", "west",
           });

  ::reset();

}

void init() {
  ::init();
  add_action("_follow","follow");
}

_follow(str) {
  switch(str) {
    case "tracks" :
    case "animal tracks" :
      write("You find a path through the woods to the north.\n");
      say(TPN +" finds a path north and follows it.\n");
      tell_room("players/emerald/good/light/light21",TPN+ " arrives.\n");
      this_player()->move_player("north#players/emerald/good/light/light21");
      return 1;
    default :
      notify_fail("Follow what?\n");
      return 0;
}
  }

