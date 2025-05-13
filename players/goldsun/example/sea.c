inherit "players/cashimor/inherit/water";

#include "/players/goldsun/gen/harb.h"
#define TP this_player()
#define CENTRAL_HARBOUR "players/goldsun/gen/room/central_harb"

string *boat_land;  /*  boat(s) that land here */
                                      
reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="All at sea";
    long_desc="You are swimming out at the sea.\n";
    boat_land=({"cargo junk"});
    set_light(1);
//    dest_dir=({"room/jetty2","west"});
    dest_dir=({"players/beardy/port/ptown","west"});
    nodanger=1;
    floats="room/sea_bottom";
    smell="You have salt in your nose.";
  }
}

init() {
int i;
  ::init();
  if (TP && !TP->query_npc())
   for(i=0;i<sizeof(boat_land);i++)
    CENTRAL_HARBOUR->call_boat(file_name(this_object()),boat_land[i]);
  this_player()->set_smell("You smell salt seawater.");
  add_action("dive","dive");
}

dive() {
  this_player()->move_player("down#room/sea_bottom");
  return 1;
}

