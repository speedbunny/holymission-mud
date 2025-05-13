inherit "room/room";
object ob;
reset (arg) {
	if (!ob|| !living(ob)) {
	ob = clone_object("players/bobo/monsters/eagle1");
	move_object(ob,this_object());
}
if (arg) return;
set_light(10);
short_desc="A clearing with a massive beam of energy flowing north to south.";
long_desc="Wandering into this clearing you are struck by the brilliance of\n"+
"a very large very radiant beam of energy that runs from north to south\n"+
"approximately fifty feet off the ground.  You see a deer go under it so you\n"+
"know it is safe to cross but are very reluctant to do the same.\n";
dest_dir=({
	"players/bobo/rooms/forrest/18.c","east",
	"players/bobo/rooms/forrest/6.c","south",
	"players/bobo/rooms/forrest/16.c","west",
	"players/bobo/rooms/forrest/refract.c","north",
});
items=({
	"trees","The trees that are so thick in the forest shy away from the beam",
   "beam","The energy seems to be of a magical sort. It is about 8 feet across",
	"deer","The dear that you saw ggo under the beam seem to have disapeared",
});
}
