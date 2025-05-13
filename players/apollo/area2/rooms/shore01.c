

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
        "players/apollo/area2/rooms/forest02", "east",
        "players/apollo/area2/rooms/shore07", "northeast",
        "players/apollo/area2/rooms/shore05", "northwest"
           }); 

  items = ({
	"forest", "You see large green pine trees all around you",
	"air", "You smell the fresh fragrance of pine needles",
	"ground", "The ground is covered in old brown pine needles",
	"lake", "You see a lake covered in a dense fog that prevents you \n" +
		"from seeing very far to your north. Perhaps you should \n" +
		"investigate the lake a little closer by swimming in that \n" +
		"direction",
	});

  smell = "You smell the fresh fragrance of pine needles";

}

  init() {
	::init();
	add_action("swim", "swim");
	}

  swim(str) {
    if (!str || str=="south" || str=="east" || 
	str=="west" || str=="northeast" || str=="southeast" ||
	str=="southwest" || str=="northwest") {
        notify_fail("You cannot swim in that direction because the \n" +
  	 	    "lake is not in that direction! \n");
        return 0;
      }
    if (str=="north") {
        write("You start to swim northward out into the lake. \n");
	write("You can see much clearer now that you are in the lake. \n");
	this_player()->move_player("north#/players/apollo/area2/rooms/lake06");
      }	 
    return 1;
  }

