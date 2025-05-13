inherit "/players/figleaf/smurf/def_room";

void reset(int arg) {
  check="lazy";
  msg="Atop a large pile of pillows you see Lazy peering at you sleepily.";
  set_light(1);
  short_desc="Lazy smurf's house.";
  base_long_desc="This is Lazy smurf's house. There really isn't much here, \
just a large bed and pillows all over the place.";

  dest_dir=({
    "/players/figleaf/smurf/smurf8","south",
           });

  items=({
    "room","The only room in the house",
    "bed","A large, comfortable looking bed piled high with blankets \
and pillows",
    "blankets", "Perfect for snuggling up in on a cold night",
    "pillows","All sizes, shapes and colors",
        });

  clone_list=({
    1, 1, "lazy", "players/figleaf/smurf/beasties/lazy", 0,
    -1, 1, "pillow", "players/figleaf/smurf/things/pillow", 0,
             });

  ::reset(arg);
  replace_program("/players/figleaf/smurf/def_room");
}

