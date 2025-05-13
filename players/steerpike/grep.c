#define GRAB_FILE(x) explode(read_file(x) || "", "\n")

#define EXPAND_PATH(x) \
   switch (x[0]) \
   { \
      case '~': \
	 if (x[1] == '/') \
	    x = "/players/" + (string)this_player() -> query_real_name() \
	       + "/" + x[2 .. ]; \
	 else \
	    x = "/players/" + x[1 .. ]; \
	 break; \
      case '/': \
	 break; \
      default: \
	 x = "/" + x; \
   }

short() { return "grep"; }
id(s)   { return s == "grep"; }
get()   { return 1; }
drop()  { return 1; }
init()  { add_action("grep", "grep"); }

int grep(string str)
{
   string exp, file, dir;
   string *files, *ret;
   string out;
   int i;
   if (str
      && (sscanf(str, "\"%s\" %s", exp, file) == 2
      || sscanf(str, "%s %s", exp, file) == 2))
   {
      EXPAND_PATH(file);
      dir = implode(explode(file + "/", "/")[0 .. <3], "/") + "/";
      if (!(files = get_dir(file)))
	 write("No files matched search parameters.\n");
      else
      {
	 for (out = "" ; i < sizeof(files) ; i ++)
	 {
	    if (sizeof(ret = regexp(GRAB_FILE(dir + files[i]), exp)))
	       out += files[i] + "\n" + implode(ret, "\n") + "\n";
	 }
	 this_player() -> more_string(out);
      }
   }

   else
      write("Usage: grep <expression> <file-list>.\n");
   return 1;
}

query_auto_load() { return __FILE__ + ":"; }
