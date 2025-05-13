inherit "/players/patience/guild/nweap/ninja_weapon";

void reset(int arg)
{
   ::reset(arg);
   if (!arg)
   {
       set_name("sai");
       set_short("A sai");
       set_long("A sai is a three pronged dagger. It is a ninja-weapon. " +
		"The sai looks rather sharp.\n" );
       set_class(15);
       set_value(6000);
       set_weight(5);

       set_critical_hit_factor(3);
       set_parry_class(3);
   }
}
