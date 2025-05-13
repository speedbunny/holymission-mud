inherit "/room/room";

#include "/players/matt/defs.h"
#define PPATH "/players/arthur/mystuf/"
#include "/players/whisky/genesis/sys/break_string.h"

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc = "A Quiet Sitting Room";
  long_desc = break_string(
	"This is a quiet sitting room.  One may come here and converse "+
	"without the inconvenience of being bombarbed with shouts and "+
	"tells.  Comfortable chairs are arranged in no particular "+
	"order.  To the east several silk screens make up a wall. "+
	"To the south and west are archways stretching to the vaulted "+
	"ceiling.\n",65);

items = ({"screens","they appear to slide on tracks.\n",
	  "screen","They appear to slide on tracks.\n",
	  "chairs","They have been imported from the mainland\n",
	});
dest_dir=({PPATH+"conserv.c","south",
	   PPATH+"theater.c","west",
	});
property =({"has_fire"});
}

void init() {
  ::init();
  if(interactive(TP)) {
    add_action("rshad", "rshad");
    (CLONE(PPATH + "listenshad"))->start_shad(TP);
  }
add_action("_slide","slide");
}
  
_slide(str){
if(str=="east screen"){
TP->move_player("through the east screen#players/haplo/guild/enthall.c");
return 1;
}
if(str=="screen"){
TP->move_player("through the east screen#players/haplo/guild/enthall.c");
return 1;
}
else
write("Slide What?\n");
return 1;
}
int rshad() {
  object shad;
  shad = shadow(TP, 0);
  if(shad) {
    destruct(shad);
    write("Shadow dested.\n");
    return 1;
  }
  write("No shadow detected.\n");
  return 1;
}

void exit(object obj) {
  object shad;
  if(obj && interactive(obj)) {
    shad = shadow(obj, 0);
    if(shad) destruct(shad);
    TELL(obj, "DEBUG: Shadow dested.\n");
  }
}
