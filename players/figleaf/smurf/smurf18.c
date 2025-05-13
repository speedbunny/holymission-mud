inherit "/players/figleaf/smurf/def_room";

void reset(int arg) {
  check="smurfette";
  msg="Smurfette is sitting at her vanity trying on some jewelry.";
  set_light(1);
  short_desc="Smurfette's house.";
  base_long_desc="This is Smurfette's house. The interior is decorated \
in pink and green, from the pretty pink curtains to the dark green and \
pink striped silk sheets. There is a vanity by a window which is \
covered in small bottles of perfume and a couple of brushes. Two candles \
are burning on a small table beside her bed.";

  dest_dir=({
    "/players/figleaf/smurf/smurf9","west",
           });

  items=({
    "room", "The only room in the house",
    "curtains", "Pretty pink curtains",
    "vanity", "Complete with drawers and a mirror",
    "perfume", "Many scents that Smurfette likes",
    "bed", "Smurfette's bed",
    "bottles", "Bottles of different sizes and shapes all containing \
various perfumes",
    "brushes", "Several different brushes for her hair",
    "table", "A small end-table",
    "jewelry", "Small trinkets Smurfette likes to wear",
    "candles", "Long, dark green tapers",
        });

  clone_list=({
    1, 1, "smurfette", "players/figleaf/smurf/beasties/smurfette", 0,
    -1, 1, "earrings", "players/figleaf/smurf/things/earrings", 0,
             });

  ::reset(arg);
  replace_program("/players/figleaf/smurf/def_room");
}
