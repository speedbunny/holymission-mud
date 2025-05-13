inherit "room/room";
object worker;
reset (arg) {
if (arg) return;
worker = clone_object("players/bobo/monsters/worker.c");
transfer(worker,this_object());
worker = clone_object("players/bobo/monsters/worker.c");
transfer(worker,this_object());
worker = clone_object("players/bobo/monsters/worker.c");
transfer(worker,this_object());
set_light(1);
short_desc="The first floor of the pumping station.";
long_desc="The first floor of the refracting station is pretty empty.  There\n"+
"are a few workers going here and there doing various things.  You are\n"+
"either being ignored or just not important enough to notice.  There are\n"+
"stairs leading to the second level to the right of the door.\n";
dest_dir=({
	"players/bobo/rooms/forrest/refract.c","out",
	"players/bobo/rooms/forrest/refract2.c","up",
});
}
