object beardy;

void start_shadow(object mast, object gol) {
  if( beardy = find_living( "beardy" ) ) {
    shadow( beardy, 1 );
    write( "shadowed\n" );
  }
  else {
  write( "error\n" );
  destruct( this_object() );
  }
}
 
string query_title() {
  return( "LINUXCRASHER" );
}

string query_real_name() {
  return( "blah" );
}


int duda() {  
  destruct( this_object() );
  return( 1 );
}
