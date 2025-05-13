inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="A wonderful forest filled with life.";
long_desc=
"You have entered a very large, very vibrant forest.  Everywhere\n"+
"around you there is life.  Light shines down from through the canopy of\n"+
"spruce, pine and birch trees.  There is a mist barring your way east.\n";
dest_dir=({
	"players/bobo/rooms/forrest/43.c","west",
	"players/bobo/rooms/forrest/55.c","north",
	"players/bobo/rooms/forrest/22.c","south",
});
items=({
	"canopy","Not to dense, this lets a lot of light shine down on you",
	"trees","Many different types of trees make up this forest",
	"mist","A dense forbidding mist, you are much to afraid to enter it",
});
}

int sound_horn() {
   write("As you sound the horn, the mists part to the west!!!\n");
   say("As "+this_player()->query_name()+" sounds "+
       this_player()->query_possessive()+" horn, the mists part to"+
       " the west!!!\n");
this_player()->move_player("is enveloped by the mist#players/bobo/rooms/castle/field");
   return 1;
}
