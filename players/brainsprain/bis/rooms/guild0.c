inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  short_desc = "Saferoom for members of the Adventurers Guild";
  long_desc = 
    "Old, battered tables and wobbly chairs are the only furniture in this "+
    "room.  Hanging over the dusty fireplace is the insignia of the "+
    "Adventurers guild.  A thick layer of dust covers the floor.  You "+
    "feel safe from members of all other guilds here.\n";
  set_light(1);
  items = ({
    "tables",
    "Old battered tables",
    "furniture",
    "Old, battered tables and wobbly chairs",
    "floor",
    "Floor of the guild room",
    "chairs",
    "wobbly and broken chairs",
    "fireplace",
    "A small fire burns to warm yourself by",
    "dust",
    "A thick layer of dust",
    "insignia",
    "The coat of arms of the Adventurers Guild",
  });
  
  property=({ "no_teleport","no_fight","has_fire", });   
  dest_dir = ({ br+"/tr-15.c","south", });
  ::reset(arg);  
  replace_program("room/room");
}
