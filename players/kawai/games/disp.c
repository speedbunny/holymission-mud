#define PATH "/players/kawai/games/"
#define NUM 3

mixed items;

int get(string str)
  {return 0;}

int id(string str)
  {return str=="dispenser";}

string query_name()
  {return "A game dispenser";}

string short()
  {return "A small box with buttons that dispenses various games.\n";}

void long()
  {write("The box is a dispenser for various games to play.  Current\n"+
  "choices are: 1) Minesweeper\n"+
  "             2) IQ Pegs\n"+
  "You can 'press #' to get a game.\n");}

void init()
  {add_action("press","press");}

void reset(int arg)
 {if(!arg) 
  {items=({"mines","portagame","pegs","portagame"});}}

status press(string arg)
  {int x;
  object z;
  if(!arg) 
    {notify_fail("Press what?\n");
    return 0;}
  sscanf(arg,"%d",x);
  if((x<1)||(x>NUM))
    {notify_fail("That button doesn't work!\n");
    return 0;}
  else 
    {z=clone_object(PATH+items[(x-1)*2]);
    if(present(items[((x-1)*2)+1],this_player()))
      {write("You can only have one portable game at a time!\n");
      return 1;}
    else 
      {transfer(z, this_player());
      write("Ta da!\n");
      return 1;}}
  return 0;} 
   

  