inherit "obj/armour";

reset(arg){
 ::reset(arg);

if (arg) return;
 set_name("green ring");
 set_alias("white_tower_g_ring_1");
 set_type("ring");
 set_short("A green ring");
 set_long("A green ring with WT sign on it.\n");
 set_ac(1);
 set_value(100);
 set_weight(1);
 }

query_quest_item(){ return 1; }

