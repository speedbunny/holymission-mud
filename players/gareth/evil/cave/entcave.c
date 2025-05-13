
  inherit "room/room";

  reset(arg) {
    ::reset(arg);
    if(!arg) {

  set_light(1);
  
  short_desc = "Cave entrance";
  
  long_desc = 
	"You arrive at the base of a mountian. To the north the\n"+ 
	"rock climbs up a steep angle, and you can not see the top,\n"+ 
	"for it is hidden by the dense clod cover.  There is a faint\n"+ 
	"foul stench, that issues from a cave entrance to the east.\n"+ 
	"As you look into the cave all you see is darkness. The \n"+
	"twisted and oddly bloated trees give you an eerie sense of\n"+
	"uneasiness, perhaps you had better go back, while there's\n"+ 
	"still time.\n";
      
  items = ({
	"mountain", "You can't climb it stupid!",
	"trees", "They look twisted and evil",
	"cave", "A creepy looking cave, are you sure ya want to go in?",
    });

	smell = "The stench of death and evilness";

  dest_dir = ({
        "players/apollo/area2/rooms/mountain60", "south",
	"players/gareth/evil/cave/cave1", "east",
    });

  }
  }
