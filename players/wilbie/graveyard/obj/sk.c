inherit "/obj/treasure";
reset(arg){
if (arg)return;
set_id("skeleton");
set_short("A battered skeleton");
set_long("This looks like the battered skeleton on a large human. "+
         "Whoever it was obviously died very hard!\n");
set_value(10);
set_weight(5);
}
