
inherit "room/room";

reset(arg) {

  if (!arg) {
    set_light(1);
   dest_dir=({"players/rasta/room/market","southeast",
               "players/rasta/room/ibar","west",
              "players/rasta/room/path2","north"});

  short_desc="Mountain path";
  long_desc=
  "You are walking along a path up to the Rasta mountains.\n"
+"The ITAL DRINKS BAR is to the west\n";
  }
}
