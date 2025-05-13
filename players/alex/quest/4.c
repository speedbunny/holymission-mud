inherit "room/room";
reset(arg) {
    if (arg) return;
 
    set_light(1);
    short_desc = "A stone tunnel.";
    long_desc =
    "The heat is much more intense in this room. The source of the heat seems\n"+
    "to emanate from the portal to the south. You feel totally engulfed\n"+
    "in heat energy but you strangely enjoy it even though you realize the\n"+
    "danger of staying in such an environment for too long.\n";
    items=({
      "portal",
      "A portal that burns with heat",
 
    });
 
    dest_dir = ({
      "players/alex/quest/fire","south",
      "players/alex/quest/3","west",
      "players/alex/quest/8", "north",
    });
}
 
 
