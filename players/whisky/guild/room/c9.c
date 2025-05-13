

inherit "room/room";
#include "../guild.h"

void reset(int arg) 
{
    if (arg) return;
    set_light(1);
    short_desc = "In a chapel"; 
    long_desc = BS(
          "This is the inner of the monks chapel. It is a room where then "
        + "monks can pray to their gods. You see a black altar on the "
        + "northern wall, where you can 'pray' if you are ghost."
        + " A little corridor leads further to the west " 
        + "and south. The entrance to a small wedding chapel is to the "
        + "east");
        
    items = ({ 
            "walls","White stone walls",
            "altar","You see a big black altar, it looks mystical\n"+
                    "and its burning to spend the holy fire for this guild.\n"+
                    "You can also pray here when you are ghost",
            "bottom","A brown wooden bottom"
             });
    dest_dir = 
        ({
        PATH+"c8","west",
        PATH+"c6","south",
        "players/whisky/genobj/chapel","east",
        });
   }
  query_property(arg) {
  if (arg=="has_fire") return 1;
  }

  light_text(str) {
  say(this_player()->query_name()+" lights "+str+" on the burning altar.\n");
  write("You light "+str+" on the burning altar !\n");
  }

 void init()
{
  ::init();
  add_action("do_pray","pray");
}

int do_pray()
{
  if (!this_player()->query_ghost())
  {
     write("An image of Whisky appears telling you:\n"+
           "    Opps, but you are no ghost.        \n");
     return 1;
  }
  write("Whisky arrives in a cloud of mushrooms.\n");
  call_out("do_wave",1,this_player());
  return 1;
}

void do_wave(object ob)
{
     write("Whisky sadly looks at you.\n");
     call_out("do_wave1",1,ob);
}

void do_wave1(object ob)
{
     write("Whisky utters the word 'ufzrlrk urzzz runk'.\n");
     catch(call_other(ob,"remove_ghost"));
     ob->heal_self(1000);
     call_out("do_wave2",1);
}

void do_wave2()
{
     write("Whisky happily waves at you.\n");
     call_out("do_wave3",1);
}

void do_wave3()
{
     write("Whisky disappears in a cloud of mushrooms !\n");
}
