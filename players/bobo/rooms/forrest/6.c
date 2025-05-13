inherit "room/room";
reset (arg) {
if (arg) return;
set_light(10);
short_desc="A clearing with a massive beam of energy flowing north to south.";
long_desc="Wandering into this clearing you are struck by the brilliance of\n"+
"a very large very radiant beam of energy that runs from north to south\n"+
"approximately fifty feet off the ground.  You see a deer go under it so you\n"+
"know it is safe to cross but are very reluctant to do the same.\n";
dest_dir=({
	"players/bobo/rooms/forrest/7.c","east",
	"players/bobo/rooms/forrest/pump.c","south",
	"players/bobo/rooms/forrest/5.c","west",
	"players/bobo/rooms/forrest/17.c","north",
});
items=({
	"trees","The trees that are so thick in the forest shy away from the beam",
	"beam","The energy seems to be of a magical sort.  It is about 8 feet across",
	"deer","The deer that you saw go under the beam seems to have dissapeared",
});
}
