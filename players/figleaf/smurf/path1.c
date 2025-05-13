inherit "room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc="Woodland path";
  long_desc=
"The path is completely walled off to the east and west by thick forest and \
undergrowth, barring your passage in those directions. In the soft earth \
at the sides of the path you can see many footprints that are not humanoid \
in appearance. There is also a funny smell in the air.\n";

  items = ({
"forest", "An impenetrable wall of trees. Too thick to walk through",
"undergrowth", "Tangled bushes and vines make passage impossible",
"footprints", "Each about 6 inches long with evidence of long claws!",
"earth","Brown, earthy stuff",
          });

  dest_dir = ({
"players/figleaf/smurf/path2","north",
"players/figleaf/smurf/path","south" });

  smell = "You smell the pungent aroma of reptiles.";
  clone_list = ({
    1, 4, "lizard", "/players/figleaf/smurf/beasties/lizard", 0
               });

::reset(arg);
replace_program("room/room");
}
