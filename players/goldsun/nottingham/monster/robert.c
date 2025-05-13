inherit "/obj/monster";
#define MASTER "/players/goldsun/nottingham/monster/master"
#define ROOM(x) tell_room(environment(this_player()),x)
#define TO this_object()

object enemy,shd;
void how;

void heal(){
 reduce_hit_point(query_hp()-query_max_hp());
}

void set_enemy(object en){ enemy=en; }   /* for ending fighting */

void start_fight(object en,void death){

 enemy=en;
 how=death;
 if (!death){
    shd=clone_object("/players/goldsun/nottingham/obj/fight_shad");
    transfer(shd,enemy);
    shd->start_shadow(enemy,0,"fight_shad");
 } 
 ROOM("Robert says: If you are ready, bow to me.\n");

}

void reset(int arg)
 {
 ::reset(arg);

if (arg) return;

set_name("robert");
set_alt_name("student");
set_race("hobbit");
set_short("Robert the student of fence");
set_long("Robert the hobbit.\nHe is student of fence.\n");
set_wc(16);
enable_commands();
set_gender(1);
set_ac(5);
set_al(100);
set_aggressive(0);
set_level(9);
set_size(3);
move_object(clone_object("/players/goldsun/nottingham/obj/rapier"),TO);
command("wield sword");
set_dead_ob(this_object());
}

void not_worry(){
   ROOM("Robert smiles happily.\n");
   ROOM("Robert says: You, don't worry. I am alive. You win this match.\n");
}
   
monster_died(object ob){
 object att;

 if (!how){    /* not how == not to death */
    att=ob->query_attack();
    att->stop_fight();
    this_object()->stop_fight();
    att->stop_hunt();
    this_object()->stop_hunt(1);
    shd->mend_shadow();
    not_worry();
    transfer(enemy,"/players/goldsun/nottingham/room/f_school");
    transfer(this_object(),"/players/goldsun/nottingham/room/f_school");
    MASTER->student2(how);
 return 1;
 }
  transfer(this_player(),"/players/goldsun/nottingham/room/f_school");
  MASTER->student2(how);
}

init(){
 ::init();
add_action("fight","ready");
}

int fight(){
 if (this_player()==enemy){
    say(this_player()->query_name()+" bows to Robert.\n");
    write("You bow to Robert.\n");
    ROOM("Robert says: Ok. FIGHT ! \n");
    transfer(enemy,"/goldsun/nottingham/room/empty");
    transfer(this_object(),"/players/goldsun/nottingham/room/empty");
    attack_object(enemy);
    return 1;
 }
 return 0;
}
 

catch_tell(string str){
 string who, vic;

 if (sscanf(str,"You killed %s",who)==1){
   vic=capitalize(enemy->query_real_name())+".\n";
tell_object(find_player("goldsun"),"who>>"+who+"<<\n>>"+vic+"<<\n");
   if (who==vic){
     transfer(enemy,"/players/goldsun/nottingham/room/f_school");
     transfer(this_object(),"/players/goldsun/nottingham/room/f_school");
     heal();
     MASTER->defeat();
     return 1;
   }
 }
 if (sscanf(str,"%s bows before you.",who)==1){
 if (this_player()==enemy){
     say(this_player()->query_name()+" bows to Robert.\n");
     write("You bow to Robert.\n");
     ROOM("Robert says: Ok. FIGHT ! \n");
     transfer(enemy,"/players/goldsun/nottingham/room/empty");
     transfer(this_object(),"/players/goldsun/nottingham/room/empty");
     attack_object(enemy);
     return 1;
 }
    
    write("Robert bows before you.\n");
    say("Robert bows to "+who+".\n");
 }
} 
