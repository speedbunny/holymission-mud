inherit "room/room";
 
#define me capitalize(this_player()->query_name())
 
reset(arg) {
    if(arg) return;
#if 0 
    ::reset(arg);
    set_light(1);
    set_outdoors(4);
#endif
    set_light(1);
    long_desc = "Top of ravine.\n" +
         "\n" +
         "     You have managed to climb out of the ravine.\n" +
         "     You made to a small prairie. Prairie grass and\n" +
         "     sagebrush are all around you.\n" +
         "\n";
    short_desc = "Top of ravine";
    dest_dir = ({
        "players/animal/light/light18", "north",
        "players/animal/light/light17", "east"
    });
    items = ({
   "ravine","The ravene lies 20 feet below you",
    });
    return;
}
 
query_long() {
    return long_desc;
}
 
query_outdoorness() {
    return 4;
}
 
query_light() {
    return 1;
}
 
init() {
          ::init();
          add_action("climb","climb");
          add_action("search","search");
}
 
climb(str)  {
          if(!str) {
               write("Climb where?\n");
               return 1;
          }
 if(str == "down") {
          if (random(10) <4) {
  write("You try hard to climb down, but you get scared and crawl back up.\n");
     say(me + " tries to climb down but chickens out.\n");
          return 1;
          }
          write("You succeed in climbing down into the ravine.\n");
     say(me + " climbs down into the ravine.\n");
     tell_room("players/animal/light/light15",me+" climbs down from the top of the ravine.\n");
     move_object(this_player(), "players/animal/light/light15");
     call_other(this_player(), "look");
     return 1;
          }
     return 0;
}
 
search(str) {
    if (!str) str = "room";
    if (str == "room") {
          write("You find nothing unusual.\n");
 
          say(me + "searches the room.\n");
            return 1;
        }
            return 0;
}
