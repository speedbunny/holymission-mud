inherit "obj/weapon";

void reset(int arg)
  {::reset(arg);
  if(!arg)
    {set_id("athame");
    set_alt_name("knife");
    set_weight(1);
    set_value(15000);
    set_class(15);
    set_short("An athame");
    set_long("The athame is the traditional tool used in circle magick.  It's white handle\n"+
     "is ingraved with various runes.\n");}}


