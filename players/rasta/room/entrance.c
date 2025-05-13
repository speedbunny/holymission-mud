
inherit "room/room";

object sign;
object rastaman;
reset(arg) {

  if (!arg) {
    set_light(1);
    dest_dir=({"players/rasta/room/raspath","north",
   "players/rasta/room/bulletin","east",
   "players/rasta/room/jinx","west", 
	     "players/rasta/room/archway","northwest"});

 short_desc="Massive Gateway";
   long_desc="You duck through the massive gateway of Rasta City, a maze \n"
+ "of caves and catacombs haunted by the ghosts of intoxication and death\n"
+ "but also by a spirit which resolutely clings to the life in the face\n"
+ "of adversity.\n";
    no_castle_flag = 1;
/*
if (!sign) { sign=clone_object("players/rasta/obj/sign1");
	     transfer(sign,"room/vill_track");     }
*/
if (!rastaman) { rastaman= clone_object("players/rasta/obj/man");
  transfer(rastaman,"room/main_shop");  }
  }
}
