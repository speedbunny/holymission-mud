/*
 * Author : Uglymouth
 * Date   : 8-AUG-1993
 */
#include "path.h"
inherit "room/store";

void reset(int arg) {
  ::reset(arg);
  dest_dir = ({ PATH+"shop","south" });
  }
