

inherit "room/room";

object whale;
object dolphin;

reset(arg){        
  if(arg) return;
  set_light(1);

  short_desc = "A clear dark blue lake";

  long_desc = 
	"You are somewhere in a clear dark blue lake. All around you, you \n" +
	"see small fish swimming around. You begin to wonder where the big \n" +
	"fish are in this lake. You also see large amounts of seaweed floating \n" +
	"in this lake offering some cover for small prey such as yourself. As \n" +
	"you look at the bottom of the lake you can make out what way the \n" +
	"shore is from where you are. \n";
	
  dest_dir = ({
        "players/apollo/area2/rooms/lake12", "north",
        "players/apollo/area2/rooms/lake13", "northeast",
        "players/apollo/area2/rooms/lake11", "northwest"
           }); 

  items = ({
	"fish", "You see several schools of fish",
	"seaweed", "You see some green seaweed floating around you",
	"water", "The water is very clear and clean",
	"bottom", "You should look at the shore",
	"shore", "You see the shore to the south, east, and the west.\n" +
		 "Perhaps you can swim in that direction",
	});

  move_object((clone_object("players/apollo/area2/monsters/whale")),
	this_object());
  move_object((clone_object("players/apollo/area2/monsters/dolphin")),
 	this_object());

}

  init() {
	::init();
	add_action("swim", "swim");
	}

  swim(str) {
    if (!str || str=="north" || str=="northeast" || str=="southeast" ||
	str=="southwest" || str=="northwest") {
        notify_fail("You cannot swim in that direction because the \n" +
  	 	    "shore is not in that direction! \n");
        return 0;
      }
    if (str=="south") {
	write("You start to swim southward towards the shore. \n");
	this_player()->move_player("south#/players/apollo/area2/rooms/shore01");
      }
    if (str=="east") {
	write("You start to swim eastward towards the shore. \n");
	this_player()->move_player("east#/players/apollo/area2/rooms/shore07");
      }
    if (str=="west") {
	write("You start to swim westward towards the shore. \n");
	this_player()->move_player("west#/players/apollo/area2/rooms/shore05");
      }
    return 1;
  }

