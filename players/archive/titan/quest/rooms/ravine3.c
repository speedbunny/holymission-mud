	inherit "room/room";


	reset (arg) {

	set_light(1);
	short_desc = "In dangerous ravine";
	long_desc = 
		"You have entered a dangerous ravine. It looks very dangerous, because\n"
      	       + "the slopes are steep and rocks appears to be loosen. Jagged peaks stand out\n" 
	       + "against the sky. Is it place of eternal darkness, because sun never shines\n"
	       + "here. A narrow path rises to the southwest and sinkings to the\n"
	       + "northeast.\n";
	dest_dir = ({ "players/titan/quest/rooms/ravine4","southwest",
		      "players/titan/quest/rooms/beach3","northeast"});

	items = ({ "mountains","You see dark high mountains",
		"ravine","You stand on the bottom of dangerous ravine",
		"slopes","Is very steep and nobody climb up here",
		"rock","Rocks appears to be loosen",
		"peaks","Dark peaks rises up to sky"});
}
	init() {
	::init();
	call_out("lavina",random(60));
	add_action("climb","climb");
}
	climb(str) {
	if(str=="mountain") {
	write("No way.\n");
	return 1;
}}
	lavina() {
	int i;

	i=random(100);
		if(i<21) {
		tell_room(this_object(),"Suddenly you hear rattle of landslide.\n");
	        write("Big boulder hits you into the head.\n");
		say("Big boulder hits "+this_player()->query_name()+" into the head.\n");
	return 1;
}
                if((i>20)&&(i<51)) {
		tell_room(this_object(),"Suddenly you hear rattle of landslide.\n");
		tell_room(this_object(),"Big and small boulders smash near you.\n");
	return 1;
}
		if(i>50) {
		tell_room(this_object(),"Somewhere in distance you hear rattle of landslide.\n");
	return 1;
}}
