#ifndef __LOG_C__

#define __LOG_C__

#include "weapon_class.h"
#include "weapon_defs.h"
#include "weapon_log.h"
#include "weapon_name.h"
 
void log_weapon(string func) {
  if(stringp(func)) {
    if(TP) {
      log_file("ILLEGAL",
               TPRN+" "+func+", WC"+" "+class_level+", "+short_desc+"("
               +name_of_weapon+")"+" creator: "+creator(TO)+" "+file_name(TO)
               +"\n");
    }
    else 
      log_file("ILLEGAL",ctime()+"\n");
  }
}

#endif // _LOG_C__
