int sleep,arg;
 
#define ME this_object()
inherit "/obj/monster";
 
   reset(arg) {
    ::reset(arg);
     if(arg) return;
    move_object(clone_object("/players/alex/weapons/bow"),ME);
    move_object(clone_object("/players/alex/armour/helmet"),ME);
    command("wear ",ME);
 
    set_name("master bowman guard");
    set_alt_name("bowman");
    set_alt_name("cathan");
    set_alias("guard");
    set_short(" A master bowman Cathan guard");
    set_long("This guard is obviouly a good shot with his bow and is\n"+
            "looking at the open plains, but mostly he looks at the forest.\n" +
            "he seems to make his home just east of here but he would not\n"+
            "like trespassers.\n");
 
    set_gender(1);
    set_level(15);
    set_aggressive(0);
    set_al(-100);  
    set_chance(10);
    set_spell_mess1("Pulls out a arowe from his quiver and shoots you.");
    set_spell_mess2("Jumps up and hits you with his head OUCHH!!!.");
    set_spell_dam(20);
    add_money(1000);
}
init() {  
 ::init();
 add_action("east","east");
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
 
east() {
   write("The master bow man steps in your way and holds his bow tighter\n" +
         "He growls: Where do you think you are going??\n");
  return 1;
}
 
