inherit "room/room";
#include "/players/unuscione/def.h"
#include "/players/unuscione/break_string.h"
object axe;
reset(arg){
 if(arg) return;
 set_light(0);
 short_desc="Dungeon of Hilo";
long_desc=break_string("The corridor turns here going north and west. "+
	         "This place is completly barren.\n",65);
items=({"corridor",long_desc,
         });
dest_dir=({KPATH+"room10","north",
	         KPATH+"room8","west",
            });
axe=CO("/players/unuscione/weapons/pickaxe");
MO(axe,TO);
}
