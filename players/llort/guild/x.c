#define GUILD           "mage"                  /* mage guild */
#define GM		"guild/master"
#define LGF		"GUILD.JOIN"
#define SM		"spells/master"

inherit "guild/guild_room";

/*-------------------------------------------------------*/
/* All the Advance, Cost, List stuff here		 */
/* All the pretitles, titles and exp levels for a mage.  */
/*-------------------------------------------------------*/

#define TO		this_object()
#define TP		this_player()
#define TPN		this_player()->query_name()
#define env		environment
#define SAY(x)		tell_room(env(TO),x)

int	guild;
int     nr_of_spells;		/* for the skill-system */

reset(tick)
{
    ::reset(tick);

    if (tick) return;
    guild=GM->query_number(GUILD);
    set_guild(guild);
//    nr_of_spells=init_spell_list(guild);

    short_desc = "Mages guild";
    long_desc =
"Mages guild. The place is dominated by lots of mirrors covering the walls.\n" +
"To the west you can see a hallway leading deeper into the Tower. The doorway \nemits a lightblue glow.\n" +
"You notice a sign on the wall saying:\n"+
"                   you can 'start' here now if you like.\n"+
"Commands: cost, advance,\n" +
"          list, list [number],\n" +
"          list all or join.\n";

    dest_dir = ({ "room/mount_top2","south",
	          "players/llort/guild/tower/hallway","west"});
}

re_init() { return nr_of_spells=init_spell_list(guild); }

init() {
    ::init();
    add_action("envoke","envoke");
    add_action("practice","practice");
    add_action("startroom","start");
    if(member_array(this_player()->query_real_name(),
       ({ "llort","whisky" })) != -1)
    {
         add_action("re_init","init_spells");
    }
}

envoke(arg) {
object scep;

  if(arg=="scepter" || arg=="scepter of arcanarton") 
    if(scep=present("scepter of arcanarton",this_player())) {
      write("As you wave the scapter, a bright flash breaks free of the "+
            "mirrors,\nand the scepter disappears from your hand.\n"+
            "A strange voice forms the words ..\n"+
            "    'Well done, you solved that quest'\n"+
            "                                       .. in your mind.\n");
      destruct(scep);
      return 1;
      }
}

do_advance(arg)
{
   int lev,llev, oldlev, oldll, pracs, plevs;

   oldlev=this_player()->query_level();
   oldll=this_player()->query_legend_level();
   ::do_advance(arg);
   lev=this_player()->query_level();
   llev=this_player()->query_legend_level();
   if (lev+llev == oldlev+oldll+1)
   {
       this_player()->add_practice_sessions(
           8+(this_player()->query_wis()-oldlev)/2 );
   }
   return 1;
}

do_join() {
  string qu;

  if (::do_join()) return 1; /* Joining not possible */

  if (TP->query_int()<4) {
     write("Yorel tells you: You are too dull to learn spells.\n");
     return 1;
  }  
  if (TP->query_money()<100) {
     write("Yorel tells you: You don't have enough gold coins.\n" +
           "Yorel tells you: You need to pay 100 gold coins for your mage's robe!\n");
     return 1;
  }
  TP->add_money(-100);
  TP->set_guild(guild);
  write("You pay your fee for joining.\n");
  write("Yorel tells you: Now you are a mage !\n");
  say(TPN+" has joined the mages guild.\n");
  log_file(LGF,TPN+" joins the "+GUILD+"'s guild at "+
	   ctime(time())+"\n");
  TP->add_practice_sessions(10);
  return 1;
}

query_maxsp(my_int,ll) {
int max,i;
  i=my_int;
  max=45+i*8;
  while(i>0) {
    max+=(i/2);
    --i; 
  }
  return max+ll*my_int/2; 
}

query_maxhp(my_con,ll) {
  return my_con*12+47+ll*my_con/2;
}

