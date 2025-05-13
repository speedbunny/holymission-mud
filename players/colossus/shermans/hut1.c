/* Edited by Colossus 030294 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(1);
    short_desc = "A small decrepit thatched hut";
    long_desc=
    "This hut must have belonged to the undertaker. There is a pile of\n"+
    "wood that must have been the remains of a chair and table. The whole\n"+
    "place is looted and vandalized. There is also evidence of a struggle\n"+
    "here as broken things lie all around and blood is splattered all over\n"+
    "one of the walls. There are tools of the trade belonging to an undertaker\n"+
    "lying on the ground. Most of them are broken now and the rest have no\n"+
    "use.\n";
    items=({
      "blood", "The blood is so old that it has turned brown. It is a most gruesome\n"+
      "sight and you rather not look it",
      "wood", "The wood is old and brittle now, not much use for anything but\n"+
      "kindling. This pile is the remains of a table and chair",
    });
    dest_dir=({
      "/players/sherman/grave6","west",
      "/players/sherman/hut2","north"
    });
}
