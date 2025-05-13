inherit "/players/figleaf/smurf/def_room";

void reset(int arg) {
  check="grouchy";
  msg="At the back of the room you can just make out Grouchy grumbling \
to himself as he kicks the wall.";
  set_light(1);
  short_desc="Grouchy smurf's house.";
  base_long_desc="This is Grouchy smurf's house. The windows are closed \
and the curtains drawn leaving the room dim and hard to see around. To \
the side is a small hard bed.";

  dest_dir=({
    "/players/figleaf/smurf/smurf19","west",
           });

  items=({
    "room", "The only room in the house",
    "windows", "All closed up",
    "curtains", "The black curtains have been drawn keeping most of the \
light out",
    "bed","A small hard bed with a thin mattress",
        });

  clone_list=({
    1, 1, "grouchy", "players/figleaf/smurf/beasties/grouchy", 0,
             });

  ::reset(arg);
  replace_program("/players/figleaf/smurf/def_room");
}

