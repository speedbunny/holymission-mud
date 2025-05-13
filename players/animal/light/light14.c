inherit "room/room";
 
#define me capitalize(this_player()->query_name())
 
reset(arg) {
	if(!arg) {
#if 0 
    ::reset(arg);
    set_light(1);
    set_outdoors(4);
#endif
    set_light(1);
    short_desc = "Mountain";
    long_desc=
   "Mountain\n\n" +
       "     The mountain looks very steep here. It is covered with\n" +
       "     ice and it looks very slick. You wonder if there is anyway\n" +
       "     to climb to the top of the mountain from here. To the north\n" +
       "     appears to be a small mountain village.\n\n";
    items = ({
        "mountain","The mountain is very steep and icy",
        "ice","You would need something to help you climb this",
    });
     dest_dir = ({
     "players/animal/light/light11","south",
     "players/animal/shops/shop_street1","north",
     });
	}
    return;
}
 
 
query_light() {
    return 1;
}
 
init() {
          ::init();
          add_action("climb","climb");
}
 
 
climb(str) {
     object ob;
     ob = present("snow boots",this_player());
	if(!ob) {
          write("You try to climb the mountain, but you cannot get a grip\n"+
          "without something to help you climb. You slide back down the\n" +
          "mountain. You slide all the way to the base of the mountain.\n");
     tell_room("players/animal/light/light11",me+" comes sliding into view.\n");
     say(me+ " slides down the mountain after unsuccessfully trying to climb it.\n");
     move_object(this_player(),"players/animal/light/light11");
     return 1;
          }
	if(!ob->query_worn()) { write("You MUST wear them first!.\n");
	return 1;
	}
     write("The snow boots dig right in and you climb like a goat.\n");
     say(me+" climbs up the mountain and out of sight.\n");
     tell_room("players/animal/light/light4",me+" arrives looking tired.\n");
     move_object(this_player(),"players/animal/light/light4");
	this_player()->look();
     return 1;
}
