inherit "/obj/treasure";

reset(arg){
if (arg) return;
set_name("arrow");
set_value(0);
set_alias("arrow");
set_weight(1);
set_short("Magic arrow");
set_long("Magic silver arrow. You feel strange energy from it.\n");
}

query_quest_item(){ return 1;}

id_quest(str){
 return str=="help_hern";
} 
