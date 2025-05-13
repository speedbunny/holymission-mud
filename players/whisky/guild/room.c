/* guild room */

inherit "/guild/guild_room";

#include "/players/whisky/guild/guild.h"
#include "/players/whisky/guild/skill_system.c"
#if 0
#include "/players/whisky/guild/titles.h"
#endif

#define TO		this_object()
#define TPL		TP->query_level()
#define TPN		this_player()->query_name()
#define MASTER		"Sauron"
#define env		environment
#define SAY(x)		tell_room(TO, x);

#define RACES		({"human"})
#define GUILD		"monk" 
#define FILE		"/players/whisky/guild/guild_banish"
#define HP		17
#define SP		17
#define HPBASE		(HP * 5)
#define SPBASE		(SP * 3)
#define GM		"/guild/master"
#define LGF		"GUILD.JOIN"
#define _partner	"/players/sauron/guild/room"

#undef LOWER_SKILLS

int guild;

int do_read(string arg) {
   if(arg != "sign")
       return 0;
   write(
   "This is the famous Monks guild of Holy Mission. To join\n"+
   "our guild you have first to help poor Hobbe (a miller south\n"+
   "of the bridge on the Main road) to get his watermill working\n"+
   "again. You can join us as human or accepted player by a Legend.\n"+
   "Local commands are: 'touch', 'about', 'toplist'\n"+
   "'cost', 'advance', 'list' or 'list <number>', 'start'.\n\n"+
   "Warning! Touching the iron is risking your life!\n");
   return 1;
}

int do_start(string arg) {
    if(TP->query_real_guild() != 7) {
        notify_fail("You are not a member of this guild, go home!\n");
        return 0;
    }
    else if(!arg) {
        notify_fail("Possible startpositions are: guild or church.\n");
        return 0;
    }
    switch(arg) {
       case "guild":
          write("Ok, you will now start here when you log in.\n");
          TP->start_in_guild(1);
          break;
       case "church":
          write("Ok, you will now start in the church when you log in.\n");
          TP->start_in_guild(0);
          break;
       default:
         write("Depperl :*)\n");
         break;
    }
    return 1;
}

int do_opinions() {
    this_player()->more("/players/whisky/guild/monk.info");
    return 1;
}

mixed no_advance() {
    object ob;    

    ob = present("monks_chk", this_player());

    if(!ob || ob->query_adv_level() < this_player()->query_level()) {
       return "You first have to proof if you are worth to advance\n"+
              "by winning a challenge north of the meditation room.\n"+
              "If you are there and type 'read sign' you'll get the\n"+
              "conditions.\n";
    }
    return 2;
}

int do_about(string arg) {
    if(!arg) {
       cat("/players/whisky/guild/help/guild");
       return 1;
    }
    if(file_size("/players/whisky/guild/help/"+arg) != -1) {
       cat("/players/whisky/guild/help/"+arg);
       return 1;
    }
    write("Sorry no help on that topic available.\n");
    return 1;
}

int do_toplist() {
    object ob;

    call_other("/players/whisky/guild/room/challenge","???");
   
    if(ob = find_object("/players/whisky/guild/room/challenge")) {
        write("Here is the list of the most honorable Nuns and Monks:\n\n");
        ob->show_list();
    }
    return 1;
}

int do_advance(string arg) {
    if(no_advance() != 2)
       write(no_advance());
    else if(::do_advance(arg) == 2)
        "/sys/chatd"->do_chat(7, "[*Monk*] "+TP->query_real_name(1)
                                +" is now level "+TP->query_level()+"!\n");
    return 1;
}

