#include "/players/tatsuo/guild/ndef.h"

main(arg){

object ob1, wep;
int fault, catchit, i;
string nam;

  if(environment(TP)->query_property("no_fight")){ 
  return printf("This is not a place of violence.\n"),1; }

if(TP->query_ghost()) return printf("You are completly dead.\n"),1;
 
 if (TPL < 20) return printf("Such feats are beyond you.\n"),1;
 
if(!TP->query_wielded()) return printf("You need a weapon for this.\n"),1;

  if(TP->query_sp() < DISARM_COST){

    printf("You cannot summon the strength to disarm anyone.\n");
    return 1;
  }

  if(!arg) {
  
   ob1= TP->query_attack();
   if(ob1) arg = ob1->query_name();
  }

  else ob1=present(arg,environment(TP));
  
  if ((!ob1) || (!living(ob1))){
  return printf("Disarm who?\n"),1;
  }

  nam = ob1->query_name();
  wep = all_inventory(ob1);
  fault = 0;
  catchit = 0;
 ob1->attack_object(TP);

for (i=0; i<sizeof(wep); i++){
    if(wep[i]->query_wielded()) {
      fault=1;
    if(random(DISARMSKILL) > ob1->query_level() && wep[i]->query_wc() < 16){ 
       wep[i]->stop_wielding();
          if((random(TPL) > random(ob1->query_level()))){
            transfer(wep[i],TP);
            catchit = 1;
          }
      else { TP->drop(wep[i]); }

        printf("You twist "+nam+"'s weapon away.\n");
      tell_object(ob1, TPN+" twists your weapon from your grasp!\n",ob1);
        say(TPN+" twists "+nam+"'s weapon from "+ob1->query_possessive()+" grasp!\n",ob1);
      if(catchit) {
       printf("You catch the weapon!\n");
         tell_object(ob1, TPN+" catches your weapon in midair!\n");
      say(TPN+" catches the weapon in midair!\n",ob1);
       } 
      return 1;
     }
    else {
      write("You attempt to disarm and FAIL!\n");
       tell_object(ob1, TPN+" does some flashy shit and fails to disarm you.\n");
    say(TPN+" does some flashy moves and FAILS to disarm "+nam+"!\n",ob1);
    return 1;
   }

  } 
 }
 
if(!fault) {
  write(nam+" is not wielding a weapon!\n");
  return 1;
  }
 TP->restore_spell_points(- DISARM_COST);
  ob1->attack(TP);
 return 1;
}

 

