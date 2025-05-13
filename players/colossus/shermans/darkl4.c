/* Edited by Colossus 022494 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;

    set_light(1);
    short_desc = "Dark path";
    long_desc = 
    "The path you are traveling on is ridden with thorny rotten\n"+
    "bushes and sharp stones that hurt your feet. The path\n"+
    "is typical of this whole place. It is dark, almost hostile\n"+
    "with the obstacles it has, that hinder and slow your progress.\n";
    items=({
      "path","A small path with sharp stones, on each side there are some\n"+
      "dead bushes",
      "stones","Sharp black stones",
      "bushes","Some rotten bushes",
      "bush","A rotten bush"
    });
    dest_dir=({
      "/players/sherman/darkl2","east",
      "/players/sherman/darkl5","west"
    });
}
