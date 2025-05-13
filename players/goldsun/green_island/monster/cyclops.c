inherit "/obj/monster";
#define SAY(x) tell_room(environment(this_object()),x)

reset(arg){
  
load_a_chat(40,({"Cyclops shouts: Muhahaha !\n",
	         "Cyclops says: I'll make my dinner from you.\n"}));

 ::reset(arg);
 if (arg) return;
set_name("cyclops");
set_race("giant");
set_short("Cyclops");
set_long("A large giant with one eye.\n");
set_wc(15+random(9));
set_gender(1);
set_ac(1);
set_aggressive(1);
set_al(-200);
set_level(13+random(15));
set_size(4);
add_money(2000+random(1000));
set_spell_mess2("Cyclops snatches a peace of your body !\n");
set_spell_mess1("Cyslops snatches a peace of enemies body !\n");
set_spell_dam(110);
set_chance(10);
if (random(15)<1){
  move_object(clone_object("players/goldsun/green_island/obj/bone_key"),
	this_object());
}
}

string query_plural(){
 return  "cyclops";
}

init()
{
    ::init();
add_action("up","up");
add_action("up","sneak");
}

int up(){
   write("Cyclops bars you the way !\n");
  return 1;
}

run_away(){
 write("This is Cyclops. There is no way to fear him.\n");
 return 1;
}

