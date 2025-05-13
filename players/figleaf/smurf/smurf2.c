inherit "room/room";

void reset(int arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Dense Woodland";
  long_desc = 
"The path twists through the woods, running south and west. There is a \
narrower trail branching off to the north and you can see the tower more \
clearly now. From the north drift sounds of someone ranting and raving \
about something. Whoever it is, they seem to be pretty upset.\n";

 dest_dir = ({
  "/players/figleaf/smurf/smurf3", "north",
  "/players/figleaf/smurf/smurf1", "west",
  "/players/figleaf/smurf/smurf4", "south",
            });

 items = ({
"trees", "Huge oak and beech trees, hundreds of years old",
"tower", "It looks dark and gloomy, and more than a little run-down",
"path", "The path winds between the trees",
"trail", "Narrower than the main path",
         });

::reset(arg);
replace_program("room/room");
}


