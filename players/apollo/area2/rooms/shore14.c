

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
        "players/apollo/area2/rooms/forest08", "south",
        "players/apollo/area2/rooms/shore15", "east",
        "players/apollo/area2/rooms/forest09", "southeast",
        "players/apollo/area2/rooms/shore07", "southwest",
           }); 

  items = ({
	"forest", "You see large green pine trees all around you",
	"air", "You smell the fresh fragrance of pine needles",
	"ground", "The ground is covered in old brown pine needles",
	"lake", "You see a lake covered in a dense fog that prevents you \n" +
		"from seeing very far to your north, west, northeast, \n" +
		"and northwest. Perhaps you should investigate the lake \n" +
		"a little closer by swimming in that direction",
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
    if (!str || str=="south" || str=="east" || str=="southeast" || 
	str=="southwest") {
        notify_fail("You cannot swim in that direction because the \n" +
  	 	    "lake is not in that direction! \n");
        return 0;
      }
    if (str=="north") {
        write("You start to swim northward out into the lake. \n");
	write("You can see much clearer now that you are in the lake. \n");
	this_player()->move_player("north#/players/apollo/area2/rooms/lake22");
      }	 
    if (str=="west") {
	write("You start to swim westward out into the lake. \n");
	write("You can see much clearer now that you are in the lake. \n");
	this_player()->move_player("west#/players/apollo/area2/rooms/lake13");
      }
    if (str=="northeast") {
	write("You start to swim northeastward out into the lake. \n");
	write("You can see much clearer now that you are in the lake. \n");
	this_player()->move_player("northeast#/players/apollo/area2/rooms/lake23");
      }
    if (str=="northwest") {
	write("You start to swim northwestward out into the lake. \n");
	write("You can see much clearer now that you are in the lake. \n");
	this_player()->move_player("northwest#/players/apollo/area2/rooms/lake21");
      }
    return 1;
  }

