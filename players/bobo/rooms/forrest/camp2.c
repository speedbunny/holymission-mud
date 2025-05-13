inherit "room/room";
object ob;
reset (arg) {
	if(!ob|| !living(ob)) {
	ob = clone_object("players/bobo/monsters/keeper");
	move_object(ob,this_object());
if (arg) return;
set_light(1);
short_desc="General store.";
long_desc=
"Entering the shop you feel an uneasiness about you.  It's as if you feel\n"+
"unwanted here.  There isn't much to see in here a few nick nacks and\n"+
"such.  The thing that really catches your eye however is a large shiny\n"+
"saw.  Too bad the shopkeeper won't talk to you so that you could buy it.\n";
dest_dir=({
	"players/bobo/rooms/forrest/camp.c","out",
});
items=({
	"nick nacks","A few odds and ends nonessential for a warrior like you.",
	"saw","Nice and shiny.  You covet it.",
});
}
}
