inherit "room/shop";

reset(arg) {
    ::reset(arg);
   if (arg) return;
   set_short("Keidall Trading Post");
   set_long( "You have entered the Keidall Trading Post where the\n" +
	"populace of the city of Keidall buys and sells items.\n" +
	"All the usual shop commands work here also.\n" +
	"There is an opening to the north, and some shimmering\n" +
	"blue light in the doorway.\n");
   set_store_room("room/store");
   set_store_exit("north");
   set_exits(({"players/silas/fghant/keidall4","south"}));
   set_light(1);
   smell = "A musty smell envelops this room.\n";
}
