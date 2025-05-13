inherit "/players/figleaf/smurf/def_room";

void reset(int arg) {
  check="vanity";
  msg="Vanity stands at a window admiring himself in yet another mirror!";
  set_light(1);
  short_desc="Vanity smurf's house.";
  base_long_desc="This is Vanity smurf's house. Everywhere you look you \
see mirrors. Full-length mirrors on the walls, smaller hand mirrors on \
the bed and table, even a large mirror on the ceiling about his bed!";

  dest_dir=({
    "/players/figleaf/smurf/smurf9","north",
           });

  items=({
    "room","The only room in the house",
    "mirror","They are all around, all shapes and sizes",
    "mirrors", "They are all around, all shapes and sizes",
    "table","A small yet sturdy table",
    "bed","Where Vanity sleeps",
    "ceiling","Nothing unusual here, except for the huge mirror over the \
bed",
    "window","It lets in plenty of light",
        });

  clone_list=({
    1, 1, "vanity", "players/figleaf/smurf/beasties/vanity", 0,
    -1, 1, "mirror", "players/figleaf/smurf/things/mirror", 0,
             });

  ::reset(arg);
  replace_program("/players/figleaf/smurf/def_room");
}

