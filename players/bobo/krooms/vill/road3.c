inherit "/room/room";

object people;

void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="Village road.";
   long_desc=
	"You're on the village road.  A grocery store is to the west.  An "+
	"armoury is to the east.  The road continues south and northeast "+
	"To the north you can make out a gate.\n";
   dest_dir=({
	"/players/mangla/rooms/newbie/new0","north",
	"/players/bobo/krooms/vill/armoury","east",
	"/players/bobo/krooms/vill/road2","south",
	"/players/bobo/krooms/vill/grocery","west",
	"/players/bobo/krooms/vill/road4","northeast",
   });

   if(!present("man")) {
     people=clone_object("obj/monster");
     people->set_name("man");
     people->set_race("human");
     people->set_male();
     people->set_short("A man");
     people->set_long("A man who lives here.\n");
     people->set_level(10);
     people->set_al(50);
     people->set_move_at_reset();
   }
replace_program("room/room");
}
