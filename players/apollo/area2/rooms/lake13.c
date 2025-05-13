

inherit "room/room";

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
        "players/apollo/area2/rooms/lake21", "north",
        "players/apollo/area2/rooms/lake12", "west",
        "players/apollo/area2/rooms/lake22", "northeast",
        "players/apollo/area2/rooms/lake06", "southwest",
           }); 

  items = ({
	"fish", "You see several schools of fish",
	"seaweed", "You see some green seaweed floating around you",
	"water", "The water is very clear and clean",
	"bottom", "You should look at the shore",
	"shore", "You see the shore to the south, east, and northwest. \n" +
		 "Perhaps you can swim in that direction",
	});

  move_object((clone_object("players/apollo/area2/monsters/dolphin")),
	this_object()); 

  clone_list = ({ 1, 3, "whale", "players/apollo/area2/monsters/whale", 0, });

  ::reset(arg);

}

  init() {
	::init();
	add_action("swim", "swim");
	}

  swim(str) {
    if (!str || str=="north" || str=="west" || str=="southeast" || 
	str=="northeast" || str=="southwest") {
        notify_fail("You cannot swim in that direction because the \n" +
  	 	    "shore is not in that direction! \n");
        return 0;
      }
    if (str=="south") {
	write("You start to swim southward towards the shore. \n");
	this_player()->move_player("south#/players/apollo/area2/rooms/shore07");
      }
    if (str=="east") {
	write("You start to swim eastward towards the shore. \n");
	this_player()->move_player("east#/players/apollo/area2/rooms/shore14");
      }
    if (str=="northwest") {
	write("You start to swim northwestward towards the shore. \n");
	this_player()->move_player("northwest#/players/apollo/area2/rooms/shore20");
      }
    return 1;
  }

