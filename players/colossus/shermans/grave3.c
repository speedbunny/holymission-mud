/* Edited by Colossus 022794 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(1);
    short_desc = "In a part of a graveyard with an open grave";
    long_desc=
    "This part of the graveyard has several tombstones that are\n"+
    "shattered and one of the tombstones looks to be totally pulled\n"+
    "out of the ground and shattered as if with a tremendous force.\n"+
    "The grave under the tombstone is also open and all that is left\n"+
    "is a gaping hole.\n";
    items=({
      "grave", "The grave is open and there are claw marks around\n"+
      "it that suggest that someone or something has dug\n"+
      "it up on purpose",
      "hole", "All that is left of the grave is a dark gaping hole.\n"+
      "Upon closer inspection you realize that the coffin was\n"+
      "broken from the inside",
    });
    dest_dir=({
      "/players/sherman/grave2","west",
      "/players/sherman/grave6","north"
    });
    smell = "The graveyard reeks of dead and decaying things.";
}

status dig(){
    write("You dig and find an open grave.\n");
    return 1;
}
