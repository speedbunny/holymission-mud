/* Edited by Colossus 022794 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(1);
    short_desc = "Death-filled graveyard";
    long_desc=
    long_desc = 
    "In this part of the graveyard are the usual graves and tombstones\n"+
    "but one that catches your eye in particular is a small grave and\n"+
    "an elegant tombstone with an iron cross atop of it that seems so\n"+
    "tarnished that it looks brown.\n";
    items=({
      "cross", "The iron cross is browned from rust and age",
      "grave", "The grave is small, it's about 4 feet by 2 feet, it\n"+
      "probably is the grave of a child",
    });
    dest_dir=({
      "/players/sherman/grave1","west",
      "/players/sherman/grave3","east",
      "/players/sherman/grave5","north"
    });
}

status dig(){
    write("You find nothing.\n");
    say((string)this_player()->query_name()+" digs and finds nothing.\n"); 
    return(1);
}
