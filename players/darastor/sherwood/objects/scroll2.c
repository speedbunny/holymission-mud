inherit "/obj/treasure";

reset(arg){
 if (arg) return;
 set_id("scroll");
 set_read("Old chest opened by a snake key.\n");
 set_short("A scroll");
 set_long("An old scroll.\n");
 set_weight(1);
 set_value(2);
 }
