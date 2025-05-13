/* Thor's hammer */
inherit "obj/thing";

void reset(int arg) {
   ::reset(arg);

   if(!arg) {
      set_name("mjolnir");
      set_alias("hammer");
      set_short("Mjolnir, Thor's hammer");
      set_long("Mjolnir is Thor's magic hammer. \n"
             + "But as it is now, its hilt is as thick as your waist and its head looks more \n"
             + "like a small mountain. Although it's craftly made, it's impossible to lift it for you. \n");
      set_can_get(0);
      }
   }

void init() {
   ::init();
   add_action("lift_it","lift");
   add_action("lift_it","move");
   add_action("lift_it","get");
   add_action("lift_it","take");
   }

int lift_it(string str) {
   if(str!="mjolnir" && str!="hammer" && str!="thor's hammer") return 0;
   write("You are not strong enough to move it even an inch. \n");
   return 1;
   }
