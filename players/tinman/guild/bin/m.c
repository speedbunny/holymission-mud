#include "/players/tinman/defs.h"

/********* 
**********/

int query_delay() {
  return 0;
}


int main(string str) {
    
  object *u;
  int num, i, sz;
  string msg, pret;

  if (!str) {
    write("~~~~~~~~~~~~ "+
    "Monks online "+
    "~~~~~~~~~~~~\n\n");
    u=users();
    msg="\n";
    num=0;
    sz=sizeof(u);
    for (i=0;i<sz;i++) {
      if(u[i]->query_guild() == GUILDNUM) {
        if( u[i]->is_invis_for(TP) ) continue;
        pret = u[i]->query_pretitle();
        if(u[i]->query_testchar())
          pret = "Test Monk";
          else {
            if(pret="") {
	switch(present("monksoul",u[i])->query_g_status()) {
                case 0: pret="Monk Member"; break;
                case 1: pret="Protector"; break;
                case 2: pret="Master"; break;
                case 3: pret="Assistant Guild Master"; break;
                case 4: pret="Guild Master"; break;
                default: pret="Monk"; break;
              }
            }
          }
          msg=msg+sprintf("(%3i) %20s %s\n",
                  u[i]->LEVEL,
                  pret,
                  CAP(u[i]->RNAME));
          num++;
        }
      }
      write(msg+"\nThere are "+num+" monks online.\n");
      return 1;
    }
    TP->guild_line(str);
    return 1;
}
