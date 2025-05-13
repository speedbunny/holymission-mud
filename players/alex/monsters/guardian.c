int sleep,arg;
#define ME this_object()
inherit "/obj/monster";
 
   reset(arg) {
    ::reset(arg);
     if(arg) return;
 
    set_name("Guardian");
    set_alias("guardian");
    set_short("The guardian");
    set_long("This is a guardian of the higher planes who is here to guard the sword\n"+
             "watch out, he is VERY hard.\n");
    set_gender(1);
    set_level(95);
    set_aggressive(0);
    set_al(-1000);
    set_chance(25);
    set_spell_mess1("The guardian screams and you cower in fear.");
    set_spell_mess2("The guardian spits hell fire at you.");
    set_spell_dam(52);
    add_money(8000);
}
 
init() {
 ::init();
 add_action("take","take");
 add_action("get","get");
 remove_call_out("sleep_again");
}
 
heart_beat() {
 ::heart_beat();
 if (sleep == 1) {
   if (random(100)>50)
      say("CHCHCHC!!!!!!!!!\n");
    }
}
 
sleep_again() {
  sleep=1;
}
 
take() {
       write("The guardian screams and attacks you.\n");
        set_aggressive(1);
         return 1;
}
 
get() {
        write("The guardian screams and attacks you.\n");
         set_aggressive(1);
          return 1;
}
 
