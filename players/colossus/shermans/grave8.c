/* Edited by Colossus 030294 */

#pragma strict_types

inherit "room/room";

void reset(int arg){
    if (arg) return;
    set_light(1);
    short_desc = "Rather empty section of the graveyard";
    long_desc=
    "In this section of the graveyard it appears that no one has been\n"+
    "buried here yet, and thus, the brief relief from the stench. There\n"+
    "are open holes everywhere that are waiting for new residents and\n"+
    "a few gnarled and twisted trees grow around here. This might be one\n"+
    "of the places in the graveyard that might be safe for the time being.\n";
    items=({
      "holes", "These holes are open and they almost seem to invite you to\n"+
      "take up your permanent residency in them",
      "graves", "Empty graves waiting for new residents. You care not to apply\n"+
      "for a permanent home here",
      "trees", "The trees are gnarled and twisted but they are still the few\n"+
      "living things in this graveyard",
    });
    dest_dir=({
      "/players/sherman/grave5","south",
      "/players/sherman/grave9","east",
      "/players/sherman/grave11","north",
      "/players/sherman/grave7","west"
    });
    smell = "The air smells stale and dusty but at least it doesn't smell bad.";
}

status dig(){
    write("The graves are empty, why dig more new graves?\n");
    say((string)this_player()->query_name()+" refrains from digging "+
      "after seeing that all the graves are empty.\n");
    return(1);
}
