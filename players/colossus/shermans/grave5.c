/* Edited by Colossus 030194 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(1);
    short_desc = "Section of a graveyard with a wooden cross";
    long_desc=
    "While this section of the graveyard looks very much like the others,\n"+
    "something attracts your attention. It is not the tombstone markings of\n"+
    "graves rather than a rather simple wooden cross that marks a secluded\n"+
    "grave. For some reason, in this part of the graveyard, there is absolutely\n"+
    "no sound at all. There is a silence, one that can only be described as\n"+
    "overpowering. Even the sounds of your movement seem strangely muffled in\n"+
    "this area.\n";
    items=({
      "grave", "This particular grave is secluded and marked only by a wooden cross.\n"+
      "The person who is buried... or not buried here anymore must have\n"+
      "been quite poor. It appears undisturbed though",
      "cross", "A battered and rotting wooden cross which marks a modest grave",
    });
    dest_dir=({
      "/players/sherman/grave2","south",
      "/players/sherman/grave6","east",
      "/players/sherman/grave8","north",
      "/players/sherman/grave4","west"
    });
    smell = "Strangely enough there is no smell of death and decay here... you\n"+
    "ponder that fact but are happy enough to have some relief from the stench.";
}

status dig(){
    write(
      "While you proceed to dig up the grave you feel like a lowdown grave robber\n"+
      "and as you continue digging, the feeling gets worse and worse.\n"+
      "You press on, determined to unearth what lies beneath this patch\n"+
      "of land and at last you unearth the coffin. Opening the coffin you\n"+
      "expect to see an old and decayed corpse but to your utmost surprise\n"+
      "you see a fair maiden with skin as pale as snow dressed in tattered\n"+
      "but intact robes with a white rose clasped between her fingers on her\n"+
      "breast. The sight fills you with wonder but it also makes you feel so\n"+
      "very guilty at defiling the grave of one so beautiful. You immediately\n"+
      "close the coffin and bury her again, feeling more at peace with yourself\n"+
      "as you do so.\n");
    say((string)this_player()->query_name()+
      " digs and finds the body of beautiful maiden that is untouched by\n"+
      "time and decay. Her pale white hands clasp a white rose between her\n"+
      "breasts and she wears tattered but intact white robes. Feeling guilty,\n"+
      (string)this_player()->query_name()+" buries her again.\n");
    return(1);
}
