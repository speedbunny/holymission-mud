inherit "room/room";

object mon;
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A rockpath";
    long_desc="You're on a path in the rocks.\n"+
      "To three sides the mountains raise high up into the sky.\n"+
      "The path ends here.\n";  /* yet */

    dest_dir=({
	"players/bobo/krooms/mountains/rocks4","northeast",
    });

}
