int sleep,arg;
 
#define ME this_object()
inherit "/obj/monster";
 
   reset(arg) {
    ::reset(arg);
     if(arg) return;
    move_object(clone_object("/players/alex/weapons/lspear"),ME);
    command ("wield spear");
    move_object(clone_object("/players/alex/armour/helmet"),ME);
    command("wear ",ME);
 
    set_name("A rotten corpse");
    set_alias("corpse");
    set_short("A rotten corpse");
    set_long("The corpse seems to be of a old traveler how wondered in to this\n"+
            "wood by mistake it was the biggest one of his life and death.\n");
    set_gender(1);
    set_level(2);
    set_aggressive(0);
    set_al(-100);
  
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
   write("The corpse raises a hand a stops you.\n");
   return 1;
}
