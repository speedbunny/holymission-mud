inherit "room/room";

void reset(int arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Village Edge";
  long_desc =
"You stand on the edge of the smurf village. The path widens as it enters \
the village to the east while it narrows and winds between the huge oak \
and beech trees to the west.\n";

 dest_dir = ({
  "/players/figleaf/smurf/smurf6","east",
  "/players/figleaf/smurf/smurf4","west",
            });

  items = ({
"path", "A well-groomed path",
"trees", "REALLY old trees",
"village", "The smurf village",
          });

  clone_list = ({
             1, 1, "smurf", "players/figleaf/smurf/beasties/gensmurf", 0,
            -1, 1, "smurfberry", "players/figleaf/smurf/things/sberry", 0,
               });

::reset(arg);
replace_program("room/room");
}
