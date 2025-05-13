inherit "room/room";

#define TPN this_player()->query_name()
#define TR tell_room
void reset(int arg) {

  if(arg) return;

  set_light(1);

  long_desc="You have managed to climb out of the ravine and have arrived at "+
            "a small prairie. Prairie grass and sagebrush are all around you.\n";

  short_desc="Top of ravine";

  dest_dir=({"players/emerald/good/light/light18", "north",
             "players/emerald/good/light/light17", "east"
           });

  items=({"ravine","The ravine lies 20 feet below you",
          "sagebrush","Dry-looking bushes",
          "grass","Long stems of grass",
          "prairie","A small prairie, inhabited by gophers",
        });

  ::reset();

}
void init() {
  ::init();
  add_action("_climb","climb");
}

_climb(str)  {
  if(str!="down") {
    notify_fail("Climb where?\n");
    return 0;
  }
  if(str == "down") {
    if (random(10) <4) {
      write("You try hard to climb down, but get scared and crawl back up.\n");
      say(TPN + " tries to climb down but chickens out.\n");
      return 1;
    }
    write("You succeed in climbing down into the ravine.\n");
    say(TPN+" climbs down into the ravine.\n");
    TR("players/emerald/good/light/light15",TPN+" climbs down the ravine.\n");
    this_player()->move_player("down#/players/emerald/good/light/light15");
    return 1;
  }
}
