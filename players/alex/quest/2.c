inherit "/room/room";
reset(arg) {
    ::reset(arg);
    if (arg) return;
 
    set_light(1);
    short_desc = "A stone tunnel.";
    long_desc =
    "You are in the same marble halls. The room is characteristic of all the\n"+
    "other rooms, an atmosphere filled with energy. The hair on the back of\n"+
    "your arm stand out prominently due to the static electricity in the air.\n"+
    "Exits are to the east and west.\n";
 
    items=({
      "floor", "The floor is made of a tough white marble that's unbreakable",
 
    });
 
 
    dest_dir = ({
      "players/alex/quest/1","west",
      "players/alex/quest/3","east",
    });
}
 
