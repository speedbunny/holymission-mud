inherit "/obj/treasure";

void reset(int i){
 ::reset(i);
 if (i) return;
 set_name("feathers");
 set_short("A coloured feathers");
 set_long("A coloured duck feathers.\n");
 set_weight(1);
 set_value(99);
}

