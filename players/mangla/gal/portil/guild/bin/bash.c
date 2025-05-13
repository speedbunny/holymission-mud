/* Galadriel 2-SEP-94: extracted from soul010994b.c */
/* the bash.c contained shield_block instead of bash */
/* G: had to define these too */
// Whisky: recoded it to a better code

#define TP this_player()
#define TPN this_player()->query_name()
#define ENV environment

bash(int *bash, int no_but) 
{
	object att;
	int dex;
   string mme, mout, mvic, vic;

  if(!att=TP->query_attack()) 
  {
   	write("You are not fighting.\n");
   	return 1;
  }

  vic = att->query_name();

  if(!TP->query_armour()[TP->query_arm_types("shield")]) 
  {
   	write("You need a shield to bash.\n");
   	return 1;
  }
  else if(TP->query_sp()<10){
       write("You are too tired to bash.\n");
       TP->command("drop shield");
       return 1;
}
  else if(ENV(TP)!=ENV(att)) 
  {
	write("But "+vic+" is not here.\n");
	return 1;
  }
  else if(ENV(this_player())->query_property("no_fight")) 
  {
    ENV(this_player())->try_attack(att);
    return 1;
  }

  if(bash) 
  {

    bash = bash + 1;
    if (!random(1 + TP->query_dex()/3))
    {
      	write("You loose your balance as you try to attack too soon.\n");
         say(TP->query_name()+" looses the balance and falls on the ground.\n",
             TP);
	      att->attack();   
         return 1;
   }
   tell_object(att,TP->query_name()+" fails to hit you with "+
                   TP->query_possessive()+" shield.\n");
   write("Oops, that was to early, you fail to bash "+vic+".\n"); 
   say(TP->query_name()+" fails to bash "+vic+".\n",TP,att); 
	return 1;
  }
  if(no_but) 
  {
	write("You dont have the self control to bash and butt at the same time.\n");
	return 1;
  }
	bash=2;
   dex=TP->query_dex();
   mme =  "You bash "+vic+" with your shield";
   mvic = TPN+" hits you with "+TP->query_possessive()+" shield";
   mout = TPN+" thumps "+vic+" with a shield";

// Whisky: a sucessfull bashed monster falls
     if (!random(3) && TP->query_str() > random(att->query_dex()) )
     {
         att->hold(TP,random(2));
         mme =  mme +  ", who stumbles and falls";
         mvic = mvic + ".\nYou stumble and fall";
         mout = mout + ", who stumbles and falls";
      }
      write(mme+".\n");
      say(mout+".\n",TP,att);
      tell_object(att,mvic+".\n");
      TP->add_exp(att->hit_player(random(dex)+dex+5));
      TP->restore_spell_points(-10);
	return 1;
}
