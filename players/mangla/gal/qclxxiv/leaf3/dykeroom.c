#include "/players/qclxxiv/myroom.h"

object loot;

query_qnewbie() { return 1; }

init() {
	::init();
}

check( arg, tp, tr ) {
	string what;
	int i;
	object gem, ghost;
	if (sscanf(arg, "pole with %s", what)) {
		if (!present(what,tp)) {
			write("You don't have any "+what+".\n");
			return 1;
		}
		say(tp->query_name()+" touches the pole with "+what+".\n", tp );
		switch(what) {
			case "carbonyx" : i = 0; break;
			case "lilimond" : i = 1; break;
			case "gnomopaz" : i = 2; break;
			case "carbomarine" : i = 3; break;
			case "micropyrith" : i = 4; break;
			case "gnomonyx" : i = 5; break;
			case "lilimaranth" : i = 6; break;
			case "gnomoruby" : i = 7; break;
			case "carbosapphire" : i = 8; break;
			case "gnomathyst" : i = 9; break;
			default : write("Nothing happens.\n"); return 1;
		}	
		gem = present(what+"174",tp);
		if (!gem) {
			write("Nothing happens.\n");
			return 1;
		}
		/* transfer(gem, tr); */
		destruct(gem);
		say("The "+what+" crumbles to dust.\n", tp);
		write("The "+what+" crumbles to dust.\n");
		if (i=="/players/qclxxiv/qquest/qmast"->lock_name2key(5,
						tp->query_real_name()) && (nr()-1)==
			"/players/qclxxiv/qquest/qmast"->lock_name2key(6,tp->query_real_name()))
		{
			if (loot) { write(
"You get the feeling someone was here just before you, and you may have\n"
+"to come back later...\n");
			}
			else { 
				tell_room(environment(tp),
				"Suddenly a piece of map seems to appear out of nowhere.\n");
				PLACE_IN_THIS(loot,"/players/qclxxiv/qquest/map4");
				loot->setup_map(tp);
				log_file("qmap",this_player()->query_real_name()+" map4 "
							+ctime(time())+"\n");
				write_file("/players/qclxxiv/qquest/qmap",
					this_player()->query_real_name()+" map4 "+ctime(time())+"\n");
			}
		}
		else {
			tell_room(environment(tp),
			"Suddenly a dykeghost seems to appear out of nowhere.\n");
			PLACE_IN_THIS(ghost,"/players/qclxxiv/leaf3/dykeghost");
		}
		return 1;
	}
	return 0;
}

do_get( arg ) {
   if (!arg) return 0;
   switch (arg) {
       case "pole":write("It has been firmly driven into the ground.\n"); break;
       default: return 0;
   }
   return 1;
}

touch( arg ) {
	return check( arg, this_player(), nr() );
}
