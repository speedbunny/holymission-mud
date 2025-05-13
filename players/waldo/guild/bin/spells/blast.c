/*
	Blast Spell
	(c) 1996 Waldo
*/

#include "/players/waldo/guild/defs.h"
#define LEVEL 20
#define COST 100
 
int main(string str)
{
  object *ob;
  status yes;
  int i, j,lvl,dam,total;

  if (TP->QLVL < LEVEL)
  {
    write("Unable to comply.\n");
    return 1;
    }
  if (TP->QSP < COST)
  {
    write("You are too drained to do that.\n");
    return 1;
    }
  TP->restore_spell_points(- COST);
  tell_room(ENV(TP), "The room explodes as everyone is blasted!\n"); 
  lvl = TP->QLGDLVL + TP->QLVL;
  if (lvl > 20 ) lvl = 20; // For max damage
  ob = all_inventory(ENV(TP));
  i = sizeof(ob);
  total = 0;
  dam = 0;
  for (j = 0; j < i; j++)
    if (living(ob[j]) && ob[j] != TP) 
    {
      dam = lvl*(random(20)+1);
      ob[j]->hit_player(dam);
      if (ob[j])
        TELL(ob[j], "You are burned by " + TP->QNAME + "'s firestorm!\n");
      total = total + dam;
      } 
  if (TP->QWIZ)
  {
    ME("Damage = "+total+".\n");
    }
  return (1);
}

