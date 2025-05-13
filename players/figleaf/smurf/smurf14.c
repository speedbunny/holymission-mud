inherit "/players/figleaf/smurf/def_room";

void reset(int arg) {
  check="clumsy";
  msg="As you stand here, Clumsy trips over a rug and knocks a vase to \
the floor.";
  set_light(1);
  short_desc="Clumsy smurf's house.";
  base_long_desc="This is Clumsy smurf's house. This place is a mess! \
Everywhere you look things have been knocked over or broken. A chair \
lies on it's side beside a table with only three legs. In one corner of \
the room is an unmade bed.";

  dest_dir=({
    "/players/figleaf/smurf/smurf6","north",
           });

  items=({
    "room","The only room in the house",
    "bed","A horrible mess. No normal person could sleep on it",
    "chair", "The legs look like they have been repaired many times",
    "table","There is a stack of books holding up the corner with the \
missing leg",
    "books", "Torn and beaten up, totally unreadable",
    "rug", "It was once a fine rug, now it is threadbare and torn with \
stains all over it",
    "vase", "It was a pretty green vase. Now it's in several hundred \
pieces",
        });

  clone_list=({
    1, 1, "clumsy", "players/figleaf/smurf/beasties/clumsy", 0,
    -1, 1, "crutch", "players/figleaf/smurf/things/crutch", 0,
             });

  ::reset(arg);
  replace_program("/players/figleaf/smurf/def_room");
}

