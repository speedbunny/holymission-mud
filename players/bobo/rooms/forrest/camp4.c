inherit "room/room";
object worker;
reset (arg) {
if (arg) return;
worker = clone_object("players/bobo/monsters/worker1.c");
transfer(worker,this_object());
worker = clone_object("players/bobo/monsters/worker1.c");
transfer(worker,this_object());
worker = clone_object("players/bobo/monsters/worker1.c");
transfer(worker,this_object());
set_light(1);
short_desc="The lumber mill.";
long_desc=
"This is the lumber mill.  This is the place where all of the hard work that\n"+
"the lumberjacks do gets processed and refined.  There is a pulper in here\n"+
"some workers are slaving away.  there is also sawdust covering this area.\n";
dest_dir=({
	"players/bobo/rooms/forrest/camp.c","out",
});
items=({
	"pulper","A large piece of metal with thousands of teeth to eat the wood",
	"sawdust","There are piles of sawdust covering most everything in the area.",
	"piles","Some of these piles are very large.",
});
}
init(){
::init();
add_action("search","search");
}
search(arg){
if (!arg=="piles") return 0;
write("You found a skull.\n");
move_object(clone_object("players/bobo/obj/skull.c"),this_player());
return 1;
}
