#include "/players/tatsuo/guild/ndef.h"

main(arg){

if(!arg) return printf("Say what?\n"),1;

if(TPL <20) return 0;

if(TPRN == "tatsuo" || TPRN == "nobunaga" || TPRN == "wilbie" ){
write("You say: "+arg+"\n");
say(TPN+"-sama says: "+arg+"\n");
return 1;
}

say(TPN+"-san says: "+arg+"\n");
write("You say: "+arg+"\n");
return 1;
}
