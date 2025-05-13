/* =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=                                                                            
     Psionisist Guild Soul.c     
            By
	Elementalist Tamina  (started 05-08-94)
   =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= */                                                                         

inherit "obj/armour";
                                                                            
#include "lw.h"
#include "/players/tamina/defs.h"

/*  #define EN environment         */
/*  #define QN query_name()        */
/*  #define QRN query_real_name()  */
/*  #define QL query_level()       */
/*  #define C capitalize           */

#define CHK_SP(x) if((int)TP->SP <x) \
    {write("Your mental powers are not strong enough to perform this ability.\n");\
         say (TPN+" tries to gather the energy to do something special, but fails!\n");return 1;}\
         else TP->restore_spell_points(-x)

#define CHK_GHOST() if(TP->query_ghost()) write("You are too dead to perform that ability!\n"); return 1

#define CHK_FAIL(x) if(random(100)>(((TP->CHR+TP->LVL)*2)+x)) NFAIL("Your attempt at Psionics fails, due to self-confidence!\n"); return 0

string extra_look() 
{
   return lw(CAP(TP->QPRO)+"  "
           +(TP->QPOS) +" \n"
           +(TP->QPRO)+" \n"
           +(TP->QPRO)+" ");
}

reset (arg)
{
  ::reset(arg);
  if(arg) return 0;

set_name("headband");
set_type("guild");
set_short("A Mystical Headband");
set_long("This is the Mystical Headband given to you on your admittance\n"+
         "to the secret Guild of Psionisists.\n"); 
set_ac(1);
set_weight(0);

int id(string str) 
{
   return str == "headband";
}

int drop() 
{
   write("You can't drop your Psionics Headband!\n");
   return 1;
}
/*
void init() 
{
  AA(        "psion"); 
  AA(        "psion/"); 
  AA(        "phelp"); 
  AA(        "detection");
  AA(        "eye"); 
  AA(        "pshout");
  AA(        "ptell");
  AA(        "telekinesis");
  AA(        "blur");
  AA(        "insanity");
  AA(        "pain");
  AA(        "possession");
  AA(        "phasing");
  AA(        "moving");
}
*/
/* ########################## Guild Chat Line  ######################## */

void tell_psionisists(string str);

int psion(string str) {
   int i;
   object *u;

 if(!str) {
   write("_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
   u = sort_array(filter_array(users(), "psionisist_filter", TO, 0),
    "psionisist_hierarchy", TO);

for(i = 0; i < sizeof(u); i++) {
   int lev;
   lev = (int)u[i]->LVL;
  if((u[i]->query_invis()) && (TPN == "tamina")) {
    write("["+lev+"] ["+CAP(u[i]->RNAME)+"] **INVISIBLE**\n"); 
    return 1; }
   if(u[i]->query_invis()) {
    return 1; }
   if(u[i]->RNAME == "tamina") write("[Guild Master] ");
   if(u[i]->LVL   == 1000)     write("[God]          ");
   if(u[i]->LVL   == 500)      write("[High Arch]    ");
   if(u[i]->LVL   == 50)       write("[Arch-Wizard]  ");
   if(u[i]->LVL   == 40)       write("[Lord]         ");
   if(u[i]->LVL   == 35)       write("[Senior Wizard]");
   if(u[i]->LVL   == 33)       write("[Wizard]       ");
   if(u[i]->LVL   == 31)       write("[New Wizard]   ");        
   if(u[i]->LVL   == 30)       write("[Appr Wizard]  ");
   if(u[i]->LVL    >  9)       write("["+lev+"]      ");
   if(u[i]->LVL    < 10)       write("["+lev+"]      ");
   write(" ["+C(u[i]->short())+"]");
   if(u[i]->queryenv("NO_TALK")) write(" |-- off-line --|  ");
   if(u[i]->query_al()<0) write(" |-- OUT OF PSYNC --|");
   write("\n");
  }
   write("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n");
return 1;
}

if(str == "off") {
   write("Psionics channel switched off.\n"+
	 "Your mind is now detached from your fellows.\n");
   TP->setenv("NO_TALK",1);
   return 1;
}

if(str == "on") {
   write("Psionics channel switched on.\n"+
	 "Your mind is now mixed with your fellows.\n");
   TP->unsetenv("NO_TALK");
   return 1;
}

if(query_verb() == "psion/") {
   tell_psionisists(lw("|-- Psionisist --|"+ CAP(TPN) + " " + str) + "\n");
   return 1;
   } else
   tell_psionisists(lw("|-- Psionsisist "+CAP(TPN)+ " --| " + str) + "\n");
   return 1;
}

void tell_psionsisists(string str) {
int i,j;
string *mess;
object *u;

   u=filter_array(users(), "on_line", TO);
   for(i = 0; i < sizeof(u); i++)
   TOBJ(u[i], str);
}

int psionisist_filter(object pl) {
   return (int)pl->query_guild() == 0;
}

int psionisist_hierarchy(object pl1,object pl2) {
   if((string)pl1->RNAME == "tamina") { 
   return 0;
   }
   if((string)pl2->RNAME == "tamina") {
   return 1;
   }else
   return (int)pl1->LVL < (int)pl2->LVL;
}

int on_line() {
   object pl;
   return (int)pl->query_guild()==0 && !pl->queryenv("PSIONISIST_OFF");
}

/* ######################### HELP #################################### */
int phelp(string str) {
   if(!str)
   return 0;
   if(str == "levels") {
   "guild/master"->list_levels(0, (int)TP->query_gender());
   return 1;
   }
   if(str == "guild") {
   TP->more_string(read_file("/players/tamina/others/psion/help"));
   return 1;
   }
   if(str == "info") {
   TP->more_string(read_file("/players/tamina/others/psion/info"));
   return 1;
   }
}
