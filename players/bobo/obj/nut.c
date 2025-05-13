inherit "/obj/food";

void reset(int arg) {
   ::reset (arg);
   if(arg) return;
   set_name("nut");
   set_short("A yummy looking nut");
   set_long("A large acorn.  It looks very delicious.\n");
   set_value(2);
   set_weight(1);
   set_eater_mess("You bite into the nut and are highly satisfied.\n");
   set_strength(5);
}
