inherit "obj/monster";
#include "/players/tatsuo/def.h"

string s;
int i;
void reset(int flag){
::reset(flag);
if (flag==0){
  set_name("godzilla");
  set_race("lizard");
  set_short("Godzilla");
  set_long("The Terror of the Orient, GODZILLA!\n"+
	   "He appears to have a huge stone key around his neck.\n");
  set_aggressive(1);
  set_level(76);
  set_hp(3012);
  set_ac(30);
  set_wc(60);
  set_wimpy(5);
  add_money(15000);
  set_spell_mess1("GODZILLA breathes FIRE at you!!!!");
  set_spell_mess2("Gozilla breathe fire!");
   set_chance(8);
set_al(-10000);
  set_spell_dam(60);
if (sscanf(file_name(this_object()), "%s#%d",s,i)==2){
call_out("wandering",30);
MO(CO("/players/tatsuo/ishikawa/obj/KEY"),TO);
}
}
}
init(){
 ::init();
 add_action("no_ass","assassinate");
 add_action("no_ass","backstab");
  add_action("no_hold","hold");
  add_action("no_hold","timehold");
}
no_ass(){
write("Godzilla notices your attempt.\n");
say(TPN+" tried to surprise Godzilla and failed.\n");
return 1;
}
no_hold(){
write("Godzilla resists your attempt.\n");
return 1;
}

wandering(){
string s;
int i;
random_move();
while(remove_call_out("wandering")!=-1);
if(sscanf(file_name(this_object()),"%s#%d",s,i)==2)
call_out("wandering",70);
}
monster_died(){
shout(this_player()->query_name()+" has saved Ishikawa from the terrible Godzilla!\n");
return 0;
}
