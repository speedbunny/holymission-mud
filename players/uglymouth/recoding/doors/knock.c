
/* ################################################################
   #                                                              #
   #                    Mage knock door                           #
   #                                                              #
   ###############################################(C) Llort########
 * Uglymouth 970717: Adapted code to allow using inheritable room with doors.
 *                   At the same time updated code efficiency a bit.
 */

#include "mage.h"
#include "doorroom.h"

int knock_old_door( string str, object door, object pl );
int knock_inheritable_door( string str, object pl );
int check_skill( object pl, string str );

int doit( string str, object pl ) {
  object door;
  string dest, *all_doors;

  if(!str) return 0;

  if (!(door=present(str,E(TP)))) {
    all_doors = E(TP)->query_doors();
    if( !all_doors ) return 0;
    if( member_array( str, all_doors ) == -1 ) return 0;
    return knock_inheritable_door( str, pl );
  }
  if (str!="door" && sscanf(str,"%s door",dest)!=1) return 0;
  if (str=="door" && door->number_of_doors()!=1) {
    door->which_door();
    return 1;
  }
  return knock_old_door( str, door, pl );
}

int knock_old_door( string str, object door, object pl ) {
  int i, spnr;

  spnr=MS->spellnr("knock");
  CHK_LIGHT();
  CHK_GHOST();
/* Uglymouth 970718: These functions bug in magemaster, if spnr can't be assigned.
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));  
*/

  if (!door->query_locked()) {
    ME("Your spell fizzles on the unlocked door.\n");
    OTHERS( ({ TP }), TPN+" tries to cast a spell at the "+str+" but fails.\n" );
    return 1;
  }
  if( !check_skill( pl, str ) ) return 1;
  door->set_locked(0);
  door->query_partner_door()->set_locked(0);
  return 1;
}

int knock_inheritable_door( string str, object pl ) {
  int i, spnr;

  spnr=MS->spellnr("knock");
  CHK_LIGHT();
  CHK_GHOST();
/* Uglymouth 970718: These functions bug in magemaster, if spnr can't be assigned.
  CHK_SP(SPCOST(spnr));
  ADDSP(-SPCOST(spnr));
  CHK_FIZ(SPLVL(spnr));  
*/

  if( E(TP)->query_lock_status( str ) == DOOR_UNLOCKED ) {
    ME("Your spell fizzles on the unlocked door.\n");
    OTHERS(({ TP }),TPN+" tries to cast a spell at the "+str+" but fails.\n");
    return 1;
  }
  if( !check_skill( pl, str ) ) return 1;
  E(TP)->set_lock_status( str, DOOR_UNLOCKED );
  call_other( E(TP)->query_other_door( str ), "set_lock_status", str,
    DOOR_UNLOCKED );
  return 1;
}

int check_skill( object pl, string str ) {  
  int i;

  i=TPL * 100 / MS->query_max_stats();
  if (random(101)>=i) {
    ME("Your spell fizzles.\n");
    OTHERS(({ TP }),TPN+" tries to cast a spell at the "+str+" but fails.\n");
    return 0;
  }
  ME("The lock glows bright for a moment.\n");
  OTHERS(({ TP }),"The lock "+str+" glows bright for a moment.\n");
  return 1;
}

