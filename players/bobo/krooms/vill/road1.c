inherit "/room/room";

object man;
void reset (int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="Village road.";
   long_desc=
	"You are on the village road.  The local police station is to the "+
	"west making sure the law is upheld.  To the east is the Mayor's "+
	"house.  The surroundings here seem to emulate a sense of prosperity,"+
	" it seems as though this town would be a good place for an "+
	"adventurer to find their fortune.\n";
   dest_dir=({
	"/players/bobo/krooms/vill/road2","north",
	"/players/bobo/krooms/vill/mayorsgarden","east",
	"/players/bobo/krooms/vill/entrance","south",
	"/players/bobo/krooms/vill/police_office","west",
   });
   items=({
	"police","What do you expect?  It's a police station",
	"station","What do you expect?  It's a police station",
	"house","It's the house of the Mayor.  You can enter his garden",
   });
   if(!present("man")) {
	man = clone_object("obj/monster");
	man->set_name("man");
	man->set_level(3);
	man->set_al(10);
	man->set_gender(1);
	man->set_short("A man.");
	man->set_long("A tall, well dressed gentleman.\n");
	man->add_money(50);
	move_object(man,this_object());
   }
   replace_program("/room/room");
}
