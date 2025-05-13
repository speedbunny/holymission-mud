inherit "/obj/std_shadow";

start_shadow( who, time)
{
	set_effect_msg("tree travel");
	set_look_info("(green aura)");
   return( ::start_shadow( who, time, "travel_shad", 1) );
}

end_shadow( o )
{
   tell_object( me, "You don't feel as one with the trees anymore !\n" );
   ::end_shadow( o );
}

int has_tree_travel() { return 1; }

int travel_shad() { return 1; }

