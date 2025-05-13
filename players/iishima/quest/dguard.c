inherit "obj/monster";

string str1;
string str2;
status doneit;

void reset(int arg){
::reset(arg);
if (arg) return;
set_name("guard");
set_race("dragon");
set_short("A dragon guard");
set_long("This evil dragon guard is guarding Lamtrashara's Den. You think that\n"+
         "it would not be too wise to mess with him. If you attack him, you will\n"+
         "surely die!\n");
set_level(100);
set_hp(1000000);
set_gender(1);
doneit = 0;
}

void init()
{
 ::init();
 add_action("north","north");
 add_action("north","n");
}

status north()
{
 if (doneit == 0) { tell_object(this_player(),"The Guard forbids you to pass. Maybe you could mention a bribe to him?\n"); return 1; }
}

void catch_tell(string arg) 
{
if (sscanf(arg,"%s gives sword to Guard.",str1)==1)
 {
  if (present("#DRAGONSWORD#",this_object()))
  {
   write("Guard says: Very well, you may pass.\n");
   say("The Dragon Guard steps aside.\n");
   doneit = 1;
  }
 }
 if ((sscanf(arg,"%s says: bribe",str1)==1) || (sscanf(arg,"%s says: Bribe",str1)==1) ||
     (sscanf(arg,"%s tells you: bribe", str1)==1) || (sscanf(arg,"%s tells you: Bribe",str1)==1))
   {
   write("Guard says: You want to bribe me? Bring me the dragon sword and you shall pass.\n");
   }
}

