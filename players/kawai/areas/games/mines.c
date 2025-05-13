inherit "room/room";
#include <lw.h>

#define PATH "/players/kawai/areas/games/"
#define OPATH "/players/kawai/obj/"
#define MAX 9
#define SCATTER_SEED 10
#define MAX_BOMBS 10
#define DEBUG 0

mixed grid, cover;
object player;
int squares, bombs, marks, is_playing, start;


mixed make_grid() 
  {mixed temp;
  int row;
  temp=allocate(MAX);
  for(row=1;row<MAX;row++) 
    {temp[row]=allocate(MAX);}
  return temp;}


void init_grid() 
  {int row, col;
  for(row=1;row<MAX;row++) 
    {for(col=1;col<MAX;col++) 
      {grid[row][col]="?";
      cover[row][col]="?";}}}

void scatter(int arg) 
  {int row, col;
  for(row=1;row<MAX;row++)
    {for(col=1;col<MAX;col++) 
      {if((arg)&&(!(random(SCATTER_SEED)))&&(grid[row][col]=="?"))
        {arg--;
        grid[row][col]="*";}}}
  if(arg) scatter(arg);}


void fill() 
  {int row, col , x;
  for(row=1;row<MAX;row++)
    {for(col=1;col<MAX;col++)
      {x=0;
      if(grid[row][col]=="?")
        {if((row+1)<MAX) 
          {if(grid[row+1][col]=="*")
            {x++;}}
        if((row-1)>0) 
          {if(grid[row-1][col]=="*")
            {x++;}}
        if((col+1)<MAX) 
          {if(grid[row][col+1]=="*")
            {x++;}}
        if((col-1)>0) 
          {if(grid[row][col-1]=="*")
            {x++;}}
        if(((row+1)<MAX)&&((col+1)<MAX)) 
          {if(grid[row+1][col+1]=="*") 
            {x++;}}
        if(((row+1)<MAX)&&((col-1)>0)) 
          {if(grid[row+1][col-1]=="*")
            {x++;}}
        if(((row-1)>0)&&((col+1)<MAX)) 
          {if(grid[row-1][col+1]=="*")
            {x++;}}
        if(((row-1)>0)&&((col-1)>0)) 
          {if(grid[row-1][col-1]=="*")
            {x++;}}
       grid[row][col]=x;}}}}


void spawn(int row, int col) 
  {if((row+1)<MAX) 
    {if(cover[row+1][col]=="?") 
      {cover[row+1][col]=grid[row+1][col];
      squares--;
      if(!grid[row+1][col])
        {spawn(row+1,col);}}}
  if((row-1)>0) 
    {if(cover[row-1][col]=="?")
      {cover[row-1][col]=grid[row-1][col];
      squares--;
      if(!grid[row-1][col])
        {spawn(row-1,col);}}}
  if((col+1)<MAX) 
    {if(cover[row][col+1]=="?") 
      {cover[row][col+1]=grid[row][col+1];
      squares--;
      if(!grid[row][col+1])
        {spawn(row,col+1);}}}
  if((col-1)>0)
    {if(cover[row][col-1]=="?")
      {cover[row][col-1]=grid[row][col-1];
      squares--;
      if(!grid[row][col-1])
        {spawn(row,col-1);}}}
  if(((row+1)<MAX)&&((col+1)<MAX))
    {if(cover[row+1][col+1]=="?") 
      {cover[row+1][col+1]=grid[row+1][col+1];
      squares--;
      if(!grid[row+1][col+1])
        {spawn(row+1,col+1);}}}
  if(((row+1)<MAX)&&((col-1)>0)) 
    {if(cover[row+1][col-1]=="?") 
      {cover[row+1][col-1]=grid[row+1][col-1];
      squares--;
      if(!grid[row+1][col-1])
        {spawn(row+1,col-1);}}}
  if(((row-1)>0)&&((col+1)<MAX)) 
    {if(cover[row-1][col+1]=="?")
      {cover[row-1][col+1]=grid[row-1][col+1];
      squares--;
      if(!grid[row-1][col+1])
        {spawn(row-1,col+1);}}}
  if(((row-1)>0)&&((col-1)>0))
   {if(cover[row-1][col-1]=="?")
     {cover[row-1][col-1]=grid[row-1][col-1];
     squares--;
     if(!grid[row-1][col-1])
       {spawn(row-1,col-1);}}}}


void show_grid()
  {int row, col, x;
  write("\n ");
  for(x=1;x<MAX;x++) 
    {write("   "+x);}
  write("\n");
  write("  +");
  for(x=1;x<MAX;x++) 
    {write("---+");}
  write("\n");
  for(row=1;row<MAX;row++)
    {write(row+" ");
    for(col=1;col<MAX;col++)
      {if(!cover[row][col]) 
        {write("|   ");}
      else 
        {write("| "+cover[row][col]+" ");}}
    write("|\n");
    write("  +");
    for(x=1;x<MAX;x++) 
      {write("---+");}
    write("\n");}}

