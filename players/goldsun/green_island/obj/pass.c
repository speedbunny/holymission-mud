inherit "/obj/treasure";
#define TO this_object()



 reset(arg){
  ::reset(arg);
 if (arg) return;
   set_alias("goldsun_pass_over_abyss");
   set_weight(0);
 }


void end_this(){
 destruct(TO);
}

int drop(){
 return 1;
}

