inherit "/room/room";
reset(arg) {
    ::reset(arg);   
    if (arg) return;
 
    set_light(1);
    short_desc = "A stone tunnel.";
    long_desc =
    "The feeling of power in this room seems stronger than before. To the\n"+
    "north you see a portal in the distance and to the east you feel\n"+
    "a wave of heat, the energy so tantalizing yet so dangerous.\n";
 
    items=({
      "portal", "A portal in the distance to the north. It looks very inviting",
      "energy", "Pure energy that fills you with ecstasy",
       
    });
 
 
    dest_dir = ({
      "players/alex/quest/7","north",
      "players/alex/quest/1","west",
      "players/alex/quest/4","east",
    });
}
 
