inherit "room/room";

#include "/players/skeeve/area.h"

reset(arg,DEST_DIRS) {
  ::reset(arg);  
  if (!arg) {
    set_light(1);
    short_desc = "Shore";
    long_desc = "You are standing on the ocean shore.\n"
            +"Huge waves roll towards the land.\n";
    smell="The air smells salty here";
    dest_dir=DEST_DIRS;
    items=({ 
        "land",  "There is a road on the land",
        "ocean", "The wild green ocean. Many fishes lives in it",
        "wave",  "It rolls exactly in your direction",
        "waves", "They roll and roll and roll and ....",
        "tide",  "The flood is on its highest level"
    });
  }
if (sizeof(dest_dir)) CASTLE->add_monster("fisher",this_object());
}

move(dir) {   
   if (!dir) dir=query_verb();
   return (this_player()->query_stay_ocean() && (dir=="west")) ? 
     ::move("east") : ::move(dir);
}
