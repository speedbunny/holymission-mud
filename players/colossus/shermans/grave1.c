/* Edited by Colossus 022694 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(1);
    short_desc = "Dark entrance heading into places unknown";
    long_desc =
    "Toward the north and east come the stench of decay. Great\n"+
    "slabs of stone lie shattered or overrun by mildew and fungus\n"+
    "towards the northern part of this area. From what you see you\n"+
    "conclude that this is a graveyard. Though you are not in the\n"+
    "graveyard you receive chills through your spine. The dead are\n"+
    "there and they are waiting for warm flesh to feast upon that's\n"+
    "for sure. An old battered sign outside the graveyard reads:\n"+
    "e ter a  y  r own r sk.\n";
    items=({
      "stone", "Those stones are definitely tombstones but as to who\n"+
      "or what lie beneath them, you prefer not to find out",
      "sign", "The old sign's wood is half rotten already",
      "mildew", "The mildew covers the tombstones",
      "fungus", "The mushrooms growing around the tombstones is\n"+
      "an unpleasant sight",
      "dead", "There are no dead in sight yet, but just you wait...",
    });
    dest_dir=({
      "/players/sherman/tunnel2","west",
      "/players/sherman/grave4","north",
      "/players/sherman/grave2","east"
    });
    smell = "The smell of stench and decay pervade this area.";
}
