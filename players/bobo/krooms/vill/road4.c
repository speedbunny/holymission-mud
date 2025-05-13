inherit "/room/room";
 
void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="Village road";
   long_desc=
	"You are on the village road.  to the south of here there are a "+
	"number of houses.  The road continues on to the east where there "+
	"is a huge, red rock.  There is a trail leading to the north.\n";
   dest_dir=({
	"/players/figleaf/link/link1","north",
	"/players/bobo/krooms/vill/road5","east",
	"/players/bobo/krooms/vill/houseyard","south",
	"/players/bobo/krooms/vill/road3","southwest",
   });
   items=({
	"houses","Obviously these are the homes of some of the town's folk",
	"rock","A strange red rock, certainly the town is named after it",
   });
   clone_list=({
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
  replace_program("/room/room");
}
