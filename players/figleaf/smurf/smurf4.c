inherit "room/room";

void reset(int arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Dense Woodland";
  long_desc = 
"The path twists through the woods, running north and east. In the \
distance to the north you can see the top of a stone tower. Back to the \
east you can see some large mushrooms with smoke coming out of them!\n";

 dest_dir = ({
  "/players/figleaf/smurf/smurf2","north",
  "/players/figleaf/smurf/smurf5", "east",
            });

 items = ({
"trees","Huge oak and beech trees, hundreds of years old",
"tower","It looks dark and gloomy, and more than a little run-down",
"mushrooms","Large, brightly colored mushrooms, with smoke trailing from them",
"smoke", "A product of combustion",
"woods", "Trees and stuff",
"path", "The path through the woods",
"top", "The top of the tower",
         });

::reset(arg);
replace_program("room/room");
}


