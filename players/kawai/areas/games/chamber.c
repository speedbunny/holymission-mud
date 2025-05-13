inherit "room/room";

#include <lw.h>
#define PATH "/players/kawai/areas/games/"
#define RETURN_POINT "/room/church"

void reset(int arg) 
  {::reset(arg);
  if(!arg)
    {set_light(1);
    short_desc="Grand Hall";
    long_desc=
    "Bright colors and unusual patterns cover the walls in this "+
    "large hall.  Two rows of marble pillars fill the center of "+
    "the room, though no furniture can be found.  There is only "+
    "a single exit, a door that leads nowhere--just a black void.\n";
    dest_dir=({RETURN_POINT,"leave"});
    hidden_dir=({RETURN_POINT,"beg"});
    items=({"room","Just look around",
    "door","A large door frame leading out to an endless void",
    "void","A vast area of nothingness",
    "colors","All sorts of bright colors!",
    "color","Trippy!",
    "pattern","Its just a random mix of lines and curves",
    "patterns","Random mixes of lines and curves",
    "hall","Just look around",
    "furniture","There is none",
    "pillars","Two rows of 6 pillars are in the center of the hall",
    "exit","A large door frame leading out to an endless void",
    "wall","It is covered with random patterns",
    "walls","They are covered with random patterns and colors",
    "row","A row of pillars",
    "rows","Two rows of marble pillars",
    "center","The center of the room",
    "nowhere","What else..."});}}
  
void check_win()
  {object st, m;
  if(!st=present("gstub",this_player()))
    {writelw("A vision of the Grand Wizard appears and says: "+
    "How strange...I don't recall inviting you here...nor do I "+
    "find you worthy of much attention...now LEAVE!\n");
    return;}
  else if(st->query_last()<3)
    {writelw("A vision of the Grand Wizard appears and says: "+
    "Clever approach, but you have yet to finish!  Now LEAVE!\n");
    return;}
  else
    {writelw("A vision of the Grand Wizard appears and says: "+
    "I may have been wrong about your kind.  Consider your task "+
    "done, and you have my congratulations.  Feel free to leave "+
    "at your convience.\n");
    m=clone_object("obj/money");
    m->set_money(10000);
    transfer(m,this_object());
    write_file("/players/kawai/log/puzzles",this_player()->query_real_name()+
    " solved the quest on "+ctime(time())+"\n");
    if(!this_player()->query_quests("puzzles"))
      {this_player()->set_quest("puzzles");}
    destruct(st);}}

void init() 
  {::init();
  check_win();}
