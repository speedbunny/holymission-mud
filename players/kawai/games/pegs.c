/*
   MudPegs! v2.1 by Kawai@Holy Mission (140.78.3.1 2001)
   Bazyl@cleo.bc.edu
   Feel free to distribute
   Please document all code changes
*/

#include <lw.h>
#define notify_fail_lw(x) notify_fail(lw(x))

#define GOAL 2
#define X 1
#define Y 0
#define TP this_player()

object player;
mixed board;
int pegs;


int id(string str) 
 {return str=="portagame"||str=="pegs"||str=="game"||str=="iq test";}

int get(string str) 
 {return 1;}

string short() 
 {return "A peg game";}

string query_name() 
 {return "A peg game";}

void make_board() 
  {board=({0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1});}

void init_board()
  {int i;
  for(i=1;i<16;i++)
    {board[i]=1;}}

void reset_game()
  {player=0;
   pegs=15;
   init_board();}

string pn(int num) 
  {if(!num)
    return "ER";
  else if(!board[num])
    return "--";
  else if(num<10)
    return " "+(string)num;
  else
    return (string)num;} 

void show_board() 
  {write("        "+pn(1)+"\n"+
  "      "+pn(2)+"  "+pn(3)+"\n"+
  "    "+pn(4)+"  "+pn(5)+"  "+pn(6)+"\n"+
  "  "+pn(7)+"  "+pn(8)+"  "+pn(9)+"  "+pn(10)+"\n"+
  pn(11)+"  "+pn(12)+"  "+pn(13)+"  "+pn(14)+"  "+pn(15)+"\n");}

int find_p(int co, int arg) 
  {if(!board[arg])
    {return -1;}
  else if(co==Y)
    {switch(arg)
      {case 1: return 0;
      case 2..3: return 1;
      case 4..6: return 2;
      case 7..10: return 3;
      case 11..15: return 4;}}
  else
    {switch(arg)
      {case 1: case 2: case 4: case 7: case 11: return 0;
      case 3: case 5: case 8: case 12: return 1;
      case 6: case 9: case 13: return 2;
      case 10: case 14: return 3;
      case 15: return 4;}}}

int is_taken(int peg)
 {return !board[peg];}

void jump_swap(int peg1,int peg2,int peg3)
  {board[peg2]=0;
  board[peg3]=1;
  board[peg1]=0;
  pegs--;}

