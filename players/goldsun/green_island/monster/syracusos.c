inherit "/obj/monster";
#define SAY(x) tell_room(environment(this_object()),x)

reset(arg){
  
load_a_chat(40,({"Cyclop shouts: Muhahaha !\n",
	         "Cyclop says: I'll make my dinner from you.\n"}));

 ::reset(arg);
 if (arg) return;
set_name("syracusos");
set_alt_name("cyclops");
set_race("giant");
set_short("Cyclops");
set_long("Syracusos the king of cyclops.\n"+
         "He is large giant with one eye.\n");
set_wc(34);
set_gender(1);
set_ac(3);
set_aggressive(1);
set_al(-500);
set_level(43);
set_size(4);
set_spell_mess2("Cyclops snatches a peace of your body !\n");
set_spell_mess1("Cyslops snatches a peace of enemies body !\n");
set_spell_dam(110);
set_chance(10);
}

init()
{
    ::init();
add_action("enter","enter");
}

int enter(){
   write("Syracusos bars you the way!\n");
   return 1;
 }

run_away(){
 write("This is Cyclops. There is no way to fear him.\n");
 return 1;
}

