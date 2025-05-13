inherit "room/room";

object chest;

recalc_power_level() { return 45; }

reset(arg) {

  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc="Mage Chamber";
    long_desc=
"The Mage Chambers. It's a comfortable decorated room with the flair of a\n" +
"very old library. Next to the east wall you can see a big desk. In the\n" +
"middle of the room are a table and some restful chairs. All the walls are\n"+
"covered with shelves. You can see some very old books standing in the shelves.\n";
    dest_dir=({ "players/llort/guild/tower/hallway","south" });
    items=({ "desk","The surface of the desk is coverd with lots of books. "+
                    "They mean nothing to you",   
	     "table","A table with beautiful carvings",
	     "shelf","The shelves are filled with books",
	     "door","The door leads out to the hallway",
	     "books","The books are very old and VERY dusty", 
	     "chairs","They look very comfortable. Maybe you should try" +
		      " to rest in one of them" });
   chest=clone_object("obj/container");
   chest->set_weight(0);
   chest->set_max_weight(100);
   chest->set_name("dancers chest");
   chest->set_alt_name("chest");
   chest->set_long("This chest can only be unlocked by dancer.\n");
   chest->set_closed(1);
   chest->set_can_get(0);
/*
   call_other("players/llort/test/vorpal_sw","???");
   move_object(find_object("players/llort/test/vorpal_sw"),chest);
   move_object(chest,this_object());
*/
  }
}

init() {
  ::init();

  add_action("sit","sit");
  add_action("unlock","unlock");
  add_action("lock","lock");
}

unlock(arg) {
  if(arg=="chest" || arg=="dancers chest") { 
    if(this_player()->query_real_name()=="dancer") {
      if(chest) chest->set_can_close(1);
      write("You hear a KLICK.\n");
      return 1; 
    } else {
      write("Only Dancer can unlock this chest.\n");
      return 1;
    }
  }
}

lock(arg) {
  if(arg=="chest" || arg=="dancers chest") { 
    if(this_player()->query_real_name()=="dancer") {
      if(chest) chest->set_can_close(0);
      write("You hear a KLICK.\n");
      return 1; 
    } else {
      write("Only Dancer can lock this chest.\n");
      return 1;
    }
  }
}

sit(str) {
  if((str=="down") || (str=="chair")) {
    write("There are no free seats.\n");
    return 1;
  }
}
