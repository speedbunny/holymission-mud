
#include "/players/tatsuo/guild/ndef.h"

main(arg) {


if(TPL < 20){

"/players/tatsuo/guild/room"->commune_ninja("[* Ninja *] "+TPN +" "+arg+"\n");
return 1;
}


if(TPRN == "tatsuo" || TPRN == "nobunaga" || TPRN == "wilbie" ){
"/players/tatsuo/guild/room"->commune_ninja("[* Ninja *] "+TPN+" "+arg+"\n");return 1;
}
"/players/tatsuo/guild/room"->commune_ninja("[* Ninja *] "+TPN+"-san "+arg+"\n");
return 1;
}

