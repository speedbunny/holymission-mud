inherit "/obj/monster";

#define TO this_object()
#define TP this_player()
#define env(x) environment(x)
#define STUDENT1 "/players/goldsun/nottingham/monster/robert"
#define STUDENT2 "/players/goldsun/nottingham/monster/akimo"
#define STUDENT3 "/players/goldsun/nottingham/monster/hassan"
#define ROOM(x) tell_room(env(TO),x)

object my_student,shd;
status how,now;

void defeat(){
 ROOM("Master says: You are defeated ! It is end of tournament !\n");
 my_student=0;
 now=0;
 STUDENT1->set_enemy(0);
 STUDENT2->set_enemy(0);
 STUDENT3->set_enemy(0);
}

int query_busy(){ 
 if (TO->query_attack()) return 1;
 if (my_student) return 1;
 return 0;
}

void student2(int death){
 if (!present("la Akimo"),env(TO)){
   move_object(STUDENT2,env(TO));
 }
 tell_object(my_student,"DEATH IN MASTER=");
 write(death);
 STUDENT1->set_enemy(0);
 ROOM("Master says angrilly: OK. You defeat my first student.\n");
 ROOM("Master says: But my next student defeat you !\nMaster bows to La Akimo.\n");
 if (my_student){ STUDENT2->start_fight(my_student,death); }
}

void student3(int death){
 if (!present("el hassan"),env(TO)){
   move_object(STUDENT3,env(TO));
 }
 STUDENT2->set_enemy(0);
 ROOM("Master says angrilly: OK. You defeat my second student.\n");
 ROOM("Master says: But my next student defeat you !\nMaster bows to El Hassan.\n");
 if (my_student){ STUDENT3->start_fight(my_student,death);}
}

void start_fight(status death){ 

  how=death;
  now=1;
  STUDENT3->set_enemy(0);
  ROOM("Master says angrilly: OK. You defeat my last student.\n");
  ROOM("Master says: I defeat you !\n");
  if (!death){
     shd=clone_object("/players/goldsun/nottingham/obj/fight_shad");
     transfer(shd,my_student);
     shd->start_shadow(my_student,0,"fight_shad");
  } 
  ROOM("Master says: If you are ready, bow to me.\n");

}


void reset(int arg)
 {
 ::reset(arg);

if (arg) return;

set_name("master");
set_race("human");
set_short("Master of fence school");
set_long("Master of fence school.\n"+
	 "He can teach you selfdefence or\n"+
	 "he can fight with you. You can 'ask him' for more\n"+
	 "information.\n"); 
set_wc(22);
set_ac(4);
set_al(1000);
set_gender(1);
enable_commands();
set_aggressive(0);
set_level(43);
set_size(3);
now=0;
set_dead_ob(TO);
}

monster_died(object ob){
 object att;

 if (!how){    /* not how == not to death */
    att=ob->query_attack();
    att->stop_fight();
    this_object()->stop_fight();
    att->stop_hunter(1);
    this_object()->stop_hunter(1);
    shd->mend_shadow();
    transfer(my_student,"/players/goldsun/nottingham/room/f_school");
    transfer(this_object(),"/players/goldsun/nottingham/room/f_school");
    ROOM("Master says: "+my_student->query_name()+
	". You win this tournament !!!\nHere is your reward.\n");
    move_object(clone_object("/players/goldsun/nottingham/obj/master_key"),TO);
    command("drop key");
    tell_object(my_student,"Master points at chest.\n");
    return 1;
 }
   transfer(my_student,"/players/goldsun/nottingham/room/f_school");
   move_object(clone_object("/players/goldsun/nottingham/obj/master_key"),
	"/players/goldsun/nottingham/room/f_school");
   shout("Master of Fence school shouts: "+my_student->query_name()+
	" wins the tournament ! "+capitalize(my_student->query_pronoun())+
        " defeats me !\n");
    
}


init(){
 ::init();
 add_action("fight","fight");
 add_action("teach","teach");
 add_action("leave","leave");
 add_action("kill","kill");
}

int kill(string str){
 if (str=="master"){
  write("Master says: Don't do it ! I am coded by Goldsun ONLY FOR\n"+
	"SPECIAL actions. If you do it, you'll cause a bug !\n");
  return 1;
 }
}

int fight(string str){

 notify_fail("Fight to death or fight for fun ?\n");
 if (!str) return 0;

 if (query_busy()){ 
   write("I am already in tournament.\n");
   return 1;
 }
 
 if (str=="to death" || str=="to the death"){
  ROOM("Master says: Great. You have to defeat my students at first.\n"+
       "Warning !!!  You can be killed by my students !\n");
  ROOM("Master says: If you want to end this tournament, type \"leave\"\n");
  ROOM("Master says: You can leave tournament only after each fight.\n");
  ROOM("Master bows to Robert.\n");
  my_student=TP;
  STUDENT1->start_fight(my_student,1);
  return 1;
 }
 if (str=="for fun" || str=="for a fun"){
  ROOM("master says: Great. You have to defeat my students at first.\n");
  ROOM("Master says: If you want to end this tournament, type \"leave\"\n");
  ROOM("Master says: You can leave tournament only after each fight.\n");
  ROOM("Master bows to Robert.\n");
  my_student=TP;
  STUDENT1->start_fight(my_student,0);
  return 1;
 }
 return 0;
}

int leave(){

 if (TP==my_student){
   ROOM("Master says: "+TP->query_name()+", you leave the tournament.\n");
   my_student=0;
   now=0;
   STUDENT1->set_enemy(0);
   STUDENT2->set_enemy(0);
   STUDENT3->set_enemy(0);
   return 1;
 }
 return 0;
}
 
catch_tell(string str){
 string who;

 if (sscanf(str,"%s bows before you.",who)==1){
 if (this_player()==my_student && now==1){
     say(this_player()->query_name()+" bows to Master.\n");
     write("You bow to Master.\n");
     ROOM("Master says: Ok. FIGHT ! \n");
     transfer(my_student,"/players/goldsun/nottingham/room/empty");
     transfer(this_object(),"/players/goldsun/nottingham/room/empty");
     attack_object(my_student);
     return 1;
 }
    
    write("Master bows before you.\n");
    say("Master bows to "+who+".\n");
 }
} 
