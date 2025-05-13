inherit "room/room";

reset(arg){
 if(!arg){


   set_light(0);
   short_desc = "Duegar cavern";
   long_desc = 
"You are standing in a large open cavern. Stone walls are rough with an "+
"undetermined structure.  The west and musty smells fill the cavern.\n";

   smell = "It is wet and musty.";

   dest_dir = ({"players/airborne/new/path3", "north" });

   items = ({"walls", "The walls of the cavern are wet, musty, and rough. "+
			"You might be able to climb the rough surface", });

    if(!present("stone_horse", this_object())){
	object uni;
	uni = clone_object("players/airborne/obj/uni_stat");
 	move_object(uni, this_object());
	return 1;
	}

	}
}
