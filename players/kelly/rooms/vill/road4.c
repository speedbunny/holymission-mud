// 6-5-97 Kryll - reformatted room
 
inherit "/room/room";
 
void reset(int arg) {
  set_light(1);
  no_castle_flag=1;
  short_desc="Village road";
  long_desc=
    "You're on the village road.  To the south of here there are a "+
    "number of houses.  The road continues on to the east where there "+
    "is a huge, red rock.  There is a trail leading to the north.\n";
 
  dest_dir=({
    "/players/kelly/rooms/vill/road5","east",
//  04.18.97 Airborne:  Removed until further notice.
//    "/players/tegerl/jabberwocky/rooms/out/path1","north",
    "/players/figleaf/link/link1", "north",
    "/players/kelly/rooms/vill/houseyard","south",
    "/players/kelly/rooms/vill/road3","southwest",
  });
 
  items=({
    "houses","Obviously these are the homes of some inhabitants",
    "rock","It's strange red rock, certainly the town is named after it",
  });
 
  clone_list = ({
    1, 1, "people", "obj/monster", ({
      "set_name", "people",
      "set_gender", 1,
      "set_short", "Some people",
      "set_long", "They don't look too tough but there are many of them and "+
                  "only one of you.\n",
      "set_level", 9,
      "set_al", 100,
      "add_money", 100,
    }),
  });
 
  ::reset(arg);
  replace_program("/room/room");
}
