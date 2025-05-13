inherit "/room/room";
#include "/players/wilbie/def.h"

reset(arg){
if(arg)return;

smell="You smell old dust.";
set_light(1);

short_desc="In a mystical room";
long_desc=
"The room lights up mysteriously when you enter.  A strange circle is drawn "+
"in blood in the center of the floor, and arcane runes of power are "+
"etched everywhere.  There is a feeling of great evil in this place, and "+
"of great power as well.\n";

items=({
"circle","It is a circle drawn in blood, very OLD blood",
"runes","You might be able to read them, but you might not want to",
});

dest_dir=({
CPATH+"entrance","south",
});

::reset(arg);

}

void init(){
   ::init();

   add_action("read","read");
   add_action("kneel","kneel");

           }

int read(string str){ 
    if(str=="runes"){
    write("You feel like that's a very bad idea.\n");
    return 1;
    }
notify_fail("Read what?\n");
return 0;
}

int kneel(){
    write("You feel reality shift.\n"+
          "Your surroundings blur.\n"+       
          "Suddenly, you are elsewhere.\n");
    this_player()->move_player("somewhere...",CPATH+"inner1");
    return 1;
    }
