
inherit "room/room";

reset(arg) {

  if (!arg) {
    set_light(1);
   dest_dir=({"players/rasta/room/top","south",
              "players/rasta/room/path21","north"});

  short_desc="Mountain path";
  long_desc=
  "Toward the north the elevations decline, you will find karsted limestone \n"
+"plateaus which cover almost two thirds of Rasta's area.\n";
  }
}
