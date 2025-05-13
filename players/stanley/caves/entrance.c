inherit "room/room";
reset(arg) {
  if(arg) return 0;
  set_light(1);
  short_desc="Outside cave";
  long_desc=
    "Excepting a few scraggly bushes, the rocks are barren.\n"
    "There is a sign by a large rock.\n";

  dest_dir=({
    "/players/stanley/caves/cave1","in"
  });

  items=({
    "bushes","They are as bad as you have ever seen",
    "bush","One of two or three pitiful bushes",
    "rocks","The rocks are practically devoid of life",
   "rock","One rock is the same as another, here",
  });
}
