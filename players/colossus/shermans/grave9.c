/* Edited by Colossus 030294 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(1);
    short_desc = "Section of the graveyard with a small tombstone";
    long_desc=
    "You stand in front of a grave with a small tombstone. The rest of the\n"+
    "graveyard is silent except for the sounds of shuffling that seem to\n"+
    "come in quite a number of directions. Unsure as to what the shuffling is\n"+
    "caused by you decide to continue with caution. The tombstone in front of\n"+
    "you has something chiselled into it that reads: Dear Amy, I will never\n"+
    "forget you. You have brought me life.\n";
    items=({
      "tombstone", "The small tombstone reads: Dear Amy, I will never forget you.\n"+
      "You have brought me life",
      "grave", "The grave is untouched and the remains of flowers lies on the grave",
    });
    dest_dir=({
      "/players/sherman/grave6","south",
      "/players/sherman/grave12","north",
      "/players/sherman/grave8","west"
    });
}

status dig(){
    write("You find nothing.\n");
    say((string)this_player()->query_name()+" digs and finds nothing.\n");
    return(1);
}
