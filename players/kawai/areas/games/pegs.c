inherit "room/room";

#include <lw.h>
#define PATH "/players/kawai/areas/games/"
#define notify_fail_lw(x) notify_fail(lw(x))

#define GOAL 2
#define X 1
#define Y 0

object player;
mixed board;
int pegs;


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
    {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
    "You can't use a peg that you've already taken!\n");
    return 0;}
  else
   {x1=find_p(X,peg1);
    x2=find_p(X,peg2);
    y1=find_p(Y,peg1);
    y2=find_p(Y,peg2);
    if((x1==-1)||(x2==-1)||(y1==-1)||(y2==-1)) 
      {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
      "Something strange has happened, please alert the wizard Kawai!\n");
      return 0;}
/*left to right*/
    if(y1==y2)                           
      {if(x1>x2)                        
        {if( ((x2+1)!=x1) || ((x2-1)<0) )
          {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
          "Idiot!  You can't jump that piece!\n");
          return 0;}
        else if(board[peg2-1])
          {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
          "Idiot!  You can't jump that piece!\n");
          return 0;}
        else 
          {if(!test)
            {jump_swap(peg1,peg2,peg2-1);}
          return 1;}}
/*right to left*/
      else if(x1<x2)                     
        {if( ((x2-1)!=x1) || ((x2+1)>y2) ) 
          {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
          "Idiot!  You can't jump that piece!\n");
          return 0;}
        else if(board[peg2+1])
          {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
          "Idiot!  You can't jump that piece!\n");
          return 0;}
        else
          {if(!test) 
            {jump_swap(peg1, peg2, peg2+1);}
          return 1;}}
      else 
        {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
        "Fool!  A piece can't jump itself!\n");
        return 0;}}
/*diag-up-right*/
    if(x1==x2) 
      {if(y1>y2)
        {if( ((y2+1)!=y1) || ((y2-1)<x2) )
          {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
          "Idiot!  You can't jump that piece!\n");
          return 0;}
        else if(board[peg2-y2])
          {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
          "Idiot!  You can't jump that piece!\n");
          return 0;}
        else 
          {if(!test)
            {jump_swap(peg1,peg2,peg2-y2);}
          return 1;}}
/*diag-down-left*/
      else if(y1<y2)
        {if( ((y2-1)!=y1) || ((y2+1)>4) ) 
          {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
          "Idiot!  You can't jump that piece!\n");
          return 0;}
        else if(board[peg2+y2+1])
          {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
          "Idiot!  You can't jump that piece!\n");
          return 0;}
        else
          {if(!test)
            {jump_swap(peg1, peg2, peg2+y2+1);}
          return 1;}}
      else 
        {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
        "Fool!  A piece can't jump itself!\n");
        return 0;}}
/*diag-up-left*/
    else 
      {if(x1>x2)
        {if( ((x2+1)!=x1) || ((y2+1)!=y1) || (((x2-1)<0)||((y2-1)<(x2-1))) )                        
          {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
          "Idiot!  You can't jump that piece!\n");
          return 0;}
        else if(board[peg2-y2-1])
          {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
          "Idiot!  You can't jump that piece!\n");
          return 0;}
        else
          {if(!test)
            {jump_swap(peg1, peg2, peg2-y2-1);}
          return 1;}}
/*diag-down-right*/
      else if(x1<x2)
        {if( ((x2-1)!=x1) || ((y2-1)!=y1) || (((x2+1)>(4))||(y2+1)>(4)) ) 
          {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
          "Idiot!  You can't jump that piece!\n");
          return 0;}
        else if(board[peg2+y2+2])
          {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
          "Idiot!  You can't jump that piece!\n");
          return 0;}
        else
          {if(!test)
            {jump_swap(peg1, peg2, peg2+y2+2);}
          return 1;}}
      else
        {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
        "Idiot!  You can't jump that piece!\n");
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


