inherit "room/room";

void reset(int arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Gargamel's Tower";
  long_desc = 
"You're standing in a large clearing in the woods. Behind you, to the \
south, the trail disappears back between the dark trees. Standing in the \
center of the clearing is a large stone tower. It is in dire need of some \
upkeep, as the doorway seems to have collapsed and is completely blocked. \
The owner looks decidedly un-amused.\n";
 
  dest_dir = ({
  "/players/figleaf/smurf/smurf2","south",
             });

  items = ({
"clearing", "A large, treeless area in the midst of the forest",
"trail", "It disappears back between the trees to the south",
"tower", "A squat, ugly structure",
"doorway", "It is totally blocked by debris",
"woods", "Trees and stuff",
"trees", "Large woody things",
"owner", "He looks pissed",
          });

  clone_list = ({ 
              1, 1, "gargamel", "/players/figleaf/smurf/beasties/gargamel", 0,
              2, 1, "azrael", "/players/figleaf/smurf/beasties/azrael", 0,
             -1, 1, "robe", "/players/figleaf/smurf/things/robe", 0, 
             -2, 1, "collar", "/players/figleaf/smurf/things/collar", 0,
               });

::reset(arg);
replace_program("room/room");
}