int jump(int peg2, int peg1, int test) 
  {int x1, x2, y1, y2;
  if(is_taken(peg1)||is_taken(peg2))
    {notify_fail_lw("You can't use a peg that you've already taken!\n");
    return 0;}
  else
   {x1=find_p(X,peg1);
    x2=find_p(X,peg2);
    y1=find_p(Y,peg1);
    y2=find_p(Y,peg2);
    if((x1==-1)||(x2==-1)||(y1==-1)||(y2==-1)) 
      {notify_fail_lw("Something strange has happened, please alert the wizard Kawai!\n");
      return 0;}
/*left to right*/
    if(y1==y2)                           
      {if(x1>x2)                        
        {if( ((x2+1)!=x1) || ((x2-1)<0) )
          {notify_fail_lw("You can't jump that piece!\n");
          return 0;}
        else if(board[peg2-1])
          {notify_fail_lw("You can't jump that piece!\n");
          return 0;}
        else 
          {if(!test)
            {jump_swap(peg1,peg2,peg2-1);}
          return 1;}}
/*right to left*/
      else if(x1<x2)                     
        {if( ((x2-1)!=x1) || ((x2+1)>y2) ) 
          {notify_fail_lw("You can't jump that piece!\n");
          return 0;}
        else if(board[peg2+1])
          {notify_fail_lw("You can't jump that piece!\n");
          return 0;}
        else
          {if(!test) 
            {jump_swap(peg1, peg2, peg2+1);}
          return 1;}}
      else 
        {notify_fail_lw("A piece can't jump itself!\n");
        return 0;}}
/*diag-up-right*/
    if(x1==x2) 
      {if(y1>y2)
        {if( ((y2+1)!=y1) || ((y2-1)<x2) )
          {notify_fail_lw("You can't jump that piece!\n");
          return 0;}
        else if(board[peg2-y2])
          {notify_fail_lw("You can't jump that piece!\n");
          return 0;}
        else 
          {if(!test)
            {jump_swap(peg1,peg2,peg2-y2);}
          return 1;}}
/*diag-down-left*/
      else if(y1<y2)
        {if( ((y2-1)!=y1) || ((y2+1)>4) ) 
          {notify_fail_lw("You can't jump that piece!\n");
          return 0;}
        else if(board[peg2+y2+1])
          {notify_fail_lw("You can't jump that piece!\n");
          return 0;}
        else
          {if(!test)
            {jump_swap(peg1, peg2, peg2+y2+1);}
          return 1;}}
      else 
        {notify_fail_lw("A piece can't jump itself!\n");
        return 0;}}
/*diag-up-left*/
    else 
      {if(x1>x2)
        {if( ((x2+1)!=x1) || ((y2+1)!=y1) || (((x2-1)<0)||((y2-1)<(x2-1))) )                        
          {notify_fail_lw("You can't jump that piece!\n");
          return 0;}
        else if(board[peg2-y2-1])
          {notify_fail_lw("You can't jump that piece!\n");
          return 0;}
        else
          {if(!test)
            {jump_swap(peg1, peg2, peg2-y2-1);}
          return 1;}}
/*diag-down-right*/
      else if(x1<x2)
        {if( ((x2-1)!=x1) || ((y2-1)!=y1) || (((x2+1)>(4))||(y2+1)>(4)) ) 
          {notify_fail_lw("You can't jump that piece!\n");
          return 0;}
        else if(board[peg2+y2+2])
          {notify_fail_lw("You can't jump that piece!\n");
          return 0;}
        else
          {if(!test)
            {jump_swap(peg1, peg2, peg2+y2+2);}
          return 1;}}
      else
        {notify_fail_lw("You can't jump that piece!\n");
        return 0;}}}}

int can_jump()
  {int i,j, ok;
  ok=0;
  i=0;
  while((i<15)&&(!ok))
    {i++;
    if(!is_taken(i))
      {j=0;
      while((j<15)&&(!ok))
        {j++;
        if(!is_taken(j))
          {ok=jump(i,j,1);}}}}
  return ok;}

void display_score() 
  {switch(pegs) 
    {case 1:
      {write("Wow! You must be a genius! There's only 1 peg left!\n");
      break;}
    case 2:
      {write("Not bad!  You only left 2 pegs, but you can do better...\n");
      break;}
    case 3:
      {write("That's about average...still a lot of room for improvement!\n");
      break;}
    case 4:
      {write("Ha!  My dog can do better than that!\n");
      break;}
    default:
      {write("You're pathetic...\n");
      break;}}}

status parse_move(string str) 
  {int x,y;
  if(this_player()!=player)
    {if(player)
      {if(present(player,this_object()))
        {writelw("You are not the current player.\n");
        return 1;}
      write("Type 'begin game' to start.\n");
      reset_game();
      return 1;}
    else
      {notify_fail_lw("Type 'begin game' to start.\n");
      return 0;}}
  if(sscanf(str,"%d with %d",x,y)!=2)
    {notify_fail_lw("Jump <x> with <y>\n");
    return 0;}
  else
    {if((x<1)||(y<1)||(x>15)||(y>15))
      {notify_fail_lw("Those pegs do not exist!\n");
      return 0;}
    if(x==y)
      {notify_fail_lw("A peg can not be jumped by itself!\n");
      return 0;}
    if(jump(x,y,0))
      {if(!can_jump())
        {writelw("You hav run out of moves!\n");
        display_score();
        reset_game();
        return 1;}
      else
        {write("You remove a peg from the board.\n");
        return 1;}}
    else
      {return 0;}}
  return 0;}

