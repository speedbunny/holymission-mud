inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
int rnd;

void reset(int arg) {
short_desc = "Four way intersection";
long_desc = 
"You stand in the middle of a four way intersection.  The road here is half "+
"brick and half cobblestone.  People hustle in and out of every building. "+
"From the south comes the smell of fish and salt water.  People of every "+
"race wander through town looking for the best deal.  There is a grand "+
"church to the west.  To the north there are many unique shops.  The Towpath "+
"Archive is to the south.\n";
  set_light(1);
  items = ({
    "church",
    "The Towpath church",
    "shops",
    "The closest one appears to be an armourer",
    "archive",
    "Here you can learn about the Bismarck kingdom",
    "kingdom",
    "The Bismarck Kingdom",
    "people",
    "Citizens and visitors",
    "building",
    "There are many unique shops and buildings in Towpath",
    "town",
    "Towpath",
    "intersection",
    "The main intersection in Towpath",
    "road",
    "The main road in Towpath",
    "towpath",
    "The town you are in",
    "brick",
    "The road is half brick",
    "cobblestone",
    "Round rocks fitted together to form part of the road",
  });
  dest_dir = ({
    br+"/church","west",
    br+"/tr-2","east",
    br+"/tr-4","north",
    br+"/tr-18","south",
  });
rnd = random(3);
clone_list = ({ 1, rnd, "orc",
      bm+"/peas", 0 });
   ::reset(arg);

    replace_program("room/room");
}
