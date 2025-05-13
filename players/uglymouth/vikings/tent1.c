/* the viking chief's tent */
inherit "room/room";

void reset(int arg) {
object vik;

   if(!(vik=present("viking leadar")) || !living(vik))
   transfer(clone_object("/players/uglymouth/vikings/monsters/vleadar"),this_object());

   if(arg) return 0;

   set_light(1);
   short_desc="The viking chief's tent";
   long_desc="You are in the viking chief's tent. \n"
           + "It looks quite comfortable in here, with a fieldbed containing fur blankets \n"
           + "and a table and chair. A small barrel stands in the corner. \n"
           + "There are some papers on the table. \n";
   dest_dir=({"/players/uglymouth/vikings/camp3","out", });
   items=({"fieldbed","A low bed that can easily be taken apart",
           "blankets","Fur blankets, garanteeing warm nights",
           "table","A simple light wooden table",
           "chair","A simple light wooden chair",
           "barrel","It's used to do your you know what in",
           "papers","It looks like they form a kind of journal", });
   }

void init() {
   ::init();
   add_action("read_it","read");
   }

int read_it(string str) {
string date,words1,words2,words3,*cmds;
int day;
   if(str!="paper" && str!="papers" && str!="paper 1" &&
      str!="paper 2") return 0;
   if(str=="paper" || str=="papers") {
      write("In the mess you find two papers that make some sense. \n"
          + "Do you want to read paper 1 or paper 2 ? \n");
      return 1;
      }
   if(str=="paper 1") {
      write("Sxdawju: \n");
      write("Cqrb ngynmrcrxw qjb knnw xamnanm kh Qjpja, Qrqp Uxam xo cqn Ertrwpb. \n"
          + "Cqrb kjh qjb knnw lqxbnw oxa lxwzdnbc, knljdbn bxvngqnan jaxdwm qnan \n"
          + "cqn anvjrwb xo xwn xo xda qnaxb urn kdaarnm dwmna j vxewm, bdaaxdwmnm \n"
          + "kh kunbbnm bcxwnb. Vjh xda udlt kn pxxm. \n");
      /* for all you poor wizards who don't have time to translate it:
         Journal: 
         This expedition has been ordered by Hagar, High Lord of the
          Vikings. This bay has been chosen for conquest, because
          somewhere around here the remains of one of our heros lie
          burried under a mound, surrounded by blessed stones.
          May our luck be good. (translate with j = a) */
      return 1;
      }
   if(str=="paper 2") {
      date=ctime(time());
      sscanf(date,"%s %s %d %s",words1,words2,day,words3);
      cmds=({"juu jkxjam","qxvn wn px","armn cqn bnj","kanjt dy ljvy",
             "kjlt exyjpn","armn cqn fjenb","cnjen cqn kjh",
             "pjcqna cqn uxxc","qxrbc cqn oujp","jc cqn xjab"});
      if(day > 29) day=day-30;
      if(day > 19) day=day-20;
      if(day > 9)  day=day-10;
      write("Bnlanc Lxmnb: \n"
          + "Cxmjh'b lxvvjwm cx bjru kjlt qxvn rb " + cmds[day] + ".\n"
          + "Cnuu cqrb lxvvjwm cx Ertrwp Admmja oxa ngnldcrxw. \n\n");
      /* this translates as: Secret Codes:
         Today's command to sail back home is cmds[day].
         Tell this command to Viking Ruddar for execution.
         cmds = all aboard, home we go, ride the sea, break up camp,
                back voyage, ride the waves, leave the bay, 
                gather the loot, hoist the flag, at the oars. (j=a) */
      return 1;
      }
   }

void vikings_leave() {
object *inv;
int i;
   tell_room(this_object(),"A viking arrives. \n"
      + "The viking says: We're breaking up. You'll have to leave this tent. \n"
      + "The viking shows you out. \n\n");
   inv=all_inventory(this_object());
   for(i=0;i<sizeof(inv);i++) {
      if(inv[i]->query_player()) {
         transfer(inv[i],"/players/uglymouth/vikings/camp3");
         environment(inv[i])->long();
         }
      }
   return 0;
   }

vikings_arrive() {
object vik;
   if(!(vik=present("viking leadar")) || !living(vik))
   transfer(clone_object("/players/uglymouth/vikings/monsters/vleadar"),this_object());
   return 0;
   }
