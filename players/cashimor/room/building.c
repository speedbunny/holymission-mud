inherit "room/room";

reset(arg) {
  ::reset(arg);
  if(!arg) {
    short_desc="On the building";
    long_desc="You are on a large stone building in the middle of a\n"
            + "wood. It sounds hollow.\n";
    smell="The air is fresh here.";
    set_light(1);
    dest_dir=({"room/forest9","down"});
    items=({"wood","It looks beautiful, at this height",
            "building","It's as closed from here as from downunder"});
  }
}

init() {
  ::init();
  "players/cashimor/room/inside"->roof_walk();
}
