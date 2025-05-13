

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
        "players/apollo/area2/rooms/lake00", "north",
        "players/apollo/area2/rooms/lake00", "south",
        "players/apollo/area2/rooms/lake00", "east",
        "players/apollo/area2/rooms/lake00", "west",
        "players/apollo/area2/rooms/lake00", "northeast",
        "players/apollo/area2/rooms/lake00", "southeast",
        "players/apollo/area2/rooms/lake00", "southwest",
        "players/apollo/area2/rooms/lake00", "northwest"
           }); 

  items = ({
	"fish", "You see several schools of fish",
	"seaweed", "You see some green seaweed floating around you",
	"water", "The water is very clear and clean",
	"bottom", "You should look at the shore",
	"shore", "You see the shore to the < DIR >. Perhaps you can \n" +
		 "swim in that direction",
	});

  move_object((clone_object("players/apollo/area2/monsters/dolphin.c")),
	this_object());
 
}

  init() {
	::init();
	add_action("swim", "swim");
	}

  swim(str) {
    if (!str || str=="north" || str=="south" || str=="east" || 
	str=="west" || str=="northeast" || str=="southeast" ||
	str=="southwest" || str=="northwest") {
        notify_fail("You cannot swim in that direction because the \n" +
  	 	    "shore is not in that direction! \n");
        return 0;
      }
    if (str=="north") {
        write("You start to swim northward towards the shore. \n");
	this_player()->move_player("north#/players/apollo/area2/rooms/shore00");
      }	 
    if (str=="south") {
	write("You start to swim southward towards the shore. \n");
	this_player()->move_player("south#/players/apollo/area2/rooms/shore00");
      }
    if (str=="east") {
	write("You start to swim eastward towards the shore. \n");
	this_player()->move_player("east#/players/apollo/area2/rooms/shore00");
      }
    if (str=="west") {
	write("You start to swim westward towards the shore. \n");
	this_player()->move_player("west#/players/apollo/area2/rooms/shore00");
      }
    if (str=="northeast") {
	write("You start to swim northeastward towards the shore. \n");
	this_player()->move_player("northeast#/players/apollo/area2/rooms/shore00");
      }
    if (str=="southeast") {
	write("You start to swim southeastward towards the shore. \n");
	this_player()->move_player("southeast#/players/apollo/area2/rooms/shore00");
      }
    if (str=="southwest") {
	write("You start to swim southwestward towards the shore. \n");
	this_player()->move_player("southwest#/players/apollo/area2/rooms/shore00");
      }
    if (str=="northwest") {
	write("You start to swim northwestward towards the shore. \n");
	this_player()->move_player("northwest#/players/apollo/area2/rooms/shore00");
      }
    return 1;
  }

