inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="Recieving Station.";
long_desc="Strolling in from the north you can see that you have wandered onto\n"+
"a penninsula.  While there is water surrounding it fifty yards out the mist\n"+
"envelopes everything.  Some distance from the south shore is a building which\n"+
"the beam of energy which has continued from the north flows into.\n";
dest_dir=({
	"players/bobo/rooms/forrest/6.c","north",
});
items=({
	"building","A very large building, it is most definitely locked.",
   "beam","The energy seems to be of a magical sort. I flows into the building"
});
}
