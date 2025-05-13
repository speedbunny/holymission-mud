inherit "/room/room";

object man;

void reset(int arg) {
   if (arg) return;
   set_light(1);
   short_desc="village road.";
   long_desc=
	"You are on the village road.  The shop is to the east while the "+
	"famous Red Rock Junction Pub is to the west.  This area is generally "+
	"clean and devoid of trash.\n";
    dest_dir=({
	"/players/bobo/krooms/vill/road3","north",
	"/players/bobo/krooms/vill/shop","east",
	"/players/bobo/krooms/vill/road1","south",
	"/players/bobo/krooms/vill/pub","west",
   });
   items=({
	"shop","Maybe you can buy or sell things there",
	"pub","A small pub, it looks inviting",
   });

   if(!present("man")) {
        man = clone_object("obj/monster");
        man->set_name("man");
        man->set_level(3);
        man->set_al(10);
        man->set_gender(1);man->set_short("A man.");
        man->set_long("A tall, well dressed gentleman.\n");
        man->add_money(50);
	move_object(man,this_object());
   }
   replace_program("/room/room");
}
