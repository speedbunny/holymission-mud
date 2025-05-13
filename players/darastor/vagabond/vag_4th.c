inherit "room/room";

void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc =  "Guild Jump to the 4th";
    long_desc =
    "You have entered the realm of the Vagabonds. To the north,\n"+
    "you see their Great Guild Hall.  Located here is a portal\n"+
    "which connects to the '4th' a place where time and realities\n"+
    "intersect.\n"+
    "\n";

    dest_dir = ({
      "/players/nylakoorub/guild/room",
      "north",
    });

    if(!present("portal")) {
	move_object(clone_object("/players/nylakoorub/4th/portalob"),
	  this_object());
    }

    items = ({
      "portal", "You glance into the portal and see a shady vision\n"+
      "of a vast void, as you look, you hear a depp god\n"+
      "like voice which says 'Lurk within to find the doorways\n"+
      "to places of different times and realities'",
    });

}

void init() {
    ::init();
    add_action("enter", "enter");
}


int enter(string arg) {
    string destroom;
    destroom = "/players/nylakoorub/4th/4th_vag";
    if(arg=="portal") {
	tell_room(destroom,
	  capitalize(this_player()->query_real_name())+
	  " emerges from the portal.\n");
	move_object(this_player(), destroom);
	tell_room(this_object(),
	  capitalize(this_player()->query_real_name())+
	  " enters the portal.\n");
	command("look", this_player());
    } else {
       write("Enter what?\n");
    }
    return 1;
}


