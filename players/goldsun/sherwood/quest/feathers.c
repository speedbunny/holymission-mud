inherit "/obj/treasure";

reset(arg){
if (arg) return;
set_name("feathers");
set_value(0);
set_alias("feathers");
set_weight(1);
set_short("The feathers");
set_long("The magic feathers.\n");
}

query_quest_item(){ return 1;}
 
id_quest(arg){
 return arg == "help_hern";
}
