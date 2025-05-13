inherit "room/room";

void reset(int arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Village Road";
  long_desc = 
"You're standing on the main road through the smurf village. All around \
are the sounds of smurfs going happily about their business. The road runs \
east and west through the village. To the north is Lazy Smurf's house and \
to the south is Hefty Smurf's house.\n";

 dest_dir = ({
  "/players/figleaf/smurf/smurf16","south",
  "/players/figleaf/smurf/smurf13","north",
  "/players/figleaf/smurf/smurf9","east",
  "/players/figleaf/smurf/smurf7","west",
            });

  items = ({
"smurfs", "Happy blue fellows",
"road", "The main road through the village",
"village", "Where the smurfs live",
"house", "The home of a smurf",
          });

  clone_list = ({
             1, 3, "smurf", "players/figleaf/smurf/beasties/gensmurf", 0,
            -1, 1, "pie", "players/figleaf/smurf/things/sbpie", 0,
               });

::reset(arg);
replace_program("room/room");
}

