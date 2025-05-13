/* Edited by Colossus 022794 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(1);
    short_desc = "Graveyard with a particularly big tombstone";
    long_desc=
    "Though the stench of death and decay is still very much on your mind\n"+
    "right now, there is something here that takes your mind away from that\n"+
    "rather unpleasant thought. Here in this part of the graveyard lies a\n"+
    "particularly huge tombstone. This area is sparse on vegetation and there\n"+
    "are a few claw marks around here.\n";
    items=({
      "grave", "The grave must belong to a rather large person judging form the size\n"+
      "of the tombstone",
      "tombstone", "The tombstone has something chiseled on it and wiping away\n"+
      "the dust, you read: In memory of an unfortunate thief who was\n"+
      "as dumb as to steal from a mage",
      "claw marks", "The marking on the ground definitely did not come from a\n"+
      "wild beast as you have not seen a living thing here yet",
      "marks", "THe marks on the ground definitely did not come from a\n"+
      "wild beast as you have not seen a living thing here yet",
    });
    dest_dir=({
      "/players/sherman/grave1","south",
      "/players/sherman/grave5","east",
      "/players/sherman/grave7","north"
    });
    smell = "Though the stench of death is still very strong, the thing that\n"+
    "draws your attention away from the smell is the presence of a huge\n"+
    "tombstone";
}

/* read function added because players got confused by the response
   of Cashimor's locket to 'read inscription'. Uglymouth 930905 */
void init(){
    ::init();
    add_action("read","read");
}

status read(string str){
    if(str!="inscription") return 0;
    write("It reads: Here rests Drago not in peace because he\n"
      + "stole money from a mage.\n");
    return 1;
}

status dig(){
    write("You find nothing.\n");
    say((string)this_player()->query_name()+" digs and finds nothing.\n");
    return(1);
}