soul() {
object s;
  if(s=present("magerobe",this_player())) destruct(s);

  s=clone_object("players/llort/guild/soul2");
  if(s) move_object(s,this_player());
  return 1;
}

/************************** SKILL SYSTEM **************************/
mixed *spells;

string know_level(int val)
{
   string rtc;

   if(val ==   0)      rtc = "not learned";
   else if(val <   10) rtc = "Awful";
   else if(val <   25) rtc = "Bad";
   else if(val <   40) rtc = "Poor";
   else if(val <   60) rtc = "Average";
   else if(val <   80) rtc = "Fine";
   else if(val <   90) rtc = "Good";
   else if(val <   95) rtc = "Very good";
   else if(val <  100) rtc = "Superb";
   else if(val == 100) rtc = "Perfect";
   else                rtc = " ** Strange ** ";

   return rtc;
}

string time_level(int val)
{
   string rtc;

   if(val <  -2) rtc = " ** Strange ** ";
   else if(val == -2) rtc = "-----";
   else if(val == -1) rtc = "Immediate";
   else if(val ==  0) rtc = "Very short";
   else if(val ==  1) rtc = "Short";
   else if(val ==  2) rtc = "Average";
   else if(val ==  3) rtc = "Long";
   else if(val ==  4) rtc = "Very long";
   else rtc = "Extremly long";

   return rtc;
}

int init_spell_list(int gid)
{
   int i, nr;
   mixed *tmp;

   spells=({ ({ }), ({ }), ({ }), ({ }), });

   tmp=SM->dump_spells();
   if(!tmp)
   {
      write("SYSTEM-Error: Empty skill Database!\n");
      return 1;
   };
   for(i=nr=0;i<sizeof(tmp[0]);i++)
   {
      if(tmp[2][i] == gid)
      {
         spells[0]+= ({ tmp[0][i], });
         spells[1]+= ({ tmp[1][i], });
	 spells[2]+= ({ tmp[1][i]->level(), });
         spells[3]+= ({ tmp[1][i]->min_speed(), });
         nr++;
      };
   };
   return nr;
}

act_practice(arg)
{
   mixed *spdat, *mysp;
   int new;

   if(TP->get_skill("mage_practice")[0]<=1)
   {
      write(
   "You have to go out to earn more experience before comming here again!\n");
      return 1;
   };

   new=0;
   spdat=SM->get_spell(arg);
   if(!spdat || spdat[2]!=5)
   {
      write("You can find no library-entry about this field of knowledge.\n");
      return 1;
   };
   mysp=TP->get_spell(spdat[0]); 
   if(!mysp) 
   {
      new=1;
      mysp=({ spdat[0], 0, 100, 5 });
   };
   mysp[3]=spdat[1]->speed(TP->query_level());
   if(mysp[1]>94)
   {  
      write(
  "You already know as much in this skill, as you ever could learn here.\n");
      return 1;
   };

   if(spdat[1]->level()>TP->query_level())
   {
      write("After studing for a while, you're sure, to be too unexperienced"+
            "to master this field of knowledge.\n");
      return 1;
   };

   if(mysp[1] < 25) mysp[1]+=10+random(10);
   else if(mysp[1] < 40) mysp[1]+=8+random(8);
   else if(mysp[1] < 50) mysp[1]+=7+random(7);
   else if(mysp[1] < 60) mysp[1]+=6+random(6);
   else if(mysp[1] < 70) mysp[1]+=5+random(5);
   else if(mysp[1] < 80) mysp[1]+=4+random(4);
   else if(mysp[1] < 90) mysp[1]+=3+random(3);
   else if(mysp[1] < 95) mysp[1]+=2+random(2);
   else mysp[1] = 95;

   if(new)
   {
      write("You start to understand a totally new field of knowledge.\n");
   }
   else
   {
      write("You improve your knowledge in this field.\n");
      if(mysp[1]>94)
      {
         mysp[1]=95;
         write("You are now learned in this field.\n");
      };
   };
/* recalc(mysp[3]) */
   TP->change_spell(mysp[0],mysp[1],mysp[2],mysp[3]);
   TP->change_spell(mysp[0],-2,mysp[2],mysp[3]);
   GM->change_skill(TP,"mage_practice",
                    TP->get_skill("mage_practice")[0]-1,100,5);

   return 1;
}

