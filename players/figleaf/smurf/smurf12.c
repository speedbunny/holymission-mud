inherit "room/room";

void reset(int arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Village Road";
  long_desc = 
"You're standing on a smaller road that runs north from the fountain. \
Happy smurfs are attending to their daily activities, smiling as you pass. \
To the east and west you see the sides of mushroom houses and to the north \
is a small cul-de-sac.\n";

 dest_dir = ({
  "/players/figleaf/smurf/smurf7","south",
  "/players/figleaf/smurf/smurf19","north",
            });

  items = ({
"smurfs", "Happy blue fellows",
"road", "A smaller side road",
"houses", "Homes of the smurfs",
"cul-de-sac", "A dead end",
"fountain", "It's too far away to make out clearly",
"sides", "Sides of houses",
          });

  clone_list = ({
             1, 3, "smurf", "players/figleaf/smurf/beasties/gensmurf", 0,
            -1, 1, "pie", "players/figleaf/smurf/things/sbpie", 0,
               });

::reset(arg);
replace_program("room/room");
}

