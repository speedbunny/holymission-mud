#include "/players/tatsuo/guild/ndef.h"

main(){
 
string kskill, sskill, asskill, thkill, brkill, dikill, smkill, kuskill;
 
switch(KARATESKILL){

case 1..10   :  kskill= "unskilled";    break;
case 11..15  :  kskill= "kohai";        break;
case 16..24  :  kskill= "sempai";       break;
case 25..32  :  kskill= "di-sempai";    break;
case 33..39  :  kskill= "yudan";        break;
case 40..46  :  kskill= "renshi";       break;
case 47..55  :  kskill= "kyoshi";       break;
case 56..62  :  kskill= "hanshi";       break; 
case 63..75  :  kskill= "shihan";       break;
default      :  kskill= "grandmaster";  break;

}

switch(SILENCESKILL){

case 1..10   :  sskill= "unskilled";    break;
case 11..15  :  sskill= "kohai";        break;
case 16..24  :  sskill= "sempai";       break;
case 25..32  :  sskill= "di-sempai";    break;
case 33..39  :  sskill= "yudan";        break;
case 40..46  :  sskill= "renshi";       break;
case 47..55  :  sskill= "kyoshi";       break;
case 56..62  :  sskill= "hanshi";       break;
case 63..75  :  sskill= "shihan";       break; 
default      :  sskill= "grandmaster";  break;

} 
switch(ASSASSKILL){

case 1..10   :  asskill= "unskilled";    break;
case 11..15  :  asskill= "kohai";        break;
case 16..24  :  asskill= "sempai";       break;
case 25..32  :  asskill= "di-sempai";    break;
case 33..39  :  asskill= "yudan";        break;
case 40..46  :  asskill= "renshi";       break;
case 47..55  :  asskill= "kyoshi";       break;
case 56..62  :  asskill= "hanshi";       break;
case 63..75  :  asskill= "shihan";       break;
default      :  asskill= "grandmaster";  break;
}
 

switch(THROWSKILL){

case 1..10   :  thkill= "unskilled";    break;
case 11..15  :  thkill= "kohai";        break;
case 16..24  :  thkill= "sempai";       break;
case 25..32  :  thkill= "di-sempai";    break;
case 33..39  :  thkill= "yudan";        break;
case 40..46  :  thkill= "renshi";       break;
case 47..55  :  thkill= "kyoshi";       break;
case 56..62  :  thkill= "hanshi";       break;
case 63..75  :  thkill= "shihan";       break;
default      :  thkill= "grandmaster";  break;

}

switch(BREAKSKILL){

case 1..40   :  brkill= "unskilled";    break;
case 41..42  :  brkill= "kohai";        break;
case 43..49  :  brkill= "sempai";       break;
case 50..55  :  brkill= "di-sempai";    break;
case 56..60  :  brkill= "yudan";        break;
case 61..65  :  brkill= "renshi";       break;
case 66..75  :  brkill= "kyoshi";       break;
case 76..80  :  brkill= "hanshi";       break;
case 81..85  :  brkill= "shihan";       break;
default      :  brkill= "grandmaster";  break;

}

switch(DISARMSKILL){

case 1..50   :  dikill= "unskilled";    break;
case 51..55  :  dikill= "kohai";        break;
case 56..60  :  dikill= "sempai";       break;
case 61..65  :  dikill= "di-sempai";    break;
case 66..70  :  dikill= "yudan";        break;
case 71..75  :  dikill= "renshi";       break;
case 76..80  :  dikill= "kyoshi";       break;
case 81..85  :  dikill= "hanshi";       break;
case 86..95  :  dikill= "shihan";       break;
default      :  dikill= "grandmaster";  break;

}
 
switch(SHADOWMAGIC){


case 1..60   :  smkill= "unskilled";     break;
case 61..62  :  smkill= "kohai";        break;
case 63..64  :  smkill= "sempai";       break;
case 65..68  :  smkill= "di-sempai";    break;
case 69..73  :  smkill= "yudan";        break;
case 74..78  :  smkill= "renshi";       break;
case 79..85  :  smkill= "kyoshi";       break;
case 86..90  :  smkill= "hanshi";       break;
case 91..95  :  smkill= "shihan";       break;
default      :  smkill= "grandmaster";  break;
 
}
switch((TPL*3)+13){ 

/*Kubudo Skill, phantom skill, not used, just gives fighting prowness */


case 1..10 :   kuskill= "unskilled";     break;
case 11..20 :  kuskill= "kohai";        break;
case 21..30 :  kuskill= "sempai";       break;
case 31..40 :  kuskill= "di-sempai";    break;
case 41..50 :  kuskill= "yudan";        break;
case 51..60 :  kuskill= "renshi";       break;
case 61..80 :  kuskill= "kyoshi";       break;
case 81..95 :  kuskill= "hanshi";       break;
case 96..100 : kuskill= "grandmaster";  break;
default :      kuskill= "godly";       break;


}

 
 write("\n");
      
write("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
write("<>           Your Ninja skills are as follows           <>\n");
write("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
write("                                                          \n");
write("           You are "+kskill+" in Karate Jitsu             \n");
write("           You are "+sskill+" in Chimmoku Waza            \n");
write("           You are "+asskill+" in Assassination           \n");
write("           You are "+thkill+" in Throwing                 \n");
write("           You are "+brkill+" in Breaking                 \n");
write("           You are "+dikill+" in Disarming                \n");
write("           You are "+smkill+" in Shadow Magic            \n");
write("           You are "+kuskill+" in Kubudo Jitsu            \n");
write("                                                          \n");
write("<><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");

return 1;
} 


