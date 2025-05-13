inherit "room/room";

#include "/players/skeeve/area.h"

reset(arg) {
  if (!arg)  {
    set_light(1);
    short_desc = "fork";
    long_desc = 
         "You are on a fork on the path.\n"
       + "Beside the path is druid Lakmir's Rest and Druid Lakmir's Shop.\n"
       + "There is a wooden sign.\n";
    no_castle_flag = 0;
    dest_dir = ({
        LAND + "forest11",  "north",
        LAND + "path1", "east",
        LAND + "path3", "south",
        LAND + "path2", "west"
       });
   hidden_dir = ({
        LAND + "rest",  "rest",
        LAND + "shop",  "shop"
       });
   items = ({
      "fork", "The path continous to the east, south and west",
      "path", "It's a small and lonesome path beetween high oaks",
      "sign", "There is a map on it",
      "map",  "Maybe, you should read it",
      "shop", "It's druid Lakmir's shop and, you think so, it's open",
      "rest", "It's druid Lakmir's rest and, you think so, it's open"
    });
  }
}

init() {
  ::init();
  add_action("read", "read");
  add_action("enter","enter");
}

enter (str) {
  if ( (str == "rest") || (str == "shop") ) return ::move (str);
}

read(str) {
  if ((str =="sign")||(str =="map")) {
    write("         rest shop\n"
         +"cottage <- fork -> road\n"
         +"             I\n"
         +"          pasture\n");
    return 1;
  }
  return 0;
}

move(dir) {
   if (!dir) dir=query_verb();
   return (this_player()->query_stay_garden() && ((dir=="shop")||(dir=="rest")) ) ?
     ::move("west") : ::move(dir);
}
