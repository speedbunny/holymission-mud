

inherit "room/room";

object crab;

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
        "players/apollo/area2/rooms/forest42", "north",
        "players/apollo/area2/rooms/shore37", "east",
        "players/apollo/area2/rooms/forest35", "west",
        "players/apollo/area2/rooms/forest43", "northeast",
        "players/apollo/area2/rooms/shore27", "southwest",
           }); 

  items = ({
	"forest", "You see large green pine trees all around you",
	"air", "You smell the fresh fragrance of pine needles",
	"ground", "The ground is covered in old brown pine needles",
	"lake", "You see a lake covered in a dense fog that prevents you \n" +
		"from seeing very far to your south and southeast. Perhaps \n" +
		"you should investigate the lake a little closer by swimming \n" +
		"in that direction",
	});

  smell = "You smell the fresh fragrance of pine needles";

  move_object((clone_object("players/apollo/area2/monsters/crab")),
	this_object());

}

  init() {
	::init();
	add_action("swim", "swim");
	}

  swim(str) {
    if (!str || str=="north" || str=="east" || 
	str=="west" || str=="northeast" || 
	str=="southwest" || str=="northwest") {
        notify_fail("You cannot swim in that direction because the \n" +
  	 	    "lake is not in that direction! \n");
        return 0;
      }
    if (str=="south") {
	write("You start to swim southward out into the lake. \n");
	write("You can see much clearer now that you are in the lake. \n");
	this_player()->move_player("south#/players/apollo/area2/rooms/lake28");
      }
    if (str=="southeast") {
	write("You start to swim southeastward out into the lake. \n");
	write("You can see much clearer now that you are in the lake. \n");
	this_player()->move_player("southeast#/players/apollo/area2/rooms/lake29");
      }
    return 1;
  }

