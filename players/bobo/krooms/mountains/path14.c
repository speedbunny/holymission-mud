inherit "room/room";
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A path";
    long_desc="A path in the mountains. \n";

    dest_dir=({
	"players/bobo/krooms/mountains/path15","north",
	"players/bobo/krooms/mountains/path13","southeast",
   });
}