void reset_game()
  {player=0;
   init_grid();
   scatter(MAX_BOMBS);
   fill();
   squares=(MAX-1)*(MAX-1);
   marks=0;
   bombs=MAX_BOMBS;}

int check_win()
#if DEBUG
  {write("Checking for win: bombs="+bombs+" marks="+marks+"\n");
#else
  {
#endif
  if((!bombs)&&(marks==MAX_BOMBS))
    {return 1;}
  return 0;}

status parse_move_mark(string str) 
  {int row, col;
  object stub;
  if(this_player()!=player)
    {if(player)
      {if(present(player,this_object()))
        {writelw("As you reach to touch the piece, a strange force overwhelms "+
        "your body.  As you recover from the blow, you find yourself in a "+
        "different place.\n");
        this_player()->move_player("in a burst of light",PATH+"start");
        return 1;}
      writelw("A vision of the Grand Wizard appears and says: "+
      "It appears our last victim has left.  Why don't you try...\n");
      reset_game();
      return 1;}
    else
      {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
      "Finally, another victim!  Why don't you 'begin game'\n"));
      return 0;}}
  if(sscanf(str,"%d,%d",row,col)!=2)
    {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
    "Have you no brain?  That is not how you mark a piece!\n"));
    return 0;}
  else
    {if((row>=MAX)||(row<1)||(col>=MAX)||(col<1))
      {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
      "Fool!  That is not a valid position!\n"));
      return 0;}
    if(cover[row][col]=="#")
      {write("Unmarking "+row+","+col+".\n");
      if(grid[row][col]=="*")
        {bombs++;}
      squares++;
      marks--;
      cover[row][col]="?";
      if(check_win())
        {writelw("A vision of the Grand Wizard appears and says: "+
        "Very good, my little toy!  You may now proceed...\n");
        reset_game();
        if(!stub=present("gstub",this_player()))
          {transfer(stub=clone_object(OPATH+"stub"),this_player());}
        stub->set_last(1);
        this_player()->move_player("in a puff of smoke",PATH+"coins");
        return 1;}
      return 1;}
    else if(cover[row][col]=="?") 
      {write("Marking "+row+","+col+".\n");
      if(grid[row][col]=="*")
        {bombs--;}
      squares--;
      marks++;
      cover[row][col]="#";
      if(check_win())
        {writelw("A vision of the Grand Wizard appears and says: "+
        "Very good, my little toy!  You may now proceed...\n");
        reset_game();
        if(!stub=present("gstub",this_player()))
          {transfer(stub=clone_object(OPATH+"stub"),this_player());}
        stub->set_last(1);
        this_player()->move_player("in a puff of smoke",PATH+"coins");
        return 1;}
      return 1;}
    else 
      {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
      "Fool!  You can't do that!\n"));
      return 0;}}
  return 0;}


status parse_move_turn(string str) 
  {int row, col;
  object stub;
  if(this_player()!=player)
    {if(player)
      {if(present(player,this_object()))
        {writelw("As you reach to touch the piece, a strange force overwhelms "+
        "your body.  As you recover from the blow, you find yourself in a "+
        "different place.\n");
        this_player()->move_player("in a burst of light",PATH+"start");
        return 1;}
      writelw("A vision of the Grand Wizard appears and says: "+
      "It appears our last victim has left.  Why don't you try...\n");
      reset_game();
      return 1;}
    else
      {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
      "Finally, another victim!  Why don't you 'begin game'\n"));
      return 0;}}
  if(sscanf(str,"%d,%d",row,col)!=2)
    {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
    "Have you no brain?  That is not how you mark a piece!\n"));
    return 0;}
  else
    {if((row>=MAX)||(row<1)||(col>=MAX)||(col<1))
      {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
      "Fool!  That is not a valid position!\n"));
      return 0;}
    if(cover[row][col]=="?")
      {write("Turning square "+row+","+col+".\n");
      if(grid[row][col]=="*")
        {writelw("A vision of the Grand Wizard appears and says: "+
        "Alas, you've run out of chances.  Time for you to be leaving...\n\n"+
        "A powerful whirlwind surrounds your body, and as the air around "+
        "you clears, you notice much different surroundings.\n");
        reset_game();
        this_player()->move_player("in a puff of smoke",PATH+"labr1");
        return 1;}
      squares--;
      cover[row][col]=grid[row][col];
      if(grid[row][col]==0) 
        {spawn(row,col);}
      if(check_win())
        {writelw("A vision of the Grand Wizard appears and says: "+
        "Very good, my little toy!  You may now proceed...\n");
        reset_game();
        if(!stub=present("gstub",this_player()))
          {transfer(stub=clone_object(OPATH+"stub"),this_player());}
        stub->set_last(1);
        this_player()->move_player("in a puff of smoke",PATH+"coins");
        return 1;}
      return 1;}
    else
      {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
      "Pathetic creature!  Can't you see you've already done that!\n"));
      return 0;}}
  return 0;}