status parse_move(string str) 
  {int x,y;
  if(this_player()!=player)
    {if(player)
      {if(present(player,this_object()))
        {writelw("As you reach to touch the piece, a strange force overwhelms "+
        "your body.  As you recover from the blow, you find yourself in a "+
        "different place.\n");
        this_player()->move_player("in a burst of light",PATH+"start");
        return 1;}
      write("A vision of the Grand Wizard appears and says: "+
      "It appears our last victim has left.  Why don't you try...\n");
      reset_game();
      return 1;}
    else
      {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
      "Finally, another victim!  Why don't you 'begin game'\n");
      return 0;}}
  if(sscanf(str,"%d with %d",x,y)!=2)
    {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
    "Have you no brain?  That is not how you move a piece!\n");
    return 0;}
  else
    {if((x<1)||(y<1)||(x>15)||(y>15))
      {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
      "Idiot!  Those pegs do not even exist!\n");
      return 0;}
    if(x==y)
      {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
      "You fool!  A peg can not be jumped by itself!\n");
      return 0;}
    if(jump(x,y,0))
      {if(pegs<=GOAL)
        {write("A vision of the Grand Wizard appears and says: "+
        "Very good, my little toy!  You may now proceed...\n");
        reset_game();
        this_player()->move_player("in a puff of smoke",PATH+"knight");
        return 1;}
      else if(!can_jump())
        {writelw("A vision of the Grand Wizard appears and says: "+
        "Alas, you've run out of chances.  Time for you to be leaving...\n"+
        "A powerful whirlwind surrounds your body, and as the air around "+
        "you clears, you notice much different surroundings.\n");
        reset_game();
        this_player()->move_player("in a puff of smoke",PATH+"labr1");
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
    {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
    "Next time try specifying which peg you wish to remove.\n");
    return 0;}
  else if(sscanf(num,"%d",arg)!=1)
    {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
    "Next time try specifying which peg you wish to remove.\n");
    return 0;}
  if(this_player()!=player)
    {if(player)
      {if(present(player,this_object()))
        {writelw("As you reach to touch the piece, a strange force overwhelms "+
        "your body.  As you recover from the blow, you find yourself in a "+
        "different place.\n");
        this_player()->move_player("in a puff of smoke",PATH+"start");
        return 1;}
      write("A vision of the Grand Wizard appears and says: "+
      "It appears our last victim has left.  Why don't you try...\n");
      reset_game();
      return 1;}
    else
      {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
      "Finally, another victim!  Why don't you 'begin game'\n");
      return 0;}}
  else if((arg>15)||(arg<1))
    {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
    "Idiot!  That peg does not even exist!\n");
    return 0;}
  else if(pegs<15) 
    {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
    "What a pathetic attempt at cheating!  You already picked one!\n");
    return 0;}
  else
    {board[arg]=0;
    pegs--;
    write("You remove the first peg from the board.\n");
    return 1;}}


status read_note(string str) 
  {if(!str) 
    {notify_fail_lw("Read what?\n");
    return 0;}
  if(str=="note")
    {writelw(
    "Greetings, "+capitalize(this_player()->query_real_name())+"!\n\n"+
    "   Congratulations on the first puzzle, but don't get your hopes up, "+
    "for here awaits another one!  As you see on the table, there is a small "+
    "triangular board with 15 holes and pegs.  This puzzle may seem familiar, "+
    "it simply involves removing all but one of the pegs by jumping one "+
    "with another.  To jump a peg there must be a free hole on the other "+
    "side however, and of course you have to stay within the boundaries of "+
    "the board.  If you care to try this puzzle, you may 'begin game'.  To "+
    "jump a peg, utter the command 'jump x with y', using the numbers of the "+
    "appropriate pegs.  When you first start, you may remove a peg of your "+
    "choosing as a starting point with the command 'pick x'. You may, if "+
    "you are truly pathetic, 'escape' unharmed while you have the "+
    "chance, but if you take the challenge and fail, the punishment will "+
    "be severe!\n\n"+
    "                                           -The Grand Wizard\n");
    if(GOAL>1)
      {writelw("\nP.S.- Due to an unusual feeling of generosity, I've decided "+
      "to let you off easy.  To pass the test, you need only leave "+GOAL+
      " pegs!\n");}
    return 1;}
  return 0;}


status begin(string str) 
  {if(!str) 
    {notify_fail_lw("Begin what?");
    return 0;}
  if(str=="game")
    {if(player)
      {if(this_player()==player) 
        {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
        "You are already playing, adventurer!\n");
        return 0;}
      if(present(player,this_object()))
        {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
        "My apologies, adventurer, but someone has beaten you to the task.  "+
        "Don't be alarmed, however, their demise is soon approaching and "+
        "then you may begin.\n");
        return 0;}
      else
        {write("A vision of the Grand Wizard appears and says: "+
        "It appears that our last victim has somehow eluded us... "+
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
   {notify_fail_lw("A vision of the Grand Wizard appears and says: "+
   "Too late, fool!  You have already accepted my challenge!\n");
   return 0;}
 else
   {this_player()->move_player("in a puff of smoke",PATH+"start");
    return 1;}}

void init()
  {::init();
  add_action("parse_move","jump");
  add_action("start_peg","pick");
  add_action("escape","escape");
  add_action("begin","begin");
  add_action("read_note","read");
  add_action("look","look");
  add_action("look","l");}


status look(string str)
  {if(!str)
    {notify_fail_lw("Look at what?\n");
    return 0;}
  if(str=="at board"||str=="at game"||str=="at puzzle")
    {if(this_player()!=player)
      {write("It is a small triangular board with pegs.\n");
      return 1;}
    else
      {show_board();
      return 1;}}
  return 0;}
 

void reset(int arg)
  {if(!arg)
    {make_board();
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
     "tapestries","They show a dark, forbidding forest..",
     "tree","A pine tree",
     "trees","A forest of pine trees",
     "cricket","You notice several small insects in the forest",
     "crickets","Though they don't appear to be here, you can hear them",
     "room","The room you are in.  Just look",
     "table","A small pine table with a board and a note tacked next to it",
     "note","Try reading it",
     "pegs","A bunch of small wooden pegs"});}
  ::reset(arg);}


