#define TP this_player()
#define TPN TP->query_name()
#define SAY(x) tell_room(environment(),x)
#define PPATH "/players/whisky/mill_quest/"

inherit "obj/monster";

reset(arg){
 ::reset(arg);
 if(!arg){
    set_name("hobbe");
    set_alt_name("hobbit");
    set_long("You see Hobbe the hobbit:\n"+
             "He looks very strong. He has a potato nose,\n"+
             "donkey ears and goggle eyes. He smiles friendly at you.\n");
    set_gender(1);
    set_level(2);
    set_ac(40);
    }
}
   
init(){
   add_action("show", "show");
   add_action("give", "give");
   ::init();
}
catch_tell(arg){
string who;
    
 if(sscanf(arg,"%s arrives", who)==1) {
      if ((PPATH+"path4")->check_boulder()==0)
         call_out("unhappy",3);
      else {
         if(present("millhonour",TP))
            call_out("solved",3);
         else
            call_out("happy",3);
      }
   }       
   return 1;
}
    
        
unhappy() {
   SAY( "Hobbe scratches his head thinking.\n" );
   call_out("unhappy1", 3);
}

unhappy1() {
   SAY( "Hobbe says: Do you understand why the wheel doesn't turn?\n" );
   call_out("unhappy2", 2);
}

unhappy2(){
   SAY("Hobbe bursts into tears!\n");
   call_out("unhappy3", 4);
}

unhappy3(){
   SAY("Hobbe says: I wish that I could find somebody to help me.\n");
}


happy(){
   SAY("Hobbe smiles brightly.\n");
   call_out("happy1", 3);
}

happy1(){
   SAY("Hobbe flips head over heels.\n");
   call_out("happy2", 2);
}

happy2(){
   SAY("Hobbe takes your hands and dances around with you.\n");
}

solved(){
   SAY("Hobbe says: I see, there is someone who helped me.\n");
   call_out("solved1", 3);
}

solved1(){
   SAY("Hobbe flips head over heals.\n");
   call_out("solved2", 2);
}

solved2(){
   SAY("Hobbe scratches himself thinking.\n");
   call_out("solved3", 4);
}

solved3(){
   SAY( "Hobbe says: I wish that the person who helped me could show me the tool\n" +
        "            with which the mill was repaired.\n" );
}

give(arg) {
string what;

  if(!stringp(arg) || !arg) {
    write("Give what ?\n");
    return 1;
  }
 if((sscanf(arg,"%s to hobbit",what)==1) || (sscanf(arg,"%s to hobbe",what)==1)) {
    write("Hobbes says: Keep your stuff, I am no beggar !\n");
    return 1;
  }
  return;
}

show(arg){
object ob;

 if(arg=="hammer to hobbit" || arg=="hammer to hobbe" || arg=="hammer") {
   if(present("hobbithammer",TP)) {
	ob = present("millhonour", TP);
     if(ob){
          write("Hobbe says: Oh, thanks for helping me, here are 200 coins reward !\n");
          this_player()->set_quest("millquest");
          TP->add_money(200);
          destruct(ob);
         }
      else
          write("Yes, that's a fine hammer, where have you found it ?\n");
      }
   else
       write("You have no hammer !!!!\n");
       return 1;
   }
   return;
}
