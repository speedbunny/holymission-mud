inherit "/obj/treasure";
reset(arg){
if (arg) return;
set_alias("tooth");
set_short("A silver rat tooth");
set_long("A silver rat tooth. Something in your minds tells you that\n"
       +"it is magical tooth.\n");
set_weight(1);
set_value(0);
}

query_quest_item(){ return 1; }

id_quest(arg){
 return arg=="help_hern";
}
