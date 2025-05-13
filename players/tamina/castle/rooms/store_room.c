/* This is the Store room  */

#include "/players/tamina/defs.h"

inherit "room/room";
    int key_found, scroll_found;

void reset(int arg) 
{
  key_found    = 0;  scroll_found = 0;
  ::reset(arg);
  if(arg) return 0;

     set_light(-1);
     short_desc = "Store Room ";
     long_desc = 
   "The darkness in this small room is so oppressive you can almost feel\n"+ 
   "it pushing down on you....Claustrophobia??\n"+
   "The dust that you have disturbed here almost threatens to extinguish\n"+
   "your torch...  You cough and splutter your way through the assorted\n"+
   "pieces of junk, and find yourself in the middle of an old store room.\n"+
   "There are a whole load of useless items here, ranging from old wooden\n"+
   "stools, to boxes, or even rags.\n";

     dest_dir = ({
   CROOMS + "wwing1","out",
     });

     items = ({
   "junk",
"As it looks...just a pile of useless junk.",
   "rags",
"Old scraps of worn, tattered clothes",
   "stools",
"Some of these still have the three legs that they were built with.  "+
"Others are not so lucky..",
   "boxes",
"Several wooden crates that contain all manner of things..",
     });

     smell = "The clogging dust makes this room smell very old, as if\n"+
             "not used in a long, long time.";
}

void init() 
{
  ::init();
  add_action("_search","search");
}

int _search (string str) 
{
  object key, scroll;

  if (str == "junk" || str == "pieces")
  {
    if (key_found)
    { 
      write("You search the junk and find nothing.\n");
      say(TPN+ "dives into the junk, but comes out empty-handed.\n");   
      return 1;
    } 
    else
      write("You search through the junk, and find a key!\n");
      say(TPN+" dives into the junk, and miraculously finds a key!\n");

    key = CLO ("obj/key");

    key->set_key_data("rusty key001");

    TR(key, TP);  
    key_found = 1;
    return 1;
  }
  if (str == "boxes" || str == "crates")
  {
    if (scroll_found)
    {
      write("You search through the things in the boxes,\n"+
            "but find nothing more of interest.\n");
      say(TPN+ "dives head-first into a box, but comes out\n"+ 
          "empty-handed.\n");   

      return 1;
    } 
    else
      write("\n        ***  C O U G H  ***\n\n"+
            "But you do manage to find a strange looking scroll\n"+
  	    "in amongst the rubbish in one box...\n");
      say(TPN+" produces a scroll after looking through one\n"+
	  "of the boxes.\n");

    scroll = CLO ("obj/thing");
    
    scroll->set_name("scroll");
    scroll->set_alias("parchment");
    scroll->set_short("A top piece of Scroll");
    scroll->set_long(
"A small, torn part of a crumbling scroll.  It seems to be the top\n"+
"part of a longer scroll.  But you might still be able to read it...\n");
    scroll->set_read_file(COBJ + "scroll1.txt");
    scroll->set_value(20);
    scroll->set_weight(1);
    
    TR(scroll, TP);
    scroll_found = 1;

    return 1;
  }
  if (str == "stools")
  {
    write("You find nothing but dust through these useless things.\n"+
          "\n               ***  C O U G H  ***\n\n");
      say(TPN+" coughs out a lot of dust after looking over the stools.\n");

    return 1;
  }
  else
  {
    notify_fail("Search what?\n");
    return 0;
  }
}
