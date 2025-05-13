

inherit "room/room";

reset(arg){        
  if(arg) return;
  set_light(1);

  short_desc = "A deep thick forest on the edge of a foggy lake";

  long_desc = 
	"This is the dark forest, that seems to surround a very foggy \n" +
	"lake. You wonder if you will ever make it out of the forest \n" +
	"alive. You begin thinking of what draws you to explore a forest \n" +
	"that appears to be so peaceful and yet serves absolutely no \n" +
	"purpose at all. This alone urges you to explore it further. \n";

  dest_dir = ({
        "players/apollo/area2/rooms/forest39", "north",
        "players/apollo/area2/rooms/forest32", "east",
        "players/apollo/area2/rooms/shore24", "southeast",
        "players/apollo/area2/rooms/shore38", "northwest"
           }); 

  items = ({
	"forest", "You see large green pine trees all around you",
	"air", "You smell the fresh fragrance of pine needles",
	"ground", "The ground is covered in old brown pine needles",
	"lake", "You see a lake covered in a dense fog that prevents you \n" +
		"from seeing very far to your south, west and southwest. \n" +
		"Perhaps you should investigate the lake a little closer \n" +
		"by swimming in that direction",
	});

  smell = "You smell the fresh fragrance of pine needles";

  clone_list = ({ 1, 2, "cancer", "players/apollo/area2/monsters/cancer", 0, });

  ::reset(arg);

}

  init() {
	::init();
	add_action("swim", "swim");
	}

  swim(str) {
    if (!str || str=="north" || str=="east" || str=="northeast" || 
	str=="southeast" || str=="northwest") {
        notify_fail("You cannot swim in that direction because the \n" +
  	 	    "lake is not in that direction! \n");
        return 0;
      }
    if (str=="south") {
	write("You start to swim southward out into the lake. \n");
	write("You can see much clearer now that you are in the lake. \n");
	this_player()->move_player("south#/players/apollo/area2/rooms/lake23");
      }
    if (str=="west") {
	write("You start to swim westward out into the lake. \n");
	write("You can see much clearer now that you are in the lake. \n");
	this_player()->move_player("west#/players/apollo/area2/rooms/lake30");
      }
    if (str=="southwest") {
	write("You start to swim southwestward out into the lake. \n");
	write("You can see much clearer now that you are in the lake. \n");
	this_player()->move_player("southwest#/players/apollo/area2/rooms/lake22");
      }
    return 1;
  }

