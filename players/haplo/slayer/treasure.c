inherit "room/room";
#include "/room/orc/orc.h"

object shaman;
void reset(int arg) {
   ::reset(arg);
  set_light(1);
  short_desc="The orc treasury";
  long_desc=
       ("You have entered the orc temple where the orcs practice their brutal \n"+
        "and horrific religion.  There is an altar in the center of the room \n"+
       "covered in blood and gore. The walls have terrifying pictures carved \n"+
        "into the stone. It is dimly lit and you see what appears to be blood \n"+
      "dripping from the mouths of two monstrous idols.\n");
  dest_dir=({
         ORC+"fortress", "south",
  });
  items=({
        "altar","It is made of a black rock and has what appears to be fresh blood on it",
        "pictures","It is to horrific to describe",
         "here", "Here, right here, duh",
         "entrance", "The entrance to the orc fortress",
         "fortress", "The orc fortress",
         "blood", "Red blood",
         "red", "Red blood",
       "idols","They are the gods of the orcs",
         "treasury","Treasury of skulls",
         "treasure", "Treasure of skulls",
  });
  smell="It smells like blood and guts.\n";
  shaman=clone_object("/players/haplo/slayer/obj/shaman");
 move_object(shaman,this_object());
} 
