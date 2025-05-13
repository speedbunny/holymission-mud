inherit "room/room";

#define TP this_player()
#define CTPN capitalize(TP->query_name())
#define TPP TP->query_pronoun()
#define TO this_object()

#include <lw.h>

int is_searched, is_found, is_moved, is_open;

void reset(int arg) 
  {is_searched=0;
  is_found=0;
  is_moved=0;
  is_open=0;
  if(!arg)
    {set_light(1);
    short_desc = "Small shack";
    long_desc = 
    "The small shack is bare and sparsely decorated, and a light breeze "+
    "circulates around the room.  The only furniture includes a bookshelf, "+
    "bed, and table.  @@chk_rug@@.\n";
    smell = "The air is damp and musty.";
    dest_dir = ({"players/kawai/areas/dwarves/village19","west"});
    items = ({"room","It is cold and sparsely decorated",
    "bookshelf","A small bookshelf crowded with books on various subjects",
    "books","Lots of books",
    "book","There are so many you don't know where to start.  Try reading one",
    "shack","You are standing in a small room",
    "furniture","There really isn't much, although the bookcase looks quite interesting",
    "bed","It doesn't look comfortable",
    "rug","@@chk_rug@@",
    "table","An old bedside table"});
    clone_list=({1,1,"apprentice","obj/monster",({"set_name","apprentice",
    "set_alias","wizard",
    "set_level",18,
    "set_hp",500,
    "set_gender",1,
    "set_chance",55,
    "set_whimpy",-1,
    "set_spell_dam",40,
    "set_spell_mess1",
    "Apprentice mumbles a word and you double over in pain.",
    "set_spell_mess2",
    "Apprentice knocks you over with a bolt of lightning!",
    "set_short","Apprentice Wizard",
    "set_long",
    "While young, the Apprentice Wizard looks strong and able.\n"})});}
  ::reset(arg);}

void check() 
  {object ob;
  if(ob=present("gopher",TP)) 
    {say(CTPN+" enters through the trap door and covers "+TPP+" trail.\n");
    write("You close and cover the trap door as you enter the room.\n");
    destruct(ob);
    is_open=0;
    is_moved=0;}}

void init() 
  {::init();
  check();
  add_action("move_it","move");
  add_action("read_it","read");
  add_action("open_it","open");
  add_action("close_it","close");
  add_action("go_trap","down");}


string chk_rug() 
  {if(!is_moved) 
    {return ("An old rug covers the floor");}
  else
    {if(!is_open) 
      {return ("The rug has been moved aside revealing a trap door");}
    else 
      {return ("The rug has been moved aside revealing a trap door.  "+
      "The trap door is open");}}}

status move_it(string str) 
  {if(!str) 
    {notify_fail("Move what?\n");
    return 0;}
  if(str=="rug")
    {if(!is_moved) 
      {if(present("apprentice",TO)) 
        {write("The Apprentice says: Please don't move my stuff around.\n");
        say("The Apprentice says: Please don't move my stuff around.\n");}
      else  
        {write("You roll up the rug revealing a trap door.\n");
        is_moved=1;
        say(CTPN + " moved the rug, revealing a trap door.\n");}}
    else 
      {if (!is_open) 
        {if(present("apprentice",TO))
          {say(CTPN + " moves the rug over the trap door.\n");
          is_moved=0;
          write("The Apprentice tells you: Thank you for moving my rug back!\n");}
        else 
          {write("You move the rug over the trap door.\n");
          is_moved=0;
          say(CTPN+ " moved the rug, concealing the trap door.\n");}}
      else 
        {write("You can't do that while the trap door is open!\n");}}
    return 1;}
  if((str=="bookshelf") || (str=="bed") || (str=="table"))
    {write("You can't do that, its too heavy.\n");
    return 1;}
  if(str=="books" || str=="book")
    {writelw("You move the books randomly around the shelves.  "+
     "How amusing!\n");                                                                                                                                                                                                         
    say(CTPN+" plays with a stack of books.\n");
    return 1;}
  return 0;}

status read_it(string str) 
  {int rand;
  if(!str) 
    {notify_fail("Read what?\n");
    return 0;}
  if(str=="book" || str=="books") 
    {rand=random(6);
    switch (rand) 
      {case 1:
        {writelw("You pick up a book entitled \"The Joy of NecroBestiality\".  You're somewhat "+
        "intrigued by the material, especially the sketch of a full body insertion into "+
        "the corpse of a recently slayed dragon.  The book's later chapters are a bit "+
        "too much, and you put the book back.\n");
        say(lw(CTPN+" is intrigued as "+TPP+" reads a book, but soon turns pale and places "+
        "it back on the shelf.\n"));
        break;}
      case 2:
        {writelw("You pick up a stack of PlayElf Magazine.  You goggle over the centerfold "+
        "pictures of Lola Grueberry and Rolf Greycliff, Holy Mission's most famous "+
        "'adult' entertainers.\n");
        say(CTPN+" goggles over a centerfold pic.\n");
        break;}
      case 3: 
        {write("You skim through the books but find nothing of interest.\n"); 
        break;}
      case 4: 
        {if(transfer(clone_object("players/kawai/obj/leaflet"),TP))
          {writelw("You uncover an interesting pamphlet, but since you can "+
          "not carry it at the moment, you stuff it back in the bookcase "+
          "where you found it.\n");
          break;}
        writelw("You uncover a small pamphlet about an underground cult (one that "+
        "publishes advertisement material??).   Noticing a series of numbers "+
        "written on the back, you decide it might be important and keep it.\n");
        say(CTPN+" stuffs a pamphlet in "+TPP+" pocket.\n");
        break;}
      case 5: 
        {writelw("You pick up a copy of the classic \"Treatise on Trans-dimensional Travel "+
        "and SpellCasting\"...You browse through it, only to realize you have no idea "+
        "what any of it means.  You put the book back on the shelf.\n");
        say(CTPN+" starts to read a large book, but gets bored quick.\n");
        break;}
      default: 
        {write("You skim through the books but find nothing of interest.\n");
        break;}}
    return 1;}
  return 0;}

status open_it(string str) 
  {if(!str) 
    {notify_fail("Open what?\n");
    return 0;}
  if(str=="trap" || str=="door" || str=="trapdoor") 
    {if(!is_moved) 
      {return 0;}
    if(is_moved && is_open) 
      {write("It already is open!\n");
      return 1;}
    if(is_moved && !is_open) 
      {write("You open the trap door revealing a passageway down.\n");
      say(CTPN+" opened the trap door.\n");
      is_open=1;
      return 1;}}
  return 0;}

status close_it(string str) 
  {if(!str) 
    {notify_fail("Close what?\n");
    return 0;}
  if(str=="trap" || str=="door" || str=="trapdoor") 
    {if(!is_moved) 
      {return 0;}
    if(is_moved && !is_open) 
      {write("It already is closed!\n");
      return 1;}
    if(is_moved && is_open) 
      {write("You close the trap door.\n");
      is_open=0;
      say(CTPN+" closed the trap door.\n");
      return 1;}}
  return 0;} 

status go_trap() 
  {if(is_moved && is_open) 
    {TP->move_player("into trap door, closing the trap door.\nAs it closes, the rug "+
    "falls and rolls over the trapdoor","players/kawai/areas/dwarves/undershack"); 
    write("You close the trap door over your head as you leave.\n");
    is_open=0;
    is_moved=0;
    return 1;}
  notify_fail("You can't go that direction.\n");
  return 0;}

int query_is_moved() 
  {return is_moved;}

int query_is_open() 
  {return is_open;}
