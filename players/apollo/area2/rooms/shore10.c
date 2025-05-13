

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
        "players/apollo/area2/rooms/forest18", "north",
        "players/apollo/area2/rooms/shore19", "northeast",
        "players/apollo/area2/rooms/shore05", "southeast",
        "players/apollo/area2/rooms/forest17", "northwest"
           }); 

  items = ({
	"forest", "You see large green pine trees all around you",
	"air", "You smell the fresh fragrance of pine needles",
	"ground", "The ground is covered in old brown pine needles",
	"lake", "You see a lake covered in a dense fog that prevents you \n" +
		"from seeing very far to your east. Perhaps you should \n" +
		"investigate the lake a little closer by swimming in that \n" +
		"direction",
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
    if (!str || str=="north" || str=="south" || 
	str=="west" || str=="northeast" || str=="southeast" ||
	str=="southwest" || str=="northwest") {
        notify_fail("You cannot swim in that direction because the \n" +
  	 	    "lake is not in that direction! \n");
        return 0;
      }
    if (str=="east") {
	write("You start to swim eastward out into the lake. \n");
	write("You can see much clearer now that you are in the lake. \n");
	this_player()->move_player("east#/players/apollo/area2/rooms/lake11");
      }
    return 1;
  }

