inherit "room/room";
object man;
reset (arg) {
    if (arg) return;
    set_light(1);
short_desc="Village road.";
long_desc=
"You are on the village road.  The local police station is to the west\n"+
"making sure the law is upheld.  To the east is the Mayor's house.  The\n"+
"surroundings here seem to emminate a sense of prosperity, it seems as\n"+
"though this town would be a good place for an adventurer to find their\n"+
"fortune.\n";
    dest_dir=({
    "players/kelly/rooms/vill/road2","north",
    "players/kelly/rooms/vill/entrance","south",
    "players/kelly/rooms/vill/mayorsgarden","east",
    "players/kelly/rooms/vill/police_office","west",
   });
   items=({
   "police","What do you expect ? It's a policestation",
   "station","What do you expect ? It's a policestation",
   "house","It is the house of the mayor. You can enter his garden",
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
}
