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
    long_desc = "End of ravine.\n" +
         "\n" +
         "     You have reached the end of the ravine.\n" +
         "     The walls still look dry and steep, but you might\n" +
         "     be able to climb up if you are lucky.\n" +
         "\n";
    short_desc = "End of ravine";
    dest_dir = ({
         "players/animal/light/light9", "north",
	});
    items = ({
        "walls","The river walls look climbable here",
        "wall","The wall looks climbable",
    });
    return;
}
 
init() {
          ::init();
          add_action("climb","climb");
          add_action("search","search");
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
 
climb(str)  {
          if(!str) {
               write("Climb what?\n");
               return 1;
          }
 if(str == "walls" || str == "wall" || str == "the walls" || str =="the wall")
{
          if (random(10) <4) {
          write("You try hard to climb, but you slide back down.\n");
          say(me + " tries to climb the river wall but fails.\n");
          return 1;
          }
          write("You succeed in climbing up the ravine wall.\n");
     say(me + " climbs up out of the ravine.\n");
     tell_room("players/animal/light/light16",me+" climbs out of the ravine.\n");
     move_object(this_player(), "players/animal/light/light16");
     call_other(this_player(), "look");
     return 1;
          }
     return 0;
}
 
search(str) {
    if (!str) str = "room";
    if (str == "room") {
          write("You find nothing unusual.\n");
          say(me + " searches the room.\n");
            return 1;
        }
     return 0;
}
