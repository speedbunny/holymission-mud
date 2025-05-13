/* 
  MudMines! v 2.1 by Kawai@Holy Mission (140.78.3.1 2001)
  Bazyl@cleo.bc.edu
  Base on the popular PC game
  Feel free to distribute.
  Please document any changes
*/

#include <lw.h>
#define TP this_player()
#define name lower_case(this_player()->query_real_name())
#define MAX 9
#define SCATTER_SEED 10
#define MAX_BOMBS 10
#define DEBUG 0

mixed grid, cover;
object player;
int squares, bombs, marks, is_playing, start;


int id(string str)
  {return str=="game"||str=="minesweeper"||str=="portagame";}

string short()
  {return "The game Minesweeper";}

int get(string str)
  {return 1;}

int drop()
  {return 0;}

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
        {writelw("You are not the current player.\n");
        return 1;}
      writelw("Type 'begin game' to play.\n");
      reset_game();
      return 1;}
    else
      {notify_fail(lw("Type 'begin game' to play.\n"));
      return 0;}}
  if(sscanf(str,"%d,%d",row,col)!=2)
    {notify_fail(lw("Mark row,col.\n"));
    return 0;}
  else
    {if((row>=MAX)||(row<1)||(col>=MAX)||(col<1))
      {notify_fail(lw("That is not a valid position!\n"));
      return 0;}
    if(cover[row][col]=="#")
      {write("Unmarking "+row+","+col+".\n");
      if(grid[row][col]=="*")
        {bombs++;}
      squares++;
      marks--;
      cover[row][col]="?";
      if(check_win())
        {writelw("You solved the puzzle!\n");
        reset_game();
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
        {writelw("You solved the puzzle!\n");
        reset_game();
        return 1;}
      return 1;}
    else 
      {notify_fail(lw("You can't do that!\n"));
      return 0;}}
  return 0;}

status parse_move_turn(string str) 
  {int row, col;
  object stub;
  if(this_player()!=player)
    {if(player)
      {if(present(player,this_object()))
        {writelw("You are not the current player.\n");
        return 1;}
      writelw("Type 'begin game' to play\n");
      reset_game();
      return 1;}
    else
      {notify_fail(lw("Type 'begin game' to play.\n"));
      return 0;}}
  if(sscanf(str,"%d,%d",row,col)!=2)
    {notify_fail(lw("Turn row,col.\n"));
    return 0;}
  else
    {if((row>=MAX)||(row<1)||(col>=MAX)||(col<1))
      {notify_fail(lw("That is not a valid position!\n"));
      return 0;}
    if(cover[row][col]=="?")
      {write("Turning square "+row+","+col+".\n");
      if(grid[row][col]=="*")
        {writelw("Ooops!  You uncovered a bomb!  You lose!\n");
        reset_game();
        return 1;}
      squares--;
      cover[row][col]=grid[row][col];
      if(grid[row][col]==0) 
        {spawn(row,col);}
      if(check_win())
        {writelw("You solved the puzzle!\n");
        reset_game();
        return 1;}
      return 1;}
    else
      {notify_fail(lw("Can't you see you've already done that!\n"));
      return 0;}}
  return 0;}

status begin(string str) 
  {if(!str) 
    {notify_fail("Begin what?\n");
    return 0;}
  if(str=="game")
    {if(player)
      {if(this_player()==player)
        {notify_fail(lw("You are already playing!\n"));
        return 0;}
      if(present(player,this_object()))
        {notify_fail(lw("Somebody else is already playing.\n"));
        return 0;}
      else
        {writelw("You begin the puzzle...\n");
        reset_game();
        player=this_player();
        return 1;}}
    else
      {write("You begin the puzzle...\n");
       reset_game();
       player=this_player();
       return 1;}}
  return 0;}

void long()
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
        write("|   ");
      else
        write("| "+cover[row][col]+" ");}
    write("|\n");
    write("  +");
    for(x=1;x<MAX;x++)
      {write("---+");}
    write("\n");}
  write("Type 'help game' for more info.\n");}

status stop(string str)
  {if(!id(str))
    {notify_fail("Stop what?\n");
    return 0;}
  if(TP!=player)
    {write("You aren't playing right now!\n");
    return 1;}
  long();
  is_playing=0;
  reset(1);
  return 1;}

status re(string str)
  {if(!id(str))
    {notify_fail("Reset what?");
    return 0;}
  if(this_player()->query_level()<31)
    {notify_fail("You are too low level for that!\n");
    return 0;}
  reset_game();
  write("Game has been reset.\n");
  return 1;}

void reset(int arg)
  {if(!arg)
    {grid=make_grid();
    cover=make_grid();
    reset_game();}}

status check(string str)
  {if(!id(str))
    {notify_fail("Check what?\n");
    return 0;}
  write("Squares remaining: "+squares+".\n"+
  "Marks made: "+marks+".\n"+
  "Bombs remaining: "+bombs+".\n");
  return 1;}

void init()
  {add_action("parse_move_mark","mark");
  add_action("parse_move_turn","turn");
  add_action("begin","begin");
  add_action("stop","stop");
  add_action("re","reset");
  add_action("check","check");
  add_action("help","help");}

status help(string str)
  {if(!id(str))
    {notify_fail("What do you want help on?");
    return 0;}
  writelw("MudMines! v2.1 by Kawai.\nBased on the popular PC game.\n\n"+
  "The purpose of Minesweeper is to correctly guess the location of "+MAX_BOMBS+
  " mines on a "+(MAX-1)+"x"+(MAX-1)+" grid.  You can either reveal "+
  "a square, or flag it as a mine.  If you "+
  "uncover a safe square, it will tell you the total number of mines in bordering "+
  "squares (ie. a 2 indicates that any 2 surrounding squares could be mined) "+
  "Of course, if you uncover a mine, you lose!  The game is won only when all then "+
  "squares have been marked or revealed, and all the mines are correctly marked.  "+
  "Note however, that you simply can't mark every square, for only the mines may be "+
  "covered in order to win.\n\n"+
  "Commands are:  mark r c       -- Marks a square at row r, column c\n"+
  "               turn r c       -- Turns a square at row r, column c\n"+
  "               check game     -- Shows status of game.  Use this any time\n"+
  "                                 You need to, and must be done at the end of\n"+
  "                                 the game to verify the grid.\n"+
  "               begin game     -- Starts playing the game.\n"+
  "               stop game      -- Stops playing.\n"+
  "               help           -- This screen\n"+
  "\nJust looking at the game will show the grid.\n");
  if(this_player()->query_level()>30)
    {write("Wizards can restart by typing 'reset game'.\n");}
  return 1;}

