
inherit "/obj/weapon";

  reset(arg)
{
	::reset(arg);
	if (arg) return;
         set_name("bone knife");
          set_alias("knife");
      set_short("bone knife");
      set_long("A knife with a wicked looking blade. It is shiny and looks \n"+
    "to be extremely sharp. The handle is made of finely polished bone. \n");
       set_class(8);
        set_value(750);
        set_weight(1);

return 1;
}
