#define CHUNK 16

inherit "/obj/thing.c";

static string more_file;	/* Used by the more command */
static int more_line;
static string current_path;
string resolve_path(string path);

void reset(int arg) {
  if (arg)
    return ;
  set_can_get(1);
  set_weight(1);
  set_value(0);
  set_name("more");
  set_short("Dworkin More Reader");
  set_long("The Dworkin More reader. Allows emacs users to use clpmud to edit files.\n");
}

void init() {
  if (!this_player()->query_immortal()) {
    write("You have to be a wizard to use this tool.\n");
  }
  add_action("more","more");
}

static int more(string str) {

  if (!str)
    return 0;
      
  str=resolve_path(str);
  more_file = str;
  more_line = 1;


  if ( file_size(more_file)<=0 ) {
    write("File doesn't exist.\n");
    return 1;
  }

  if (cat(more_file, more_line, CHUNK) == -1) {
    write("No such file!\n");
    return 1;
  }
  input_to("even_more");
  write("More: (line " + (CHUNK + 1) + ") ");
  return 1;
}

static void even_more(string str) {
    if (str == "" || str == "d")
	more_line += CHUNK;
    else if (str == "q") {
	write("Ok.\n");
	return;
    } else if (str == "u") {
	more_line -= CHUNK;
	if (more_line < 1)
	    more_line = 1;
    }
    if (cat(more_file, more_line, CHUNK) == 0) {
	more_file = 0;
	write("\nEOF\n");
	return;
    }
    write("More: (line " + (more_line + CHUNK) + ") ");
    input_to("even_more");
}

string resolve_path(string path) {
  current_path="/"+this_player()->query_path();

  if (path[0]=='/') 
    path=path;
  else
    if (path[0]=='~')
      path="/players/"+this_player()->query_real_name()+"/"+path[2..];
    else

      path=current_path+"/"+path;
  return path;
}

int drop(int dummy) {
  write ("The more tool vanishes as it hits the ground...\n");
  destruct(this_object());
  return 1;
}



