inherit "room/room";


int _read(string str) {

    if(str!="milestone" && str!="stone") return 0;
    write("It reads:\n\t\tBeware of the dark powers that rule the Wastelands.\n\n");
    return 1;
}

reset(arg) {

    ::reset();
    set_light(1);
    short_desc="A path in Mythwood";
    long_desc="You are walking on a path in mythwood.\n" +
              "To the east and south the wastelands begin.\n" +
              "A milestone stands here.\n";
    dest_dir=({
		"players/bobo/krooms/wastelands/waste2","south",
		"players/bobo/krooms/wastelands/waste1","east",
		"players/bobo/krooms/mythwood/mythpath3","west",
             });
    items=({
            "milestone","It reads: Beware of the dark powers that rule the Wastelands",
            "stone","It has something written on it",
            "wastelands","The wastelands are very deserted and chill you too look at them",
          });
    clone_list = ({ 1, 1, "wnderer", "players/kelly/monster/wanderer", 0 });

}

void init() {
    ::init();
    add_action("_read","read");
}

