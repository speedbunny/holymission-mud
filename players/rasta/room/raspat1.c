
inherit "room/room";

reset(arg) {

  if (!arg) {
    set_light(1);
    dest_dir=({"players/rasta/room/entranc1" ,"north"});

 short_desc="Path to Rasta City";
   long_desc="The power of philosophy floats through your head.\n"
    +"You are on your way to Rasta City\n";
    no_castle_flag = 1;

  }
}
