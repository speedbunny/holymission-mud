inherit "room/room";

void reset(int arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Village Square";
  long_desc =
"You stand in the center of the smurf village. All around are smurfs going \
about their chores. There is a small fountain in the middle of the road \
here. Roads lead off to the north, west and east and to the south is Papa \
Smurf's house.\n";

 dest_dir = ({
  "/players/figleaf/smurf/smurf15","south",
  "/players/figleaf/smurf/smurf12","north",
  "/players/figleaf/smurf/smurf8","east",
  "/players/figleaf/smurf/smurf6","west",
            });

  items = ({
"smurfs", "Happy blue fellows",
"fountain", "A pretty little fountain with roses growing around it",
"roses", "They smell divine. Their petals are white at the bottom, becoming \
red at the tips",
"village", "Where the smurfs live",
"road", "A road through the village",
"house", "Where a smurf lives",
          });

  clone_list = ({
             1, 4, "smurf", "players/figleaf/smurf/beasties/gensmurf", 0,
            -1, 1, "smurfberry", "players/figleaf/smurf/things/sberry", 0,
               });

::reset(arg);
replace_program("room/room");
}
