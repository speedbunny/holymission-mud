inherit "/obj/treasure";
 reset(arg){
  ::reset(arg);
 if (arg) return;
 set_alias("goldsun_pass_to_rel");
 set_long("religion obj coded by GOLDSUN (c) 1995\n");
 set_weight(0);
 }

drop(){
 return 1;
}

