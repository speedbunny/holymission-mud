#include "/players/mangla/defs.h"

/********* 
**********/

int main(string str) {
    
  object *u;
  int num, i, sz;
  string msg, pret;

  if (!str) {
    write(">>>>====---- "+
    "Jedis online "+
    "----====<<<<\n\n");
    u=users();
    msg="\n";
    num=0;
    sz=sizeof(u);
    for (i=0;i<sz;i++) {
      if(u[i]->query_guild() == 4) {
        if( u[i]->is_invis_for(TP) ) continue;
        pret = u[i]->query_pretitle();
        if(u[i]->query_testchar())
          pret = "Test Jedi";
        else
          if(u[i]->RNAME=="mangla") {
            if(u[i]->query_invis())
              continue;
            pret="Guild Master";
          }
          else {
            if(pret="") {
              switch(u[i]->query_level()) {
                case 1..5: pret="Beginner"; break;
                case 6..10: pret="Student"; break;
                case 11..15: pret="Apprentice Jedi"; break;
                case 16..20: pret="Jedi"; break;
                case 21..25: pret="Senior Jedi"; break;
                case 26..28: pret="Jedi Knight"; break;
                case 29..30: pret="Jedi Master"; break;
                default: pret="Jedi Lord"; break;
              }
            }
          }
          msg=msg+sprintf("(%2i) %20s %s\n",
                  u[i]->LEVEL,
                  pret,
                  CAP(u[i]->RNAME));
          num++;
        }
      }
      write(msg+"\nThere are "+num+" jedis online.\n");
      return 1;
    }
    TP->guild_line(str);
    return 1;
}
