inherit "/room/room";
#include "/players/wilbie/def.h"

reset(arg){
if (!arg) {

set_light(1);
short_desc="Depths of hell";
long_desc=
"You shouldn't be here.  This room is used to bring Narguhl's into the "+
"fight with Sheankala at a more moderate pace.  If you're a player, "+
"you're somehow cheating.  If you're a wiz, feel free to sit here and "+
"do whatever...\n";






dest_dir=({
GPATH+"doom6","west",


});
clone_list=({
  1,3,"narguhl2","/players/wilbie/graveyard/monsters/narguhl2",0,
});

}
::reset(arg); replace_program("/room/room");
}
