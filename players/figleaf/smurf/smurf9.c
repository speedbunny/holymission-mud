inherit "room/room";

void reset(int arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Village Road";
  long_desc = 
"You're standing on the main road through the smurf village. All around \
are the sounds of smurfs going happily about their business. The road \
leads back to the west and to the north is a small copse of trees. To the \
south is Vanity Smurf's house, and to the east is Smurfette's house.\n";

 dest_dir = ({
  "/players/figleaf/smurf/smurf17","south",
  "/players/figleaf/smurf/smurf10","north",
  "/players/figleaf/smurf/smurf18","east",
  "/players/figleaf/smurf/smurf8","west",
            });

  items = ({
"smurfs", "Happy blue fellows",
"road", "The main road through the village",
"trees", "A small copse of trees",
"copse", "Just a small patch of woodland encroaching on the village",
          });

  clone_list = ({
             1, 4, "smurf", "players/figleaf/smurf/beasties/gensmurf", 0,
            -1, 1, "smurfberry", "players/figleaf/smurf/things/sberry", 0,
               });

::reset(arg);
replace_program("room/room");
}

