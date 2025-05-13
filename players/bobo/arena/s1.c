inherit "room/room";


reset (arg) {
    if (arg) return;
    clone_list=({
      1, 2, "guard","players/bobo/monsters/gguard", 0,
      2, 1, "peasant","players/bobo/monsters/peasant", 0,
    });
    ::reset (arg);
    set_light (1);
    short_desc="In the stands.";
    long_desc=
    "You are at the southernmost part of the collesium.  Here most of\n"+
    "the crowd have gone in search of safer vantage points to watch the\n"+
    "fighting going on in the arena.  A couple have remained to see\n"+
    "how you will fare against the guard post that is here.\n";
    dest_dir=({
      "players/bobo/arena/s2.c","northeast",
      "players/bobo/arena/s12.c","northwest",
    });
    items=({
      "collesium","The large structure is currently housing a large, very full arena",
      "crowd","Loud and vicious but utterly uninterested in engaging in a fight themselves",
      "guard post","There isn't actually a guard post here, just a place for guards to stand",
      "post","There isn't actually a guard post here, just a place for guards to stand",
    });
    replace_program("room/room");
}
