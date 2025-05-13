inherit "/players/patience/guild/nweap/ninja_weapon";

void reset(int arg)
{
   ::reset(arg);
   if (!arg)
   {
       set_name("tonfa");
       set_short("A tonfa");
       set_long("A tonfa is a club with a side handle. It is a ninja-weapon. " +
		"The tonfa looks pretty dangerous!.\n" );
       set_class(13);
       set_value(6000);
       set_weight(2);

       set_critical_hit_factor(3);
       set_parry_class(4);
   }
}
