inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"
object key_obj;
void reset(int arg){
    ::reset(arg);
if(arg) return;
    set_name("orgetorix");
    set_race("human");
    set_gender(1);
    set_alias("guard");
    set_alt_name("captain");
    set_short("Orgetorix");
            set_long(
"This is Orgetorix, the captain of the Bismarck Guard.  He is easily "+
"eight feet tall and three feet across the chest.  He is covered virtually "+
"head to toe in steel armour.  The visor of his helmet is up and his pale "+
"white skin and blue eyes shine with an inner light.\n")+
    set_level(50);
    set_hp(5000);
    set_al(1000);
    set_ac(20);
    set_wc(40);
    move_object((clone_object(bi+"/longsword.c")),this_object());
    move_object((clone_object(bi+"/gauntlets.c")),this_object());
    move_object((clone_object(bi+"/boots.c")),this_object());
    move_object((clone_object(bi+"/shield.c")),this_object());
    move_object((clone_object(bi+"/helmet.c")),this_object());
    move_object((clone_object(bi+"/platemail.c")),this_object());
    key_obj = clone_object(bi+"/key.c");
    move_object(key_obj, TO);
    init_command("wield longsword");
    init_command("wear shield");
    init_command("wear gauntlets");
    init_command("wear boots");
    init_command("wear helmet");
    init_command("wear platemail");
    add_money(500);
    }
init(){
  ::init();
  heart_beat();
}
heart_beat(){
  object ob;
  ob=this_object()->query_attack();
  ::heart_beat();
  if(this_object()->query_attack()){
    tell (ob,this_object()->query_name()+" punches you in the face.\n");
    say(this_object()->query_name()+" punches "+TP->query_name()+" in the face.\
n");
    ob->hit_player(random(50));
    return;
  }
}
catch_tell(arg)
  {
string str1;
 if (sscanf(arg,"%s key",str1)==1){
 if(!present("#QMED#",this_player())){
  write("Only a member of my guard can have the key.\n");
  return 1;
}
else{
write("Here guardsman, go check on the princesses safety.\n");
move_object(key_obj,this_player());
return 1;
}
}
}
