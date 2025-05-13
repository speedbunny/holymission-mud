inherit "/players/kbl/objs/thing";

#include "/players/kbl/cloud/gen.h"

int num_parts,
    max;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    name = "cloud puzzle";
    short_desc = "Cloud Puzzle";
    long_desc = "This is Cloud Cities Cloud Puzzle Holder. On the side\n"+
                "there's a slot for cloud parts. Currently this puzzle\n"+
                "has not been solved. There's one command engraved next\n"+
                "to the slot: remaining\n";
    max = 20;
    weight = 1;
    value = 1;
    alt_name = "puzzle";
    alias_name = "holder";
    read_message = "You cannot see the cloud puzzle for it has not been "+
                   "solved yet.\n";
  }
}

init()
{
  ::init();
   add_action("in","insert");
   add_action("re","remaining");
}

in(str)
{
  object ob;

  if(!str)
   return;
  if(num_parts == max)
  {
    write("The puzzle has been solved. Now go find the keeper of Cloud\n"+
          "City for he will tell you what to do next.\n");
    return 1;
  }
  if(str == "part" || str == "cloud part")
  {
    if(ob = present("cloud_part",TP))
    {
      num_parts+=1;
      destruct(ob);
      write("You insert your cloud part into the puzzle and its absorbed.\n");
      say(CTPRN+" inserted a cloud part into the cloud puzzle.\n",TP);
      if(num_parts == max)
      {
        write("You have filled the cloud puzzle, congratulations!!\n"+
              "Now you need to find the keeper of Cloud City. He is\n"+
              "located in the palace lookout tower. Ask Olav where that is.\n";
      }
      return 1;
    }
    write("You do not have a cloud part.\n");
    return 1;
  }
}

re()
{
  write("The puzzle whispers to you: You need "+(num_parts-max)+" more"+
        " parts.\n");
  return 1;
}

set_max(n)
{
  max = n;
}
