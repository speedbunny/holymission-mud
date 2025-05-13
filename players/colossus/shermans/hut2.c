/* Edited by Colossus 030294 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    object sp;
    if (arg) return;
    set_light(1);
    short_desc = "Bedroom of the Undertaker's House";
    long_desc=
    "This is what remains of the bedroom of the undertaker. It is a modestly sized\n"+
    "room with a window overlooking the graveyard and the wooden corpse of a bed.\n"+
    "A decent sized armoire stands next to the window but has all the drawers\n"+
    "yanked out and looted. The roof of this room has a large hole which exposes\n"+
    "the room to the elements and the middle of the room's floor is rotted through\n"+
    "due to the moisture that has seeped in since this place is close to the river.\n";
    items=({
      "bed", "The bed is long gone and the wood is good for nothing",
      "armoire", "The armoire is a french-style cabinet with its drawers yanked out\n"+
      "and everything of value looted from it",
      "floor", "The middle of the room's floor is particularly hazardous as it is\n"+
      "rotted through",
      "window", "The window allows a view to the graveyard though who would want to\n"+
      "see it in this condition, you don't know",
      "roof", "The roof has a large hole which allows all sorts of things to come\n"+
      "through and ruin the room",
    });
    dest_dir=({
      "/players/sherman/hut1","south"
    });
    clone_list = ({1,1, "spectre", "/players/sherman/spectre", 0, 
      -1,1, "shovel", "/players/sherman/shovel", 0});
    smell = "This place smells really musty and dirty.";
    ::reset();
    replace_program("room/room");
}
