# define coins coins
# define numb %d
#define str coins
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
    set_short("A sleepy guard");
    set_long("The guard seems to be half asleep, he is slumped against the wall.\n");
 
    set_gender(1);
    set_level(15);
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
add_action("up","up");  
add_action("bribe","bribe");
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
     
up() {
  write("The guard stands up and growls: Where do you think you are going??\n");
  return 1;
}    
 
bribe() {
if(! "coins") {  
notify_fail("Bribe guard with coins.\n");
return 0;
         }
  if(sscanf("coins", "guard with %d coins", numb) == 1) {
        if(numb > 199) {
        dest and such
         return 1;
        }
  else {
  write("I do not fall for your puny bribes.\n");
    return 1;
         }
        }
        notify_fail("Bribe guard with coins.\n");
         return 0;  
         }
    
