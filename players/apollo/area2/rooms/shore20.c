

inherit "room/room";

object cancer;
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
        "players/apollo/area2/rooms/shore19", "west",
        "players/apollo/area2/rooms/shore27", "northwest"
           }); 

  items = ({
	"forest", "You see large green pine trees all around you",
	"air", "You smell the fresh fragrance of pine needles",
	"ground", "The ground is covered in old brown pine needles",
	"lake", "You see a lake covered in a dense fog that prevents you \n" +
		"from seeing very far to your north, south, east, northeast, \n" +
		"southeast, and southwest. Perhaps you should investigate \n" +
		"the lake a little closer by swimming in that direction",
	});

  smell = "You smell the fresh fragrance of pine needles";

  move_object((clone_object("players/apollo/area2/monsters/cancer")),
	this_object());
  move_object((clone_object("players/apollo/area2/monsters/crab")),
	this_object());

}

  init() {
	::init();
	add_action("swim", "swim");
	}

  swim(str) {
    if (!str || str=="west" || str=="northwest") {
        notify_fail("You cannot swim in that direction because the \n" +
  	 	    "lake is not in that direction! \n");
        return 0;
      }
    if (str=="north") {
        write("You start to swim northward out into the lake. \n");
	write("You can see much clearer now that you are in the lake. \n");
	this_player()->move_player("north#/players/apollo/area2/rooms/lake28");
      }	 
    if (str=="south") {
	write("You start to swim southward out into the lake. \n");
	write("You can see much clearer now that you are in the lake. \n");
	this_player()->move_player("south#/players/apollo/area2/rooms/lake12");
      }
    if (str=="east") {
	write("You start to swim eastward out into the lake. \n");
	write("You can see much clearer now that you are in the lake. \n");
	this_player()->move_player("east#/players/apollo/area2/rooms/lake21");
      }
    if (str=="northeast") {
	write("You start to swim northeastward out into the lake. \n");
	write("You can see much clearer now that you are in the lake. \n");
	this_player()->move_player("northeast#/players/apollo/area2/rooms/lake29");
      }
    if (str=="southeast") {
	write("You start to swim southeastward out into the lake. \n");
	write("You can see much clearer now that you are in the lake. \n");
	this_player()->move_player("southeast#/players/apollo/area2/rooms/lake13");
      }
    if (str=="southwest") {
	write("You start to swim southwestward out into the lake. \n");
	write("You can see much clearer now that you are in the lake. \n");
	this_player()->move_player("southwest#/players/apollo/area2/rooms/lake11");
      }
    return 1;
  }

