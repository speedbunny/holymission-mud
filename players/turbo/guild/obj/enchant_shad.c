inherit "/obj/std_shadow";
int old_wc;
string old_short;
object weapon;

varargs int start_shadow( object ob, int time, int wc ) {
    tell_room( environment( environment( ob ) ), "A golden glow covers " + ob->short() + ".\n" );
    old_wc = ob->weapon_class();
    old_short = ob->short();
    ob->set_class( old_wc + wc );
    ob->set_short( old_short + " (Enchanted)" );
    weapon = ob;
    call_out( "end_shadow", time, ob );
    return ::start_shadow( ob, time, "enchant_shad", 0 );
}

void end_shadow( object ob ) {
    ob->set_short( old_short );
    ob->set_class( old_wc );
    tell_room( environment( environment( ob ) ), "The golden glow fades from " + ob->short() + ".\n" );
    ::end_shadow( ob );
}

int enchant_shad() { return ( 1 ); }
