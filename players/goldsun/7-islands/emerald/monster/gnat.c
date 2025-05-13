inherit "/obj/npc";               
#define TO this_object()
#define TP this_player()
#define env(x) environment(x)
#define Say(x) tell_room(env(TO),x);
#define saY(x) say(x,TP->query_attack())
#define HP 5   /* gnat's hp */


string s;
int  num_;


void make_corpse(int num){
 object co;
 int i;

 tell_object(TP->query_attack(),"You killed "+num+" gnats with your great hit.\n");
 saY(TP->query_attack()->query_name()+" killed "+num+" gnats.\n");
 if (num>10) write("      COOL   !!!\n");
   else write("\n");
 for(i=0;i<num;i++){
    co=clone_object("/obj/corpse");
    co->set_name("gnat");
    num_--;
    tell_room(env(TO),"Gnat falls headlong down.\n");
    transfer(co,env(TO));
 }
}

long(){
 write("Swarm of gnats. There are "+num_+" gnats.\n");
 return 1;

}

void reset(int arg) {


    ::reset(arg);

  
    if (arg) return;
 
    set_name("gnat swarm");
    set_alias("swarm");
    set_alt_name("gnats");
    set_race("gnat");
    set_short("A gnat swarm");
    set_level(9);
    set_al(-20);
    num_=random(50)+9;
    set_attacks_change(50);
    set_attacks(random(num_-2)+1);
    set_heart_beat(1);
    set_aggressive(0);
    set_wc(1);
    set_hp(HP*num_);
}


heart_beat(){
  ::heart_beat();

 if (query_hp()<query_max_hp()-HP &&  num_>1){

        make_corpse((query_max_hp()-query_hp() ) / HP);
        reduce_hit_point(query_hp()-query_max_hp());
        set_attacks(random(num_-2)+1);
 }
return 1;
}

