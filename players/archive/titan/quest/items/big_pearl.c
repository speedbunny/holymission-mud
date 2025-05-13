	inherit "obj/treasure";

#define TP this_player()

	reset(arg) {
	::reset(arg);
	if(arg) return;

	set_id("Big pearl");
	set_alias("pearl");
	set_short("A big pearl");
	set_long("Beautiful big pearl with strange color. You never seen biger pearl.\n"
	+ "It is suitable as a part of some necklace or jewel. Maybe you can type\n"
	+ "create necklace.\n");
	set_value(2000);
}
	init() {
	::init();
	add_action("create","create");
}

	object necklace,needle,thread,pearl1,pearl2,pearl3,pearl4,pearl5,pearl6,pearl7,pearl8,pearl9,pearl10,nic;

	create(str) {
	if(str!="necklace") return;
	if(present("small pearl 1",TP)&&present("small pearl 2",TP)&&present("small pearl 3",TP)&&present("small pearl 4",TP)&&present("small pearl 5",TP)&&present("small pearl 6",TP)&&present("small pearl 7",TP)&&present("small pearl 8",TP)&&present("small pearl 9",TP)&&present("small pearl 10",TP)&&present("silver needle",TP)&&present("golden thread",TP)) {
	necklace=clone_object("players/titan/quest/items/necklace");
	needle=present("silver needle",this_player());
	nic=present("nic",TP);
	pearl1=present("small pearl 1",TP);
	pearl2=present("small pearl 2",TP);
	pearl3=present("small pearl 3",TP);
	pearl4=present("small pearl 4",TP);
	pearl5=present("small pearl 5",TP);
	pearl6=present("small pearl 6",TP);
	pearl7=present("small pearl 7",TP);
	pearl8=present("small pearl 8",TP);
	pearl9=present("small pearl 9",TP);
	pearl10=present("small pearl 10",TP);
	thread=present("golden thread",this_player());
	destruct(nic);
	destruct(pearl1);
	destruct(pearl2);
	destruct(pearl3);
	destruct(pearl4);
	destruct(pearl5);
	destruct(pearl6);
	destruct(pearl7);
	destruct(pearl8);
	destruct(pearl9);
	destruct(pearl10);
	destruct(thread);
	destruct(needle);
	transfer(necklace,this_player());
	destruct(this_object());
	write("You make a beautifull necklace.\n");
	say(TP->query_name()+" created beautiful necklace.\n");
	return 1;
}
	else
	notify_fail("You haven't necessary items.\n");
	return 0;
}
