/* 
  Inheritable generic tree - 10-1-93

*/

inherit "/players/kbl/objs/thing";
#include "/players/kbl/header/T.h"

string *tree_dir;
int    i;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(1);
    name = "Branch of a giant pine tree";
    short_desc = "Branch of a large tree";
    long_desc = "You are on a branch of a large tree. Not much to see here.\n"+
                "The branch overlooks a room below.\n";
    tree_dir = ({
                 "players/kbl/pine/tree_room","down",
                });
    weight = 500;
    value = 500000;
    alt_name = "tree";
    alias_name = "branch";
    read_message = "Branch of a giant pine tree. It has special qualities.\n";
  }
}

init()
{
  ::init();
   for(i=0;i<sizeof(tree_dir);i+=2)
    add_action("proc",tree_dir[i+1]);
}

proc()
{
  string qv;
  int    idx;

  qv = query_verb();
  if((idx = member_array(qv,tree_dir)) != -1)
  {
    transfer(this_player(),tree_dir[idx-1]);
    command("look",this_player());
    return 1;
  }
}

set_tree_dest(str)
{
  tree_dir = str;
}
