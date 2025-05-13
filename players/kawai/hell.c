inherit "room/room";

#include "/players/kawai/hell.h"
#define env environment

object kill_ob;

void reset(int arg)
  {if(!arg)
    {set_light(1);
    short_desc="HELL!!!";
    long_desc = "Welcome to Hell, Asshole!  You have offended the gods, so now you "+
    "must pay the price!  Enjoy your stay!!!\n";}}

void init()
  {object ob;
  move_object(ob=clone_object("players/kawai/obj/flames"),this_object());
  if(this_player())
    {ob->burn_player(this_player());
    if(!this_player()->query_wizard())
      {add_action("block","",1);}}
  else
    {destruct(ob);}}

status block(string str)
  {if(this_player()->query_ghost())
    {write("\n\nYour smoking remains pass through an opening in the oven ...\n\n");
    move_object(this_player(),"room/church");
    say("Smoking remains of "+capitalize(this_player()->query_real_name())+
    " arrives.\n");
    command("look",this_player());
    return 1;}}

void burn_player(object ob)
  {kill_ob=ob;}

int query_no_teleport()
  {return 1;}
