inherit "/players/figleaf/smurf/def_room";

void reset(int arg) {
  check="jokey";
  msg="Jokey is standing at the table chuckling to himself.";
  set_light(1);
  short_desc="Jokey smurf's house.";
  base_long_desc="This is Jokey smurf's house. Scattered across the \
room are empty boxes and pieces of brightly colored wrapping paper. \
There is a table that looks slightly scorched and a bed in the corner.";

  dest_dir=({
    "/players/figleaf/smurf/smurf19","south",
           });

  items=({
    "room","The only room in the house",
    "boxes","Small empty boxes",
    "paper", "Large rolls and small sheets of wrapping paper in many \
colors",
    "table","The top appears to be scorched all over",
    "bed","Almost completely buried under wrapping paper",
        });

  clone_list=({
    1, 1, "jokey", "players/figleaf/smurf/beasties/jokey", 0,
    -1, 1, "package", "players/figleaf/smurf/things/package", 0,
             });

  ::reset(arg);
  replace_program("/players/figleaf/smurf/def_room");
}

