/* Edited by Colossus: 070994 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(0);
    short_desc = "Huge cave complex";
    long_desc=
    "This part of the cave is filled with the presence of a lesser\n\
evil. There are torn up corpses of less fortunates and around\n\
the room there are poles with decapitated heads as a warning\n\
to those who would brave this area.\n";
    items=({ 
      "cave", "Huge cave complex",
      "corpses", "The corpses have been eaten and ripped apart",
      "poles", "The poles have decapitated heads on them",
      "heads", "The heads are gross enough as it is but it looks as\n"+
      "though the eyes were torn out and eaten",
    });
    dest_dir=({
      "/players/sherman/hills/cave5","west",
      "/players/sherman/hills/cave7","down"
    });
    clone_list = ({1,8,"tiny demon","/players/sherman/hills/demont", 0});
    ::reset();
    replace_program("room/room");
}
