inherit "room/room";

object mon;
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A rockpath";
    long_desc="You're on a path in the rocks.\n"+
      "To both sides the mountains raise high up into the sky.\n"+
      "To the north the falls down to a plain area and to south you see a suspension\nbridge over a deep valley.\n"; 

    dest_dir=({
	"players/bobo/krooms/mountains/plain3","north",
	"players/bobo/krooms/mountains/suspension","south",
	"players/bobo/krooms/mountains/plain3","down",
    });
    items=({
      "valley","You don't see the bottom of the valley",
      "plain","A small plain",
      "bridge","It's a suspension bridge"
    });
}
