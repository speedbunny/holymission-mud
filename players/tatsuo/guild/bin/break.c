#include "/players/tatsuo/guild/ndef.h"

main(arg) {
 
string nam;
object ob1, wep;
int i, ii, iii, fault;
if(TP->query_level()<15) return printf("You do not command the skill to do this.\n"),1;


if(environment(TP)->query_property("no_fight")) 
  return printf("This is not a place of violence.\n"),1;


if(TP->query_sp() < BREAK_COST) 
   return printf("You are much to tired to accomplish this.\n"),1;      

if(present("heart_beat",TP)) 
  return printf("You are just beggining the next attack.\n"),1;

if(arg==TP->query_real_name())
  return printf("You hurt yourself badly in the attempt.\n"),1;
if(!TP->query_wielded()) return printf("You need a weapon for this.\n"),1;
 
if(!arg){

 ob1=TP->query_attack();
  }
  else ob1=present(arg,environment(TP));  if((!ob1) || (!living(ob1))){
  return printf("Whose weapon do you wish to break?\n"),1;
  
}

nam = ob1->query_name();
wep = all_inventory(ob1);
ob1->attack_object(TP);

for(i=0; i<sizeof(wep); i++){

 if(wep[i]->query_wielded() && wep[i]->query_wc() < TPL/2 ){
  fault=1;
  if(random(120) < BREAKSKILL){
  wep[i]->stop_wielding();
  printf("You strike a blow that shatters "+nam+"'s "+
          wep[i]->short()+"!\n");
  TP->add_exp(wep[i]->query_wc()*2);
  destruct(wep[i]);
  tell_object(ob1, TPN+" shatters your weapon with a terrible blow.\n");
  say(TPN+" shatters "+nam+"'s weapon with a feirocious hit.\n",ob1);
  return 1;
  } 
      
  else {

   printf("You strike a blow at "+nam+"'s weapon and it fails to wield!\n");
   tell_object(ob1,TPN+" executes a fierce blow on your weapon, but you stand firm.\n");
   say(TPN+" attempts to shatter the weapon of "+nam+" to no avail.\n",ob1);
   
    if(random(50) < 30 && TP->query_wielded()->query_wc() < 17 ){
     tell_object(ob1,TPN+" loses control of "+TPOSS+" weapon and it flies into the air!\n");
     printf("You lose control of your weapon and it flies high into the air!\n");
     say(TPN+" loses control of "+TPOSS+" weapons and it flies high into the air!\n",ob1);
     for(ii=0; ii<sizeof(all_inventory(TP)); ii++){
     if(all_inventory(TP)[ii]->query_wielded()){
     all_inventory(TP)[ii]->stop_wielding();
     move_object(all_inventory(TP)[ii], environment(TP));
       }
      }
     return 1;
     }
    }
   }
  }  
     
   
 if(!fault){
  printf(nam+ " is not wielding a weapon.\n");
  return 1;
 }

ob1->attack_ob(TP);
TP->restore_spell_points(- BREAK_COST);
move_object(clone_object("/players/tatsuo/guild/heart_beat"),TP);
return 1;
}
 



