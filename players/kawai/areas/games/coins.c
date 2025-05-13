inherit "room/room";

#include <lw.h>
#define PATH "/players/kawai/areas/games/"
#define OPATH "/players/kawai/obj/"
#define NUM_COINS 12
#define MAX_MOVES 3
#define VISION "A vision of the Grand Wizard appears and says: "
#define DEBUG 0

mixed coins;
object player;
int moves;

void make_coins()
  {int i;
  coins=allocate(NUM_COINS);}

void init_coins()
  {int i,j;
  for(i=0;i<NUM_COINS;i++)
    {coins[i]=2;}
  i=random(12);
  switch(random(2))
    {case 0: coins[i]=1;
             break;
    case 1: coins[i]=3;
             break;}}

void reset_game()
  {init_coins();
  player=0;
  moves=0;}

int compare(int x, int y)
 {if(x>y)
   {return -1;}
  else if(x==y)
   {return 0;}
  else
   {return 1;}}


mixed convert_list(string list)
  {mixed expanded_string, expanded_int;
  int i, size;
  expanded_string=explode(list," ");
  if(!size=sizeof(expanded_string))
    {notify_fail(lw(VISION+
    "You can't leave a side of the scale empty!\n"));   
    return;}
  expanded_int=allocate(size);
  for(i=0;i<size;i++)
     {if(!sscanf(expanded_string[i],"%d",expanded_int[i]))
       {notify_fail(lw(VISION+
       "Incompetent fool!  Only specify the number of the coin when "+
       "using the scale!\n"));
       return;}}
  return expanded_int;}


int add_weights(mixed list)
  {int i,total;
  mixed ilist;
  ilist=0;
  total=0;
  if(!ilist=convert_list(list))
    {return 0;}
  else
    {for(i=0;i<sizeof(ilist);i++)
      {total=total+coins[ilist[i]-1];}
    return total;}}


int duplicates(mixed left, mixed right)
  {int i, j, found;
  mixed ileft, iright;
  found=0; 
  if(!ileft=convert_list(left))
    {notify_fail("Please alert Kawai that an error has occured.\n");
    return 0;}
  else if(!iright=convert_list(right))
    {notify_fail("Please alert Kawai that an error has occured.\n");
    return 0;}
  else
    {for(i=0;i<sizeof(ileft);i++)
      {for(j=0;j<sizeof(iright);j++)
        {if(ileft[i]==iright[j])
           {found=1;}}}
    return found;}} 

int verify_move(string str, int x)
 {if(!str)
    {if(!x) 
      {notify_fail(lw(VISION+
      "Come again, adventurer?  The proper way to utilize the equipment "+
      "before you is 'balance a against b', where 'a' and 'b' are the numbers "+
      "of the coins you'd like to weigh, separated by spaces.  For example, "+
      "you may 'balance 1 3 4 against 2 5 6'.\n"));
      return 0;}
    else
      {notify_fail(lw(VISION+
      "Say again, adventurer...what coin do you choose?\n"));
      return 0;}}
  if(this_player()!=player)
    {if(player)
      {if(present(player,this_object()))
        {writelw("As you reach to get the coin, a strange force overwhelms "+
        "your body.  As you recover from the blow, you find yourself in a "+
        "different place.\n");
        this_player()->move_player("in a burst of light",PATH+"start");
        return 1;}
      writelw(VISION+
      "It appears our last victim has left.  Why don't you try...\n");
      reset_game();
      return 1;}
    else
      {notify_fail(lw(VISION+
      "Finally, another victim!  Why don't you 'begin game'\n"));
      return 0;}}
  return -1;}

status parse_move(string str)
  {string list1, list2;
  int left, right;
  if(verify_move(str,0)!=-1)
    {return 0;}
  if(sscanf(str,"%s against %s",list1,list2)!=2)
    {notify_fail(lw(VISION+
    "Come again, adventurer?  The proper way to utilize the equipment "+
    "before you is 'balance a against b', where 'a' and 'b' are the numbers "+
    "of the coins you'd like to weigh, separated by spaces.  For example, "+
    "you may 'weigh 1,3,4 against 2,5,8'.\n"));
    return 0;} 
 if(moves>=MAX_MOVES)
    {writelw(VISION+
    "Unfortunately, little one, you have already used the scale as many "+
    "times as allowed.  You must make your choice, and pray it is correct.\n");
    return 1;}
  if(!left=add_weights(list1))
    {return 0;}
  if(!right=add_weights(list2))
    {return 0;}
  if(duplicates(list1,list2))
    {writelw(VISION+
    "You really are a dullard, aren't you?  You can't balance a coin against "+
    "itself!\n");
    return 1;}
#if DEBUG
  write("Left: "+left+" Right:"+right+"\n");
#endif
  switch(compare(left,right))
    {case -1: write("The scale tips to the left.\n");
              break;
     case 0:  write("The scale is balanced.\n");
              break;
     case 1:  write("The scale tips to the right.\n");
              break;}
  moves++;
  return 1;}

