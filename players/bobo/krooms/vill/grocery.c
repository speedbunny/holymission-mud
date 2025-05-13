inherit "/room/room";

object baker;

void reset (int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="The grocery.";
   long_desc=
	"You have entered the local grocery store.  It is a small store "+
	"but it has many things lining its shelves including meat, produce, "+
	"dairy, and assorted bread items, and of course junk food.  There "+
	"is a sign hanging over the front counter.\n";
   dest_dir=({
	"/players/bobo/krooms/vill/road3","east",
	"/players/bobo/krooms/vill/innergrocery","west",
   });
   items=({
	"sign","It's written in the common language, you can reat it",
	"counter","It's an old, but clean wooden counter",
	"shelves","The shelves are stocked with many varios goodies",
	"meat","Many assorted meats await you in the cooler",
	"produce","Looks like rabbit food but it could be good..",
	"dairy","looks like a normal dairy section found in any store",
	"bread","Fresh baked bread and goodies come from the bakery",
	"junk food","Possibly nutritious but definitely good",
   });

   if(!baker) {
	baker=clone_object("players/bobo/kmonster/grocer");
	move_object(baker,this_object());
   }
}

init() {
   ::init();
   add_action("read","read");
   add_action("buy","buy");
}

read(str) {
  if(str!="sign") return;
  write("The sign reads: Closed due to family bereavement.\n");
  return 1;
}

buy(str) {
  write("The grocery is closed.\n");
  return 1;
}
