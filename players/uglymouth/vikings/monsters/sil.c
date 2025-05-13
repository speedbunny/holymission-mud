/* Sil the beachcomber */
inherit "obj/monster";

void reset(int arg)   {
   ::reset(arg);

   if(!present("rope",this_object())) {
      transfer(clone_object("/obj/rope"),this_object());
      }

   if(!arg)   {

   set_name("sil");
   set_alias("Sil the beachcomber");
   set_short("Sil the beachcomber");
   set_long("Sil, the famous beachcomber. \n"
          + "He looks rather worn by the life on the beach, but this is how he likes it. \n"
          + "He's dressed in old but sturdy fisherman's clothes. \n"
          + "In his eyes you can see a certain wisdom, but he doesn't look very smart. \n");
   set_level(4);
   set_aggressive(0);
   set_gender(1);

   transfer(clone_object("/players/uglymouth/vikings/items/longknife"),this_object());
   command("wield longknife");
   }
}

void init() {
   ::init();
   add_action("buy","buy");
   }

int catch_tell(string str) {
string name,words;
   if(sscanf(str,"%s tells you: advise %s rabbits",name,words)==2 ||
      sscanf(str,"%s says: advise %s rabbits",name,words)==2) {
      call_out("advise",5);
      return 1;
      }
   return 0;
   }

void advise() {
   write("Sil scratches his head, thinking. \n"
       + "Sil tells you: Aah, yes, I remember. Haven't done that in a mighty long time. \n"
       + "Well, first you need a rope. From it you 'make snare', like this. \n"
       + "Sil does the rope trick. \n"
       + "Sil tells you: Find a rabbit's hole and 'set snare' before the entrance. \n"
       + "Then just wait until you've got something and regularly 'check snare'. \n"
       + "Might you run out of patience or time, just 'disarm snare'. \n"
       + "I wish you good hunting, my friend. \n");
   if(!present("rope",this_player()) && present("rope",this_object())) {
      write("Oh, but I see you don't have a rope. I can sell you one for only 20 coins. \n");
      }
   say("Sil mumbles something to "+this_player()->query_name()+". \n",this_player());
   return;
   }

int buy(string str) {
object rope;
   if(!(str=="rope" || str=="rope from sil")) return 0;
   if(!present("rope",this_object())) {
      write("Sil says: Sorry, but I don't have any ropes right now. \n");
      return 1;
      }
   if(this_player()->query_money() < 20) {
      write("Sil says: The rope costs 20 gold coins which you don't have. \n");
      return 1;
      }
   rope=present("rope",this_object());
   transfer(rope,this_player());
   this_player()->add_money(-20);
   write("You buy a rope from Sil. \n");
   say(this_player()->query_name()+" buys a rope from Sil. \n",this_player());
   return 1;
   }
