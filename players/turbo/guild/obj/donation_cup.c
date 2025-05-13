inherit "obj/thing";
#define MAX_MONEY 100000
int MONEY;

void reset( int arg ) {
    ::reset( arg );
    if( arg ) 
	return;
    set_name( "cup" );
    set_alias( "donation cup" );
    set_short( "A donation cup" );
    set_long( "This is a large glass jar that is used for holding money.\n\
Perhaps you can either DONATE or WITHDRAW some?\n" );
    set_value( 0 );
    set_weight( 0 );
    MONEY = 0;
}

void long() {
    ::long();
    if( MONEY )
	printf( "It contains %d coins.\n", MONEY );
    else 
	write( "But, alas, it is empty.\n" );
}

int get() {
    write( "It is firmly secured to the table.\n" );
    say( this_player()->query_name() + " tried to steal the donation cup!\n" );
    return ( 0 );
}

void init( ) {
    ::init( );
    add_action( "_donate", "donate" );
    add_action( "_withdraw", "withdraw" );
}

status _donate( string str ) {
    int coins;
    object me;

    if( !str || sscanf( str, "%d coins", coins ) != 1 || sscanf( str, "%d coin", coins) != 1 ) {
	write( "Donate how many coins?\n" );
	return ( 1 );
    }
    me = this_player();
    if( me->query_money() < coins ) {
	printf( "You do not have %d coins!\n", coins );
	return ( 1 );
    }
    if( coins + MONEY > MAX_MONEY ) {
	printf( "Sorry, the cup will only hold %d more coins.\n", ( MAX_MONEY-MONEY ) );
	return ( 1 );
    }
    me->add_money( - coins );
    MONEY += coins;
    if( coins == 1 ) {
	write( "You deposit 1 coin.\n" );
	say( this_player()->query_name() + " drops a coin into the cup.\n" );
    }
    else {
	printf( "You deposit %d coins.\n", coins );
	say( this_player()->query_name() + " drops some coins into the cup.\n" );
    }
    return ( 1 );
}

status _withdraw( int arg ) {
    int coins;

    if( !arg || sscanf( arg, "%d coins", coins ) != 1 || sscanf( arg, "%d coin", coins ) != 1 ) {
	write( "Withdraw how many coins?\n" );
	return ( 1 );
    }
    if( coins > MONEY ) {
	printf( "But the cup only has %d coins!\n", MONEY );
	return ( 1 );
    }
    MONEY -= coins;
    this_player()->add_money( coins );
    if( coins == 1 ) {
	write( "You withdraw 1 coin.\n" );
	say( this_player()->query_name() + " withdraws a coin from the cup.\n" );
    }
    else {
	printf( "You withdraw %d coins.\n", coins );
	say( this_player()->query_name() + " withdraws some coins from the cup.\n" );
    }
    return ( 1 );
}
