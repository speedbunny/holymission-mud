 inherit "room/room";
#include "/players/tatsuo/def.h"
#include "/players/tatsuo/break_string.h"

object blob;
  reset(arg)
{
  if(arg) return;

   set_light(0);
short_desc="Cave of the Serpent";
    long_desc= break_string(
     "You are in the lair of a gelatinous blob. It's smell is overpowering."+
     "You can see piles of bones stacked in a corner, dinner for the blob. "+
     "The lair is very dirty and covered in refuse. There are large grooves "+
     "all over the lair from the blobs acid.\n",65);
    items=({"walls","The walls are a smooth, gray, rock. They appear to be granite",
   "floor","The floor is filthy covered with bones and scum.",
   "bones","Past mals for the blob no doubt.",
           "bone","That might be yours if your not careful"});

dest_dir=({CPATH+"c43","south"});
property=({"no_steal"});
 if(!blob)
   blob=clone_object("/players/tatsuo/ishikawa/monsters/blob");
   move_object(blob, this_object());
}
