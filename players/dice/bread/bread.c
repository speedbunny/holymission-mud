inherit "obj/food";

reset(arg)
{
    ::reset(arg);
    if(arg) return;
   set_name("bread");
      set_short("Bread");
    set_long("A delicious-looking praline bonbon.\n");
    set_weight(1);
    set_strength(5);
   set_eater_mess("That bread really tastes good, you feel stronger !\n");
  set_eating_mess(" eats some bread, and looks better.\n");
}
prevent_insert() { return 0; }
