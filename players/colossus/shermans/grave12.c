/* Edited by Colossus 022694 */

inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "Northeastern corner of the graveyard";
    long_desc=
    "You arrive at the northeastern part of the graveyard. This place\n"+
    "does not resemble a graveyard as much as it resembles as junkyard\n"+
    "though. There is a vast amount of trash and tombstones lying shattered\n"+
    "around this place. The whole area is littered with useless items.\n"+
    "You are grateful that the stench is not so strong here, however.\n";
    items=({
      "items", "The useless items consist of general trash and shattered\n"+
      "tombstones",
      "trash", "The trash is mainly pieces of unwanted litter that is\n"+
      "unidentifiable now due to age",
      "tombstones", "These tombstones lie shattered and litter the area",
    });
    dest_dir=({
      "/players/sherman/grave9","south",
      "/players/sherman/grave11","west"
    });
    smell = "Thankfully this place smells better than the rest of the\n"+
    "graveyard.";
}
