inherit "room/room";

void reset(int arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Country Path";
  long_desc = 
"You stand at the edge of a small area of woodland. The trees are very \
old with huge, gnarled trunks. The path winds between them into darkness \
to the east and off to the west the path runs across the rolling \
countryside and passes north of a larger forest. You can see the top of a \
stone tower through the trees to the northeast.\n";

 dest_dir = ({
  "/players/figleaf/smurf/smurf2","east",
  "/players/figleaf/smurf/path2", "west",
            });

 items = ({
"trees","Huge oak and beech trees, hundreds of years old",
"tower","It looks dark and gloomy, and more than a little run-down",
"trunks", "Huge and gnarled",
"path", "A narrow path winding between the trees",
"darkness", "Hmmm, it's dark",
         });

::reset(arg);
replace_program("room/room");
}