fix_practice()
{
   int *pracs, prac, *plevs, plev, i, lev,llev;

   pracs=this_player()->get_skill("mage_practice");
   plevs=this_player()->get_skill("mage_prac_lev");
   if(!pracs) prac=1;
   else prac=pracs[0];
   if(!plevs) plev=1;
   else plev=plevs[0];
   lev=this_player()->query_level();
   llev=this_player()->query_legend_level();
   GM->change_skill(TP,"mage_practice",0,500,5);
   if(lev+llev > plev)
   {
      for(i=plev; i<lev+llev; i++) prac+=6;
      GM->change_skill(TP,"mage_practice",prac,500,5);
      GM->change_skill(TP,"mage_prac_lev",lev+llev,100,5);
   }
}

fix_practice2()
{
   int *pracs, prac, *plevs, plev, i, lev;

   this_player()->set_con(this_player()->query_con());
   if(this_player()->queryenv("mage_fixed")) 
   {
       return 1;
   }

   pracs=this_player()->get_skill("mage_practice");
   plevs=this_player()->get_skill("mage_prac_lev");
   if(!pracs || !plevs) return 0;
   prac=pracs[0];
   plev=plevs[0];
   GM->change_skill(TP,"mage_practice",prac+plev*2,500,5);
   this_player()->setenv("mage_fixed","yep");
   this_player()->save_me(1);
   write("Fixed. Type 'practice' to check!\n");
   return 1;
}

practice(arg)
{
   object tp;
   mixed *spdat;
   string msg;
   int i,j;

   tp=this_player();
   fix_practice();
   fix_practice2();
		
   if(tp->query_guild() != guild)
   {
      write("You have to enroll in the the Colleg of Magii,\n"+
            "to be able to improve your knowledge here.\n");
      return 1;
   };

   if(!TP->get_skill("mage_practice"))
   {  GM->change_skill(TP,"mage_practice",11,500,5); };

   if(arg) return act_practice(arg);

   msg = "Your library-research reveals tomes to the following fields:\n"+
         "------------------------------------------------------------\n"+
         sprintf(" %-20s   %|20s   %|20s\n",
                 "Name of field","Knowledge","Time to perform")+"\n";
   for(i=j=0;i<nr_of_spells;i++)
   {
      if(tp->query_level() >= spells[2][i])
      {
         spdat = tp->get_spell(spells[0][i]);
         if(!spdat) spdat = ({ spells[0][i], 0, 100, -2, });
         msg+=sprintf(" %-20s   %|20s   %|20s\n", spdat[0],
                      know_level(spdat[1]), time_level(spdat[3]) );
         j++;
      };
   };
   
   msg += "\nYou have "+(tp->get_skill("mage_practice")[0]-1)+
          " practice sessions left.\n";
  
   if (!j)
   {
      write(
  "Sorry, you can't find anything you're able to understand at the moment.\n");
      return 1;
   }
   else this_player()->more_string(msg);

   return 1;
}

query_mage_guild() { return 1; }

startroom(a)
{
    if(!a)
    {
        write("Where do you wnt to start? church or guild ?\n");
        return 1;
    }
    a=lower_case(a);
    switch(a)
    { 
        case "guild":
            this_player()->start_in_guild(1);
            write("You will start in the guild from now on.\n");
            this_player()->save_me(1);
            break;
        case "church":
            this_player()->start_in_guild(0);
            write("You will start in the church from now on.\n");
            this_player()->save_me(1);
            break;
        default:
            write("You have to start in the guild or the church!\n");
    };
    return 1;
}
