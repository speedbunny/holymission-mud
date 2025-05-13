/* Edited by Colossus 022494 */

#pragma strict_types

inherit "room/room";

void reset(int arg)
{
    if (arg) return;
    set_light(1);
    short_desc = "The dark crossroad";
    long_desc =
    "After for walking for some time, you arrive at a crossroads where\n"+
    "the paths lead north, east, south, and west. Towards the west looms\n"+
    "a tall dark castle while toward the east you see a dilapidated \n"+
    "where weird noises seem to come from. To the north there is a\n"+
    "crumbling shed which seems out of place for some reason. To the\n"+
    "south there is nothing of interest that is visible.\n";
    items = ({
      "castle", "An ominous looming castle with bats flying around the parapets",
      "tower", "A tower looking like a sharp, thin, black blade"
    });
    dest_dir = ({
      "/players/sherman/darkl3", "north",
      "/players/sherman/darkl9", "east",
      "/players/sherman/darkl1", "south",
      "/players/sherman/darkl4", "west"
    });
    clone_list = ({ 1, 1, "vampirelord", "/players/sherman/vampire2", 0 });
    ::reset();
    replace_program("room/room");
}

