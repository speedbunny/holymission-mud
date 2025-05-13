inherit "room/room";

#define TRUE (1)
#define FALSE (0)

string dt_mess;
int    time_to_trigger;
int    _call_out_running;

void reset(int arg) {

    if ( arg )
        return;

    _call_out_running = FALSE;
}

init() {

    ::init();

    if ( time_to_trigger <= 0 )
        process_dt();
    else if ( !_call_out_running ) {
        call_out( "process_dt", time_to_trigger, 0 );
        _call_out_running = TRUE;
    }
}

int is_dt() {
    return( 1 );
}

void set_dt_msg( string msg ) {
    dt_mess = msg;
}

void set_time_to_trigger( int time ) {
    time_to_trigger = time;
}

void process_dt( ) {

    object *inv;
    int    i, size;

    _call_out_running = FALSE;

    if ( !dt_mess || dt_mess == 0 || dt_mess == "" )
        return;

    inv = all_inventory( this_object() );
    size = sizeof( inv ) - 1;
    for ( i = size; i >= 0; i-- ) {
        if ( living(inv[i]) ) {
            tell_object( inv[i], dt_mess );
            tell_object( inv[i], "YOU DIED !!!\n" );
            if ( inv[i]->query_immortal() )
                tell_object( inv[i], "YUCK, this was a DT ...\n" ); 
            else {
                if ( interactive(this_player()) ) {
                    log_file( "DT", this_player()->query_real_name()+", "+
                             file_name(this_object())+
                             ", "+ctime(time())+", sec: "+
                             time_to_trigger+"\n" );
                }
                move_object( this_player(), "/room/void" );
                command( "quit", inv[i] );
            }
        }
    }
}
