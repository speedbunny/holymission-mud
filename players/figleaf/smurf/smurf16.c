inherit "/players/figleaf/smurf/def_room";

void reset(int arg) {
  check="hefty";
  msg="Hefty stands by his weights and smiles at you as he does curls.";
  set_light(1);
  short_desc="Hefty smurf's house.";
  base_long_desc="This is Hefty smurf's house. Everything is neat and \
tidy except for a collection of weights scattered across the floor to \
one side of the room. On the other side of the house is Hefty's cot. It \
doesn't look terribly comfortable but you doubt Hefty is the kind of \
smurf who would mind.";

  dest_dir=({
    "/players/figleaf/smurf/smurf8","north",
           });

  items=({
    "room","The only room in the house",
    "cot","A strictly utilitarian bed",
    "weights", "Dumbbells and barbells",
        });

  clone_list=({
    1, 1, "hefty", "players/figleaf/smurf/beasties/hefty", 0,
    -1, 1, "dumbbell", "players/figleaf/smurf/things/dumbbell", 0,
             });

  ::reset(arg);
  replace_program("/players/figleaf/smurf/def_room");
}

