inherit "room/room";
#include <lw.h>
#define PATH "/players/kawai/areas/games/"
#define OPATH "/players/kawai/obj/"

object  player;
mixed grid;
int moves;


void make_grid()
 {int i;
 grid=allocate(3);
 for(i=0;i<3;i++)
   {grid[i]=allocate(3);}}


void init_grid()
 {int i,j;
 for(i=0;i<3;i++)
   {for(j=0;j<3;j++)
     {grid[i][j]=0;}}
 grid[0][0]=1;
 grid[0][2]=1;
 grid[2][0]=2;
 grid[2][2]=2;}

void reset_game()
  {player=0;
   moves=0;
   init_grid();}

string shp(int x, int y, int num) 
 {if(grid[x][y]==1)
   {if(num==0)
     {return "R";}
   else if(num==1)
     {return "E";}
   else {return "D";}}
 else if(grid[x][y]==2)
   {if(num==0)
     {return "B";}
   else if(num==1)
     {return "L";}
   else 
     {return "K";}}
 else
   {return " ";}} 


void show_grid()
  {int i, j, k;
  write("     1     2     3\n"+
  "  -------------------\n");
  for(i=0;i<3;i++)
    {for(j=0;j<3;j++)
      {if(j==1)
        {write((i+1)+" |");}
      else
        {write("  |");}
    for(k=0;k<3;k++)
        {if(j==0)
          {write(" "+shp(i,k,j)+"   |");}
        else if(j==1)
          {write("  "+shp(i,k,j)+"  |");}
        else 
          {write("   "+shp(i,k,j)+" |");}}
    write("\n");}     
  write("  -------------------\n");}}


int check_win()
  {if((grid[0][0]==2)&&(grid[0][2]==2)&&(grid[2][0]==1)&&(grid[2][2]==1))
    {return 1;}
   else
    {return 0;}}

int move_piece(int x1, int y1, int x2, int y2)
  {if((x1<1)||(x2<0)||(y1<0)||(y2<0)||(x1>3)||(x2>3)||(y1>3)||(y2>3))
    {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
    "That move is not allowed, you pathetic creature!\n"));
    return 0;}
  if(!(((x1==x2+2)&&(y1==y2+1))||
       ((x1==x2+2)&&(y1==y2-1))||
       ((x1==x2-2)&&(y1==y2+1))||
       ((x1==x2-2)&&(y1==y2-1))||
       ((x1==x2+1)&&(y1==y2+2))||
       ((x1==x2+1)&&(y1==y2-2))||
       ((x1==x2-1)&&(y1==y2+2))||
       ((x1==x2-1)&&(y1==y2-2))))
    {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
    "That move is not allowed, you pathetic creature!\n"));
    return 0;}
  if(grid[x2-1][y2-1]>0)
    {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
    "That space is occupied, dunce!\n"));
    return 0;}
  if(grid[x1-1][y1-1]==0)
    {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
    "There is no piece to move, you fool!\n"));
    return 0;}
  else
    {grid[x2-1][y2-1]=grid[x1-1][y1-1];
     grid[x1-1][y1-1]=0;
     write("You move the piece.\n");
     return 1;}}


status parse_move(string str) 
  {int x1,x2,y1,y2;
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
  if(sscanf(str,"%d,%d to %d,%d",x1,y1,x2,y2)!=4)
    {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
    "Have you no brain?  That is not how you move a piece!\n"));
    return 0;}
  else
    {if(move_piece(x1,y1,x2,y2))
      {moves++;
      if(check_win())
        {writelw("A vision of the Grand Wizard appears and says: "+
        "Very good, my little toy!  You may now proceed...\n");
        reset_game();
        if(!stub=present("gstub",this_player()))
          {transfer(stub=clone_object(OPATH+"stub"),this_player());}
        stub->set_last(3);
        this_player()->move_player("in a puff of smoke",PATH+"chamber");
        return 1;}
      else if (moves>16)
        {writelw("A vision of the Grand Wizard appears and says: "+
        "Alas, you've run out of chances.  Time for you to be leaving...\n\n"+
        "A powerful whirlwind surrounds your body, and as the air around "+
        "you clears, you notice much different surroundings.\n");
        reset_game();
        this_player()->move_player("in a puff of smoke",PATH+"labr1");
        return 1;}
      else
        {writelw("The piece slides effortlessly across the board.\n");
         return 1;}}
    else
      {return 0;}}
  return 0;}
   
