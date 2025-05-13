inherit "room/room";

#include "/players/helmut/defs.h"

void reset(int arg) {
  object ob;
  ::reset(arg);
  if(!(ob=present("velociraptor",TO)) || !living(ob)) {
    MO(CO("players/helmut/monsters/raptor3"),TO);
  }
  if(!arg) {
    short_desc="Bloody Clearing";
    long_desc="The first thing you notice in this clearing is the large\n"+
      "amount of blood that covers the ground. In fact, the\n"+
      "plants are covered with it. Your feet stick to the short,\n"+
      "jungle grass, and your heart skips a beat as you look\n"+
      "around. Was that a pair of eyes in the dark jungle?\n"+
      "You aren't sure. Then you notice that there might be\n"+
      "something in the area with you...\n";
    set_light(1);
    dest_dir=({"players/helmut/rooms/skelpath","west",
      "players/helmut/rooms/stream","north",
      "players/helmut/rooms/sign","east"});
    replace_program("room/room");
  }
}
