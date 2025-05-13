#define NAME "morrolan"
#define RLN this_player()->query_real_name()
#define CNAME   capitalize(NAME)

inherit "room/room";

// This procedure is called periodically to check for monsters
//    which need to be replaced or other values that need
//    to be reset.

int shield;

void reset(int arg) {

// Here you call the the reset in the inherited "room/room"
    ::reset(arg);

// First we need some light in here
    set_light(1);

// Then lets set a short description in case we are in brief-mode
    short_desc=CNAME + "'s workroom",

// Now the long standard room description
//    change this to fit your style
    long_desc=
"          Welcome to Morrolan's Workroom!!\n"+
"This is Morrolan's workroom.  There's not much here besides a desk and a light.";

// We need some exits too ... lets set the destination directions
    dest_dir=({
               "room/post", "post",
               "room/church", "church",
               "room/adv_guild", "guild", 
               "players/matt/newworld/city/rooms/votebooth", "vote",
               "players/redsexy/workroom", "red",
              });

// Item descriptions can be placed in here
    items=({ 
            "desk","A large oak desk",
		"walls","Navy blue walls with nothing on them",
		"light","A small lamp sits on the desk",
          });

// Properties can be set like the following
    property = ({
                 "no_teleport","no_sneak","no_steal","no_snoop",
               });

//    The replace program will keep the room updated
//    without further function calls
    replace_program("room/room");
}

/********** You can place add_actions in here for special actions************/
init() {
    ::init();
    add_action("set_shield","shield",0);
}

set_shield(str sh)
	{
	  if (this_player()->query_real_name != "morrolan") return;
	  if (!sh)
		 { 
  if (shield = 1)
		  write("The shield is up.\n");
		  write("The shield is down.\n);
		  return;
		 }
	  if (sh == "on")
		{
		 write("You turn the shield on.\n);
		 say(CNAME+" turns on the shield.\n);
		 shield = 1;
		 return 1;
		}
	
	  if (sh == "off")
		{
		 write("You turn the shield off.\n);
		 say(CNAME+" turns off the shield.\n);
		 shield = 0;
		 return 1;
		}
	}

check()
  {
	if(shield && (RLN != "morrolan") && (RLN != "redsexy"))
	  {
	    write("Genius at work. Please come back later.\n");
	    say(this_player()->query_name()+" hath tried to disturb thee!\n);
    move_object(this_player(),"/players/"+RLN+"/workroom");
	    return 1;
	  }
  }
	
