/* A rock in the sea with a mermaid */
inherit "room/room";
int cn;

void get_chats() {
string *chats;

   if(!chats) {
      chats = allocate(8);
      chats[0] = "The mermaid sings: 'Lift the anchor' sounded like hell at departure.\n";
      chats[1] = "The mermaid sings: The family at home never knew if they'd see their men again.\n";
      chats[2] = "The mermaid sings: Second mates always were the scapegoats aboard, for crew and officers.\n";
      chats[3] = "The mermaid sings: Green like grass the weaker ones hung aside during heavy storms.\n";
      chats[4] = "The mermaid sings: Rock sea floor is now the last bed for the many unlucky ones.\n";
      chats[5] = "The mermaid sings: In storms many gods were prayed to, to relieve them of this hell.\n";
      chats[6] = "The mermaid sings: The rations were low and so was the men's spirit if disease broke out.\n";
      chats[7] = "The mermaid sings: Pool your money and gamble was all the entertainment sailors had.\n";
      }
   if(cn < 8) {
      tell_room(this_object(),chats[cn]);
      cn++;
      call_out("get_chats",3);
      return;
      }
   cn = 0;
   return;
   }

monster_died() {
   if(find_call_out("get_chats")!=-1) remove_call_out("get_chats");
   cn = 0;
   return 0;
   }

void make_mermaid() {
object merm;
   merm = clone_object("obj/monster");
   merm->set_name("a beautiful mermaid");
   merm->set_alias("mermaid");
   merm->set_short("A beautiful mermaid");
   merm->set_long("You immediately fall in love with her. She sings so sweet.\n");
   merm->set_gender(2);
   merm->set_al(75);
   merm->set_level(2);
   merm->set_wc(4);
   merm->set_ac(4);
   merm->set_spell_mess1("That high note hurt your ears, but it sounds lovely");
   merm->set_spell_mess2("The mermaid sings so lovely it breaks your heart");
   merm->set_chance(60);
   merm->set_spell_dam(10);
   merm->set_dead_ob(this_object());
   move_object(merm,this_object());
   return;
   }

void reset(int arg)   {

   if(!present("a beautiful mermaid")) make_mermaid();

   if(arg) return 0;
   set_light(1);
   short_desc="A rock in the sea";
   long_desc="You're on the top of the rock, trying not to slip down again. \n"
           + "From here you indeed have a magnificent view over the bay. \n"
           + "You notice a smoothed spot, like if someone likes to sit here very often. \n";
   items=({
           "rock","Solid grey rock. It's slippery because it's wet",
           "view","It's a wide view over the bay. You think see a ship in the distance",
           "ship","You can hardly distinguish it, but it looks unfamiliar",
           "bay","A white beach surrounding a calm part of the sea",
           "sea","A heavenly blue sea, reflecting a golden sun",
           });

   }

void init() {
   ::init();
   if(present("a beautiful mermaid") && find_call_out("get_chats")==-1)
      call_out("get_chats",5);

   add_action("climb","climb");
   }

int climb(string str) {
object merm,*ob;
int i,j;
   if(str!="down" && str!="rock") return 0;
   if(present("a beautiful mermaid") && random(10)<7) {
      write("Your mind tells you to go, but your heart says you want to stay here. \n"
           + "You struggle inside, but then your heart wins so you stay to hear more songs. \n");
      return 1;
      }
   write("You climb down the slippery rock \n");
   ob = all_inventory(this_object());
   for(i=0;i<sizeof(ob);i++) {
      if(ob[i]->query_player() && ob[i]!=this_player()) j++;
      }
   if(j==0 && find_call_out("get_chats")!=-1) {
      remove_call_out("get_chats");
      cn = 0;
      }
   this_player()->move_player("down the rock#players/uglymouth/vikings/shallow");
   return 1;
   }

void vikings_leave() {
   items=({
           "rock","Solid grey rock. It's slippery because it's wet",
           "view","You have a beautiful look at the scenery of the bay",
           "bay","A white beach surrounding a calm part of the sea",
           "sea","A heavenly blue sea, reflecting a golden sun",
      });
   return 0;
   }

void vikings_arrive() {
   items=({
           "rock","Solid grey rock. It's slippery because it's wet",
           "view","It's a wide view over the bay. You think see a ship in the distance",
           "ship","You can hardly distinguish it, but it looks unfamiliar",
           "bay","A white beach surrounding a calm part of the sea",
           "sea","A heavenly blue sea, reflecting a golden sun",
      });
   return 0;
   }
