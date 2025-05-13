
#define CAP capitalize
#define RNAME this_player()->query_real_name()
#define TO this_object()
#define ENV environment

id( str ) {
	return str == "inventory notifier" || str == "inv_notifier";
}

short() {
	tell_object( ENV( TO ), "	\n" +
	   "<<<>>> " + CAP( RNAME ) + " just looked at your " +
	   "inventory! \n" +
	   "	\n" );

	return "An inventory notifier";
}

long() {
        write( "This item notifies you when your inventory has been \n" +
	       "checked or marked by someone! \n" );
}

get() {
	return 1;
}

drop() {
	return 1;
}

query_auto_load() {
	return "/players/apollo/private/stuff/inv_notifier:";
}

