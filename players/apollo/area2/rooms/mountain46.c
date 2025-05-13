

inherit "room/room";

reset(arg){        
  if(arg) return;
  set_light(1);

  short_desc = "A deep thick forest";

  long_desc = 
	"This is the dark forest. You begin thinking of what draws you to \n" +
	"explore a forest that appears to be so peaceful. This urges you to \n" +
	"explore it further. You see large trees around you, the ground is \n" +
	"covered in something, and there is a sweet smell in the air. You see \n" +
	"a large mountain rising above the forest to the north. \n";

  dest_dir = ({
        "players/apollo/area2/rooms/mountain60", "north",
        "players/apollo/area2/rooms/forest40", "south",
        "players/apollo/area2/rooms/forest41", "southeast",
           }); 

  items = ({
	"mountain", "You see a large mountain to the north, maybe \n" +
		    "you should investigate it! \n",
	"forest", "You see large green pine trees all around you",
	"ground", "The ground is covered in old brown pine needles",
	});

  smell = "You smell the fresh fragrance of pine needles";

  clone_list = ({ 1, 5, "golem", "players/apollo/area2/monsters/golem", 0, });

  ::reset(arg);

}


