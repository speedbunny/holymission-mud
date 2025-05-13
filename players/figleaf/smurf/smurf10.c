inherit "room/room";

void reset(int arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Pool";
  long_desc =
"You stand in a sunny glade, surrounded on three sides by trees. To the \
south the trail leads back to the smurf village. In the center of the \
glade is a pool filled with clear, sparkling water where the smurfs come \
to swim when it's hot.\n";

 dest_dir = ({
  "/players/figleaf/smurf/smurf9","south",
            });

  items = ({
"glade", "A small grassy area in the middle of the copse",
"trees", "Silver birch trees with birds singing in the branches",
"birds", "Many birds just singing happily",
"trail", "A narrow trail leading back into the village",
"pool", "A shallow pool full of clear, sparkling water",
"water", "Clear and sparkling",
"village", "Home of the smurfs",
          });

::reset(arg);
replace_program("room/room");
}
