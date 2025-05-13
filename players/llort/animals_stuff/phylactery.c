inherit "/obj/armour";

object phy;

query_mage_wear() { return 1; }
query_monk_wear() { return 1; }
query_ninja_wear() { return 1; }

void reset(int arg) 
{
    ::reset(arg);
    if (arg == 0) 
    {
      set_name("phylactery");
      set_alias("phylactery of free action");
      set_type("arm");
      set_ac(2);
      set_short("Phylactery of Free Action");
      set_long("A perfectly crafted silver band, made to put it around the "+
               "upper arm.\n");
      set_weight(1);
      set_value(17355);
    }
}

init()
{
  ::init();
}

mixed wear(object me)
{
  int res;
  if(!this_object()->query_worn() && (res=::wear(me)))
  {
    phy=clone_object("/obj/shadows/free_action_shad");
    phy->start_shadow(this_player(),0);
    return res;
  }
  return ::wear(me);
} 

int drop(mixed x)
{
   remove("phylactery");
   return 0;
}

mixed remove(string me)
{
  int res;

  if(this_object()->query_worn() && ::remove(me))
  {
   if(phy) destruct(phy); 
   return 1;
  }
  return ::remove(me);
}
