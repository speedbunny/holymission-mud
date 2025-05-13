inherit "room/room";

void reset(int arg) {
  if (arg) return;
  set_light(1);
  short_desc = "Cul-de-sac";
  long_desc = 
"You are standing at the end of the north road. To the south you can see \
the village square and on the other three sides are mushroom houses. To \
the north is Jokey Smurf's house, to the east is Grouchy Smurf's house and \
to the west is Farmer Smurf's house.\n";

 dest_dir = ({
  "/players/figleaf/smurf/smurf12","south",
  "/players/figleaf/smurf/smurf21","north",
  "/players/figleaf/smurf/smurf22","east",
  "/players/figleaf/smurf/smurf20","west",
            });

  items = ({
"road", "A smaller side road",
"houses", "Homes of the smurfs",
"square", "Too far away to see clearly",
          });

  clone_list = ({
             1, 3, "smurf", "players/figleaf/smurf/beasties/gensmurf", 0,
            -1, 1, "pie", "players/figleaf/smurf/things/sbpie", 0,
               });

  ::reset(arg);
  replace_program("room/room");
}

