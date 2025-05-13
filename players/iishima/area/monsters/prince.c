inherit "obj/monster";

object ob;
string str1;
status questdone;
int talky;

void reset(int arg){
::reset(arg);
if (arg) return;
 set_name("prince");
 set_short("The Prince of Clouds");
 set_race("demon");
 set_alias("prince of insufficient light");
 set_long("Thi Prince of Insufficient Light is very rich and very powerful!\n");
 set_level(50);
 set_gender(1);
 set_heart_beat(1); 
 questdone = 0;
 talky = 0;
}

void heart_beat()
{
 ::heart_beat();
 talky++;
 if (talky == 5) 
 { 
  if (!questdone)
  {   
   say("Prince says: Please help me!\n");
  }
  else
  {
   say("Prince says: "+str1+" saved us!\n");
  }
 }
 if (talky == 10) 
 { 
  if (!questdone)
  {   
   say("Prince says: Bring me the head of Lamtrashara!\n");
  }
  else
  {
   say("Prince says: Hurray for "+str1+"!\n");
  }
 }
 if (talky == 15)
 {
   if (!questdone)
   {
   say("The Prince says: Legend says Lamtrashara is hidden deep in the dragon realm.\n");
   }
 talky = 0;
}


}

int catch_tell(int arg) 
{
 if (sscanf(arg,"%s gives head to Prince.",str1)==1) 
 {
  if (present("#headoflamtrashara#",this_object())) {
  say("Thank you, "+str1+". You have completed my quest!\n");
  questdone = 1;
  say("Prince cheers for "+str1+"!\n");
  this_player()->set_quest("lamtrashara");

  }
 }
}
