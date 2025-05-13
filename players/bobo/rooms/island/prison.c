inherit "room/room";
reset (arg) {
if (arg) return;
set_light(1);
short_desc="The prison.";
long_desc=
"You have entered a prison with a few cells but with massive amounts\n"+
"of prisoners.  They all look glassy eyed and without their senses.\n"+
"Some of them are wailing for no apparent reason while others just\n"+
"stare vacantly at you.  There is a team of people administering\n"+
"some sort of liquid to the prisoners one at a time.\n";
dest_dir=({
	"players/bobo/rooms/island/opium.c","south",
});
items=({
	"torches","Wooden torches line the walls",
	"prisoners","Glassy eyes and lack of expression...what are they on?",
	"liquid","looks a lot like opium",
	"cells","Three massive cells packed full of people",
	"people","The people in white coats are scurrying about giving shots",
	"team","A group of people in white uniforms administering medicine",
});
replace_program("room/room");
}
