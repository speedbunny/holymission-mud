inherit "/room/room";

static int nr_alarm;

void reset(int arg) {
   clone_list=({
      1, 1, "policeman","obj/monster", ({
	 "set_name","policeman",
	 "set_alias","man",
         "set_level", 10,
         "set_ac", 5,
         "set_gender", 1,
         "set_al", 50,
         "set_short", "A policeman.",
         "set_long", "A policeman. You see nothing special about him.\n",
      }),
      -1, 1, "club", "obj/weapon", ({
         "set_name", "club",
         "set_class", 10,
         "set_weight", 2,
         "set_short", "A club",
         "set_long", "A wooden club with a stamp on it signifying that it "+
		     "belongs to the Red Rock Junction police.\n",
      }),
   });
   nr_alarm = 0;
   ::reset(arg);
   if(arg) return;
   set_light(1);
   short_desc="The police office.";
   long_desc=
	"You have entered the outer office of the police station.  There "+
	"is a large number of desks placed about the room in no apparent "+
	"order.  The cells of the station are off to the west and to the "+
	"north is a bureau.  In the center of the room there is a pole "+
	"stretching up through a hole in the ceiling.\n";
   dest_dir=({
	"/players/bobo/krooms/vill/bureau","north",
	"/players/bobo/krooms/vill/road1","east",
	"/players/bobo/krooms/vill/corridor1","west",
   });
   items=({
	"corridor","A dimly lit corridor, you can hear the bellowing "+
		   "of some prisoners",
	"desks","Large wooden desks cluttered with many papers",
	"papers","They are reports about crimes committed and action taken",
	"cells","Though you can't see them you know they're there",
	"bureau","A label on the door reads:  Captain",
	"hole","It's big enough that policemen can go through it",
	"pole","It seems you can only slide down it.  It is too slippery "+
	       "to climb up",
   });
}

alarm(direction,criminal) {
   if(nr_alarm>2) return ;
   tell_room(this_object(),"You can hear an alarm from above.\n");
   "/players/bobo/krooms/vill/quarters"->alarm(direction,criminal);
   nr_alarm++;
}
