#include <std.h>
#define SYNTAX "Syntax: \"eval <lpc commands>\".\n"

int cmd_eval( string a )
{
  string file, filename;
  mixed err, ret;
string x,y;

  if( !a ) { notify_fail( SYNTAX ); return 0; }
  file = ""+
"#include <std.h>\n"+
"mixed eval() { " + a + "; }\n"+
  "";
filename = "/players/margusko/";
  if( file_size( filename ) != -2 ) 
    { notify_fail( "You must have a valid home directory!\n" ); return 0; }
  filename += "CMD_EVAL_TMP_FILE.c";
  rm( filename );
  if( ret = find_object( filename ) ) destruct( ret );
  write_file( filename, file );
  if( err = catch( ret = (mixed)call_other( filename, "eval" ) ) )
    write( "Error = " + err );
  else 
write( ( "Result = " + sprintf("%O", ret) ) );
write("\n");
  rm( filename );
  if( ret = find_object( filename ) ) destruct( ret );
  return 1;
}

