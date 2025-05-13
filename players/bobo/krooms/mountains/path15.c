inherit "room/room";
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A path";
    long_desc="A path in the mountains. \n"+
      "To the north there is a strange forest.\n";

    dest_dir=({
	"players/bobo/krooms/mountains/wood1","north",
	"players/bobo/krooms/mountains/path14","south",
    });
    items=({
      "forest","A really strange forest",
    });
}
