inherit "obj/treasure";

reset(arg) {
   if (arg) return 1; 
   set_id("cone");
   set_short("A spruce cone");
   set_long("A big brown spruce cone\n");
   set_value(20);
   set_weight(1);
}