int choose(string str) 
  {int num;
  object stub;
  if(verify_move(str,1)!=-1)
    {return 0;}
  if(!sscanf(str,"%d",num))
    {notify_fail(lw(VISION+
    "Say again, adventurer...what coin do you choose?\n"));
    return 0;}
  if((num<1)||(num>NUM_COINS))
    {writelw(VISION+
    "You think you're clever?  There is no such coin!\n");
    return 1;}
  else
    {if(coins[num-1]==2)
      {writelw(VISION+
      "As I expected, this simple task was beyond your comprehension.  "+
      "The coin you picked was not the counterfeit, and now you shall "+
      "pay the price!\n\n"+
       "A powerful whirlwind surrounds your body, and as the air around "+
       "you clears, you notice much different surroundings.\n");
       reset_game();
       this_player()->move_player("in a puff of smoke",PATH+"labr1");
       return 1;}
    else
      {writelw(VISION+
      "Such surprise from my little plaything.  Procede...\n");
      reset_game();
        if(!stub=present("gstub",this_player()))
          {transfer(stub=clone_object(OPATH+"stub"),this_player());}
        stub->set_last(2);
      this_player()->move_player("in a puff of smoke",PATH+"knight");
      return 1;}}
  return 0;}


status read_note(string str) 
  {if(!str) 
    {notify_fail("Read what?\n");
    return 0;}
  if(str=="note")
    {writelw(
    "Greetings, "+capitalize(this_player()->query_real_name())+"!\n\n"+
    "   In this second puzzle you have a fairly simple task.  On the table "+
    "are "+NUM_COINS+", all of which are identical in appearance.  "+
    "There is, however, a counterfeit coin among the batch, and it "+
    "is your task to decide which one.  All the coins, with the "+
    "exception of the counterfeit one, are identical in weight.  "+
    "The odd coin, however, may be lighter or heavier than the rest, "+
    "but you'll have to figure that out for yourself.\n"+
    "   You will be able to use this scale "+MAX_MOVES+" times in "+
    "order to determine the false coin, and you can weigh the coins "+
    "against each other in whatever combinations you see fit.  To "+
    "weigh, utter the command 'balance <coins> against <coins>', such "+
    "that <coins> is a list of the coins you wish to weigh on that side, "+
    "separated by spaces.  You need only specify the number of the coin, "+
    "for example, 'weigh 1 3 4 against 2 7 9'.  The scale will then "+
    "either tip to the left, the first group of coins, stay balanced, "+
    "or tip to the left.  When you are confident that you have determined "+
    "the right coin, you must 'choose <coin>'.  You only get one "+
    "chance to pick, so best hope you are right!  To may 'begin game' at any time, but once you start, there "+
    "is no turning back.  You may also 'escape' now and be spared the "+
    "price for failure.\n"+
   "                                           -The Grand Wizard\n");
    return 1;}
  else
    {return 0;}}


status begin(string str) 
  {if(!str) 
    {notify_fail("Begin what?\n");
    return 0;}
  if(str=="game")
    {if(player)
      {if(this_player()==player) 
        {notify_fail(VISION+
        "You are already playing, adventurer!\n");
        return 0;}
      if(present(player,this_object()))
        {notify_fail(lw(VISION+
        "My apologies, adventurer, but someone has beaten you to the task.  "+
        "Don't be alarmed, however, their demise is soon approaching and "+
        "then you may begin.\n"));
        return 0;}
      else
        {writelw(VISION+
        "It appears that our last victim has somehow eluded us..."+
        "Nevertheless, you may begin!\n");
        reset_game();
        player=this_player();
        return 1;}}
    else
      {writelw("You begin the puzzle...\n");
       reset_game();
       player=this_player();
       return 1;}}
  return 0;}
 
status escape()
 {if(this_player()==player)
   {notify_fail(lw(VISION+
   "Too late, fool!  You have already accepted my challenge!\n"));
   return 0;}
 else
   {this_player()->move_player("in a puff of smoke",PATH+"start");
    return 1;}}

void init()
  {::init();
  add_action("parse_move","balance");
  add_action("choose","choose");
  add_action("escape","escape");
  add_action("begin","begin");
  add_action("read_note","read");
  add_action("take","take");
  add_action("take","get");}
 

status take(string str) 
  {if(!str) 
    {notify_fail(capitalize(query_verb())+" what?\n");
    return 0;}
  else if(str=="coin"||str=="coins"||str=="scale")
    {notify_fail(lw(VISION+
    "I think not!  When will children learn to share their toys!\n"));
    return 0;}
  else
    {notify_fail("You can't take that.\n");
    return 0;}}


void reset(int arg)
  {if(!arg)
    {make_coins();
    reset_game();
    set_light(1);
    short_desc="The second puzzle room";
    long_desc="The walls of this small room are covered in tapestries "+
     "portraying a scene of a dark forest.  The pictures are so "+
     "real that you can almost hear the chirping of crickets in "+
     "the background.  The only furniture in the room is a small "+
     "pine table in the corner of the room.\n";
    dest_dir=0;
    items=({"tapestry","It is of a dark, forbidding forest",
     "wall","It has several large tapestries on it",
     "forest","A dark pine forest",
     "picture","A picture of a pine forest",
     "pictures","Various scenes of a pine forest",
     "pine","A pine tree",
     "pines","Pine trees",
     "walls","They are covered in large tapestries",
     "scene","A woodland scene",
     "scenes","They show a dark, forbidding forest..",
     "furniture","A table",     
     "game","A puzzle involving "+NUM_COINS+" and a scale",
     "puzzle","A puzzle involving "+NUM_COINS+" and a scale",
     "scale","A balancing scale used to weigh items against one another",
     "coin","They all look the same",
     "coins","They all look the same",
     "tapestries","They show a dark, forbidding forest..",
     "tree","A pine tree",
     "trees","A forest of pine trees",
     "cricket","You notice several small insects in the forest",
     "crickets","Though they don't appear to be here, you can hear them",
     "room","The room you are in.  Just look",
     "table","A small pine table with a scale, "+NUM_COINS+" coins, and a note tacked next to it",
     "note","Try reading it",
     "pegs","A bunch of small wooden pegs"});}
  ::reset(arg);}

