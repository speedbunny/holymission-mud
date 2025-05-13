inherit "/players/figleaf/smurf/def_room";

void reset(int arg) {
  check="farmer";
  msg="Farmer smurf stands off to the side weeding his rutabaga patch \
with a hoe.";
  set_light(1);
  short_desc="Farmer smurf's garden.";
  base_long_desc="This is Farmer smurf's garden. This is where he grows \
all his fruit and vegetables. There is row after row of well-tended \
plants, each well-marked. There is a large basket of fresh parsley on \
the ground by the back door.";

  dest_dir=({
    "/players/figleaf/smurf/smurf20","south",
           });

  items=({
    "fruit", "Apples, pears, strawberries..",
    "vegetables", "Potatos, peas, carrots..",
    "basket", "A large wicker basket",
    "parsley", "Green and lush. Looks good",
    "door", "The way back into Farmer smurf's house",
    "rutabaga", "You can't see them because they're still in the ground",
        });

  clone_list=({
    1, 1, "farmer", "players/figleaf/smurf/beasties/farmer", 0,
    -1, 1, "hoe", "players/figleaf/smurf/things/hoe", 0,
             });

  ::reset(arg);
  replace_program("/players/figleaf/smurf/def_room");
}

