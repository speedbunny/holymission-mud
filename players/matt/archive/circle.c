inherit "room/room";

#include "/players/matt/definitions"

object chest;

reset(arg) {
  TELLR(TO, "The mighty wind howls and blows hard against you.\n");
  if(arg) return;
  set_light(0);
  short_desc = "Mountain Circle";
  long_desc =
    "    You stand in a circle near the summit of the mountain.\n" +
    "A perpetual night darkens your surroundings, and something\n" +
    "about the strength and fury of the wind suggests that there\n" +
    "is a mighty force nearby.\n" +
    "    In the center of the circle stands a square building\n" +
    "made of black stone. No light shines from within.\n";

  dest_dir = ({
    "players/matt/rooms/mountains/passage4", "down",
              });

  items = ({
    "circle", "A circle of stone at the top of this mountain",
    "summit", "You stand on the summit of one of the higher peaks",
    "mountain", "You are very high up in the mountains",
    "building", "There is an open doorway set into the building",
    "stone", "Black stones that make up the building's exterior",
    "doorway", "A doorway into the dark building"
           });
           }

init() {
  ::init();
  add_action("enter", "enter");
  add_action("dig", "dig");
       } 

enter(arg) {
  if(arg == "door" || arg == "doorway" ||
     arg == "building") {
    write("You enter the doorway.\n");
    TP->MOVEP("through the doorway#" +
	      "players/matt/guild/rooms/anteroom");
    return 1;
                        }
  write("Enter what?\n");
  return 1;
           }

dig(arg) {
  int i;
  object chalk, book, prism;
  if(!arg || arg == "in ground") {
    if(present("parchment", TP)) {
      write("You dig deep into the icy ground, following the map\n");
      write("scrawled onto the bottom of the parchment.\n");
      say(TP->NAME + " digs into the icy ground.\n");
      if(!chest) {
	chest = clone_object("players/matt/guild/objects/chest");
	MOVE(chest, TO);
	chalk = clone_object("players/matt/guild/objects/chalk");
	MOVE(chalk, chest);
	book = clone_object("players/matt/guild/objects/book");
	MOVE(book, chest);
	for(i = 0; i < 4; i++) {
	  prism = clone_object("players/matt/guild/objects/diamondprism");
	  MOVE(prism, chest);
	                       }
	write("You unearth a small chest.\n");
	say(TP->NAME + " unearths a small chest.\n");
	return 1;
               }
      write("You find nothing.\n");
      return 1;
                                 }
    write("You have no idea where to dig, so you choose a random spot.\n");
    write("After digging for several minutes you give up.\n");
    say(TP->NAME + " digs into the ground.\n");
    return 1;
                                 }
         }
