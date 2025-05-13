

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
        "players/apollo/area2/rooms/lake22", "south",
        "players/apollo/area2/rooms/lake29", "west",
        "players/apollo/area2/rooms/lake23", "southeast",
        "players/apollo/area2/rooms/lake21", "southwest",
           }); 

  items = ({
	"fish", "You see several schools of fish",
	"seaweed", "You see some green seaweed floating around you",
	"water", "The water is very clear and clean",
	"bottom", "You should look at the shore",
	"shore", "You see the shore to the north, east, and northwest. \n" +
		 "Perhaps you can swim in that direction",
	});

  clone_list = ({ 1, 4, "whale", "players/apollo/area2/monsters/whale", 0, });

  ::reset(arg);

}

  init() {
	::init();
	add_action("swim", "swim");
	}

  swim(str) {
    if (!str || str=="south" || str=="west" || str=="northeast" ||
	str=="southwest" || str=="southeast") {
        notify_fail("You cannot swim in that direction because the \n" +
  	 	    "shore is not in that direction! \n");
        return 0;
      }
    if (str=="north") {
        write("You start to swim northward towards the shore. \n");
	this_player()->move_player("north#/players/apollo/area2/rooms/shore38");
      }	 
    if (str=="east") {
	write("You start to swim eastward towards the shore. \n");
	this_player()->move_player("east#/players/apollo/area2/rooms/shore31");
      }
    if (str=="northwest") {
	write("You start to swim northwestward towards the shore. \n");
	this_player()->move_player("northwest#/players/apollo/area2/rooms/shore37");
      }
    return 1;
  }