status start_peg(string num)
  {int arg;
  if(!num)
    {notify_fail_lw("Specify which peg you wish to remove.\n");
    return 0;}
  else if(sscanf(num,"%d",arg)!=1)
    {notify_fail_lw("Specify which peg you wish to remove.\n");
    return 0;}
  if(this_player()!=player)
    {if(player)
      {if(present(player,this_object()))
        {writelw("You are not the current player.\n");
        return 1;}
      write("Type 'begin game' to start.\n");
      reset_game();
      return 1;}
    else
      {notify_fail_lw("Type 'begin game' to start.\n");
      return 0;}}
  else if((arg>15)||(arg<1))
    {notify_fail_lw("That peg does not exist!\n");
    return 0;}
  else if(pegs<15) 
    {notify_fail_lw("You already picked one!\n");
    return 0;}
  else
    {board[arg]=0;
    pegs--;
    write("You remove the first peg from the board.\n");
    return 1;}}

status begin(string str) 
  {if(!str) 
    {notify_fail_lw("Begin what?");
    return 0;}
  if(str=="game")
    {if(player)
      {if(this_player()==player) 
        {notify_fail_lw("You are already playing!\n");
        return 0;}
      if(present(player,this_object()))
        {notify_fail_lw("Somebody else is playing at the moment.\n");
        return 0;}
      else
        {write("You begin the puzzle...\n");
        reset_game();
        player=this_player();
        return 1;}}
    else
      {write("You begin the puzzle...\n");
       reset_game();
       player=this_player();
       return 1;}}
  return 0;}

status help_peg(string str)
  {if(!str) 
    {notify_fail("Help with what?\n");
    return 0;}
  else if(str=="pegs")
    {writelw("MudPegs! v2.0 by Kawai\n"+
    "Yet another silly game....\n"+
    "The object of the game is to eliminate as many pegs as possible "+
    "from the playing board.  To remove a peg, it must be jumped by "+
    "an adjacent peg.  There must be a free hole for the jumping peg "+
    "to move into, and it must travel in a straight line.  "+
    "Basically, if you've never played this before, there must be "+
    "something wrong with you, so its not even worth explaining in "+
    "much detail....\n"+
    " Commands: begin game              - Begin playing the game\n"+
    "           pick <peg#>             - Chose initial empty hole\n"+
    "           jump <peg#> with <peg#> - Jump a peg\n"+
    "           look at pegs            - To view the board\n"+
    "           quit pegs               - To stop playing\n"+
    "           help pegs               - This screen\n");
    if(TP->query_level()>31)         
      {write("           reset pegs              - Reset the game.\n");}    
    return 1;}
  else
    {notify_fail("Help with what?\n");
    return 0;}}

void long()
  {if(TP!=player)
    {writelw("It's a small triangular board with pegs, used to measure IQ.  You can\n"+
    "get more information by typing 'help pegs'.\n");}
  else
    {show_board();}}

void reset(int arg) 
 {if(!arg) 
   {make_board();
   reset_game();}}

void init() 
 {add_action("parse_move","jump");
  add_action("start_peg","pick");
  add_action("reset_g","reset");
  add_action("quit_game","quit");
  add_action("begin","begin");
  add_action("help_peg","help");}

status reset_g(string str) 
  {if(!id(str)) 
    {notify_fail("Reset what?\n"); 
    return 0;}
  else if(TP!=player) 
    {if(TP->query_level()<31)
      {notify_fail("You must be playing the game to reset it.\n");
      return 0;}}
  else
    {write("You reset the game.\n");
    reset(0);
    return 1;}}

status quit_game(string str) 
  {if(str!="pegs") 
    {notify_fail("Whatever...\n");
    return 0;}
  else if(TP!=player) 
    {notify_fail("You're not playing!\n");
    return 0;}
  else 
    {write("You stop playing with the pegs.\n");
    display_score();
    reset(0);
    return 1;}}

