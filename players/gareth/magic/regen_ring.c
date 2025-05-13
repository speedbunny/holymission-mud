inherit "obj/armor";
 
int counter;
 
void reset(int arg)
{
  ::reset(arg);
  if(arg) return;
  counter=0;
  set_name("ring");
  set_short("Sauron's ring");
  set_long("One of the rings of power!!\n"+
           "This ring will heal the wearer without cost!\n");
  set_value(5000);
  set_size("any");
  set_weight(2);
  set_ac(2);
  set_type("ring");
  set_alias("sauron's");
}
 
wear(str)
{
  if(::wear(str) && worn)
  {
    remove_call_out("do_heal");
    call_out("do_heal", 2);
    return 1;
  }
}
 
remove(str)
{
  if(::remove(str))
  {
    remove_call_out("do_heal");
    return 1;
  }
}
 
drop(sil)
{
  ::drop(sil);
  remove_call_out("do_heal");
}
 
do_heal()
{
  object o;
  remove_call_out("do_heal");
  o=environment();
 if(!o || !living(o) || o->query_npc()) return;
  if(o->query_hp() < o->query_max_hp())
  {
    tell_object(o, "You feel your health increasing...\n");
    o->add_hit_points(2);
    counter++;
  }
  if(counter < 5000)
    call_out("do_heal", 2);
}
