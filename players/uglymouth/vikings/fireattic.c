/* the attic of the warehouse */
inherit "room/room";

void reset(int arg) {
   if(arg) return;

   set_light(1);
   short_desc="The attic of the warehouse";
   long_desc="You are at the attic of the warehouse. \n"
           + "The fire is intense here, since all the heat gets sucked upwards. \n"
           + "All the goods stored here have already changed to ashes. A heavy \n"
           + "smoke hangs in the air. A small window gives looks out south. \n";
   dest_dir=({"/players/uglymouth/vikings/firehouse","down", });
   items=({"fire","As you look at the fire, you notice your coat is on fire! You put it out quickly",
           "goods","What goods? Everything already burned to ashes here",
           "ashes","Ashes to ashes, dust to dust, as will happen to you if you stay here too long",
           "smoke","Thick black smoke makes it hard to breathe here",
           "window","It's covered with a thick layer of ashes", });
   smell="The smoke is so dirty you can hardly breathe! \n";
   property=({ "has_fire" });
   }

void init() {
   ::init();
   add_action("clean","clean");
   add_action("open","open");
   add_action("open","break");
   add_action("open","shatter");
   }

int clean(string str) {
   if(str!="window") return 0;
   write("You burn your fingers as you touch the window. \n");
   return 1;
   }

int open(string str) {
   if(str!="window") return 0;
   write("And give more oxygen to the fire?!?! You must be crazy. \n");
   return 1;
   }
