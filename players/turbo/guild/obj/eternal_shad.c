inherit "/obj/std_shadow";
string old_short;
object weapon;
int level;

varargs int start_shadow( object ob, int time, int lvl, int llvl ) {
    tell_room( environment( environment( ob ) ), "A blue glow covers " + ob->short() + ".\n" );
    old_short = ob->short();
    ob->set_short( old_short + " (Flaming)" );
    weapon = ob;
    level = lvl + llvl;
    call_out( "end_shadow", time, ob );
    ob->set_hit_func( this_object() );
    return ::start_shadow( ob, time, "eternal_shad", 0 );
}

int weapon_hit( object victim ) {
    int hit;

    hit = random( level ) + 10;
    printf( "The blue flame singes %s!\n", victim->query_name() );
    say( "The blue flame singes " + victim->query_name() + "!\n");
    tell_object( victim, "The blue flames singe you!\n");
    return ( hit );
}

void end_shadow( object ob ) {
    ob->set_short( old_short );
    tell_room( environment( environment( ob ) ), "The blue flame fades from " + ob->short() + ".\n" );
    ::end_shadow( ob );
}

int eternal_shad() { return ( 1 ); }
