
inherit "room/room";

reset(arg) {

  if (!arg) {
    set_light(1);
   dest_dir=({"players/rasta/room/entrance","southeast",
              "players/rasta/room/wind","west"});

  short_desc="Domed Archway";
  long_desc=
  "You are walking along a domed archway. It leads further west\n";
    no_castle_flag = 1;
  }
}
