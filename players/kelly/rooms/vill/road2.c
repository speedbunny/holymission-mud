inherit "room/room";
object man;
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
short_desc="village road.";
long_desc=
"You are on the village road.  The shop is to the east while\n"+
"the famous Red Rock Junction pub is to the west.  This area\n"+
"is generally clean and devoid of trash.\n";
    dest_dir=({
      "players/kelly/rooms/vill/road3","north",
      "players/kelly/rooms/vill/road1","south",
      "players/kelly/rooms/vill/shop","east",
      "players/kelly/rooms/vill/pub","west",
    });
    items=({
      "shop","Maybe you can buy or sell things there",
      "pub","It looks inviting",
    });
   /*   Not yet 
   people=clone_object("obj/monster");
   people->set_name("man");
   people->set_male();
   people->set_short("A man");
   */
/*  	yes yet- bobo*/
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
}
