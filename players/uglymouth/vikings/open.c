/* an open plain on which you can catch rabbits for food */
inherit "room/room";

void reset(int arg)   {
   if(arg) return;

   set_light(1);
   short_desc="An open area in the dunes";
   long_desc="You arrive at a flat and open part of the dunes. \n"
           + "The grass is greener here, probably because of the river \n"
           + "you hear streaming further west. \n"
           + "you can make out the playground of rabbits, but the rabbits have fled. \n";
   dest_dir=({"/players/uglymouth/vikings/dunes_n","east",
              "/players/uglymouth/vikings/dunes_w","south",
              "/players/uglymouth/vikings/river_n","west", });
   items=({"grass","Fresh, green grass is growing here",
           "river","You can only hear it. To see it you must go west",
           "playground","The grass is eaten here. You can vaguely make out some rabbit footprints",
           "footprints","At first glance they seem to go nowhere. But you could try to track them", });
   }

void init() {
   ::init();
   add_action("track","track");
   add_action("set","set");
   add_action("make","make");
   add_action("check","check");
   add_action("pick","disarm");
   add_action("snare","snare");
   }

int snare(string str) {
   if(str!="rabbit" && str!="rabbits") return 0;
   write("There's a little more to it, then just this. \n"
       + "If you don't know how to do it, you might ask one of the locals to \n"
       + "advise you on snaring rabbits. \n");
   return 1;
   }

int track(string str) {
object fhole;
   if(str!="footprints" && str!="rabbits") {
      notify_fail("You want to track WHAT?\n");
      return 0;
      }
   if(present("foundhole",this_player())) {
      write("You don't find any more entrances to the rabbit's lair. \n");
      return 1; }
   write("You track the footprints back to the rabbit's hole. \n"
       + "If you know how to snare a rabbit you might catch some food. \n"
       + "If not, maybe one of the locals can advise you on snaring rabbits. \n");
   say(this_player()->query_name()+" walks with "+this_player()->query_possessive()
     + " nose through the grass. \n",this_player());
      fhole=clone_object("obj/treasure");
      fhole->set_id("foundhole");
      fhole->set_weight(0);
      fhole->set_info("not set");
      transfer(fhole,this_player());
   return 1;
   }

int make(string str) {
object rope,snare;
   if(!present("rope",this_player())) {
      write("You need a rope to make a snare. \n");
      return 1;
      }
      rope=(present("rope",this_player()));
      snare=clone_object("obj/treasure");
         snare->set_id("snare");
         snare->set_alias("trap");
         snare->set_short("A snare");
         snare->set_long("A snare made by "+this_player()->query_name()+". \n");
         snare->set_value(20);
         transfer(snare,this_player());
         destruct(rope);
         write("You make a snare of your rope. \n");
         say(this_player()->query_name()+" does the rope trick. \n",this_player());
      return 1;
      }

int set(string str) {
object rtrap,fhole;
   if(str!="snare" && str!="trap") return 0;

   if(!present("snare",this_player())) {
      write("You don't have a snare. \n");
      return 1;
      }

   if(!present("foundhole",this_player())) {
      write("You don't see a good spot to set the snare. \n");
      return 1;
      }

   write("You set the trap before the entrance to the rabbit's hole. \n"
       + "Now it's just a matter of patience... \n");
   say(this_player()->query_name()+" seems to be hiding something in the grass. \n",this_player());

      rtrap=(present("snare",this_player()));
      fhole=(present("foundhole",this_player()));
      destruct(rtrap);
      fhole->set_value(time()+random(90)+90);
      fhole->set_info("set");
   return 1;
   }

int check(string str) {
object fhole,meat;
int i;
int j;
   if(str!="snare") return 0;

   fhole=(present("foundhole",this_player()));
   if(!present("foundhole",this_player())) {
      write("You haven't seen a good spot here to set a snare. \n"
          + "So why check on one? \n");
      return 1;
      }

   if(fhole->query_info()!="set") {
      write("There is no snare set. \n");
      return 1;
      }

   if(time()<fhole->query_value()) {
      write("As you check your snare, you find it still empty. \n"
          + "You'll have to wait a while longer... \n");
      return 1;
      }
   
   write("GOTCHA!! You got yourself a nice juicy rabbit. You cut it up and \n"
       + "prepare it for later consumption. Unfortunately in its struggle \n"
       + "for life the rabbit rendered both your snare and the entrance to \n"
       + "its lair useless. \n");
   say(this_player()->query_name()+" takes a fat rabbit from a snare. \n",this_player());
   destruct(fhole);

   i=4;
   if(this_player()->query_level()<20) i=3;
   if(this_player()->query_level()<10) i=2;
   write("In your hunting experience you manage to get "+i+" parts of \n"
       + "rabbitmeat when cutting up the rabbit. \n");
   for(j=0;j<i;j++) {
   meat=clone_object("obj/food");
      meat->set_name("rabbitmeat");
      meat->set_alias("meat");
      meat->set_short("Some nice, self-caught rabbitmeat");
      meat->set_long("A nice, juicy, self-caught piece of rabbitmeat. \n");
      meat->set_weight(1);
      meat->set_value(20);
      meat->set_strength(random(3)+6);
      meat->set_eater_mess("Yummie... Nothing like a self-caught piece of rabbit. \n");
      meat->set_eating_mess(" devours a fat piece of rabbitmeat. Juice is dripping from the chin. \n");
      transfer(meat,this_player());
      }
   return 1;
}

int pick(string str) {
object fhole,biter;
   if(str!="snare") return 0;

   if(!present("foundhole",this_player())) {
      write("You don't see a good spot to set a snare, so where would you want to get one? \n");
   return 1; }

   fhole=(present("foundhole",this_player()));
   if(fhole->query_info()!="set") {
      write("You haven't set a snare, so you can't take one. \n");
      return 1;
      }

   write("Becoming impatient? \n"
       + "You disarm your biter and pick up your snare. \n");
   biter=clone_object("obj/treasure");
      biter->set_id("snare");
      biter->set_alias("trap");
      biter->set_short("A snare");
      biter->set_value(20);
      transfer(biter,this_player());

      fhole->set_info("not set");
      return 1;
   }
