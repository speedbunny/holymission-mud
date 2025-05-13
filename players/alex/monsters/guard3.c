int sleep,arg;
 
#define ME this_object()
inherit "/obj/monster";
 
   reset(arg) {
    ::reset(arg);
    if(arg) return;
    move_object(clone_object("/players/alex/weapons/gmace"),ME);
    move_object(clone_object("/players/alex/armour/helmet"),ME);
    command("wear ",ME);
 
    set_name("catguard");
    set_alias("guard");
    set_short(" A Tough catguard");
    set_long("The guard seems to be stoping evry one from getting past.\n" +
         "It is realy just a big cat but it is holding a mace and is NOT cuddly.\n");
 
    set_gender(1);
    set_level(10);
    set_aggressive(0);
    set_al(-100);
    set_chance(10);
    set_spell_mess1("Spins his mace and brings it down on your head.");
    set_spell_mess2("Brings his foot up and kicks you hard.");
    set_spell_dam(20);
    add_money(1000);
}
init() {
 ::init();
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
   write("The guard shouts: What you think you are strong enough to see.\n"+
         "Alex THE DARK DESTROYER?? you have to kill me first.\n");
  return 1;
}
 
 
