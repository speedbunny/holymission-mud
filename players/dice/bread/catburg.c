inherit "obj/food";

reset(arg)
{
    ::reset(arg);
    if(arg) return;
   set_name("catburger");
      set_short("Catburger");
 set_long("A smelly catburger, but maybe it's edible.\n");
    set_weight(1);
    set_strength(1);
   set_eater_mess("That catburger really tastes good !\n");
  set_eating_mess(" eats a catburger, and looks ridicules.\n");
}
prevent_insert() { return 0; }
