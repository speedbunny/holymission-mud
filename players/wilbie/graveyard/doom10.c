inherit "/room/room";
#include "/players/wilbie/def.h"

reset(arg){
if (!arg) {

set_light(1);
short_desc="Depths of hell";
long_desc=
"You have reached the innermost den of Sheankala.  You can feel her "+
"horrid presence to the north.\n";



items=({
"fire","It is the fire of hades",
"goddess","She is to the north, but it's too dark to see her",
"sheankala","She is north of here",


});

dest_dir=({
GPATH+"doom11","north",
GPATH+"doom9","south",


});
clone_list=({
  1,3,"narguhl","/players/wilbie/graveyard/monsters/narguhl",0,
});

}
::reset(arg); replace_program("/room/room");
}
