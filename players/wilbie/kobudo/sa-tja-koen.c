inherit "/players/patience/guild/nweap/ninja_weapon";

void reset(int arg)
{
    ::reset(arg);
    
   if (arg)
   {
       set_name("sa-tja-koen");
       set_short("A sa-tja-koen");
       set_long("A sa-tja-koen is like a nunchaku, but with a third handle " +
		"and a second chain attached. It is a ninja-weapon and " +
		"looks to be rather effective.\n" );
       set_class(13);
       set_value(3700);
       set_weight(5);

       set_critical_hit_factor(4);
       set_parry_class(3);
   }
}