status read_note(string str) 
  {if(!str) 
    {notify_fail("Read what?\n");
    return 0;}
  if(str=="note")
    {writelw(
    "Greetings, "+capitalize(this_player()->query_real_name())+"!\n\n"+
    "   I see you have made it so far, but I have yet another challenge "+
    "for you.  As you see on the table, there is a small grid, 3 squares "+
    "by 3 squares.  Starting in the corners are 4 knights, 2 red and two "+
    "black.  Your task is simple, just move the knights to the other side "+
    "of the board.  You must, of course, stay within the boundries of the "+
    "board, and must obey the rules of movement for a knight (which is, "+
    "for those of little wisdom, 2 spaces either horizontally or vertically, "+
    "and one space perpendicular to that, similar to the letter 'L').  Be "+
    "forwarned, I am keep careful watch on how many moves and mistakes you "+
    "make, so do not try my patience!  You may move the pieces 16 times.\n"+
    "   You may 'begin game' when you are ready for the challenge, and may "+
    "move the pieces by uttering the command 'move r,c to r,c' in which "+
    "the proper locations are included.  You may, if you are truly "+
    "pathetic, 'escape' unharmed while you have the chance, but if you "+
    "take the challenge and fail, the punishment will be severe!\n\n"+
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
        {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
        "Did you forget?  You are already playing!\n"));
        return 0;}
      if(present(player,this_object()))
        {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
        "My apologies, adventurer, but someone has beaten you to the task.  "+
        "Don't be alarmed, however, their demise is soon approaching and "+
        "then you may begin.\n"));
        return 0;}
      else
        {writelw("A vision of the Grand Wizard appears and says: "+
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
   {notify_fail(lw("A vision of the Grand Wizard appears and says: "+
   "Too late, fool!  You have already accepted my challenge!\n"));
   return 0;}
 else
   {this_player()->move_player("in a puff of smoke",PATH+"start");
    return 1;}}


void init()
  {::init();
  add_action("parse_move","move");
  add_action("escape","escape");
  add_action("begin","begin");
  add_action("read_note","read");
  add_action("look","look");
  add_action("look","l");}


status look(string str)
  {if(!str)
    {notify_fail("Look at what?\n");
    return 0;}
  if(str=="at board"||str=="at game"||str=="at puzzle")
    {if(this_player()!=player)
      {write("It is a small board with four chess pieces.\n");
      return 1;}
    else
      {show_grid();
      return 1;}}
  return 0;}
 

void reset(int arg)
  {if(!arg)
    {make_grid();
    reset_game();
    set_light(1);
    short_desc="The third puzzle room";
    long_desc="The walls of this small room are covered with beautiful "+
     "frescos portraying a scene of a calvary of knights engaged in a "+
     "fierce battle.  The only furniture in the room is a small oak table "+
     "in the center of the room.\n";
    dest_dir=0;
    items=({"fresco","It portrays a battle between two armies",
     "wall","It has a giant fresco on it",
     "walls","They are decorated with giant frescos",
     "scene","It portrays a battle between two armies",
     "secenes","They portray a battle between two armies", 
     "calvaries","Two calvaries engaged in fierce battle",
     "furniture","A table",
     "frescos","They portray a battle between two armies",
     "calvary","An army of knights on horseback",
     "army","An army of knights on horseback",
     "armies","An army of knights on horseback",
     "knight","A knight in black armor",
     "knights","Several knights in black armor or painted on the wall",
     "armor","Black armor",
     "horse","A large horse in leather padding",
     "horses","Several horses being ridden in to battle",
     "leather","Protection for the horses",
     "padding","Protection for the horses",
     "room","The room you are in.  Just look",
     "battle","You can't quite make out who or what the knights are fighting",
     "table","A small oak table with a board and a note tacked next to it",
     "note","Try reading it",
     "pieces","They are all a knight from a chess set"});}
  ::reset(arg);}


