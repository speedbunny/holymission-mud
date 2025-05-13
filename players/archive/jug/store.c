inherit "room/room";

reset(arg) {
  object iob;
	
  if (arg) return;
  set_light(1);
  short_desc = "A deposit room";
  long_desc = 
    "This is the deposit room for Jug`s workroom. All the objects he don`t need\n"+
    "in his workroom, were deposit here. Take that what you need.\n";
  
  dest_dir = ({
    "/players/jug/workroom", "home",
  });
  
  iob = clone_object("/players/jug/monster/gardener");
  move_object(iob, this_object());
}
