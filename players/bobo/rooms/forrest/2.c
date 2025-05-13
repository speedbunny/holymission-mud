inherit "room/room";
int found;

reset (arg) {
if (arg) return;
set_light(1);
short_desc="A wonderful forest filled with life.";
long_desc=
"You have entered a very large, very vibrand forest.  Everywhere\n"+
"around you there is life.  Light shines down from through the canopy of\n"+
"spruce, pine and birch trees.  There is a mist barring your way south.\n";
dest_dir=({
	"players/bobo/rooms/forrest/3.c","east",
	"players/bobo/rooms/forrest/1.c","west",
	"players/bobo/rooms/forrest/13.c","north",
});
items=({
	"canopy","Not to dense, this lets a lot of light shine down on you",
	"trees","Many different types of trees make up this forest",
	"mist","A dense forbidding mist, you are much to afraid to enter it",
	"ground","A thick covering of leaves lies beneath your feet",
});
   found=0;
}

init(){
::init();
add_action("search","search");
}

search(arg){
   if(!arg=="ground") return 0;
   if(found) {
      write("Someone already searched here!\n");
      say(this_player()->query_name()+" kicks the ground a bit.\n");
      return 1;
   }
write("You found a horn.\n");
say(this_player()->query_name()+" kicks the ground and uncovers a horn!\n");
move_object(clone_object("/players/bobo/obj/horn.c"),this_player());
found=1;
return 1;
}
