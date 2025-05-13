#include "/players/sargon/define.h"

bash(int *bash, int no_but) 
{
        object att;
        int dex;
   string mme, mout, mvic, vic;

  if(previous_object()->query_bash()) return 0;

  if(!att=TP->query_attack()) 
  {
        write("You are not fighting.\n");
        return 1;
  }

  vic = att->N;

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
  else if(E(TP)!=E(att)) 
  {
        write("But "+vic+" is not here.\n");
        return 1;
  }
  else if(E(TP)->query_property("no_fight")) 
  {
    E(TP)->try_attack(att);
    return 1;
  }

  if(bash) 
  {

    bash = bash + 1;
    if (!random(1 + TP->query_dex()/4))
    {
        write("You loose your balance as you try to attack too soon.\n");
         say(TPN+" looses the balance and falls on the ground.\n", TP);
              att->attack();   
         return 1;
   }
   tell_object(att,TPN+" fails to hit you with "+
                   TP->query_possessive()+" shield.\n");
   write("Oops, that was to early, you fail to bash "+vic+".\n"); 
   say(TPN+" fails to bash "+vic+".\n",TP,att); 
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
  
   previous_object()->set_bash(1);

     if (!random(3) && TP->query_str() > random(att->query_dex()) )
     {
         att->hold(TP,random(2));
         mme =  mme +  ", who stumbles and falls";
         mvic = mvic + ".\nYou stumble and fall";
         mout = mout + ", who stumbles and falls";
      }
      write(mme+".\n");
      say(mout+".\n",TP,att);
      TOB(att,mvic+".\n");
      TP->add_exp(att->hit_player(random(dex)+dex+5));
      TP->restore_spell_points(-15);
        return 1;
  }

  int bash;
      void reset_bash() {
        bash = 0;
  }

      void set_bash() {
        bash = 1;
        call_out("reset_bash", 0, 1);
        return;
  }

int query_bash() {
    return bash;
}
