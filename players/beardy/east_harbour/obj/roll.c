inherit "/obj/food";

reset(int arg)
{ ::reset(arg);
  if(arg) return 0;

  set_name("roll");
  set_short("a roll");
  set_long("It looks delicious.\n");

  set_value(3);
  set_weight(1);
}
