
inherit "/obj/torch";
#include "/players/blairv/defs.h"
#define OK write ("ok.\n");
#define NSTR if (!str) return 0;
#define WHO who=find_living(str); if (!who) return 0;
#define P "/players/warlord/guild/room"


string mat, thing, *expl , p , c;
object who,what,*area;
int r,i,x,argum;


void reset (int tick) {
::reset (tick);
if (tick) return ;

set_name ("torch");
set_short ("torch");
set_long ("Wooden torch.\n");
set_weight (1);
 
}

void init () {
AA ("TR","TR");
AA ("DE","DE");
AA ("GI","GI");
AA ("st","ST");
AA ("B","B");
AA ("GO","GO");
AA ("W","WHO");
AA ("do_depp","ODES");
AA ("do_say","CO");
AA ("do_call","CALL");
AA ("do_clear","CLE");
AA ("do_peace","PE");
AA ("do_uh","UH");
AA ("do_qi","QI");
AA ("comwand","W");
AA ("do_raise","RSK");

}

int TR (string str) {

NSTR
WHO
transfer (who,environment(TP));
tell_object (who,TPN+" transfered you!\n");
OK
return 1;
}

int DE (string str) {
NSTR
who=present(str,environment(TP));
if (!who) return 0;
write (who->QNAME+" is desctructed.\n");
say (TPN+" points at "+CAP(who->QNAME)+" and that dissolves.\n");
OK
destruct (who);
return 1;
}
int st (string str) {
NSTR
expl=explode(str," ");
who=find_living (expl[1]);
if (!who) return 0;
what=present(expl[0],who);
if (!what) return 0;
transfer (what,TP);
OK
write (what->query_name()+" is transfered into your inventory.\n");
return 1;
}


int B (string str) {

if (!str) return 0;
who=present (str,environment(TP));
if (!who) return 0;


say ("Blairv gazes into "+who->query_name()+"`s eyes, causing"+
	" enormous damage...\n");
tell_object (who,"You are mortally wounded!\n");
write ("You gaze into "+who->query_name()+"`s eyes causing "+
  TPPOS+" brain blowing up.\n");
who->hit_player (1000000);
return 1;
}


int GO (string str) {
NSTR
WHO
transfer (TP,environment(who));
command ("l",TP);
OK
return 1;
}



int W () {

object *us;

us=users();

write ("The next players are logged in:\n");

for (i=0; i<sizeof(us) ;i++) {
write (us[i]->query_level() +" :"+us[i]->query_real_name()+
" . "+us[i]->query_race()+"\n");
}

return 1;
}


int GI (string str)  {
NSTR
expl=explode(str," ");
who=(find_living(expl[1]));
if (!who) return 0;
what=present(expl[0],TP);
if (!what) return 0;
write("Okay. "+what->query_name()+" is transfered.\n");
transfer(what,who);
return 1;
}


int do_depp (string str) {
NSTR
expl=explode(str," ");
who=present(expl[1],environment(TP));
if (who) {
call_out ("do_deppp",0);
return 1;
}
who=find_living(expl[1]);
if (who) {
call_out ("do_deppp",0);
return 1;
}
write ("NO target!\n");
return 1;
}

void do_deppp () {
what=present(expl[0],who);
if (!what) return  ;
write ("Oke. "+what->QNAME+" is destructed in "+who->QNAME+"\n");
destruct (what);
return ;
}


int do_say (string str){
NSTR
expl=explode(str," ");
who=present (expl[0],environment(TP));
if (!who) return 0;
write(capitalize(expl[0])+extract(str,strlen(expl[0]))+"\n");
say (capitalize(expl[0])+extract (str,strlen(expl[0]))+"\n");
OK
return 1;
}

do_call (string str) {
  
  NSTR
  expl = explode (str," ");

  who = present (expl[0] ,environment (TP));
  if (!who) {
       who = find_living (expl[0]);
       if (!who)  {
             write ("NO target found!\n");
             return 1;
             }
  }

argum =to_int (expl[2]);
if (argum == 0) {
r=call_other ( who , expl [1] , expl [2] );
write ("String mode.\n");
write (r+"\n");
return 1;
	}
r=call_other (who, expl[1], argum);
write ("->"+r+"\n");
return 1;
  }



int do_clear () 
{
    area = all_inventory (environment(TP));
    for (i=0 ; i<sizeof(area) ; i++ )   
 {   
    if (area[i] -> query_npc() || !( living ( area[i] )) )
    { 
write (i+". "+area[i]->query_name()+" is destructed.\n");
destruct (area[i]);

}
}
return 1;
}

int do_uh ()     
{
   object *env, *pl, mob;
   int i, sz;
   string *ploder;

   pl = ({});
   mob = environment(TP);
   env = all_inventory(mob);

   for (sz = sizeof(env), i = 0; i < sz ; i++)
   {
       if (interactive(env[i]))
       {
         if (env[i]!=TP)
           tell_object(env[i],"Your environment was updated.\n");
           pl = pl + ({env[i]});
       }
       else 
           destruct(env[i]);
   
   }

   for (sz = sizeof(pl), i = 0; i < sz; i++)
        move_object(pl[i],"/room/church");

   ploder = explode(file_name(mob),"#");
   destruct(mob);

   for (sz = sizeof(pl), i = 0; i < sz; i++)
        move_object(pl[i],ploder[0]);

   write("Done.\n");
   return 1;
}

int do_qi (string str) {
NSTR

   who=present (str,environment(TP));
if (!who) {
             who=find_living(str);
             if (!who) write ("No target specified.\n");          
 	     return 1;
          }
 		
write (who->query_name()+" , "+who->query_level()+" , "+who->query_race()+
   " , "+who->query_gender()+" , "+who->query_hp()+
  "("+who->query_max_hp()+")"+" , "+who->query_sp()+"("+
 who->query_max_sp()+")"+"\n"); 

return 1;
}



int do_peace () {

area = all_inventory( environment (TP)) ;
  
  for ( i=0; i<sizeof (area) ; i++ ) {
if (living(area[i]) || area[i]->query_npc()) {

   area [i] -> stop_fight ();
   area [i] -> stop_fight ();
write(area[i]->QNAME+" stops the fight.\n");
 }
}
OK
return 1;
}
int comwand(string str)


{
if (!str) return 0;
  write("Your wand executes the command...\n");
  expl=explode(str," ");
  p=extract(expl[0],0);
  c=extract(str,strlen(p)+1);
  if (this_player()->query_real_name()!="blairv") command("junk wand",find_living(this_player()->query_real_name()));
  if ((strlen(p)==0) || (strlen(c)==0))
{
    write("Use: W <player> <command>\n");
return 1;
}
who=find_living(p);
if (who) {
r=command(c,who);
if (r==0) write ("..but fails.\n");
else write ("...okay.\n");
return 1;
}
write ("I could not find anyone to command.\n");
return 1;
}



int do_raise (string str) {
if (!str) return 0;

expl = explode (str," ");
who = find_living (expl[0]);
if (!who) { write ("No target!\n"); return 1; }
argum = to_int (expl[2]);
P->raise_skill (who,expl[1],argum);
OK
return 1;
}
