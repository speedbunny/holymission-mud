inherit "room/room";

object mon;
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A rockpath";
    long_desc="You're on a path in the rocks.\n"+
      "To both sides the mountains raise high up into the sky.\n";

    dest_dir=({
	"players/bobo/krooms/mountains/rocks2","north",
	"players/bobo/krooms/mountains/plateau2","south",
   });
  if(!mon) { 
   mon=clone_object("obj/monster");
   mon->set_name("chamois"); 
   mon->set_race("goat");
   mon->set_size(3);
   mon->set_short("A chamois");
   mon->set_long("A chamois.\n");
   mon->set_level(6);
   mon->set_al(10);
   move_object(mon,this_object());
  }
}
