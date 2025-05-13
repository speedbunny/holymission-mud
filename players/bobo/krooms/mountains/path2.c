inherit "room/room";
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A path";
    long_desc="A path in the mountains. To the south the path falls down to a uninviting\n"+
      "area. You can see the magic swamps there. You shiver from the cold that runs \n"+
      "down your nack, when look at them.\n";

    dest_dir=({
	"players/bobo/krooms/mountains/path1","south",
	"players/bobo/krooms/mountains/path3","notheast",
   });
}
