inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
void reset(int arg) {
  short_desc = "Saferoom for members of the Fighters Guild";
  long_desc =
    "Opulent tapestries cover the walls here.  Rugs that seem to have "+
    "been spun from pure gold cover the floor.  Hanging over the "+
    "gilded fireplace is the insignia of the Fighters guild.  You feel "+
    "safe from members of all other guilds here.\n";
  set_light(1);
  dest_dir = ({
    br+"/tr-15.c","south",
  });
  items = ({
    "furniture",
    "Old, battered tables and wobbly chairs",
    "floor",
    "Floor of the guild room",
    "tapestries",
    "Tapestries showing great deeds",
    "rugs",
    "Rugs that have the seal of Bismarck on them",
    "insignia",
    "The insignia of the Fighters guild",
  });
  property=({ "no_teleport","no_fight","has_fire", });    
  ::reset(arg);
  replace_program("room/room");
}

