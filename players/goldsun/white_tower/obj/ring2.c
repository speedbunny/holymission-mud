inherit "obj/armour";

reset(arg){
 ::reset(arg);

if (arg) return;
 set_name("red ring");
 set_alias("white_tower_g_ring_2");
 set_type("ring");
 set_short("A red ring");
 set_long("A red ring with WT sign on it.\n");
 set_ac(1);
 set_value(100);
 set_weight(1);
 }

query_quest_item(){ return 1; }

