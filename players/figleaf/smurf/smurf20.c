inherit "room/room";

void reset(int arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Farmer smurf's house";
  long_desc = 
"This is Farmer smurf's house. Potted plants line the window sills and \
yet more stand on tables in patches of sunlight. There is even a large \
sunflower sitting on his bed. There is a small door on the north side \
of the room and the front door is to the east.\n";

 dest_dir = ({
  "/players/figleaf/smurf/smurf19","east",
  "/players/figleaf/smurf/smurf23", "north",
            });

 items = ({
"room", "The only room in the house",
"plants", "Pretty flowers and herbs",
"flowers","Violets, geraniums, chrysanthemums and sweet peas",
"herbs", "Mint, parsley and sage",
"tables", "They serve merely to place the plants on",
"sunlight", "Bright light shining in through the windows",
"windows", "Flung open to let in as much light as possible",
"door", "Which door",
"small door", "It leads out to Farmer's garden",
"front door", "This leads back out to the street",
"sunflower", "A large, bright yellow sunflower",
"bed", "Farmer's bed",
         });

  ::reset(arg);
  replace_program("room/room");
}


