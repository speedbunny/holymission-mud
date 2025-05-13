inherit "/room/room";

void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="Roaming through the crops.";
   long_desc=
	"You are in the northern portion of the fields.  All around you "+
	"you can see crops except to the north where there is a thick "+
	"impenetrable mist that you dare not enter.  You can hear an odd "+
	"sound here but you can't quite make it out.\n";
   dest_dir=({
	"/players/bobo/area/farm/f7","east",
	"/players/bobo/area/farm/f13","south",
	"/players/bobo/area/farm/f5","west",
   });
   items=({
	"crops","Some large grain type crop that is about seven feet high",
	"fields","These fields have to belong to someone as they are well kept",
	"mist","This mist is unlike any other mist that you have seen and is "+
	       "very scary",
   });
}
init () {
   ::init();
   add_action("listen","listen");
}

listen(str){
   if(!str || str == "") {
      write("You can hear what you think to be someone screaming.\n");
      return 1;
   }
}
