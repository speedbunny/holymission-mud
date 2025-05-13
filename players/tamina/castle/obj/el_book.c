inherit "/obj/thing";

#include "/players/tamina/defs.h"

status is_reading;
string part1, part2, part3, part4;
string code1, code2, code3, code4;

void reset(int arg) 
{
  ::reset(arg);
  if(arg) return;

  set_name("book of elements");
  set_alias("book");
  set_short("The Book of Elements");
  set_long(
"This is a rather large book, concerned with the study of all things\n"+
"Elemental.  Perhaps you could read it.\n");
  set_weight(2);
  set_value(100);
  set_can_get(1);
  
  switch(random(13))
  {
    //     AIR         WATER           EARTH            FIRE
    //  1 - Head     2 - Arms        3 - Legs       4 - Torso
    case 0 .. 1:
     part1 = "head"; part2 = "arms"; part3 = "legs"; part4 = "torso";
     code1 = "ah1";  code2 = "wa2";  code3 = "el3";  code4 = "ft4";
    break;
    case 2:
     part1 = "arms"; part2 = "legs"; part3 = "head"; part4 = "torso";
     code1 = "aa2";  code2 = "wl3";  code3 = "eh1";  code4 = "ft4";
    break;
    case 3 .. 4:
     part1 = "legs"; part2 = "arms"; part3 = "torso"; part4 = "head";
     code1 = "al3";  code2 = "wa2";  code3 = "et4";   code4 = "fh1";
    break;
    case 5 .. 6:
     part1 = "torso"; part2 = "head"; part3 = "legs"; part4 = "arms";
     code1 = "at4";   code2 = "wh1";  code3 = "el3";  code4 = "fa2";
    break;
    case 7:
     part1 = "head"; part2 = "arms"; part3 = "torso"; part4 = "legs";
     code1 = "ah1";  code2 = "wa2";  code3 = "et4";   code4 = "fl3";
    break;
    case 8 .. 9:
     part1 = "torso"; part2 = "legs"; part3 = "arms"; part4 = "head";
     code1 = "at4";   code2 = "wl3";  code3 = "ea2";  code4 = "fh1";
    break;
    case 10 .. 11:
     part1 = "legs"; part2 = "head"; part3 = "torso"; part4 = "arms";
     code1 = "al3";  code2 = "wh1";  code3 = "et4";   code4 = "fa2";
    break;
    default:
     part1 = "arms"; part2 = "torso"; part3 = "legs"; part4 = "head";
     code1 = "aa2";  code2 = "wt4";   code3 = "el3";  code4 = "fh1";
    break;
  }
}

void init()
{
  ::init();
  AA("_read", "read");
}

int _read(string str)
{
  if (str == "book")
  {
    if (TP->INT < 20)
    {
      write("But you are far too unintelligent to read this book.\n");
      return 1;
    }
    if (is_reading)
    {
      write("But you are already looking through the pages...\n");
      return 1;
    }
    write("You flick through the old vellum pages of the manuscript...\n\n");
    say(TPN+" looks at a book on elementalism.\n");

    is_reading = 1;
    call_out("reader", 2);
    return 1;
  }
}

reader()
{
  switch(random(5))
  {
    case 4:
      write(
"You turn over a page that contains a list of properties of certain\n"+
"valuable items in Elemental Magicks.  You read...\n\n"+
"   ...It is known that the four main elements have their\n"+
"      counterparts in the Primus Plane.  We have since found\n"+
"      that the following objects hold vital clues to elements:\n"+
"	   rubies   --  fire\n"+
"	   diamonds --  earth\n"+
"	   silver   --  air\n"+
"	   wood     --  water\n"+
"      We believe that the power of these objects is yet to be\n"+
"      realised...\n");
      return 1;
    break;

    case 3:
      write("You find nothing interesting in the book to read.\n");
      return 1;
    break;

    case 2:
      write(
"You come to a page on the Elemental Lord.  It gives you details\n"+
"on how to summon the dread lord:\n"+	    
"It says that you need four bodily parts from each of\n"+
"the Lords of Air, Water, Earth, and Fire.\n"+
"The correct parts are:\n"+
"	Air   - "+query_part(1)+"\n"+
"	Water - "+query_part(2)+"\n"+
"	Earth - "+query_part(3)+"\n"+
"	Fire  - "+query_part(4)+"\n"+
"When you have the assembled parts, you must go to a holy\n"+
"place, and cast the great Summons...\n");
      say(TPN+" finds an interesting part of the book.\n");
      is_reading = 0;
      return 1;
    break;

    case 1:
      write(
"You come to an interesting page on the relation between the\n"+
"different aspects of magics in the various elements, such as\n"+
"Plasma and Electricity, Water and Nether, Earth and Fire.\n"+
"You get quickly bored, and lose the page.\n");
      say(TPN+" finds an interesting part of the book.\n");
      is_reading = 0;
      return 1;
    break;

    case 0:
      write(
"You find an interesting page on the Elemental Lord, and his\n"+
"vulnerabilities.  It says that the dread lord is incredibly\n"+
"powerful, and resistant to most magics.  He has few weaknesses\n"+
"and in defeat he can be at his best...\n");
      say(TPN+" finds an interesting part of the book.\n");
      is_reading = 0;
      return 1;
    break;
  }
}

string query_part(int num)
{
  if (num == 1) 
    return part1;
  else  if (num == 2) 
    return part2;
  else  if (num == 3) 
    return part3;
  else  if (num == 4) 
    return part4;
}

string query_code(int num)
{
  if (num == 1) 
    return code1;
  else  if (num == 2) 
    return code2;
  else  if (num == 3) 
    return code3;
  else  if (num == 4) 
    return code4;
}
