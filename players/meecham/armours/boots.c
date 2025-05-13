inherit "obj/armour";
#define TP this_player()
reset(arg)
{
  ::reset(arg);
  if(arg) return;
  set_name("boots");
  set_ac(1);
  set_short("Meecham's boots");
  set_long("Meecham's boots of healing.\n");
}

init()
{
  ::init();
  if(TP->query_name()=="meecham" && TP->query_hp()<TP->query_max_hp())
  {
    TP->heal_self(1000);
    return 1;
  }
}
