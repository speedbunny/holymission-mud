inherit "room/room";
reset (arg) {
   ::reset (arg);
   set_light(1);
   short_desc="In an open area.";
   long_desc=
	"This portion of the clearing is large and flat. The grass here\n"+
	"spreads in nearly every direction for a long way. To the east\n"+
	"however the green carpet is stopped by a large white stone\n"+
	"building.\n";
   dest_dir=({
	"/players/bobo/clan/rooms/open/o15.c","north",
	"/players/bobo/clan/rooms/nunnery/n1","east",
	"/players/bobo/clan/rooms/open/o8.c","south",
	"/players/bobo/clan/rooms/open/o12.c","west",
      });
   items=({
	"building","This large white edifice looms in front of you and is surprisingly clean",
	"carpet","Do you seriously think that it is a real carpet ?",
	"clearing","It is very large and covered in lush grass",
	"grass","Thick green grass is under your feet",
	"green carpet","The grass is so thick that it looks more like a carpet",
      });
   replace_program("room/room");
}
