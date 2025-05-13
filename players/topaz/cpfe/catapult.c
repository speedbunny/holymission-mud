inherit"obj/treasure";
#include "/players/exos/defs.h"
   object target, there, here, item, ob;
   int LOADED, load_name, i ;
   int uses;
   
reset(arg) {

  if(arg) return;
  
   set_id("catapult");
   set_alias("trebuchet");
   set_short("A battered trebuchet");
   set_long(
           "It looks like a catapult, but uses a massive counter-weight\n"
         + "system to hurl objects long distances. Objects may be ARMed \n"
   +"and then you may FLING them at a target.\n");
  set_weight(2000);
uses=random(10)+1;
 }
 
 
 init(){
   ::init();
   add_action("arm", "arm");
   add_action("fling", "fling");
   }
   
   
get() {
   write("It is secured to the ground.\n");
    say(this_player()->query_name()+" tries to take the trebuchet, but is too wimpy.\n");
   return 0;
}

 
arm(arg) {
   if (!arg)
   return 0;
   if(LOADED) {
   write("There is already "+item->short()+" in the catapult.\n");
   return 1;   
   }

   item = present(arg,this_player());
   
   if(item){
   move_object(item,this_object());
    this_player()->add_weight(-item->query_weight());  /* :-) */
   write(item->short()+" loaded\n");
   say(this_player()->query_name()+" loads "+arg+" into the catapult.\n");
   LOADED = 1;
   return 1;
   }
   
   else
   {
   write("You dont have that!\n");
   return 1;
   }
}


fling(arg) {
string name;
int busy;

   if(!arg)
   return 0;
   
   if(!LOADED){
   write("The trebuchet is not loaded with anything.\n");
   return 1;
      }
      
   if(arg == "Exos")
   {
   name = this_player()->query_name();
   command("fling "+name);
   return 1;
   }
   
   target = find_living(arg);
   
 if(!target){
   write(arg+" is not on!\n");
   return 1; }
   
   there = environment(target);
   name = target->query_name();
   ob = users();
   write("The trebuchet snaps forward with a loud clatter!\n");
   say("The trebuchet snaps forward with a loud clatter!\n");
   
if(!TPWIZ) {
   shout("Something is catapulted over your head!\n");
}
   for(i=0;i<sizeof(ob);i++){
   
  if(ob[i]->query_name() == "Atanse") {
   tell_object(ob[i],this_player()->query_name()+" splatted "+
    target->query_name()+"\n");
      }

  if(environment(ob[i]) == there && ob[i] !=target) {
   tell_object(ob[i],name +" is smacked in the back of the head with a flying "+
   item->short()+ " and falls to the grould, writing in pain!\n");
   }

    busy = target->query_earmuff_level();  /* we take the query_earmuff_level(int) :-) */
    if(ob[i] == target && (busy<30)) {
   tell_object(ob[i],"OWWW "+item->short()+" comes flying through the air and smacks you in the back of your head!\n");
   tell_object(ob[i], "\nYou were smacked by "+this_player()->query_name()+"\n");
   ob[i]->hit_player(random(item->query_weight())+2);
  }
}
      item->dest_me();
LOADED = 0;
uses--;
if(uses==0) {
   write("The catapult seems to implode!  Oops you broke it!\n");
   TP->hit_player(20);
   DEST(TO);
   return;
}
return 1;
}

