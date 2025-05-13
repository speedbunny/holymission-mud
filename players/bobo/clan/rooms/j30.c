inherit "room/room";
reset (arg) {
   clone_list=({
      1, 1, "gibnut","/players/bobo/monsters/clan/gibnut", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="In the Jungle.";
   long_desc=
	"You have entered an area that is still part of the jungle that\n"+
	"rims the clearing that the ancient buildings are in.  Though it\n"+
	"is not as dense as other portions of the jungle, there are still\n"+
	"many plants around you and you can hear the sounds of the animals\n"+
	"of the jungle.\n";
   dest_dir=({
	"/players/bobo/clan/rooms/j32.c","north",
	"/players/bobo/clan/rooms/open/o3.c","west",
      });
   items=({
	"animals","Though you cannot see all of them, you can definitely hear them",
	"buildings","old white washed buildings",
	"clearing","The area around the buildings is clear of all jungle vegetation",
	"jungle","thin compared to other portions of the jungle",
	"plants","various jungle plants are in this area",
      });
   replace_program("room/room");
}