int do_touch(string arg) {
   string quests, *banned;

   if(::do_join(arg) == 1)
      return 1;
   if(arg != "iron" && arg != "iron with arm") {
     if (this_player()->query_real_guild() != 7)
       write("An inner voice tells you: Touch the iron with your arm!\n");
     else
       write("You are already a Monk, you don't have to proof yourself \
again.\n");
     return 1;
   }
   else if (file_size(FILE) > 0) {
      banned = explode(read_file(FILE), "\n");
      if(member_array(this_player()->query_real_name(), banned) != -1) {
          write(
          "You have been banished from this guild, mail the guildmaster!\n");
          return 1;
      }
   }
   if(member_array(TP->query_race(),RACES) == -1 && 
      !stringp(TP->query_property("join_monks"))) {
      write("Guildmaster Sauron tells you: Sorry, but you must be accepted \
by a monk legend before you can join here.\n");
      return 1;
   }
   else if(((!TP->query_quests() || 
            !(member_array("millquest",explode(TP->query_quests(),"#"))+1)))) {
       write("Guildmaster Sauron tells you: First you have to help Hobbe \
to get his mill working again.\n");
      return 1;
   }
   else  {
     say(TP->query_name()+" screams loudly as "+TP->query_pronoun()+  
         " touches the glowing metal with\n"+TP->query_possessive()+
         " right arm.\n",TP);
     write(
     "As you touch the glowing metal with your arm to burn in the\n"+
     "guild symbol, you scream from pain, but an inner voice tells\n"+
     "you:\n\n");

     TP->hit_player(random((TP->query_max_hp()*5)/4), 5);
//     write(to_string(previous_object()));

     if(TP->query_ghost()) {
         write("Sorry :*( , you had a heart attack!\n");
         return 1;
     } 
     if(TP->query_gender() == 2)
        write("You are now a NUN!\n");
     else if(TP->query_gender() == 1)
        write("You are now a MONK!\n");
     else
        write("You are now a NUNK!\n");
     TP->set_guild(guild);
     call_other(_partner, "???");
     _partner->raise_practice(TP, 10);
     "/sys/chatd"->do_chat(7,"[*Monk*] "+TP->query_real_name(1)
                            +" has joined our guild!\n");
     return 1;
   }
   return 1;
}
                       
varargs int query_maxhp(int lvl, int lg) {
    return HPBASE + (lvl * HP) + (((1 + lg * lvl)* 2) / 3);
}

varargs int query_maxsp(int lvl, int lg) {
    return SPBASE + (lvl * SP) + (((1 + lg * lvl)* 2) / 3);
}

#if 0
int query_player() {
    return 1;
}
#endif

#ifdef LOWER_SKILLS
/*  
     this function is very special its to set high monk_skills down,
     when the player left the monks_guild. The idea is following,
     when you learn a skill and don't train it enough you will forget
     it slowly.
                                                                      */
int lower_skills() {
     string  *allskills, sk;
     int     i, age, szs;
     object  *players;
     mapping map;
     mixed   type;

     players = users();
     i = sizeof(players)-1;
     allskills = query_all_skills();
     szs =  sizeof(allskills);

     while(i)  {
          if ( (map = players[i]->query_property("ms_time"))!=-1 && 
                players[i]->query_real_guild()!=7 &&
                !players[i]->query_immortal()) {
               age = players[i]->query_age();
               sk = allskills[random(szs)];
               if (map[sk]  && map[sk] < (age + 1000)) {
                  type = players[i]->get_skill(sk);
                  
                  if (type && type[0] > 10) {
                      raise_skill(players[i],sk,-(20 + type[0])/20);

/* removed, because the player feel it at a time 
                      type = explode(sk,"_");
                      type = type[1];
                      tell_object(players[i],
                      "You forgot something about your "+to_string(type)+ 
                      " skill !\n");
                                                     end comment */

                  }
               }
           }
         i--;
     }
    return 1;
}
#endif

void reset(int flag) {
    ::reset(flag);
    if(!flag) {
        skill_reset(0);
        guild = GM->query_number(GUILD);
        set_guild(guild);

        short_desc = "In the Guildmaster's chamber";
        long_desc = "You are inside a rather big chamber, in the Monk \
chapel. In front of you is a black altar, with a big red ball hovering in \
the air. Beside the altar there are 2 golden pots with good, but strange \
smelling smoke of herbs steaming out of them. Standing on the altar is a \
big glowing piece of iron with big golden Dragon engraved on it. There is \
a big iron sign fixed to the wall.\n";

        dest_dir = ({
            PATH+"c2","west",
            PATH+"c6","north",
        });

        items = ({
            "wall", "The walls are made of red bricks",
            "walls", "The walls are made of red bricks",
            "bricks", "A bit dusty red bricks",
            "altar", "A big black altar",
            "pot", "You see two steaming golden pots standing beside the \
altar",
            "pots", "You see two steaming golden pots standing beside the \
altar",
            "iron", "A glowing piece of iron",
            "dragon", "You see a big golden dragon engraved into the iron",
            "sign", "There is something written on it",
        });
    }
#ifdef LOWER_SKILLS
    else if(!random(3))
        lower_skills();
#endif
}

void add_init() {
  add_action("do_about",	"about");
  add_action("do_toplist",	"toplist");
//  add_action("do_opinions",	"opinions");
  add_action("do_read",		"read");
  add_action("do_touch",	"touch");
  add_action("do_start",	"start");
}
