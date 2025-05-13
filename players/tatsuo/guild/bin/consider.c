#include "/include/defs.h"
#include "/players/tatsuo/guild/ndef.h"

int     marm, mweap, pweap, plev, mlev;
closure call;
int     parm;
object  item;


int main(string str) {

  string  pron,
          str_advice,  dex_advice,
          lev_advice,  arm_advice,
          weap_advice, weap_level;
  object  ob;
  int     intFlag, intThing;

  if(!str) {
    notify_fail("consider what?\n");
    return 0;
  }
 
  if(str == TP->RNAME) {
    write("Planning on attacking yourself?\n");
    return 1;
  }

  ob = present(str, ENV(TP));
  
  if(!ob) {
    write("Are you sure that they are here?\n");       
    return 1;     
  }

  if(ob->query_hp())
    intThing = 1;
  else
    intThing = 2;


  if(intThing == 1) {
    plev  = TPL;
    parm  = TP->query_wc();
    pweap = TP->query_ac();
    mlev  = ob->query_level();
    marm  = ob->query_ac();
    mweap = ob->query_wc();
    pron  = CAP(ob->PRO);

    if(TP->query_immortal()) {
      write("parm  = " + parm + " \n");
      write("pweap = " + pweap + " \n");
      write("marm  = " + marm + " \n");
      write("mweap = " + mweap + " \n");
      write("pron  = " + pron + " \n");
    }

    intFlag = 0;

    // Check the level of the opposition versus ours.
    if(plev < (1 + mlev) / 3) {
      intFlag = 1;
      lev_advice = pron + " is far more powerful than you!";
    }

    if(!intFlag && plev == mlev ) {
    lev_advice = pron+" is just as powerful as you.";
    intFlag = 1;
    }
    if(!intFlag && plev < (1 + mlev) / 2) {
      intFlag = 1;
      lev_advice = pron+" is much more powerful than you.";
    }

    if(!intFlag && plev < mlev) {
      intFlag = 1;
      lev_advice = pron+" is more powerful than you.";
    }

    if(!intFlag && plev > mlev) {
      intFlag = 1;
      lev_advice = pron + " barely measures up to you.";
    }
    
    if(!intFlag && (1 + plev) / 2 > mlev ) {
      lev_advice = pron + " is much weaker than you.";
    }

    intFlag = 0;

    if(pweap < (1 + mweap) / 3) {
      intFlag = 1;
      weap_advice = "far more powerful than yours!!";
    }

    if(!intFlag && pweap < (1 + mweap) / 2 ) {
      intFlag = 1;
      weap_advice = "much more powerful than yours.";
    }

    if(!intFlag && pweap < mweap) {
      intFlag = 1;
      weap_advice = "more powerful than yours.";
    } 

   if(!intFlag && pweap == mweap) {
   intFlag = 1;
   weap_advice = "exactly the same as yours.";
   }

    if(!intFlag && pweap > mweap) {
      intFlag = 1;
      weap_advice = "weaker than yours.";
    }

    if(!intFlag && (1 + pweap) / 2 > mweap) {
      weap_advice = "much weaker than yours.";
    }

    switch(mweap) {
    case 0..4:
      weap_level = "minimal";
      break;
    case 5..7:
      weap_level = "moderate";
      break;
    case 8..12:
      weap_level = "somewhat strong";
      break;
    case 13..16:
      weap_level = "rather strong";
      break;
    case 17..18:
      weap_level = "very dangerous";
      break;
    case 19..20:
      weap_level = "deadly";
      break;
    default:
      weap_level = "legendary";
      break;  
    }

    switch(marm) {
    case 0..1:
      arm_advice = "pitiful.";
      break;
    case 2..3:
      arm_advice = "rather weak.";
      break;
    case 4..5:
      arm_advice = "moderately strong.";
      break;
    case 6..7:
      arm_advice = "pretty strong.";
      break;
    case 8..10:
      arm_advice = "rather strong.";
      break;
    case 11..14:
      arm_advice = "very strong.";
      break;
    case 15..18:
      arm_advice = "extremely strong.";
      break;                       
    case 19..25:
      arm_advice = "frighteningly strong.";
      break;                      
    case 26..60:
      arm_advice = "practically unbeatable!";
      break;
    default:
      arm_advice = "AWESOME!!";
      break;                     
    }
                                        
    write("You pray to Hachiman for guidance before attacking " +
          ob->NAME + ".\n");
    write("\n");
    write("Hachiman tells you:  " + lev_advice + "\n");
    write(pron + " has a " + weap_level +
          " attack that is " + weap_advice + "\n");
    write(pron + " has defenses which are " + arm_advice + "\n");
  }

  if(intThing == 2) {
    write("You cannot attack that!\n");
  }
  return 1;
}  
