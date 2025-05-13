inherit "obj/food";
 
void reset(int arg) {
// Must call ::reset() first to initialize variables.
  ::reset(arg);
  if(arg) return;
 
  set_name("bread");
  set_alias_list(({"whole wheat","wheat","slice"}));
  set_strength(3);
  set_value(15);
  set_eater_mess("It tastes pretty good.\n");
  set_eating_mess(" eats a slice of bread.\n");
  set_short("A slice of whole wheat bread");
  set_long("This is a fairly fresh slice of whole wheat bread. "+
    "It is probably full of nutrients and tastes good.\n");
  set_weight(1);
}
