inherit "room/room";
reset (arg) {
if (arg) return;
set_light(10);
short_desc="A clearing with a massive beam of energy flowing through it.";
long_desc=
"Wandering into this clearing you are struck be the brilliance of a very\n"+
"large, very radient beam of energy that runs across it from the northeast\n"+
"to the southwest portion of the field approximately fifty feet off the \n"+
"ground.  You see a deer go under it so you know it is safer to cross but\n"+
"are very leary to do so.\n";
dest_dir=({
	"players/bobo/rooms/forrest/41.c","east",
	"players/bobo/rooms/forrest/39.c","west",
	"players/bobo/rooms/forrest/51.c","north",
	"players/bobo/rooms/forrest/29.c","south",
});
items=({
	"trees","The trees that are so thick in the forest shy away from the beam",
   "beam","The energy seems to be of a magical sort. It is about 8 feet across",
	"deer","The deer that you saw go under the beam seems to have dissapeared",
});
}
