#define TP             (this_player())
#define HIT_FACT       (5)
#define MONST_HIT_FACT (5)
#define RAISE_BLOCK    (100)

inherit "obj/weapon";

#include "/players/axlrose/weapons/extra/nweap_mess.h"
#include "/players/axlrose/weapons/extra/crit_hit.h"

string katana_owner;

query_auto_load()
{
    if (this_player()->query_guild()==8)
	return( explode( file_name( this_object() ), "#" ) )[0] + ":";
}

reset(arg)
{
    ::reset(arg);
    if (arg) return;

    if ( TP && TP->query_real_name() != katana_owner )
	katana_owner = TP->query_real_name();

set_name ("ninja-to");
set_short ("A ninja-to");
set_long("A ninja-to is a deadly ninja weapon.n");
    set_class( 20 );
    set_value( 13000 );
set_weight(2);
    set_info( "ninja_weapon" );
    set_hit_func( this_object() );
}

init()
{
    ::init();
    add_action("do_quit","quit");
}

int do_quit()
{
    if (environment()==this_player())
	call_out("self_destruct",2);
}

int self_destruct()
{
    destruct(this_object());
    return 1;
}

wield(str)
{
    if ( !id(str) )
	return;

    if ( katana_owner != TP->query_real_name() ) {
	write( "This is not your katana, it won't let you wield it.\n" );
	return( 1 );
    } 

    if ( this_player()->query_ghost() ) {
	write("You fail.\n");
	say(this_player()->query_name()+" failed to wield "+short_desc+".\n");
	return 1;
    }

    if (environment() != this_player()) {
	return 0;
    }

    if (wielded) {
	write("You already wield it!\n");
	return 1;
    }

    if (class_of_weapon>20) log_weapon("wield");

#ifdef TEST
    if (wield_conflict()) {            /* e.g try to wield a twohander while */
	write(wield_conflict()+"\n");    /* while wearing a shield             */
	return 1;

    }
#endif

    if(wield_func)
	if(!wield_func->wield(this_object())) 
	    return 1;


    wielded_by = this_player();

    if(!this_player()->wield(this_object())) 
	return 1;

    wielded = 1;
    write("Ok.\n");

    return 1;
}

/* !!!!! THE FOLLOWING FOR NINJAS ONLY !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! */

/* ---- wielded as second weapon -------------------------------------------- */
wield_second( str )
{
    object ns;

    if ( !id(str) )
	return;

    if ( katana_owner != TP->query_real_name() ) {
	write( "This is not your katana, it won't let you wield it.\n" );
	return( 1 );
    } 

    if ( this_player()->query_ghost() ) {
	write("You fail.\n");
	say( this_player()->query_name()+" failed to wield "+short_desc+".\n" );
	return( 0 );
    }

    if ( environment() != this_player() ) {
	return( 0 );
    }

    if ( wielded ) {
	write("You already wield it!\n");
	return( 0 );
    }

    if ( wield_second_conflict() ) {          /* e.g try to wield a twohander while */
	write(wield_second_conflict()+"\n");  /* while wearing a shield             */
	return( 0 );
    }

    /*   if ( wield_func )
	  if(!wield_func->wield(this_object())) 
	     return 1;
    */

    ns = present( "ninja_soul", this_player() );    /* force to unwield the second */
    if ( ns ) {
	if ( ns->query_secWielded() )
	    (ns->query_secWielded())->un_wield();
    }

    wielded_by = this_player();
    wielded = 1;
    write("Ok.\n");

    return( 1 );
}

wield_second_conflict()
{
    object armours;
    int i,j;

    if ( this_player()->query_weapon() )
	if ( (this_player()->query_weapon())->query_two_handed() )
	    return( "You have to remove your twohander first, to wield this weapon." );

    if( two_handed )
	return( "You cannot use a twohander as second weapon." );

    if(environment()->query_armour()[environment()->query_arm_types("shield")])
	return "You have to remove your shield first, to wield this weapon.";
}

drop( silently )
{
    object ns;

    if ( wielded ) {
	ns = present( "ninja_soul", wielded_by );
	if ( ns ) {
	    if ( ns->query_secWielded() == this_object() ) {  /* as second weap */
		wielded = 0;
		ns->unwield_second( this_object() );
		if ( !silently )
		    tell_object( wielded_by, "You drop your second wielded weapon.\n" );
	    }
	}
    }
    if ( wielded ) {
	wielded = 0;
	ns = present( "ninja_soul", wielded_by );
	if ( ns ) {
	    if ( ns->query_secWielded() == this_object() ) {
		ns->unwield_second( this_object() );
	    }
	}
    }

    return( 1 );
}

short()
{
    object ns;

    if ( wielded ) {
	if( short_desc ) {
	    ns = present( "ninja_soul", wielded_by );
	    if ( ns )
		if ( ns->query_secWielded() == this_object() )
		    return( short_desc + " (second wielded)" );

	    return( short_desc + " (wielded)" );
	}
    }
    return( short_desc );
}

weapon_hit( arg )
{
    return( critical_hit( arg ) );
}

query_raise_block()
{
    return( RAISE_BLOCK );
}

query_katana_owner()
{
    return( katana_owner );
}
