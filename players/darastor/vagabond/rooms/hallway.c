inherit "/room/room";
#define TP   this_player()




void reset(int arg){
    ::reset(arg);
    if(arg) return;
    set_light(1);
    short_desc = "Hallway of Time";
    long_desc =
    "You have entered the Hallway of Time.\n"+
    "This vast hallway seems to go on forever.  Along the walls are\n"+
    "portaits containing visons of the past and times to come.  Along \n"+
    "the arched ceiling is the timelines of the known world.\n"+
    "\n"+
    "You see the entrance to the great inner chambers of the Vagabond\n"+
    "Guild, Only the true keepers of time and space, may 'enter' it\n"+
    "\n";


    dest_dir = ({
      "/players/nylakoorub/guild/room", "south",
      "/players/nylakoorub/guild/rooms/inner/inner_room", "enter",
    });

    items = ({
      "walls", "The walls shimmer through the spectrum of the rainbow",
    });


    property = ({"no_fight", "no_steal", "no_fear", "no_sneak",
      "no_cleanup" });
}
void init() {
    ::init();
    add_action("enter_inner", "enter");
}

int enter_inner() {
    if(this_player()->query_guild() == 10 ||
      this_player()->query_immortal() ) {
	TP->move_player("enter#/players/nylakoorub/guild/rooms/inner/inner_room");
	return 1;
    } else {
	write("You are not member of this guild.\n");
	return 1;
    }
    return 1;
}

