inherit "/room/room";
#include "/players/wilbie/def.h"

reset(arg){
if(arg)return;

set_light(1);
smell="You can smell the scent of death.";

short_desc="A strange alcove";
long_desc=
"You have entered an alcove which holds a rather grisly scene.  A young "+
"priestess of Sheankala lies strapped to a wooden table, her body torn to "+
"pieces.  The dried blood covering her and the table would indicate that she "+
"has been here for a long time, as would the many flies and the awful smell "+
"that permeates the room.  A small archway leads further into some darkened "+
"hallway, and to the south is the dungeon of the cathedral.  A brief message "+
"has been scrawled on the table in the young girls blood.  In the corner "+
"of the room sits a small box, also covered in dry blood.\n";

items=({
"blood","It is all over the place",
"girl","She was rather beautiful until she was dismembered",
"message","You could probably read the message",
"table","It is a torture rack of some kind",
"archway","It leads off to the north",
"flies","They are common when rotting corpses are around",
});

dest_dir=({
GPATH+"hell5","south",
CPATH+"mainhall","north",
});

clone_list=({
1,1,"box","/players/wilbie/citadel/eq/box",0,
-1,1,"parchment","/players/wilbie/citadel/eq/parchment",0,
});

::reset(arg);
}

void init(){
   ::init();
             add_action("read","read");
           }

int read(string str){
    if(str=="message"){
    write("This woman spoke heresy against Sheankala!\n");
    return 1;
    }
notify_fail("Read what?\n");
return 0;
}
