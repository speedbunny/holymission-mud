inherit "/room/room";
#include "/players/wilbie/def.h"
reset(arg){
if(!arg) {
set_light(0);
short_desc="A narrow passage";
long_desc=
"You are squeezed into a vertical passage of solid rock.  Only small "+
"outcroppings keep you from plummeting down to whatever lies below. "+
"A cold wind seems to emanate from below you.\n";
items=({"rock","It looks like granite",
        "passage","A narrow passage leading up and down",
        "wind","It looks like wind",
      });
dest_dir=({
GPATH+"lower2","up",
GPATH+"doom1","down",
});

}
::reset(arg); replace_program("/room/room");
}
