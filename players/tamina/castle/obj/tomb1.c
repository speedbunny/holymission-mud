/*  This is a tomb / sarcophagus / sepulchre  */

#include "/players/tamina/defs.h"

status opened;

id (str) {
  return str == "tomb" || str == "sarcophagus" || str == "sepulchre";
}

short () {
  return "A Sarcophagus";
}
  
long () {

   if (opened) {
    write ("This is a large, limestone tomb which has recently been opened.\n"+
           "Inside, you can see very litte, except dust and spiders' webs\n"+
           "since the coffin is empty.\n");
    } else {
    write ("This is a large limestone tomb, which is currently closed.\n");
    }

}

get () { return 0; }

init() 
{
  add_action("open",  "open");
  add_action("close", "close");
}

int open (string str) 
{
  if (!str || (!id(str)) )
  {
    if (TP->STR < 19) 
    {
      write("You are far too weak to even lift the lid of the sarcophagus!\n");
      say(TPN+" strains to lift the lid of the sarcophagus, but fails to\n"+ 
          "move it an inch!\n");

      return 1;
    }

    write("You heave the heavy lid of the sarcophagus off of the top of\n"+
          "the tomb.\n");
      say(TPN+" lifts the lid from the tope of the sarcophagus, and dumps\n"+
          "it rather unceremoniously on the ground!\n");

    opened = 1;

    return 1;
  }
}

int close (string str) 
{
  if (!str || (!id(str)) )
  {
    if (TP->STR < 22) 
    {
      write("You can't close the sarcophagus, weakling!\n");
      say(TPN+" tries in vain to lift the lid back onto the sarcophagus!\n");

      return 1;
    }
    write("You lift the heavy lid back onto the top of the sarcophagus.\n");
    say(TPN+" puts the lid back on top of the tomb.\n");

    opened = 0;

    return 1;
  }
}
