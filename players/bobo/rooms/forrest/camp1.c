inherit "room/room";
object lumberjack;
reset (arg) {
::reset (arg);
if (arg) return;
lumberjack = clone_object("players/bobo/monsters/lumberjack.c");
transfer(lumberjack,this_object());
lumberjack = clone_object("players/bobo/monsters/lumberjack.c");
transfer(lumberjack,this_object());
lumberjack = clone_object("players/bobo/monsters/lumberjack.c");
transfer(lumberjack,this_object());
set_light(1);
short_desc="Barracks.";
long_desc=
"This is the barracks for the people of this camp.  There are currently\n"+
"A couple of lumberjacks sleeping here.  This room is lined with beds\n"+
"with footlockers next to them.  The beds run down each wall.\n";
dest_dir=({
	"players/bobo/rooms/forrest/camp.c","out",
});
items=({
	"beds","long narrow beds.  They look hard and utterly uncomfortable.",
	"footlockers","This is what the members of the camp store their stuff in",
});
}
init(){
::init();
add_action("search","search");
}
search(arg){
if (!arg=="footlockers") return 0;
write("You search through all the lockers and find 1500 coins.\n");
this_player()->add_money(1500);
return 1;
}
