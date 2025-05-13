

inherit "room/room";

reset(arg){::reset(arg);
    if (arg) return;

    set_light(1);
    no_castle_flag = 1;

    short_desc = "Village";
    long_desc =
    "You are in the northernmost place in the village.\n"+
    "South from here you see a strange looking tree \n"+
    "standing in the middle of a large open plain. \n"+
    "You can see its leaves hanging to the ground here, keeping you in the shadows.\n";

    dest_dir = ({
      "players/dice/rooms/vill12","south",
      "room/shore/s07","north"
    });

    items =({
      "tree","A strange looking tree standing in the middle of the plain south of here",
      "plain","A large open plain",
      "village","A coalminer village",
      "large tree","A strange looking tree, standing in the middle of the plain south of here",
      "leaves","Strange looking leaves"
    });


    smell = "The smell of fresh woods fills the air \n";

}
init(){
    ::init();
    if (this_player()->query_guild() == 8 ){
	write("You see a strange portal hanging here in thin air.\n");
	items += ({ "portal","A strange portal hanging in thin air.\n"+
	  "Seems that only ninja can see and enter it.\n"+
	  "Remember that this portal can be entered only when only\n"+
	  "ninjas are in this room.\n"+
	  "Your guild does not allow other players to use this portal",
	});
	add_action("_enter","enter");
    }
   else{
    items -= ({ "portal","You don't see that here", });
}
}
_enter(str){
    if(!this_player()->query_guild() == 8 ){
	notify_fail("What ?\n");
	return 0;
    }
    if((!str)|| (!str == "portal")){
	notify_fail("Enter what ?\n");
	return 0;
    }
    notify_fail("Naaah...what was dragon airways coded for ?\n");
    return 0; /* to make dragon airways popular MUZMUZ */
}

