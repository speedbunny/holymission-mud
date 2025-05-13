

inherit "room/room";

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
        "players/apollo/area2/rooms/lake30", "north",
        "players/apollo/area2/rooms/lake23", "east",
        "players/apollo/area2/rooms/lake21", "west",
        "players/apollo/area2/rooms/lake13", "southwest",
        "players/apollo/area2/rooms/lake29", "northwest"
           }); 

  items = ({
	"fish", "You see several schools of fish",
	"seaweed", "You see some green seaweed floating around you",
	"water", "The water is very clear and clean",
	"bottom", "You should look at the shore",
	"shore", "You see the shore to the south, northeast, and the \n" +
		 "southeast. Perhaps you can swim in that direction",
	});

}

  init() {
	::init();
	add_action("swim", "swim");
	}

  swim(str) {
    if (!str || str=="north" || str=="east" || str=="west" ||
	str=="southwest" || str=="northwest") {
        notify_fail("You cannot swim in that direction because the \n" +
  	 	    "shore is not in that direction! \n");
        return 0;
      }
    if (str=="south") {
	write("You start to swim southward towards the shore. \n");
	this_player()->move_player("south#/players/apollo/area2/rooms/shore14");
      }
    if (str=="northeast") {
	write("You start to swim northeastward towards the shore. \n");
	this_player()->move_player("northeast#/players/apollo/area2/rooms/shore31");
      }
    if (str=="southeast") {
	write("You start to swim southeastward towards the shore. \n");
	this_player()->move_player("southeast#/players/apollo/area2/rooms/shore15");
      }
    return 1;
  }

