
inherit "room/room";

reset(arg) {

  if (!arg) {
    set_light(1);
   dest_dir=({"players/rasta/room/entranc1","east",
              "players/rasta/room/wind1","west"});

  short_desc="Valley of Decision";
  long_desc=
  "You are in the Valley of Decision. Natural Mystics fill the air.\n";
  }
}
