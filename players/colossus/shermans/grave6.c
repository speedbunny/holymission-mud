/* Edited by Colossus 030194 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(1);
    short_desc = "Bridge across a small ditch";
    long_desc=
    "A stone bridge bridges the gap between the graveyard and a small plot of\n"+
    "land with a tiny thatched hut. The ditch used to be a drain of some sort\n"+
    "to drain water out of the ground when it rained but now it is nothing more\n"+
    "than a foul hole that breeds all sort of dirty insects. The bridge is made\n"+
    "of solid white rock and it still appears to be sturdy after all this time.\n"+
    "The hut, on the other hand, is falling apart as part of the roof has caved\n"+
    "in already.\n";
    items=({
      "bridge", "The bridge is solidly built of white rock and it can safely bring\n"+
      "you to the other side",
      "hut", "The hut is in shambles and part of the straw roof has caved in",
      "ditch", "The ditch is nothing more than an insect-breeding hole now",
      "hole", "The hole probably contains all sorts of foul insects and other gross\n"+
      "unimaginables. It would be best not to poke around in it",
    });
    dest_dir=({
      "/players/sherman/grave3","south",
      "/players/sherman/hut1","east",
      "/players/sherman/grave9","north",
      "/players/sherman/grave5","west"
    });
}
