inherit "obj/armour";

reset(arg) {
  ::reset(arg);
  set_name("red nose");
  set_alias("nose");
  set_short("A red nose");
  set_long("This is a red nose used to celebrate 'Red Nose Day'.\n"+
            "Wear it to support the research on baby cot death "+
            "prevention.\n");
  set_type("armour");
  set_size(0);
  set_ac(0);
  set_weight(1);
}

int wear_fun(object player)
{
  tell_object(player, "My, your nose looks VERY red, but cute !\n");
  return 1;
}

int remove_fun(object player)
{
  tell_object(player, "Thanks for helping the 'Red Nose Day'.\n");
  return 1;
}
