inherit "room/room";
#include "/obj/door.h"
object obj_1, obj_2;
reset(arg) {
    if (arg) return;
    MAKE_DOORS("players/kelly/rooms/vill/mayorsgarden","east",
               "players/kelly/rooms/vill/mayorhouse","west",
	       "iron","house","A door leading into the house of the mayor",
               1,0,0);
    set_light(1);
short_desc="The Mayor's garden.";
long_desc=
"This is a lush beautiful place full of flowers and shrubberies.\n"+
"There is a cobblestone path that leads from the main road to the\n"+
"mayor's house.  There is another path that leads around the mayor's\n"+
"house as well.\n";
    dest_dir=({
      "players/kelly/rooms/vill/road1","west",
      "players/kelly/rooms/vill/mayorpath","southeast",
   });
   items=({
     "door","A wooden door without a lock",
     "flowers","A wide variety of garden flowers are in this area",
     "shrubberies","The shrubs make intricate pattrerns on the lawn",
     "path","It seems that the path hasn't been used for a long time",
     "house","It's the mayor's house. It's very big and splendid",
     "cobblestone","A nice cobblestone path leads to the house",
   });
    property = ({ "no_clean_up" });
}
