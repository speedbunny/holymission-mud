inherit "/players/tatsuo/guild/nweap/ninja_weapon";
 
void reset(int arg)
{
    ::reset(arg);
    
    if(!arg)
    {
 
	set_name("kama");
	set_short("A kama");
	set_long("A kama is a straight-bladed sickle. The handle is about " +
		 "two feet long with a very sharp blade curving around. It " +
		 "is a great hand-to-hand weapon for ninjas.");
	set_class(11);
	set_value(1800);
	set_weight( 3 );
 
	set_critical_hit_factor(3);
	set_parry_class(2);
    }
}
