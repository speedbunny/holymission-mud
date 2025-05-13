inherit "room/room";


reset(arg) {

    set_light(1);
    no_castle_flag=1;
    short_desc="A path in Mythwood";
    long_desc="You are walking on a path in Mythwood.\n" +
              "To the west a bridge leads over the hazardous Quiet River.\n";
    dest_dir=({
		"players/bobo/krooms/mythwood/mythpath2","east",
		"players/bobo/krooms/mythwood/bridge","west",
             });
    items=({
            "bridge","It's made of wood and appears sturdy",
          });
    ::reset();
    replace_program("room/room");
}

