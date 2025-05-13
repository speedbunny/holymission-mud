inherit "room/room";
reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc = "Top";
    no_castle_flag = 1;
    long_desc =
    "You are standing in the top of the tower.\n"+
    "Some light comes from small holes in the low ceiling.\n"+
    "The room is a complete circle without windows, but the light\n"+
    "from the holes is enough to look around\n"+
    "A thick pillar is carrying the ceiling\n";
    dest_dir = ({ "players/dice/quest/tower/to3","down"
    });


    items = ({
      "tower","A dark but not big tower",
      "light","Light coming from holes in the ceiling",
      "ceiling","The roof on the top of the tower with a few holes in it",
      "low ceiling","The roof on the top of the tower, you nearly hit your head to it",
      "holes","Three holes through which light is sparcely coming",
      "top","The top of the tower",
      "lightbeam","A small lightbeam coming from the ceiling",
      "ground","The ground you're standing on",
      "pillar","A pillar carrying the ceiling, preventing it from collapsing",
      "thick pillar","A pillar carrying the ceiling",
      "small holes","Three holes in the ceiling through which light sparcely coming",
      "hole one","A small hole in the ceiling emitting a small lightbeam",
      "hole two","A small hole in the ceiling emitting a small lightbeam",
      "hole three","A small hole in the ceiling emitting a small lightbeam",
      "hole 1","A small hole in the ceiling emitting a small lightbeam",
      "hole 2","A small hole in the ceiling emitting a small lightbeam",
      "hole 3","A small hole in the ceiling emitting a small lightbeam",
      "first hole","A small hole in the ceiling emitting a small lightbeam",
      "second hole","A small hole in the ceiling emitting a small lightbeam",
      "third hole","A small hole in the ceiling emitting a small lightbeam",

    });

    smell = "The air is a bit dull here.";
}
init(){  
    ::init(); 
    add_action("_search","search");
}
_search(str){
    if(!str){
	notify_fail("Search what ?\n");
	return 0;
    }
    if(str=="hole one"||str=="hole three"||str=="hole 1"||str=="hole 3"||
      str=="first hole"||str=="third hole"){
	if(!this_player()->query_frog()){
	    write("Your hand is too big to search this hole\n");
	    return 1;
	}
	write("You search around in the hole, but find nothing.\n");
	return 1;
    }
    if(str=="hole two"||str=="hole 2"||str=="second hole"){
	if(!this_player()->query_frog()){
	    /* Galadriel: changed 'the' to 'this' to make it equal to hole 1,3 */
	    write("Your hand is too big to search this hole\n");
	    return 1;
	}
	write("You search the hole and find a small lever hidden in it\n");
	/* Galadriel: Give player the extra action */
	add_action("_pull","pull");
	items += ({ "lever","A small lever hidden in the hole",
	});
	return 1;
    }
    write("Search what ?\n");
    return 1;
}

_pull(str){
    if(!str){
	notify_fail("Pull what ?\n");
	return 0;
    }
    if(str=="lever"||str=="lever in hole"){
        if(present("dinges",this_player())){
	    notify_fail("You pull the lever, but nothing seems to happen\n");
	    return 0;
	}
	  move_object(clone_object("players/dice/quest/tower/dinges"),this_player());
	  return 1;
      }
    }
