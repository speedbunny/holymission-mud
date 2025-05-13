#include "/players/steerpike/steerpike.h"

#define FILE "/players/steerpike/____eval"

int id(string str)       { return str == "eval tool"; }
void init()              { add_action("do_eval", "eval"); }
int get()                { return 1; }
int drop()               { return 1; }
string query_auto_load() { return __FILE__ + ":"; }

int do_eval(string str)
{
   mixed err, ret;
   if (!ME)
      return 0;
   rm(FILE + ".c");
   write_file(FILE + ".c", "test_func() { return " + str + "; }\n");
   if (find_object(FILE))
      destruct(find_object(FILE));
   if (err = catch(ret = (mixed)FILE -> test_func()))
      write(err);
   else
   {
      printf("Result: %s.\n", FUNCS(display) -> display(ret));
      destruct(find_object(FILE));
   }
   rm(FILE + ".c");
   return 1;
}
