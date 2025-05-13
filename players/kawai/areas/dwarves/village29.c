inherit "room/room";

#include <lw.h>

int dwarf;

void reset(int arg)
  {dwarf=0;
  if(!arg) 
    {set_light(1);
    short_desc = "Cave";
    long_desc = "You are somewhere in a small cave, but surprisingly, "+
    "have stumbled upon some sort of underground club "+
    "or bar!  To the east is a small doorway that opens up "+
    "into a plush bar where you can see dwarves drinking "+
    "and gambling, and occasionally fighting.\n";
    smell = "The air damp and musty";
    dest_dir = ({"players/kawai/areas/dwarves/village27","northwest",
    "players/kawai/areas/dwarves/casino","east",
    "/players/meecham/pot_shops/ps_kawai","west",
    });
    items = ({"cave","It is dark and wet",
    "club","You hear the laughter and screams of many people from inside",
    "bar","You hear the laughter and screams of many people from inside",
    "dwarves","They look like they're enjoying themselves",
    "doorway","Why not go inside?",
    "door","Why not go inside?",
    "casino","You should go inside and check it out"});}
  ::reset(arg);}

void init()
  {::init();
  add_action("nw","northwest");
  add_action("nw","east");
  if(!dwarf)
    {call_out("fg",8,0);}}

status nw() 
  {remove_call_out("fg");}

void fg() 
  {writelw("All of a sudden things start heating up in the bar, and "+
  "the next thing you know, a small dwarf (is that a "+
  "redundant statement or what!?!) is thrown out the door "+
  "and smacks into the cave wall.  After being dazed for a "+
  "moments, the dwarf stands up and brushes himself off. "+
  "Dwarf says: Nice to meet you, I'm Pogo!  Hrmmph....that's "+
  "the last time I go back there!  Well..ok...well...maybe not "+
  "for awhile!  Anyway, that's the most crooked house I've "+
  "ever seen! But here's a secret....if you want, you can get "+
  "into a high stakes game by impressing the guys out front.  "+
  "It may take a little gold, but you can play the boss in the "+
  "back...If you're really gutsy, you might even take him out.. "+
  "Sure would please the king... ");
  writelw("\nPogo waves goodbye the runs out the cave.  As he "+
  "disappears, you notice he left behind a large pile of "+
  "casino chips.\n");
  dwarf=1;
  if(!present("kq1-chips",this_object()))
    {transfer(clone_object("players/kawai/obj/chips"),this_object());}}


