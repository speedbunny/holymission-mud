inherit "/obj/treasure";

reset(arg){
 ::reset();

if (arg) return;
 set_id("grass");
 set_short("A tuft of grass");
 set_long("A tuft of fresh grass.\n");
 set_value(0);
 set_weight(1);
 }
