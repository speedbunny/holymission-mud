inherit "obj/armour";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_name("Lizard skin");
    set_short("A lizard's skin");
    set_long("A very fine lizard skin. Might be useful somehow.\n");
    set_ac(1);
    set_weight(1);
    set_id("skin");
    set_value(1100);
    set_alias("lizard skin");
  }
}

init()
{
  ::init();
}
