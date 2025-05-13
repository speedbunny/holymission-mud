inherit "room/room";
#include <lw.h>

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {set_light(1);
    short_desc = "Climbing cliff";
    long_desc =
    "You are climbing up the face of a steep cliff.  The rock is slick from the moisture "+ 
    "in the air, and the climb ahead looks difficult.  You are just about half way to the "+
    "top, but you can already feel the strain on your muscles, not to mention that "+
    "nagging fear of falling to your death...\n";
    smell = "The air crisp and sweet smelling.";
    property = ({"no_fight","no_steal","no_hide"}); 
    dest_dir = ({"players/kawai/areas/cliff3","up",
    "players/kawai/areas/cliff1","down"});
    items = ({"cliff","You are near the bottom of a steep, slick cliff",
    "face","The rock is slippery, but you might be able to climb to the top",
    "rock","The rock is slippery, but you might be able to climb to the top",
    "bottom","At the base of the cliff is a small pool and plenty of hard rocks to land on"
    "cliff face","The cliff face stretches upwards about 30 feet",
    "cavern","The view is lovely, yet frightening, from here",
    "water","Crystal clear and quite refreshing looking",
    "cave","The cave is about 20 feet above you",
    "pool","A small pool at the far end of the cave",
    "rocks","Considering where you are, best not look down",
    "waterfall","You're a bit too close for comfort"});}}

void init()
   {::init();
   if(!present("kq1-glo",this_player())&&
   this_player()->query_dex()<random(20))
     {writelw("Unfortunately you grab a hold of a particularly slippery "+
     "rock while climbing and lose your grip.  After a rapid plummet, your "+
     "feet, and the rest of your body, feel the firm ground below.\n");
     this_player()->misc_hit(20,0,0);
     this_player()->move_player("down rapidly through the air",
     "players/kawai/areas/wcave");}}

  
