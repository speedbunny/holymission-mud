inherit "room/room";
#include "/players/brainsprain/bis/bisdef.h"
reset(arg) {
  short_desc = "Saferoom for members of the Vagabond's Guild";
   long_desc =
"Opulent tapestries cover the walls here.  Rugs that seem to have "+
"been spun from pure gold cover the floor.  Hanging over the "+
"gilded fireplace is the insignia of the Vagabond's guild.   You feel "+
"safe from members of all other guilds here.\n";
  set_light(1);
  dest_dir = ({
        br+"/tr-15.c","south",
});
   items = ({
    "tapestries","Tapestries showing great deeds",
    "rugs","Rugs that have the seal of Bismarck on them",
    "insignia","The insignia of the Vagabond's guild",
});

    property=({ "no_teleport","no_fight","has_fire", });   
                                    
  ::reset(arg);

    replace_program("room/room");
}

