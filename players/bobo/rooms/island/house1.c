inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="House entrance.";
long_desc=
"You are at the main entrance of the house.  Although not elaborately\n"+
"furnished it does have a certain ambience of grandure to it.  The\n"+
"walls, which seem to be made of a paper of sorts are covered with\n"+
"paintings and conji.  There is a bench running along each north\n"+
"south wall.  There is an archway to the north leading to another\n"+
"room.  To the south is the exit out of the house.\n";
dest_dir=({
	"players/bobo/rooms/island/hall1.c","north",
	"players/bobo/rooms/island/house.c","out",
});
items=({
	"archway","A small wooden arch connecting the room to the north",
	"walls","The walls seem to be made of some sort of paper though it's much stronger",
	"paintings","Mostly of animals such as tigers, they are exquisite",
	"conji","A great number of characters adorn the walls",
	"rug","This is an elaborately decorated throw rug",
	"benches","Padded benches line two of the four walls",
});
}
