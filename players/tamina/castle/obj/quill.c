#include "/players/tamina/defs.h"

inherit "/obj/thing";

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("quill");
  set_short("A Quill");
  set_long("A long, feathered-quill, with a sharp, pointed end.\n");
  set_weight(1);
  set_value(90);
  set_can_get(1);
}

id (str)
{
  return str == name || str == "a quill" || str == "the quill";
}
/*
void init()
{
  ::init();
  AA("_write", "write");
}

int _write (string str)
{
  string str1,paper;

  if (sscanf(str, " %s on %s", str1, paper) !=2)
  {
    NFAIL("You cannot do that with this.\n");
    return 0;
  }
  paper = 
*/
