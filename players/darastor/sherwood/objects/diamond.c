inherit "/obj/treasure";

reset(arg){
if (arg) return;
 set_id("diamond");
 set_short("A bright diamond");
 set_long("A very bright diamond. It seems to be very valuable.\n");
 set_weight(1);
 set_value(3000);
}
