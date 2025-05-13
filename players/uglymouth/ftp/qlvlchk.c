/* File:        qlvlchk.c
 * Creator:     Uglymouth, 971103
 * Goal:        To speed up corrections of safety checks on wizard status
 *              [ replacement of query_level() < 30 by query_immortal() ]
 *              This file adds clean objects to a log file and prints the
 *              files containing bad code.
 * Notes:       - This command can only check loaded objects
 *              - It is possible to check for files of a given wizard only
 *              - May be necessary to adapt if eval cost proves too high
 * Debug:       - Ask Sauron how to get all loaded objects
 *              - Look up repstr to remove all '\n' and ' ' characters
 */

#define CHECK_FILE "/log/qlvlchk"

int main( string str ) {
  objects *obs;
  string *ob_files, *clean_obs;

  // Get all objects (of one wiz, if given) that are currently loaded.
  if( !str ) obs = all_objects();
  else obs = filter_array( all_objects(), "wiz_filter", this_object(), str );
  
  // Get the base file_names of those objects that have not been checked
  // before and were found to be clean.
  ob_files = map_array( obs, "get_base_name", this_object() );
  
  // Split array into an array with files that do contain bad wiz checking
  //  and an array with files that don't.
  clean_obs = ob_files 
    - filter_array( ob_files, "has_query_level", this_object() );
  obs = obs - clean_obs;
  
  // Add clean files to the check log.
  update_check_file( clean_obs );
  
  // Print the file_names of those objects that contain bad wiz checking.
  printf( "The following files have bad checks for wizard status:\n%O\n"
    + "Please correct them, update and reload them. Then execute this "
    + "command again.\n", obs );
  return 1;
}

/* USERDOC:
 * Filter_array funtion. Returns 1 if it's a file in one of the
 * subdirectories of the specified wizard, and 0 otherwise.
 */
int wiz_filter( object ob, string wiz_name ) {
  return explode( file_name( ob ), "/" )[1] == wiz_name;
}

/* USERDOC:
 * Map_array function. Returns 0 if the file for the given object has been
 * checked before. If not it returns the base file_name of that object.
 */
string get_base_name( object ob ) {
  string file_name, *checked;

  file_name = explode( file_name( ob ), "#" )[0];
  checked = explode( read_file( CHECK_FILE ), "\n" );
  if( member_array( file_name, checked ) != -1 ) return 0;
  return file_name;
}

/* USERDOC:
 * Filter_array function. It reads the file, removes all 'new line' and
 * 'space' characters. Then it searches for bad wizard checking. If found
 * the function returns 1, otherwise it returns 0.
 */
int has_query_level( string file_name ) {
  string lines;

  lines = read_file( "/" + file_name + ".c" );
  lines = implode( explode( lines, "\n" ), "" );
  lines = implode( explode( lines, " " ), "" );
  if( strstr( lines, "query_level()<30" ) != -1 ) return 1;
  return 0;
}

/* USERDOC:
 * Adds files that check clean to the check log.
 */
void update_check_file( string clean_obs ) {
  int i, so;

  for( i=0, so=sizeof( clean_obs ); i<so; i++ )
    write_file( CHECK_FILE, clean_obs[i] + "\n" );
}

