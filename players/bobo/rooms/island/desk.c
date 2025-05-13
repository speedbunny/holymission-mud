inherit "room/room";
reset (arg) {
if(arg) return;
clone_list=({
        1, 1, "guard","/players/bobo/monsters/guard1", 0,
});
::reset(arg);
set_light(1);
short_desc="Underground desk.";
long_desc=
"Your in the underground chamber of the shed.  it is dimly lit with\n"+
"evenly spaced torches hanging on the walls.  The ground is stone.\n"+
"At the north end of this area is a desk with an attendant writing\n"+
"something.  Better get out of here before he notices you.\n";
dest_dir=({
	"players/bobo/rooms/island/opium.c","north",
	"players/bobo/rooms/island/shed1.c","up",
});
items=({
	"torches","Wooden torches line the walls",
	"attendant","It is actually a guard",
	"desk","An old desk covered with papers",
	"papers","Papers with some writing that you don't comprehend on it",
});
replace_program("room/room");
}
