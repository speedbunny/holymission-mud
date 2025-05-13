inherit "obj/weapon";

reset(arg) 
{ if (arg) 
    return;
  
  set_id("knife");
  set_alias("barbar knife");
  set_short("A Barbar's knife");
  set_long("The weapon of the dangerous Barbar\n");
  set_class(15);
  set_weight(3);
  set_value(3500);
}
