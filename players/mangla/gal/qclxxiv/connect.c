#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
object spliff, rasta;

query_qnewbie() { return 1; }
query_newbiehint() { 
	return "South of here you are no longer in the area of the Q's.\n";
}

extra_reset(arg) {
	if (!rasta) {
		PLACE_IN_THIS(rasta,"/players/qclxxiv/leaf1/rastaman");
		rasta->set_lines( ({ 
			"Come, Mek We Chant Down Babylon One More Time.\n",
			"ComeMek We Chant Down Babylon One More Time.\n",
			"For Them Soft...Yes Them Soft   (I-a).\n",
			"For Them Soft...Yes Them Soft   (I-a).\n",
			"Come, Mek We Chant Down Babylon One More Time.\n",
			"Musical Musicology...Please...Please Talk To Me.\n",
		"Bring A Voice Of The Rastaman Communicating-Ca-Cating To Everyone.\n",
	"Yes Now I Know...Now I Feel. Reggae Music Mek We Chant Down Babylon,\n",
	"With Music. Mek We Chant Down Babylon, With Music.\n",
					}) );
   		rasta->set_long("A rastaman, having dreadlocks till down his waist.\n");
	}
	if (!spliff) {
		spliff = clone_object("players/qclxxiv/spliff");
		move_object(spliff, this_object());
	}
	if (arg) return;
	items = ({	"sign","A red, gold and green sign. You can read it",
				"warning","A warning written on a red, gold and green sheet"
			});
}

TWO_EXIT( "players/qclxxiv/leaf1/toproom1","north",
"players/rasta/room/market","south",
"A small hall with an opening to the south, and an opening to the north",
"You are in a small hall with an opening to the south. \n"+
"A red, gold, and green SIGN is above the opening. A red, gold, and green\n"+
"WARNING is on top of the opening to the north. You hear a pleasing\n"+
"Reggae Dub coming from all directions. You feel drum and bass penetrating\n"+
"your body and soul, and it makes you feel very peaceful.\n", 1)

init() {
	object I;
	::init();
    add_action("read_sign", "read");
    add_action("please", "please");
	if (I = find_player("qclxxiv")) {
		if (I!=this_player()) {	
			tell_object(I, ">>>>>>>>>>>>> "+
				this_player()->query_name()+" entered the connect room.\n");
		}
	}
}

read_sign(str) {
    if (str=="sign") { 
        write("\n");
    	write( "To the south thou troddest the area of Rasta, one of I Irie\n"
			+"rasta Idrin. Though I&I stick together and Inite in Inity,\n"
			+"I Qclxxiv have to warn thee that I Rasta likes I&I monsters\n"
			+"to be VERY tough (the harder they come the harder he let's\n"
			+"them fall). So keepeth this in mind when going any further!\n");
    	return 1;
	}
    if (str=="warning") { 
        write("\n");
    	write( "Warning, northwards is Negus Qclxxiv's territory.\n"
			+"It is wrapped up in time-space so it could just be in any\n"
			+"solar system, but don't try to fit in into the village map.\n");
    	return 1;
	}
	return 0;  
}

please(str) {
	object ob;
	if (str=="give me dreadlocks") {
		write("Your request is honoured and some herbs appear "
				+"on the floor.\n");
		ob = clone_object("/players/qclxxiv/obj/drdpill");
		move_object( ob, this_object() );
		return 1;
	}
	return 0;
}
