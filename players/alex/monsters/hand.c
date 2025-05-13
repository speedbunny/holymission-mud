int sleep,arg;
inherit "/obj/monster";
 
   reset(arg) {
    ::reset(arg);
     if(arg) return;
 
 
    set_name("hand");
    set_alias("hand");
    set_short("hand");
    set_long("A long dead had which is holding on to your feet Very painfully.\n");
    set_gender(1);
    set_level(3);
    set_aggressive(0);
    set_al(-1000);
}
 
init() {
 ::init();
 add_action("east","east");
 add_action("west","west");
 add_action("south","south");
 add_action("north","north");
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
 
north() {
   write("The hand grabs your foot and stops you from leaving.\n");
   return 1;
}
south() {
   write("The hand grabs your foot and stops you from leaving.\n");
   return 1;
}
 
east() {
  write("The hand grabs your foot and stops you from leaving.\n");
  return 1;
}
 
west() {
  write("The hand grabs your foot and stops you from leaving.\n");
  return 1;
}
 
 
