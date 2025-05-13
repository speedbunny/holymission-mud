#define TP       this_player()
#define TPN      this_player()->query_name()
#define TPRN     this_player()->query_real_name()
#define TO       this_object()
#define RRATE    3      /* regeneration rate */
#define RTIME    6      /* regeneration time */

inherit "obj/weapon"; 

int quiet;               /* flag: turn off regeneration message */
object owner;		 /* who carries the wand ? (for heart_beat */
string true_desc;

reset(arg) {

   ::reset(arg);

   if(!arg) {
      set_name("wand");
      set_short("A wand with magic runes");
      set_long("It seems to be an interesting wand with lots of runes graved"
              +" into its surface.\n");
      set_class(10);
      set_value(300);
      set_weight(1);
      set_alias("regeneration wand");
      set_read("The strange runes seem to shiver before your eyes.\n" +
               "You can't even say what they look like.\n");
      set_true_desc("A regeneration wand");
      enable_commands();
      quiet=1;
   }
}

init() {
   ::init();
   add_action("identify","identify");
   add_action("shutup","quiet");
}

wield(str) {

   if(!wielded) {
      write("The power of the wand pulses trough your body.\n");
      say(TPN + " emits a soft blue glow.\n");
      owner=TP;
      set_heart_beat(1);
   }
   ::wield(str);
   return 1;
}

un_wield() {
   write("A foreign energy seems to leave your body.\n");
   say(TPN + "stops glowing.\n");
   set_heart_beat(0);
   ::un_wield();
}

heart_beat() {
   owner->heal_self();
   if(!quiet)
      write("You feel regenerating.\n");
}

identify(str) {
   if(!str) {
      write("try identify <obj>\n");
      return 1;
   }
   if(query_name()==str) {
      short_desc=query_true_desc();
      write("After a closer look, you decide it to be " + query_true_desc() +
            ".\n");
      say(TPN + "looks closely at " + query_name());
      set_read(read_msg+" (try 'quiet' to toggle the message printout)\n");
   }
   else {
      write("You cant identify "+str+".\n");
   }
return 1;
}

shutup() {
   quiet=!quiet;
   write("KLICK!\n");
   return 1;
}

set_true_desc(str) {
  true_desc=str; 
}
