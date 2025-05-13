#define TP       this_player()
#define TPN      this_player()->query_name()
#define TPRN     this_player()->query_real_name()
#define TO       this_object()
#define RRATE    3      /* regeneration rate */
#define RTIME    6      /* regeneration time */

inherit "obj/armour"; 

int quiet;               /* flag: turn off regeneration message */
object owner;		 /* who carries the wand ? (for heart_beat */

reset(arg) {

   ::reset(arg);

   if(!arg) {
      set_name("amulet");
      set_short("A simple golden amulet");
      set_long("At the back of the amulet you notize the fine darwing of "+
	       "a dragon.\n");
      set_ac(1);
      set_value(10000);
      set_weight(1);
      set_alias("regeneration amulet");
      set_type("amulet");
      enable_commands();
      quiet=1;
   }
}

init() {
   ::init();
   add_action("shutup","swing");
}

wear(str) {

   if(!worn) {
      write("The power of the amulet pulses trough your body.\n");
      say(TPN + " emits a soft red glow.\n");
      owner=TP;
      set_heart_beat(1);
   }
   return ::wear(str);
}

query_mage_wear() { return 1; }

remove(str) {
   if(worn) {
     write("A foreign energy seems to leave your body.\n");
     say(TPN + " stops glowing.\n");
     set_heart_beat(0);
   }
   return ::remove(str);
}

heart_beat() {
   owner->heal_self(1);
   if(!quiet)
      tell_object(owner,"You feel regenerating.\n");
}

shutup() {
   quiet=!quiet;
   write("KLICK!\n");
   return 1;
}

drop(sil) {
  if(worn) {
     write("A foreign energy seems to leave your body.\n");
     say(TPN + " stops glowing.\n");
     set_heart_beat(0);
   }
  return ::drop(sil);
}
