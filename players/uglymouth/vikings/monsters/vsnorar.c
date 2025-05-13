/* viking sonrar sleeps... don't wake him up */
inherit "obj/monster";
int awake;

void reset(int arg) {
   ::reset(arg);

   if(awake) {
      tell_room(environment(this_object()),"Viking Snorar yawns and goes back to sleep. \n");
      command("drop all");
      awake=0;
      }

   if(!arg) {
      set_name("viking snorar");
      set_alt_name("snorar");
      set_alias("viking");
      set_short("Viking Snorar");
      set_long("Viking Snorar looks like he has feasted too fanatically. \n"
             + "His breath smells very alcoholic and his belly is thick with \n"
             + "all the food he swallowed. But although he's asleep, \n"
             + "he looks as if he can take some hits in a fight. And deal them too... \n");
      set_level(8);
      set_al(-15);
      set_race("human");
      set_gender(1);

      }
   }

void wake_up() {
   if(awake==1) return;
   if(random(10) < 3) {
      write("Oh oh, you made too much noise there. \n"
          + "Viking Snorar doesn't seem pleased that you woke hime (to say the least). \n");
      set_long("Viking Snorar looks like he has feasted too fanatically. \n"
             + "His breath smells very alcoholic and his belly is thick with \n"
             + "all the food he swallowed. Now someone woke him and he's very angry about it. \n");
      if(present("helm"),environment(this_object())) {
         tell_room(environment(this_object()),"Viking Snorar takes a helm. \n");
         transfer(present("helm"),this_object());
         }
      if(present("axe"),environment(this_object())) {
         tell_room(environment(this_object()),"Viking Snorar takes an axe. \n");
         transfer(present("axe"),this_object());
         }
      if(present("clan tunic"),environment(this_object())) {
         tell_room(environment(this_object()),"Viking Snorar takes a clan tunic. \n");
         transfer(present("clan tunic"),this_object());
         }

      command("wear tunic");
      command("wear helm");
      command("wield axe");
      attacker_ob=this_player();
      attack();
      set_aggressive(1);
      awake=1;
      return;
      }
   return;
   }