status read_note(string str) 
  {if(!str) 
    {notify_fail("Read what?\n");
    return 0;}
  if(str=="note")
    {writelw(
    "Greetings, "+capitalize(this_player()->query_real_name())+"!\n\n"+
    "   Welcome to the first of 3 challenges!  This game, like the others, "+
    "is simple!  Before you is a "+(MAX-1)+"x"+(MAX-1)+" grid.  Hidden among the field "+
    "are "+MAX_BOMBS+" magic symbols.  Your task is to correctly locate the 10 symbols "+
    "by revealing and marking the squares on the board.  When you reveal a "+
    "square, it will either tell you how many, if any, symbols border that "+
    "square, or it will contain the symbol itself.  Using the numbers reveal "+
    "by the squares, you should have no trouble deducing the location of all "+
    "the symbols.  Beware!  If the space you reveal does contain a symbol, you "+
    "shall lose, and the punishment will be severe!.  To reveal a square, "+
    "simply utter the command 'turn row,col'.  When you are certain that a square "+
    "contains a symbol, you must 'mark row,col' as a signal to me.  When all the "+
    "squares containing symbols are marked, no more, no less, then you may "+
    "pass.  You may 'begin game' when you are ready, or if you are as much "+
    "of a coward as I suspected, you may 'escape' now while you have the "+
    "chance.\n"); 
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
        {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
        "Have you forgotten?  You are already playing!\n"));
        return 0;}
      if(present(player,this_object()))
        {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
        "My apologies, adventurer, but someone has beaten you to the task.  "+
        "Don't be alarmed, however, their demise is soon approaching and "+
        "then you may begin.\n"));
        return 0;}
      else
        {writelw("A vision of the Grand Wizard appears and says: "+
        "It appears that our last victim has somehow eluded us..."+
        "Nevertheless, you may begin!\n");
        reset_game();
        player=this_player();
        return 1;}}
    else
      {write("You begin the puzzle...\n");
       reset_game();
       player=this_player();
       return 1;}}
  return 0;}
 

status escape()
 {if(this_player()==player)
   {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
   "Too late, fool!  You have already accepted my challenge!\n"));
   return 0;}
 else
   {this_player()->move_player("in a puff of smoke",PATH+"start");
    return 1;}}

void init()
  {::init();
  add_action("parse_move_mark","mark");
  add_action("parse_move_turn","turn");
  add_action("escape","escape");
  add_action("begin","begin");
  add_action("read_note","read");
  add_action("look","look");
  add_action("look","l");}

status look(string str)
  {if(!str)
    {notify_fail("Look at what?\n");
    return 0;}
  if(str=="at board"||str=="at game"||str=="at puzzle"||str=="at grid")
    {if(this_player()!=player)
      {write("It is a small grid.\n");
      return 1;}
    else
      {show_grid();
      return 1;}}
  return 0;}
 
void reset(int arg)
  {if(!arg)
    {grid=make_grid();
    cover=make_grid();
    reset_game();
    set_light(1);
    short_desc="The third puzzle room";
    long_desc="The walls of this small room are covered with various paintings"+
     " of an ocean scene.  Seagulls are pearched on pointed rocks as waves "+
     "crash against the shoals, and a rainbow can be seen among the mist. "+
     "The only furniture in the room is a small marble table "+
     "in the center of the room.\n";
    dest_dir=0;
    items=({"painting","It is of a beautiful ocean scene",
     "wall","It has a painting of an ocean on it",
     "scene","A beautiful ocean scene",
     "walls","They are decorated with various paintings",
     "paintings","They are of the ocean",
     "ocean","Quite beautiful for something so destructive",
     "seagull","It is pearched on a rock",
     "seagulls","Several are standing about the rocks",
     "wave","Quite beautiful for something so destructive",
     "waves","They seem awfully rough",
     "rainbow","Just the reflection of light",
     "shoal","A dangerous set of rocks",
     "shoals","A dangerous set of rocks",
     "rock","A big, pointy rock",
     "rocks","A dangerous set of rocks",
     "mist","You can see a rainbow in it",
     "furniture","The table is rather interesting",
     "room","The room you are in.  Just look",
     "marble","Grey and white with tints of red",
     "table","A small marble table with a board and a note secured next to it",
     "note","Try reading it"});}
  ::reset(arg);}


