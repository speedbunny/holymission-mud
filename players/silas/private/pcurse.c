/* prison_curse.C 910622 Herp --- this is the autoloading Prison Curse */
 
#include "include/prison.h"
 
object prison;
 
id(str) { return str==PCURSE_ID; }
 
drop() { return 1; }
 
extra_look() {
  return capitalize(this_player()->query_pronoun())+
         " is cursed and imprisoned to the end of eternity";
}
 
query_auto_load() { return PCURSE+":normal"; }
 
init_arg(arg) {
  (prison=call_other(PRISON,"self"))->imprison(this_player());
}
 
init() {
  add_action("pris","",1);
  return;
}
 
pris(str) {
/*return (prison?prison:prison=call_other(PRISON,"self"))->pris(str); */
  if (!prison) prison=call_other(PRISON,"self");
  return prison->pris(str);
}
