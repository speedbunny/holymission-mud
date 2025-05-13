inherit "/obj/npc";               
#define TO this_object()
#define TP this_player()
#define env(x) environment(x)
#define Say(x) tell_room(env(TO),x);

string s;
object weap,arm;
int  i, num_sol, counter;


void make_corpse(int num){
 object co;
 tell_object(TP->query_attack(),"You killed "+num+" barbarians with your great hit.\n");
 Say(TP->query_attack()->query_name()+" killed "+num+" barbarians.");
 if (num>4) write("      COOL   !!!\n");
   else write("\n");
 for(i=0;i<num;i++){
    co=clone_object("/obj/corpse");
    co->set_name("barbarian");
    num_sol--;
    tell_room(env(TO),"Soldier falls to the dust.\n");
    transfer(co,env(TO));
 }
}

long(){
 write("Barbarian army. There are "+num_sol+" soldiers.\n");
 return 1;

}

void reset(int arg) {


    ::reset(arg);

  
    if (arg) return;
 
    set_name("barbarian army");
    set_alias("army");
    set_alt_name("soldier");
    set_race("army");
    set_short("Barbarian army");
    set_level(6);
    set_al(-1220);
    num_sol=random(50)+9;
    enable_commands();
    set_attacks_change(80);
    set_attacks(random(num_sol-2)+2);
    set_heart_beat(1);
    set_aggressive(0);
    set_wc(16);
    set_ac(5);
    set_hp(99*num_sol);
    add_money(random(11250));
/*
    weap = clone_object("/players/goldsun/sherwood/obj/solarm");
    arm = clone_object("/players/goldsun/sherwood/obj/solsword");
    transfer(weap,TO);
    transfer(arm,TO);
    command("wield sword");
    command("wear platemail");
*/
   if (sscanf(file_name(this_object()),"%s#%d",s,i)==2)
        call_out("wandering",330);
  
}


heart_beat(){
  ::heart_beat();

 counter++;
                                 /* 1 soldier has 99 hp */

 if (query_hp()<query_max_hp()-99 &&  num_sol>1){

        make_corpse((query_max_hp()-query_hp() ) / 99);
        reduce_hit_point(query_hp()-query_max_hp());
        set_attacks(random(num_sol-2)+2);
 }
 if (counter>120){
   counter=0;
   wandering();
 } 
return 1;
}

init(){
 ::init();
 add_action("check","check");
}

void check(){
 if (this_player()->query_immortal()){
 write("DEBUG of Soldier : ");
 write(file_name(this_object())+"\n");
 write("Counter in heart_beat = "+counter+"\n");
 write("Number of soldiers ="+num_sol+"\n");
 }
}



int catch_tell(string str){
 string who, where;

    if (sscanf(str, "%s leaves %s.\n",who,where)==2){
        call_out("moven",8,where);
     }
    return 1;
}

int moven(string where) {
    
    return command(where,this_object());
}

int wandering() {

    random_move();
    while (remove_call_out("wandering") !=-1);
    if (sscanf(file_name(TO), "%s#%d",s,i)==2)
        call_out("wandering",330);
    return 1;
}


