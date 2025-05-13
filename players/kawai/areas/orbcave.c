inherit "room/room";
#include <lw.h>
#define TP this_player()
#define CTPN capitalize(TP->query_name())
int is_taken, is_loose;

void reset(int arg) 
  {is_taken=0;
  is_loose=0;
  if(!arg) 
    {set_light(5);
    short_desc = "Underground river";
    long_desc =
    "You stand in a brightly lit cave formed by the flow of an ancient "+
    "underground river.  Water flows from a small opening to the east "+
    "but the hole is too small and the water flows much to fast to see "+
    "anything beyond it.  @@chk_orb@@";
    smell = "The air is damp and musty.";
    dest_dir = ({"players/kawai/areas/wfcave","west"});
    items = ({"cave","It is brightly lit and filled with water.", 
    "river","The river is not as strong as you once imagine it was to form such a cave, but\n"+
    "it still makes you loose your balance as you wade through it", 
    "sediment","Centuries of water flow have left hard deposits on the cave walls", 
    "hole","Water gushes from a narrow slit in the cave wall, to small to pass through"
    "opening","Water gushes from a narrow slit in the cave wall, to small to pass through",
    "water","It flows swiftly beneath you."});}
  ::reset(arg);}
 
void init() 
  {::init();
  add_action("get_it","get");
  add_action("get_it","take");
  add_action("dig_it","dig");
  add_action("dig_it","remove");
  add_action("look_at","look");
  add_action("look_at","l");}

string chk_orb() 
  {if(is_taken) 
    {return "There is a small, spherical indentation in the wall, and the "+
    "rock inside glows brightly.\n";}
  else if(!is_loose) 
    {return "A strange orb is embedded in the rock, covered with years of hardened "+
    "sediment.  A small part is still exposed, and emits a bright light.\n";}
  else
    {return "A strange orb is nestled in the rock, although it looks like it can be easily "+
    "removed.  It glows with a strange light.\n";}}

status look_at(string str) 
  {if(!str)
    {return 0;}
  if(str=="at orb") 
    {if(is_taken) 
      {notify_fail("Thats not here.\n");
      return 0;}
    if(!is_loose) 
      {writelw("The orb is a little under a foot in diameter from what you can see, and "+
      "it glows with an incredible light, yet does not seem to radiate any heat.  "+
      "It is mostly covered by years of hardened sediment and looks unmovable.  ");
      return 1;}
    writelw("The orb is a little under a foot in diameter and glows with a strange light.  It "+
    "appears to be loose enough to remove.\n");
    return 1;}
  if(str=="at rock" || str=="at rocks") 
    {if(is_taken) 
      {write("They glow softly.\n"); 
      return 1;}
    write("They appear normal.\n");
    return 1;}
  return 0;}

status dig_it(string str) 
  {string a;
  object ob;
  if(!str) 
    {return 0;}
  if(sscanf(str,"orb with %s",a) !=1)
    {write(capitalize(query_verb()) + " with what?\n");
    return 1;}
  if(!(ob=present(a,TP))) 
    {write("You don't have the "+a+"!\n");
    return 1;}
  else 
    {if(is_loose)
      {write("It already is loose.\n");
      return 1;}
    if(!((a=="axe")||(a=="pickaxe"))) 
      {write("That doesn't work.\n");
      return 1;}
    if(!ob->id("kq1-axe")) 
      {write("It doesn't seem suited for it.\n");
      return 1;}
    else
      {if(!ob->query_sharp()) 
        {write("You chip away at the rock, but the axe is just too dull.\n");
        say(CTPN+" tries to loosen the orb, but fails.\n"); 
        return 1;}
      else 
        {write("You chip away at the rock, freeing the orb.\n");
        say(CTPN+" loosens the orb with a pickaxe\n.");
        is_loose=1;
        return 1;}}}
  return 0;}

status get_it(string str) 
  {object ob;
  if(!str) 
    {return 0;}
  if(str=="orb") 
    {if(is_taken) 
      {return 0;}
    if(!is_loose) 
      {write("The orb is stuck in the rock.\n");
    return 1;}
    if(transfer(ob=clone_object("players/kawai/obj/orb"),TP))
      {write("You are unable to take the orb at the moment.\n");
      if(ob)
        {destruct(ob);}
      return 1;}
    is_taken=1;
    write("Ok.\n");
    say(CTPN+" takes the orb.\n");
    return 1;}
  if(str=="rock"||str=="rocks") 
    {write("You can't take them.\n");
    return 1;}
  return 0;}


