inherit "/obj/treasure";
 reset(arg){
  ::reset(arg);
 if (arg) return;
 set_alias("west_pass_valley_goldsun");
 set_long("pass coded by GOLDSUN (c) 1995\n");
 set_weight(0);
 }

drop(){
 return 1;
}

