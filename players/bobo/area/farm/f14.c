inherit "/room/room";

void reset(int arg) {
   ::reset(arg);
   if (arg) return;
   set_light(1);
   short_desc="Roaming through the crops.";
   long_desc=
	"You are on the eastern edge of the fields.  The crops here are "+
	"not as plentiful as they are in other areas as there is a village "+
	"directly east of here and there is more traffic here.  You can see "+
	"wagon tracks leading into the small town.  You can also hear some "+
	"screaming coming from somewhere but you don't know where.\n";
dest_dir=({
	"/players/bobo/area/farm/f7","north",
	"/players/bobo/area/town/r1","east",
	"/players/bobo/area/farm/f21","south",
	"/players/bobo/area/farm/f13","west",
   });
   items=({
	"crops","Some large grain type crop that is about seven feet high",
	"fields","These fields have to belong to someone as they are well kept",
	"town","A small little hamlet with several buildings",
	"traffic","You can see signs of people but see none now",
	"tracks","Normal old wagon tracks, the ruts aren't very deep",
	"village","A small little hamlet with several buildings",
   });
}

init () {
   ::init();
   add_action("listen","listen");
}

listen (str) {
   if(!str || str == "") {
      write("From here you can tell that it's a woman screaming.\n");
   return 1;
   }
}
