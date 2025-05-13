/*-------------------------------------------------------------------*/
/* This file is the new soul designed for guilds. It is made for     */
/* universal use and to help prevent abnormalities.                  */
/*-------------------------------------------------------------------*/
#include "/guild/guild_defines.h"
 
#define GM          "guild/master"
#define TP          this_player()
#define TPL         TP->query_level()
#define INV         query_invis()
#define IMM         query_immortal()
#define RNAME       query_real_name()
#define CAP         capitalize
#define CD          "sys/chatd"
 
#define FILE_CHECK(x,y) if(file_size(x+".c") > 0) \
                          if(call_other(x, "main", y)) \
                            return 1
 
int guild, level, classtype;
object thispl;
 
int recognize_fight() {
}
 
int get() {
  return 1;
}
 
int drop () {
  return 1;
}
 
int id(string str) {
  return (str=="testsoul" || str=="guildsoul");
}
 
int _cast_(string str) {
  string *spellname;
  string theverb;
  int i, j;
 
  if(!str || str == "") {
    write("You must supply an arguement to cast.\n");
    return 1;
  }
  spellname = explode(str," ");
  i = sizeof(spellname);
  if( i > 1 )
    for(j=1;j<i;j++)
      if(j == 1)
        theverb = spellname[j];
      else
        theverb = theverb + " " + spellname[j];
 
  switch(classtype) {
    case 10 :
      FILE_CHECK(S_ADV_GUILD + theverb, str);
      FILE_CHECK(S_RANGER_CLASS + theverb, str);
      break;
    case 20 :
      FILE_CHECK(S_ADV_GUILD + theverb, str);
      FILE_CHECK(S_VAGABOND_CLASS + theverb, str);
      break;
    case 30 :
      FILE_CHECK(S_ADV_GUILD + theverb, str);
      FILE_CHECK(S_JEDI_CLASS + theverb, str);
      break;
    case 12 :
    case 21 :
      FILE_CHECK(S_ADV_GUILD + theverb, str);
      FILE_CHECK(S_RANGER_CLASS + theverb, str);
      FILE_CHECK(S_VAGABOND_CLASS + theverb, str);
      break;
    case 13 :
    case 31 :
      FILE_CHECK(S_ADV_GUILD + theverb, str);
      FILE_CHECK(S_RANGER_CLASS + theverb, str);
      FILE_CHECK(S_JEDI_CLASS + theverb, str);
      break;
    case 23 :
    case 32 :
      FILE_CHECK(S_ADV_GUILD + theverb, str);
      FILE_CHECK(S_VAGABOND_CLASS + theverb, str);
      FILE_CHECK(S_JEDI_CLASS + theverb, str);
      break;
    case 50 :
      FILE_CHECK(S_ADV_GUILD + theverb, str);
      FILE_CHECK(S_RANGER_CLASS + theverb, str);
      FILE_CHECK(S_VAGABOND_CLASS + theverb, str);
      FILE_CHECK(S_JEDI_CLASS + theverb, str);
      break;
    default :
      FILE_CHECK(S_ADV_GUILD + theverb, str);
      break;
  }
  write("You do not seem to know that spell!\n");
  return 1;
}
 
int _cast(string str) {
  if(find_call_out("_cast_") != -1) {
    write("You are already casting.\n");
    return 1;
  }
  call_out("_cast_",1,str);
  return 1;
}
 
int _filter(string str) {
  string theverb;
 
  theverb = (string)query_verb();
  if(theverb[0] == 39) return 0;
  if(theverb == "quit" || theverb == "dest") return 0;
  if(theverb == "adv/" || theverb == "a/") {
    (A_ADV_GUILD + "adv")->main(str);
    return 1;
  }
 
  switch(classtype) {
    case 10 :
      FILE_CHECK(A_ADV_GUILD + theverb, str);
      FILE_CHECK(A_RANGER_CLASS + theverb, str);
      break;
    case 20 :
      FILE_CHECK(A_ADV_GUILD + theverb, str);
      FILE_CHECK(A_VAGABOND_CLASS + theverb, str);
      break;
    case 30 :
      FILE_CHECK(A_ADV_GUILD + theverb, str);
      FILE_CHECK(A_JEDI_CLASS + theverb, str);
      break;
    case 12 :
    case 21 :
      FILE_CHECK(A_ADV_GUILD + theverb, str);
      FILE_CHECK(A_RANGER_CLASS + theverb, str);
      FILE_CHECK(A_VAGABOND_CLASS + theverb, str);
      break;
    case 13 :
    case 31 :
      FILE_CHECK(A_ADV_GUILD + theverb, str);
      FILE_CHECK(A_RANGER_CLASS + theverb, str);
      FILE_CHECK(A_JEDI_CLASS + theverb, str);
      break;
    case 23 :
    case 32 :
      FILE_CHECK(A_ADV_GUILD + theverb, str);
      FILE_CHECK(A_VAGABOND_CLASS + theverb, str);
      FILE_CHECK(A_JEDI_CLASS + theverb, str);
      break;
    case 50 :
      FILE_CHECK(A_ADV_GUILD + theverb, str);
      FILE_CHECK(A_RANGER_CLASS + theverb, str);
      FILE_CHECK(A_VAGABOND_CLASS + theverb, str);
      FILE_CHECK(A_JEDI_CLASS + theverb, str);
      break;
    default :
      FILE_CHECK(A_ADV_GUILD + theverb, str);
      break;
  }
  return 0;
}
 
void reset(int arg) {
 
  if(arg) return;
  guild = GM->query_number("test");
  thispl = environment();
  if(TP) {
    level = TPL;
    if(TP->IMM)
      classtype = 0;
/* After changes put back to all subclasses
      classtype = 50;
*/
    else
/* set to test only jedi part i suppose */
      classtype = 0;
/* After changes of master can implement this -
      classtype = TP->query_real_guild() - (guild * 100);
*/
  }
}
 
void init() {
 
  add_action("_cast","cast");
  add_action("_cast","+",1);
  add_action("_filter","",1);
 
  tell_object(TP, "You have joined the company. The pay is good, but "+
           "the hours suck.\n");
  if(TP->RNAME!="magnal" && !TP->INV && !TP->IMM)
    CD->do_chat(guild,"[* Test *] "+CAP(TP->RNAME)+
          "returns to the company.\n");
}
 
