
inherit "room/room";

object b1,b2,b3;

reset(arg) {

  if (!arg) {
    set_light(1);
  dest_dir=({"players/rasta/room/archway1","east",
    "players/rasta/room/vallent","north"});

  short_desc="In the Valley of Decision";


  long_desc= 
  "You smell the aroma of the sensimilia burning.\n";
    no_castle_flag = 1;
  b1=clone_object("players/rasta/obj/gnat");
  b2=clone_object("players/rasta/obj/mosquito");
  b3=clone_object("players/rasta/obj/buzzard");

  move_object(b1,this_object());
  move_object(b2,this_object());
  move_object(b3,this_object());

  }
}
