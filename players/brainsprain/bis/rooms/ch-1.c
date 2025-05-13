inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  short_desc = "Bismarck Keep ante-room";
  long_desc =
    "This is the ante-room of Bismarck Keep.  This is a very beautiful room "+
    "Along the southern wall is a rack filled with cloaks.  Under the cloaks "+
    "Is a row of boots. The tiled floor leads to the west and the gates rise "+
    "up to the east.\n";
  set_light(1);
  dest_dir = ({
    br+"/ch-2.c","west",
    br+"/gates.c","east",
    
  });
  items = ({
    "room",
    "This is the cloakroom of Bismarck Keep",
    "ante-room",
    "This is the cloakroom of Bismarck Keep",
    "keep",
    "Bismarck Keep",
    "bismarck",
    "Castle Bismarck",
    "gates",
    "Huge steel gates with wrought iron hinges",
    "cloaks",
    "The cloaks of visiting dignitaries",
    "boots",
    "The boots of visiting diginitaries",
    "floor",
    "A mosiac of tiles forming a picture",
    "mosiac",
    "They form the offical seal of the lands",
  });
  
  clone_list = ({ 1, 1, "guard", bm+"/guard.c", 0 });
  ::reset(arg); 
  replace_program("room/room");
}
