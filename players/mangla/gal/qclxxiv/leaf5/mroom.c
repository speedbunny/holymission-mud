/* qroom */ /* deriviates must at least provide reset() and nr() */
#include "/players/qclxxiv/leaf5/leaf5room.h"

object monster;

init() {
   ::init();
    add_action("read_sign", "read");
	if (this_player() && living(this_player()) && !this_player()->query_npc()) {
		if (!monster) {
			PLACE_IN_THIS(monster, REGION+mymonster());	
		}	
		/*if (!present("spliff",this_player()) ) {*/
		if (!condition(this_player())) {
			/* tell_object(this_player(), "Hi there\n"); */
			monster->set_attack(this_player());
		}
		else monster->peace_with(this_player());
	}
}

extra_reset(arg) {
	object herb;
   if (arg) return;
    set_nodig(1);
   items = ({
		"lock", "A solid greenish lock, apparently old copper",
		"hinges", "Solid greenish hinges, apparently old copper",
		"plaque", 
"A simple but impressing plaque with an inscription is fitted against the wall",
		"wall", "Just old, dark wall",
		"inscription", 
"A stylish inscription is engraved on the plaque. Maybe you can read it",
   });
	if (random(5)==3) {
		PLACE_IN_THIS(herb, REGION+"ironweed");	
	}
}

read_sign(str) {
	if (!condition(this_player())&&monster) {
		write(monster->query_name()+" won't you read it!\n");	
		return 1;
	}
	return read(this_player(), str, nr());
}

min(i) { 
	switch(i) {
		case 0: return "carbonyx" ; break; 
		case 1: return "lilimond" ; break;
		case 2: return "gnomopaz" ; break;
		case 3: return "carbomarine" ; break;
		case 4: return "micropyrith" ; break;
		case 5: return "gnomonyx" ; break;
		case 6: return "lilimaranth" ; break;
		case 7: return "gnomoruby" ; break;
		case 8: return "carbosapphire" ; break;
		case 9: return "gnomathyst" ; break;
	}
	return "shouldnt happen\n";
}

read(tp,str,rn) {
	string mineral;
	int pole, mno;
    if (str=="inscription") { 
		say(tp->query_name()+" reads the inscription.\n", tp);
		if (rn==1+"/players/qclxxiv/qquest/qmast"->lock_name2key(4,
					tp->query_real_name())) {
			mno="/players/qclxxiv/qquest/qmast"->lock_name2key(5,
						tp->query_real_name());
			mineral = min(mno);
			pole = 1 +
			"/players/qclxxiv/qquest/qmast"->lock_name2key(6,tp->query_real_name());
		}
		else {
			mineral = min(random(10));
			pole = 1 + random(14);
		}
		write("It reads: \n");
		write("To find a piece, of that most important map...\n");
		write("Touch pole "+pole+" on the dyke with a piece of "+mineral+".\n");
		write(
"No doubt any local can tell thee the current location of the mines.\n");
    	return 1;
	}
	return 0;  
}

