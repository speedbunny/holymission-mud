#include "/obj/adjust.h"
#define WHEREFROM ("/players/helenette/secure/wherefrom")

level (ob) {
/*----------------------------------------------------------------*
 * level returns 3 chars of level or levelnumber if realplayer    *
 *----------------------------------------------------------------*/
  string lv; 
  lv = ob->query_level();
  if (ob->query_incognito()) return " * ";
  if (lv < 30 && ob->query_testchar())
    return ladjust (ob->query_testchar(),3);
  if (lv <  30)   return radjust (lv + " ",3);
  if (lv == 30)   return "Ap ";
  if (lv <  33)   return "Nw ";
  if (lv <  34)   return "Wz ";
  if (lv == 36)   return "Re ";
  if (lv <  40)   return "Sn ";
  if (lv <  50)   return "Ld ";
  if (lv <  1000) return "Ar ";
  if (lv == 1000) return "Gd ";
  return "   ? ";
}


sex (ob) {
/*-----------------------------------------------------------------*
 * sex returns gender as "m", "f", "x" if other, " " if testchar   *
 *-----------------------------------------------------------------*/
  if (ob->query_level() < 30 && ob->query_testchar()) return " ";
  if (ob->query_gender()==1) return ("m");
  if (ob->query_gender()==2) return ("f");
  return ("x");
}

hostsort(p1,p2) { return (query_ip_number(p1) > query_ip_number(p2)); }

allow_display (ob) {
/*---------------------------------------------------------------------*
 * allow_display returns true, if the obj might be seen by this_player *
 *---------------------------------------------------------------------*/
  return !ob->is_invis_for(this_player());
}

where (str) {
  object u, ob; int i,j, max, d;
  
  if (str) {
    ob=find_player(str);
    if (!ob || !allow_display(ob)) {
       notify_fail ("That player is currently not logged on.\n");
       return 0;
    }
    if (ob->query_linkdead()) {
      write ("That player is currently linkdead.\n");
      return 1;
    }
    write (level (ob) + sex (ob) + " " + ob->query_presentation() + "  ->   "
         + WHEREFROM->wherefrom (ob) + "\n");
    return 1;
  } 
 
  u = sort_array(users(),"hostsort",this_object());
  u = filter_array(u,"allow_display",this_object());
  write ("=================== Holy Mission: " + radjust(ctime(time()),27) +
         " ==================\n");
  max = sizeof(u); d=(max+1)/2;
  if (max < 19) write ("\n");
  for (i=0; i<d;i++) {
    write ( /* radjust (i+1,2) + */
     level (u[i]) + sex (u[i]) +
     ladjust(" " + capitalize (u[i]->query_real_name()),13) + 
     ladjust(WHEREFROM->wherefrom (u[i]),23));
    if (i + d < max)
    write ( /* radjust (i+d+1,2) + */
     level (u[i + d]) + sex (u[i + d]) +
     ladjust(" " + capitalize (u[i + d]->query_real_name()),13) + 
     WHEREFROM->wherefrom (u[i + d]));
    write ("\n");
  }
  if (max < 19) write ("\n");
  write ("============= " + radjust (max,2) + " player(s) online, " + radjust (
    query_load_average(),31) + " =============\n"); /* 48 + 31 chars */
  return 1;
}
