inherit "obj/food";

reset(arg) {
  ::reset(arg);
if (arg) return;
   set_name("cheese");
   set_short("a piece of cheese");
   set_long("A delicious smelling piece of Emmentaler.\n");
   set_eater_mess("Yuuummmmm, that cheese tastes fine.\n");
   set_eating_mess(" eats a delicious Ementhaler.\n");
   set_weight(1);
   set_value(30);
   set_strength(10);
}
