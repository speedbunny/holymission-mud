

inherit "room/room";

#include "/players/jake/defs.h"
reset(arg) {
    if (arg) return;

    set_light(3);
    short_desc = "Jakes workroom";
    long_desc = 
        "You are standing in Jakes workroom.  This is where Jake spends his\n" +
        "time figuring out how to code, and coding various rooms for his\n" +
        "area.  There is a large comfy looking chair in the middle of the floor.\n";
items = ({
 "chair","Jake's huge comfy chair.\nIt is bright red",
});
dest_dir = ({
"/players/jake/path","dorm",
"players/jake/goblin/gob1","ville",
"players/jake/goblin/castle/enter","goblin",
"room/main_shop","west",
      "/room/church","church",
        });
}

init() {
::init();
add_action ("sit","sit");
}
sit(str) {
 switch(str) {
case "in chair":
  write("You sit comfortably in Jake's chair.\n");
  say(TPN + " sits in Jake's chair.\n");
return 1;
default:
 write ("do what?\n");
return 1;
}
}
