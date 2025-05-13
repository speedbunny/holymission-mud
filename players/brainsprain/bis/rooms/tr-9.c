inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int rnd;

void reset(int arg) {
  
  short_desc = "Town road";
  long_desc =
    "Here the road comes to an elbow.  To the east lies the bar, shop, and "+
    "armoury.  To the south is the pier and other shops.  A cemetary is "+
    "fenced in on the west.  To the north a rock garden with a massive "+
    "sculpture in the center.\n";
  set_light(1);
  items = ({
    "pier",
    "The Town Pier",
    "shops",
    "Various unique and interesting shops",
    "bar",
    "The Towpath Tavern",
    "shop",
    "A general shop",
    "armoury",
    "The Towpath Armoury",
    "road",
    "The main road in Towpath",
    "towpath",
    "The town you are in",
    "cemetary",
    "The graves of long dead soldiers and citizens",
    "garden",
    "A garden commemorating the former counts of Bismarck",
    "sculpture",
    "A sculpture made in the likeness of the first Count Bismarck",
    "count",
    "The first Count Bismarck",
    "bismarck",
    "The family name of the rulers of this Empire",
  });
  dest_dir = ({
    br+"/tr-8","east",
    br+"/tr-10","south",
  });
  rnd = random(3);
  clone_list = ({ 1, rnd, "orc",
		  bm+"/peas", 0 });
  ::reset(arg); 
  replace_program("room/room");
}


