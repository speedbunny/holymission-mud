
inherit "room/room";

reset(arg) {

  if (!arg) {
    set_light(1);
  dest_dir =
    ({
       "players/rasta/room/ridges1","south",
          "players/rasta/room/lane1","north"
     });

  short_desc="Trench Town Entrance";
  long_desc=
 "Anyone who travels these roads can't help but be astonished\n"
 + "by the irony of the place, so scenic and lush on the surface, and\n"
 + "yet so hobbled by extremes of wealth and grinding poverty.\n";
  }
}
