inherit "room/room";
 
#include "/sys/levels.h"
#include "/players/shadowmonk/area/defs.h"
 
#define CF ROOM+"blizzard"
 
int      pcnt;
mapping  players;
mixed   *pfields;
 
void reset(int arg) {
  ::reset(arg);
  if(arg) return;
 
  set_light(1);
  short_desc = "Blizzard check room for wizards.";
  long_desc  = "Blizzard check room for wizards.\n"+
               "commands:  clist kout(arg)\n";
  dest_dir =({ ROOM+"svall01", "south",
               ROOM+"svall03", "north",
            });
  items    =({ "Blizzard", "Cold as ice...",
            });
  smell    =   "Fresh air clears your brain.\n";
  players  = ([ ]);
  pfields  = allocate(0);
}
 
void init() {
  int    level;
  object vroom;
  string player;
 
  if(!TP->query_immortal()) {
    player = TP->RNAME;
    if(!member(players, player)) {
       vroom  = clone_object(CF);
       level  = 1;
       pfields = ({ explode(file_name(vroom), "#")[1], level });
       players += ([ player:pfields ]);
      }
    else {  
       if(!vroom = find_object(CF + "#" + player)) {
          vroom = clone_object(CF);
          level = 1;
          pfields = ({ explode(file_name(vroom), "#")[1], level });
          players[player] = ([ player:pfields ]);
       }
    }
    move_object(TP, vroom);
    return;
 }
 else {
   ::init();
   add_action("_clist", "clist");
   add_action("_kout", "kout");
  }
}
 
int _clist() {
  int    i, sz;
  string *pl;
 
  pl = m_indices(players);
  sz = sizeof(pl);
  if(!sz) {
    write("Nobody is dieing in the cold right now.\n");
    return 1;
  }
 
  for(i=0; i<sz; i++)
    write(capitalize(pl[i]) + "\n");
  printf("%d player%s in the blizzard.\n", i, i==1 ? " is" : "s are");
  return 1;
}
 
int _kout(string arg) {
  if(!arg) return 0;
  if(!member(players, arg)) {
    notify_fail("That player is not in the blizzard.\n");
    return 0;
  }
 
  destruct(find_object(CF + "#" + arg));
  write(arg + " has been saved from a terrible dead in the blizzard.\n");
  players = m_delete(players, arg);
  return 1;
}
 
string query_nr(string player) {
  if (!member(players, player)) return 0;
  return player;
}
