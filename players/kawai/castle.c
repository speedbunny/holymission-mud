#define NAME "kawai"
#define DEST "/players/kawai/workroom"

void make_quest()
  {object x;
  x = clone_object("obj/quest_obj");
   x->set_name("kill_cult");
   x->set_hint("Recent word is that an evil cult has formed deep in the caves\n"+
                "near the dwarven city.  You must defeat the cult and their\n"+
                "idol, but your task is not easy, for only the Dwarven King\n"+
                "has the answers you need. He is a wise king, and does not\n"+
                "trust easily, so you must prove your worth to him.\n"+
                "Remember to consult the king frequently!\n");
   x->set_short_hint("Destroy Kazak and his evil cult!");
   x->set_weight(25);
   x->set_killing(4);
   x->add_quest();}

int id(string str)
  {return str == "castle";}

string short()
  {return "Castle of " + NAME;}

void long() 
  {write("This is the " + short() + ".\n"+
  NAME + " is a rather new wizard, but it is an amazing castle\n"+
  "just the same. However, the gates are closed.\n");}

void init()
  {add_action("enter", "enter");}

status enter(string str)
  {if(!id(str))
    {return 0;}
  write("It is not an open castle.\n");
  return 1;}

void reset(int arg)
  {if(!arg)
    {move_object(this_object(), DEST);}}
