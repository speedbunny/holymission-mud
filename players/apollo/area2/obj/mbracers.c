#define TP       this_player()
#define TPN      this_player()->query_name()
#define TPRN     this_player()->query_real_name()
#define TO       this_object()
#define RRATE    3      /* regeneration rate */
#define RTIME    6      /* regeneration time */

inherit "obj/armour"; 

int quiet;               /* flag: turn off regeneration message */
object owner;		 /* who carries the wand ? (for heart_beat */
int worn;

reset(arg) {

   ::reset(arg);

   if(!arg) {
      set_name("bracers");
      set_short("Onyx Bracers");
      set_long("A fine crafted pair of onyx bracers with lots of runes "+
               "carved into its surface.\n");
      set_ac(2);
      set_value(10000);
      set_weight(1);
      set_alias("onyx"); 
      set_type("arm");
      quiet=1;
      worn=0;
   }
}

init() {
   ::init();
   add_action("shutup","twist");
}

wear(str) {

   if(!worn) {
      write("You feel the power of the Bracers recharge your brains.\n");
      say(TPN + " emits a soft purple glow.\n");
      owner=TP;
      enable_commands();
      set_heart_beat(1);
      worn=1;
   }
   return ::wear(str);
}

query_mage_wear() { return 1; }
query_summoner_wear() { return 1; }

remove(str) {
   if(worn && id(str)) {
     write("A foreign energy seems to leave your body.\n");
     say(TPN + " stops glowing.\n");
     disable_commands();
     set_heart_beat(0);
     worn=0;
   }
   return ::remove(str);
}

heart_beat() {
   owner->restore_spell_points(3);
   if(!quiet)
      tell_object(owner,"You feel regenerating.\n");
}

shutup() {
   quiet=!quiet;
   write("KLICK!\n");
   return 1;
}

drop(sil) {
   remove("bracers");
   return 0;
}
