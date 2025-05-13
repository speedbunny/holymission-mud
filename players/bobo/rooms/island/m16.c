inherit "room/room";
reset (arg) {
if (arg) return;
clone_list=({
1, 1, "Chojin","players/bobo/monsters/dragon.c", 0
});
::reset(arg);
set_light(1);
short_desc="Mirror maze.";
long_desc=
"You have made it to the end of the mirror maze.  You have cornered\n"+
"the dragon.  Whether you can kill him or not is another matter\n"+
"entirely.  But somehow you get the feeling that you are missing\n"+
"something very important about his domain.\n";
dest_dir=({
	"players/bobo/rooms/island/m16.c","east",
	"players/bobo/rooms/island/m16.c","west",
	"players/bobo/rooms/island/m15.c","north",
	"players/bobo/rooms/island/m16.c","south",
	"players/bobo/rooms/island/trophy.c","out",
});
items=({
	"mirrors","Is it a mirror or is it real?",
});
}
init(arg) {
    ::init(arg);
    add_action("out","out");
    }
out(){
   if(present("chojin", this_object())) {
      write("Chojin Does not let you escape!\n");
      return 1;
   }
return 0;
}
