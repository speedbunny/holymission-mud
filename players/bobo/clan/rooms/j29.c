inherit "room/room";
reset (arg) {
   clone_list=({
      1, 1, "puma","/players/bobo/monsters/clan/puma", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="In the Jungle.";
   long_desc=
	"This area has not quite been cleared yet.  There is still a lot\n"+
	"of jungle vegetation here, including trees and other jungle plants.\n"+
	"To the west the jungle gets more dense while to the north and east\n"+
	"you can tell that the vegetation lessens considerably.\n";
   dest_dir=({
	"/players/bobo/clan/rooms/open/o4.c","north",
	"/players/bobo/clan/rooms/open/o1.c","east",
	"/players/bobo/clan/rooms/j28.c","west",
      });
   items=({
	"area","This area is still jungle, but steps are being taken to clear it",
	"jungle","This portion of the jungle is quite thing compared to other portions",
	"plants","Large leafy plants are all about this area",
	"trees","Thick jungle trees have yet to be removed from this area",
	"vegetation","Various flora cover the majority of this area",
      });
   replace_program("room/room");
}
