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
      "players/kelly/rooms/mountains/rocks3","west",
      "players/kelly/rooms/mountains/rocks1","south",
   });
  if(!mon) { 
   mon=clone_object("obj/monster");
   mon->set_name("marmot"); 
   mon->set_race("marmot");
   mon->set_size(2);
   mon->set_short("A marmot");
   mon->set_long("A marmot.\n");
   mon->set_level(3);
   mon->set_al(50);
   move_object(mon,this_object());
  }
}
